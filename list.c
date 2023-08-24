#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *lista = (List *) malloc(sizeof(List));
  if (lista != NULL)
  {
    lista -> head = NULL;
  }
  return lista;
}

void * firstList(List * movie)
{
  if(movie->head == NULL) return NULL;
  movie -> current = movie -> head;
  return movie -> head -> data;
}

void * nextList(List * list) 
{
    if (list != NULL && list->current != NULL && list->current-> next != NULL) 
    {
      list->current = list->current->next;
      return list->current->data;
    } else {
      return NULL;
    }
}

void * lastList(List * movie) {
  if(movie != NULL)
  {
    movie -> current = movie -> tail;
    return movie->tail->data;
  }
  return NULL;
}

void * prevList(List * movie) 
{
  if(movie -> current -> prev != NULL)
  {
    movie -> current = movie -> current -> prev;
    return movie-> current->data;
  }
  return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}