#include "graph.h"

#define WHITE   0
#define GREY    1
#define BLACK   2


typedef struct dfs_vertex dfs_vertex;

void dfs(graph *g)
{
    guint vertex_num    = g_list_length(g->vertex);
    gint *color         = (gint *)g_malloc0(sizeof(gint) * vertex_num);
    GQueue *stack       = g_queue_new();
    vertex *u, *v;

    g_print("DFS: ");
    GList *l = g->vertex;
    while (l != NULL) {
        u = GRAPH_GET_VERTEX(l);
        g_queue_push_tail(stack, u);
        l = l->next;
    }

    while (!g_queue_is_empty(stack)) {
        u = g_queue_pop_tail(stack);
        gint iu = graph_vertex_indexof(g, u->name);
        if (color[iu] == WHITE)
            g_print("%c, ", u->name);
        color[iu] = BLACK;
        l = u->edge;
        while (l != NULL) {
            v = GRAPH_GET_VERTEX(l);
            gint iv = graph_vertex_indexof(g, v->name);
            if (color[iv] == WHITE) {
                g_queue_push_tail(stack, v);
            }
            l = l->next;
        }
    }
    g_print("\n");

    g_queue_free(stack);
    g_free(color);
}

int main()
{
    graph *g = (graph *)g_malloc(sizeof(graph));
    g->directed = FALSE;
    g->vertex = NULL;
    // Add vertex
    char *vertexes = "rstuvwxy";
    for (int i = 0; i < 8; ++i) {
        graph_add_vertex(g, vertexes[i]);
    }
    // Add edges
    graph_add_edge(g, 'r', 'v');
    graph_add_edge(g, 'r', 's');
    graph_add_edge(g, 'w', 's');
    graph_add_edge(g, 'w', 't');
    graph_add_edge(g, 'w', 'x');
    graph_add_edge(g, 't', 'x');
    graph_add_edge(g, 'u', 'x');
    graph_add_edge(g, 'y', 'x');
    graph_add_edge(g, 't', 'u');
    graph_add_edge(g, 'u', 'y');
    // Print tree
    graph_print(g);

    dfs(g);

    return 0;
}
