#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <glib.h>

#define G_LIST_DATA(list)           ((list)->data)
#define GRAPH_GET_VERTEX(list)      ((struct vertex *)(G_LIST_DATA(list)))


// 无向图
// 邻接表
typedef struct vertex vertex;

struct vertex
{
    char name;
    GList *edge;   // Data type: struct vertex *
};

typedef struct graph graph;

struct graph
{
    GList *vertex;  // Data type: struct vertex *
    gboolean directed;  // 是否有向图
};

vertex *graph_find_vertex(graph *g, char name);

vertex *graph_find_vertex_by_index(graph *g, gint index);

gint graph_vertex_indexof(graph *g, char name);

gboolean graph_add_vertex(graph *g, char name);

gboolean graph_has_edge(graph *g, char name1, char name2);

gboolean graph_add_edge(graph *g, char name1, char name2);

void graph_print(graph *g);

#endif
