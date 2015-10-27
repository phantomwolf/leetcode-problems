#include <glib.h>
#include <stdio.h>
#include <unistd.h>

gpointer baka_callback(gpointer data)
{
    printf("Baka!\n");
    sleep(3);
    printf("Baka! Baka!\n");
    return NULL;
}


int main(int argc, char *argv[])
{
    GThread *tp;
    tp = g_thread_new("baka-thread",
                      baka_callback,
                      NULL);
    g_thread_join(tp);

    return 0;
}
