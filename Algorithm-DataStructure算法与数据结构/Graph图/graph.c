#include "graph.h"

vertex *graph_find_vertex(graph *g, char name)
{
    GList *l = g->vertex;
    while (l != NULL) {
        if (GRAPH_GET_VERTEX(l)->name == name) {
            return GRAPH_GET_VERTEX(l);
        }
        l = l->next;
    }
    return NULL;
}

vertex *graph_find_vertex_by_index(graph *g, gint index)
{
    gint i = 0;
    GList *l = g->vertex;
    while (l != NULL && i != index) {
        l = l->next;
        ++i;
    }
    if (l != NULL) {
        return GRAPH_GET_VERTEX(l);
    }
    return NULL;
}

gint graph_vertex_indexof(graph *g, char name)
{
    gint index = 0;
    GList *l = g->vertex;
    while (l != NULL && GRAPH_GET_VERTEX(l)->name != name) {
        l = l->next;
        ++index;
    }
    if (l != NULL) {
        return index;
    }
    return -1;
}

gboolean graph_add_vertex(graph *g, char name)
{
    GList *l = g->vertex;
    while (l != NULL) {
        if (GRAPH_GET_VERTEX(l)->name == name) {
            return FALSE;
        }
        l = l->next; 
    }

    vertex *v = g_malloc(sizeof(vertex));
    v->name = name;
    v->edge = NULL;
    g->vertex = g_list_append(g->vertex, v);
    return TRUE;
}

gboolean graph_has_edge(graph *g, char name1, char name2)
{
    vertex *v1 = graph_find_vertex(g, name1);
    vertex *v2 = graph_find_vertex(g, name2);
    if (!(v1 && v2)) {
        return FALSE;
    }
    GList *l = v1->edge;
    while (l != NULL && GRAPH_GET_VERTEX(l) != v2) {
        l = l->next;
    }
    if (l != NULL) {
        return TRUE;
    }
    return FALSE;
}


gboolean graph_add_edge(graph *g, char name1, char name2)
{
    vertex *v1 = graph_find_vertex(g, name1);
    vertex *v2 = graph_find_vertex(g, name2);
    if (!(v1 && v2)) {
        return FALSE;
    }
    // v1
    GList *l = v1->edge;
    while (l != NULL && GRAPH_GET_VERTEX(l) != v2) {
        l = l->next;
    }
    if (l != NULL) {
        return FALSE;
    }
    v1->edge = g_list_append(v1->edge, v2);
    // v2
    if (g->directed) {
        return TRUE;
    }
    v2->edge = g_list_append(v2->edge, v1);
    return TRUE;
}

void graph_print(graph *g)
{
    GList *lv = g->vertex;
    while (lv != NULL) {
        // Print vertex
        g_print("%c:", GRAPH_GET_VERTEX(lv)->name);
        // Print edges
        GList *le = GRAPH_GET_VERTEX(lv)->edge;
        while (le != NULL) {
            g_print("%c, ", GRAPH_GET_VERTEX(le)->name);
            le = le->next;
        }
        g_print("\n");
        lv = lv->next;
    }
}
