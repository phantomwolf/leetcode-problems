#include "graph.h"

#define WHITE   0
#define GREY    1
#define BLACK   2


void bfs(graph *g, char name)
{
    guint vertex_num    = g_list_length(g->vertex);
    gint *color         = (gint *)g_malloc0(sizeof(gint) * vertex_num); // 0 => white, 1 => grey, 2 => black
    gint *distance      = (gint *)g_malloc(sizeof(gint) * vertex_num);
    vertex **parent     = (vertex **)g_malloc0(sizeof(vertex *) * vertex_num);
    for (int i = 0; i < vertex_num; ++i) {
        distance[i] = G_MAXINT;
    }
    g_print("BFS: ");
    // Find starting point
    vertex *s       = graph_find_vertex(g, name);
    gint index      = graph_vertex_indexof(g, name);
    color[index]    = GREY;
    distance[index] = 0;
    parent[index]   = NULL;
    GQueue *queue   = g_queue_new();
    g_queue_push_tail(queue, s);
    while (!g_queue_is_empty(queue)) {
        vertex *u = g_queue_pop_head(queue);
        index = graph_vertex_indexof(g, u->name);
        GList *l = u->edge;
        while (l != NULL) {
            vertex *v = GRAPH_GET_VERTEX(l);
            gint v_index = graph_vertex_indexof(g, v->name);
            if (color[v_index] == WHITE) {
                color[v_index] = GREY;
                distance[v_index] = distance[index] + 1;
                parent[v_index] = u;
                g_queue_push_tail(queue, v);
            }
            l = l->next;
        }
        color[index] = BLACK;
        g_print("%c(%d), ", u->name, distance[index]);
    }
    g_print("\n");
    g_queue_free(queue);
    g_free(distance);
    g_free(parent);
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

    g_print("index: %d\n", graph_vertex_indexof(g, 's'));

    bfs(g, 's');


    return 0;
}
