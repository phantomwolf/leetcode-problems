#!/bin/bash
PROTO="http"
USER_AGENT='Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:53.0) Gecko/20100101 Firefox/53.0'


# 1 - url
function get_id()
{
    local id=$(basename "$1" | awk '{print substr($0, 1, 4)}')
    echo "$id"
    return 0
}

# 1 - url
function get_chapter_id()
{
    local chapter_id=$(basename "$1" | awk '{print substr($0, 5, 4)}')
    echo "$chapter_id"
    return 0
}

# 1 - url
function get_page_id()
{
    local page_id=$(basename "$1" | grep -oP '\d{3}(?=.html)')
    echo "$page_id"
    return 0
}

# 1 - url
# 2 - file to save
function download()
{
    echo "[INFO] Downloading: $1" 1>&2
    curl -A "$USER_AGENT" -s "$1" -o "$2" &> /dev/null
    local ret=$?
    if [[ $ret -ne 0 ]]; then
        rm -f "$2"
        curl -A "$USER_AGENT" -s "$1" -o "$2" &> /dev/null
        ret=$?
    fi
    return $ret
}

# Download webpage and convert it to UTF-8 encoding
# 1 - url
# 2 - file to save
function download_html()
{
    echo "[INFO] Downloading html: $1" 1>&2
    curl -A "$USER_AGENT" -s "$1" -o "$2.tmp"
    local ret=$?
    if [[ $ret -ne 0 ]]; then
        rm -f "$2.tmp"
        curl -A "$USER_AGENT" -s "$1" -o "$2.tmp"
        ret=$?
    fi
    if [[ $ret -ne 0 ]]; then
        return $ret
    fi
    iconv -c -f big5 -t utf-8 "$2.tmp" > "$2"
    rm -f "$2.tmp"
    return 0
}

# 1 - url. Example: http://www.cartoonmad.com/comic/4240.html
# 2 - (Optional)first: The first chapter, default to the first one available
# 3 - (Optional)last: The last chapter, default to the last one available
# output: relative urls of all chapters: /comic/424000162018001.html
function get_chapters()
{
    echo "[INFO] Getting chapters: $1" 1>&2
    local id=$(get_id "$1")
    local dir="$HOME/$id"
    local -i first="$2"
    local -i last="$3"
    mkdir -p "$dir"

    download_html "$1" "$dir/summary.html"
    if [[ $? -ne 0 ]]; then
        echo "[FAIL] Failed to download summary page: $1" 1>&2
        return 1
    fi

    local chapters=$(grep -oP "/comic/$id\\d+\\.html" "$dir/summary.html" | sort -h | uniq)
    if [[ -z "$2" ]]; then
        first=$(echo -e "$chapters" | head -n1 | awk '{split($0, a, "/"); print substr(a[3], 5, 4) + 0}')
    fi
    if [[ -z "$3" ]]; then
        last=$(echo -e "$chapters" | tail -n1 | awk '{split($0, a, "/"); print substr(a[3], 5, 4) + 0}')
    fi
    echo -e "$chapters" | awk "{split(\$0, a, \"/\"); id = substr(a[3], 5, 4); if (id + 0 >= $first && id + 0 <= $last) {print \$0}}"
    rm -f "$dir/summary.html"
    return 0
}

# 1 - url. Example: http://www.cartomad.com/comic/424001022018001.html
function get_pages()
{
    echo "[INFO] Getting pages: $1" 1>&2
    local id=$(get_id "$1")
    local chapter_id=$(get_chapter_id "$1")
    local dir="$HOME/$id/$chapter_id"
    mkdir -p "$dir"
    local file=$(basename "$1")
    local -i first=$(echo "$file" | cut -d'.' -f1)
    download_html "$1" "$dir/$file"
    # Get the last page number
    local -i last=$(grep -oP "${id}${chapter_id}\\d+(?=.html)" "$dir/$file" | sort -h | uniq | tail -n1 | tr -d ' ')
    local pages="$first.html"
    local -i i=0
    for (( i=$first+1 ; $i <= $last ; i+=1 )) ; do
        pages="$pages\n$i.html"
    done
    echo -e "$pages"
    rm -f "$dir/$file"
    return 0
}

# 1 - url: http://www.cartomad.com/comic/424001022018001.html
function get_pic()
{
    echo "[INFO] Downloading pic: $1"
    local id=$(get_id "$1")
    local chapter_id=$(get_chapter_id "$1")
    local page_id=$(get_page_id "$1")
    local dir="$HOME/$id/$chapter_id"
    mkdir -p "$dir"
    local pic=$(curl -A "$USER_AGENT" -s "$1" | grep -oP 'http://[\w.]+cartoonmad.com[/\w.]+\.(jpg|png)')
    local file=$(basename "$pic")
    # Download picture
    curl -A "$USER_AGENT" -s "$pic" -o "$dir/$file" &> /dev/null
    if [[ $? -ne 0 ]]; then
        rm -f "$dir/$file"
        curl -A "$USER_AGENT" -s "$pic" -o "$dir/$file" &> /dev/null
        if [[ $? -ne 0 ]]; then
            echo "[FAIL] Failed to download $pic"
            return 1
        fi
    fi
    return 0
}

function usage()
{
    echo "Usage: $0 summary_or_chapter_url [start_chapter] [end_chapter]"
}

# Parameters
if [[ $# -lt 1 ]]; then
    usage
    exit 255
fi
chapters=$(get_chapters "$1" $2 $3)
echo "$chapters" | while read chapter; do
    chapter="$PROTO://www.cartomad.com$chapter"
    pages=$(get_pages "$chapter")
    echo "$pages" | while read page; do
        page="$PROTO://www.cartomad.com/comic/$page"
        get_pic "$page"
    done
done
