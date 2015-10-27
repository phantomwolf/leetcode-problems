#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void free_func(gpointer data)
{
    printf("Destroying %i from GList...\n", *(gint *)data);
    g_free(data);
}

int main(int argc, char *argv[])
{
    srand(time(0));

    /* Init list */
    GList *list = NULL;
    gint *p;

    /* Append data */
    for(int i = 0; i < 3; ++i) {
        p = (gint *)malloc(sizeof(gint));
        //*p = (gint)rand();
        *p = i;
        list = g_list_append(list, p);
    }
    p = NULL;

    /* Iterate list */
    puts("Iteration:");
    for (GList *l = list; l != NULL; l = l->next) {
        printf("<%i>\n", *(gint *)(l->data));
    }

    /* Reverse iterate list */
    puts("Reverse iteration:");
    for (GList *l = g_list_last(list); l != NULL; l = l->prev) {
        printf("<%i>\n", *(gint *)(l->data));
    }

    /* Destroy list */
    g_list_free_full(list, free_func);

    return 0;
}
