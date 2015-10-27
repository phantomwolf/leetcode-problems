#include "graph_new.h"


void graph_init(Graph *g, GraphType type)
{
    g->type = type;
    g->vertex = 
}

void graph_destroy(Graph *g)
{
    GList *lv = g->vertex;
    while (lv != NULL) {
        Vertex *v = G_LIST_GET_VERTEX(lv);
        GList *le = v->edge;
        while (le != NULL) {
            Edge *e = G_LIST_GET_EDGE(le);
            g_free(e);
            le = g_list_next(le);
        }
        g_free(v);
        lv = g_list_next(lv);
    }
}

Vertex *graph_vertex_find(Graph *g, char name)
{
    GList *lv = g->vertex;
    while (lv != NULL) {
        Vertex *v = G_LIST_GET_VERTEX(lv);
        if (v->name == name)
            return v;
    }
    return NULL;
}

Vertex *graph_vertex_add(Graph *g, char name)
{
    // Check if a vertex with the same name already exist
    if (graph_vertex_find(g, name) != NULL)
        return NULL;
    Vertex *v = (Vertex *)g_malloc0(sizeof(Vertex));
    v->name = name;
    g->vertex = g_list_append(g->vertex, v);
    return v;
}

Vertex *graph_vertex_remove(Graph *g, char name)
{
    Vertex *target = graph_vertex_find(g, name);
    if (target != NULL) {
        // Remove the vertex
        g->vertex = g_list_remove(g->vertex, target);
        // Remove relevant edges
        GList *lv = g->vertex;
        while (lv != NULL) {
            Vertex *v = G_LIST_GET_VERTEX(lv);
            GList *le = v->edge, *le_prev;
            while (le != NULL) {
                le_prev = le;
                le = g_list_next(le);
                Edge *e = G_LIST_GET_EDGE(le_prev);
                if (e->to == target) {
                    v->edge = g_list_remove_link(v->edge, le_prev);
                }
            }
            lv = g_list_next(lv);
        }
    }
    return v;
}

void graph_print(Graph *g)
{
    GList *lv = g->vertex;
    while (lv != NULL) {
        Vertex *v = G_LIST_GET_VERTEX(lv);
        g_print("%c => ", v->name);
        GList *le = v->edge;
        while (le != NULL) {
            Edge *e = G_LIST_GET_EDGE(le);
            g_print("%c, ", e->to->name);
            le = g_list_next(le);
        }
        g_print("\n");
        lv = g_list_next(lv);
    }
}
