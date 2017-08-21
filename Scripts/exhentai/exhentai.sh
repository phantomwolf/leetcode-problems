#!/bin/bash
BROWSER_TYPE="firefox"
#PROXY=""
PROXY="http://127.0.0.1:8118"
PROXY_USER=""
PROXY_PASSWD=""
ARIA2_OPTS=""
OUTPUT_DIR="./output"

# $1        - String to be trimed
# output    - String after trim
function trim()
{
    echo "$1" | sed -e 's/^\s*//g' -e 's/\s*$//g'
    return $?
}

# $1        - String length
function randstr()
{
    cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w $1 | head -n1
    return $?
}

# $1        - Browser type: firefox/chrome
# output    - Path of cookie database file
function find_cookiefile()
{
    local database
    local -i ret
    case "$BROWSER_TYPE" in
        firefox)
            database=`find ~/.mozilla -name 'cookies.sqlite'`
            ret=$?
            ;;
        *)
            ret=255
            ;;
    esac
    [[ $ret -eq 0 ]] && echo "$database"
    return $ret
}

# $1 - URL
# $2 - Output file
function download()
{
    local cwd=`pwd`
    if [[ -d "$2" ]]; then
        local output_dir="$2"
        local output_file=""
    else
        local output_dir=`dirname "$2"`
        local output_file=`basename "$2"`
    fi
    local url=`trim "$1"`
    url=`echo "$url" | recode html..ascii`
    local cookie_database=`find_cookiefile`
    if [[ $? -ne 0 ]]; then
        echo "Couldn't find cookie database" 1>&2
        return 1
    fi
    cd "$output_dir"
    rm -f "$output_file"
    # Run aria2c to download the file
    local cmd="aria2c --load-cookies '$cookie_database' --check-certificate=false"
    [[ -n "$output_file" ]] && cmd="$cmd -o '$output_file'"
    [[ -n "$PROXY" ]] && cmd="$cmd --all-proxy='$PROXY'"
    [[ -n "$PROXY_USER" ]] && cmd="$cmd --all-proxy-user='$PROXY_USER'"
    [[ -n "$PROXY_PASSWD" ]] && cmd="$cmd --all-proxy-passwd='$PROXY_PASSWD'"
    cmd="$cmd $ARIA2_OPTS '$url'"
    echo "cmd: $cmd" 1>&2
    eval "$cmd"
    ret=$?

    cd "$cwd"
    return $ret
}

# Download main page file
# $1        - URL of main page
# output    - Path of the downloaded main page
function download_main()
{
    local str=`randstr 16`
    local outfile="/tmp/exhentai-main-${str}.html"
    rm -f "$outfile"
    download "$1" "$outfile" 1>&2
    if [[ $? -ne 0 ]]; then
        echo "Main page download fail: $1" 1>&2
        return 1
    fi
    echo "$outfile"
    return 0
}

# $1        - Main page file
# output    - Title
function get_title_from_main()
{
    local title=`grep -oP '(?<=id="gj">)[^<]*' "$1"`
    title=`trim "$title"`
    if [[ -z "$title" ]]; then
        title=`grep -oP '(?<=id="gn">)[^<]*' "$1"`
        title=`trim "$title"`
    fi
    if [[ $? -ne 0 ]]; then
        echo "Title not found: $1" 1>&2
        return 1
    fi
    echo "$title"
    return 0
}

# Get menu page urls
# $1     - Main page file
# $2     - Output directory
# output - URLS of menu pages
function get_menus_from_main()
{
    local menu_urls=`grep -oP '<table[^>]*class="ptb".*?</table>' "$1" | grep -oP 'https?://[^"]*' | sort -h | uniq`
    if [[ $? -ne 0 ]]; then
        echo "Menu urls not found: $1" 1>&2
        return 1
    fi
    echo "$menu_urls"
    return 0
}

# Download menu page file
# $1     - Menu page url
# output - Saved menu page file
function download_menu()
{
    local str=`randstr 16`
    local menu_file="/tmp/exhentai-menu-${str}.html"
    rm -f "$menu_file"
    download "$1" "$menu_file" 1>&2
    if [[ $? -ne 0 ]]; then
        echo "Menu download fail: $1" 1>&2
        return 1
    fi
    echo "$menu_file"
    return 0
}

# Get all the page url of one menu
# $1     - Menu page file
# output - Page urls. Each page contains a picture
function get_pages_from_menu()
{
    local page_urls=`grep -oP '<div[^"]*class="gdtm".*?<img' "$1" | grep -oP '(?<=href=")https?://[^"]*'`
    if [[ $? -ne 0 ]]; then
        echo "Page url not found: $1" 1>&2
        return 1
    fi
    echo "$page_urls"
    return 0
}

# Download picture from one page
# $1    - Page url
# $2    - Output directory
function handle_page()
{
    # Download page
    local page_file="$2/page.html"
    download "$1" "$page_file" 1>&2
    if [[ $? -ne 0 ]]; then
        echo "Page download fail: $1" 1>&2
        return 1
    fi
    # Get picture url
    local pic_url=`grep -ioP '<a[^<]*Download origin' "$page_file" | grep -oP '(?<=href=")http[^"]*'`
    pic_url=`trim "$pic_url"`
    if [[ -z "$pic_url" ]]; then
        pic_url=`grep -oP '<img[^>]*id="img"[^>]*' "$page_file" | grep -oP '(?<=src=")[^"]*'`
        pic_url=`trim "$pic_url"`
    fi
    rm -f "$page_file"
    if [[ -z "$pic_url" ]]; then
        echo "Picture url not found from: $1" 1>&2
        return 2
    fi
    # Download picture
    echo "Download: $pic_url"
    download "$pic_url" "$2" 1>&2
    if [[ $? -ne 0 ]]; then
        echo "Picture download fail: $pic_url" 1>&2
        return 3
    fi
    return 0
}

# Main entry
if [[ $# < 1 ]]; then
    echo "Usage: $0 URL1 [URL2] ..." 1>&2
    exit 255
fi
for arg in "$@"; do
    main_file=`download_main "$arg"`
    [[ $? -ne 0 ]] && exit 1
    # Create output directory
    title=`get_title_from_main "$main_file"`
    output_dir="$HOME/$title"
    [[ $? -ne 0 ]] && exit 2
    mkdir -p "$output_dir"
    # Get menu page urls
    menu_urls=`get_menus_from_main "$main_file"`
    [[ $? -ne 0 ]] && exit 3
    rm -f "$main_file"
    echo "$menu_urls" | while read menu_url; do
        menu_file=`download_menu "$menu_url"`
        [[ $? -ne 0 ]] && exit 4
        # Get page urls
        page_urls=`get_pages_from_menu "$menu_file"`
        [[ $? -ne 0 ]] && exit 5
        rm -f "$menu_file"
        echo "$page_urls" | while read page_url; do
            # Download each picture
            handle_page "$page_url" "$output_dir"
        done
    done
done
