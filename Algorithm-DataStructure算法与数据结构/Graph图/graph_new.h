#ifndef _GRAPH_NEW_H_
#define _GRAPH_NEW_H_

#include <glib.h>

#define G_LIST_DATA(l)          ((l)->data)
#define G_LIST_GET_VERTEX(l)    ((struct Vertex *)(G_LIST_DATA(l)))
#define G_LIST_GET_EDGE(l)      ((struct Edge *)(G_LIST_DATA(l)))

typedef enum VertexColor VertexColor;
enum VertexColor
{
    WHITE,
    GREY,
    BLACK,
};

typedef enum GraphType GraphType;
enum GraphType
{
    UG,     // 无向图
    DG,     // 有向图
    WUG,    // 有权值的无向图
    WDG,    // 有权值的有向图
};

// 邻接表 Adjacency list
typedef struct Vertex Vertex;
struct Vertex
{
    VertexColor color;  // 用于BFS、DFS等算法
    GHashTable *edge;   // vertex_name => weight
};

typedef struct Graph Graph;
struct Graph
{
    GraphType type;
    GHashTable *vertex; // vertex_name => struct Vertex
};

void graph_init(Graph *g, GraphType type);

void graph_destroy(Graph *g);

// Find vertex by name
Vertex *graph_vertex_find(Graph *g, char name);

// Add vertex
Vertex *graph_vertex_add(Graph *g, char name);

// Remove vertex and all its edges
Vertex *graph_vertex_remove(Graph *g, char name);

// Add edge
Edge *graph_edge_add(Graph *g, char from, char to);

// Remove edge
Edge *graph_edge_remove(Graph *g, char from, char to);

// Print vertexes and their edges
void graph_print(Graph *g);

#endif
