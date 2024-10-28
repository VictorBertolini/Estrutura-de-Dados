#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista Encadeada.c"

#define VERTEX_NUM 100

typedef struct 
{
    int vertex;
    bool is_digraph;
    List *adjacency_list;
} Graph;

Graph * createGraph(bool is_digraph)
{
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    newGraph->vertex = VERTEX_NUM;
    newGraph->is_digraph = is_digraph;

    newGraph->adjacency_list = (List *) malloc(sizeof(List) * VERTEX_NUM);   

    for (int i = 0; i < VERTEX_NUM; i++)
        newGraph->adjacency_list[i].init = NULL; 

    return newGraph;
}

int add_arc(Graph *graph, int init_vertex, int final_vertex)
{
    if (graph == NULL)
        return false;

    Data data;
    data.num = final_vertex;
    // add_first(&graph->adjacency_list[init_vertex], data);
    add_sorted(&graph->adjacency_list[init_vertex], data);

    return true;
}

int viewGraph(Graph *graph)
{
    if (graph == NULL) 
        return false; 

    for (int i = 0; i < VERTEX_NUM; i++)
    {
        if (graph->adjacency_list[i].init != NULL)
        {
            printf("%d -> ", i);
            viewList(&graph->adjacency_list[i]);
        }
    }

    return true;
}

int viewAllGraph(Graph *graph)
{
    if (graph == NULL)
        return false;

    for (int i = 0; i < VERTEX_NUM; i++)
    {
        printf("%d -> ", i);
        viewList(&graph->adjacency_list[i]);
    }

    return true;
}

int free_graph(Graph **graph)
{
    if (*graph == NULL)
        return true;

    for (int i = 0; i < VERTEX_NUM; i++) {
        Node *current = (*graph)->adjacency_list[i].init;
        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
        (*graph)->adjacency_list[i].init = NULL;
    }

    free((*graph)->adjacency_list);
    free(*graph);
    *graph = NULL;

    return true;
}


int main()
{
    Graph *graph = createGraph(false);

    add_arc(graph, 0, 1);
    add_arc(graph, 1, 2);
    add_arc(graph, 1, 4);
    add_arc(graph, 2, 3);
    add_arc(graph, 3, 1);
    add_arc(graph, 4, 3);
    add_arc(graph, 4, 1);
    add_arc(graph, 3, 3);
    add_arc(graph, 3, 0);

    viewGraph(graph);

    free_graph(&graph);



    return 0;
}

