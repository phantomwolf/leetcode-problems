#include <gio/gio.h>


int main(int argc, char *argv[])
{
    GFile *file;
    file = g_file_new_for_path("./gfile.c");

    return 0;
}
