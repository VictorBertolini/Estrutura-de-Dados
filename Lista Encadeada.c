#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data
{
    int num;
} Data;

typedef struct node
{
    Data data;
    struct node *next;
} Node;

typedef struct list 
{
    Node *init;
} List;

List * createList()
{
    List *newList = (List *) malloc(sizeof(List));
    newList = (List *) malloc(sizeof(List));

    if (newList == NULL)
        return NULL;

    newList->init = NULL;

    return newList;
}

Data fillData(int num)
{
    Data data;
    data.num = num;

    return data;
}

Node *fillNode(Node *node, Data data)
{
    node->data.num = data.num;

    return node;
}

Node *createNode(Data data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL)
        return NULL;
    
    newNode->next = NULL;
    newNode = fillNode(newNode, data);

    return newNode;
}

int add_first(List *list, Data data)
{
    if (list == NULL)
        return false;
    
    Node *node = createNode(data);

    node->next = list->init;
    list->init = node;

    return true;
}

int add_last(List *list, Data data)
{
    if (list == NULL)
        return false;
    
    Node *node = createNode(data);

    Node *aux = list->init;

    if (list->init == NULL)
        return add_first(list, data);

    while (aux->next != NULL)
        aux = aux->next;
    
    aux->next = node;
        
    return true;
}

int add_position(List *list, Data data, int position)
{
    if (list == NULL || position < 0)
        return false;

    Node *node = createNode(data);

    Node *aux = list->init;

    if (position == 0)
        return add_first(list, data);

    while (aux->next != NULL && position > 1)
    {
        aux = aux->next;
        position--;
    }

    node->next = aux->next;
    aux->next = node;

    return true;
}

// * Depends of Data Struct
int add_sorted(List *list, Data data)
{
    if (list == NULL)
        return false;

    if (list->init == NULL || data.num < list->init->data.num)
        return add_first(list, data);
    
    Node *aux = list->init;
    while (aux->next != NULL && data.num > aux->next->data.num)
        aux = aux->next;
    

    Node *node = createNode(data);

    node->next = aux->next;
    aux->next = node;
    
    return true;
}

int viewList(List *list)
{
    if (list == NULL)
        return false;

    Node *aux = list->init;

    while (aux != NULL)
    {
        printf("[ %d ]", aux->data.num);
        aux = aux->next;
    }
    printf("\n");

    return true;
}

int remove_first(List *list)
{
    if (list == NULL)
        return false;
    
    if (list->init == NULL)
        return true;
    
    Node *aux = list->init;

    list->init = list->init->next;
    free(aux);

    return true;
}

int remove_last(List *list)
{
    if (list == NULL)
        return false;
    
    if (list->init == NULL)
        return true;
    
    Node *aux = list->init;
    Node *prev_aux;

    while (aux->next != NULL)
    {
        prev_aux = aux;
        aux = aux->next;
    }

    prev_aux->next = aux->next;
    free(aux);
    
    return true;
}

int remove_position(List *list, int position)
{
    if (list == NULL || position < 1)
        return false;
    
    if (list->init == NULL)
        return true;

    if (position == 1)
        return remove_first(list);
    
    Node *aux = list->init;
    Node *prev_aux;

    while (aux->next != NULL && position > 1)
    {
        prev_aux = aux;
        aux = aux->next;
        position--;
    }
    if (position > 1)
        return false;

    prev_aux->next = aux->next;
    free(aux);
    
    return true;
}

int delete_list_elements(List *list)
{
    if (list == NULL)
        return false;
    
    while (list->init != NULL)
        remove_first(list);
    
        

    return true;
}

int free_list(List **list)
{
    delete_list_elements(*list);
    free(*list);

    *list = NULL;

    return true;
}

int count_list_elements(List *list)
{
    if (list == NULL)
        return -1;
    if (list->init == NULL)
        return 0;

    Node *aux = list->init;
    int count = 0;

    while (aux != NULL)
    {
        aux = aux->next;
        count++;
    }

    return count;
}

List *copy_list(List *list)
{
    if (list == NULL)
        return NULL;
    
    List *newList = createList();

    Node *aux = list->init;
    while (aux != NULL)
    {
        add_last(newList, aux->data);
        aux = aux->next;
    }

    return newList;
}

// int main()
// {
//     List *list = createList();

//     Data data;
//     for (int i = 1; i < 10; i++)
//     {
//         data.num = i;
//         add_sorted(list, data);
//     }
//     viewList(list);

//     List *secondList = copy_list(list);
//     viewList(secondList);

//     printf("[ %d ]\n", count_list_elements(list));
//     free_list(&list);
//     printf("[ %d ]\n", count_list_elements(list));

//     return 0;
// }




