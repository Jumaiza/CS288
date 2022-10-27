#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *key;
    int value;
    struct Node *next;
};
struct List {
    struct Node *head;
};
struct List SLL_new() {
    /* construct an empty list */
    struct List list;
    list.head = NULL;
    return list;
}
int SLL_length(struct List *list) {
    /* return the number of items in the list */
    struct Node *p;
    int n = 0;
    for (p = list->head; p != NULL; p = p->next) {
        ++n;
    }
    return n;
}
int SLL_empty(struct List *list) {
    /* return true if the list contains no items */
    return list->head == NULL;
}

void SLL_pop(struct List *list, char *key, int *value){
    /* remove first node */
    struct Node *node = list->head;
    list->head = node->next;

    if(key != NULL)
        key = node->key;

    if(value != NULL)
        *value = node->value;

    free(node);
}

void SLL_clear(struct List *list) {
    /* remove all items from the list */
    while (!SLL_empty(list)) {
        SLL_pop(list,NULL,NULL);
    }
}

void SLL_push(struct List *list, char *key, int value){
    /* insert the item at the front of the list */
    struct Node *node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = list->head;
    list->head = node;
}

void SLL_insert(struct List *list, char *key, int value){
    /* insert node in ascending order */
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *current;
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(SLL_empty(list)){
        list->head = newNode;
        return;

    }else if(strcmp(list->head->key, key) > 0){
        free(newNode);
        SLL_push(list,key,value);
        
    }else if(SLL_length(list)==1){
        list->head->next=newNode;

    }else{
        for (current = list->head; current != NULL; current = current->next) {

            if(current->next==NULL){
                current->next=newNode;
                break;
            }

            if(strcmp(current->next->key, newNode->key) > 0){
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
        }

    }
}

void SLL_toString(struct List *list){

    struct Node *p;
    int n = 0;
    for (p = list->head; p != NULL; p = p->next) {
        printf("%d: ",n);
        printf(p->key);
        printf(", %d\n",p->value);
        ++n;
    }
}

int main(){
    
    struct List list = SLL_new();

    SLL_insert(&list,"16",34);
    SLL_insert(&list,"13",34);
    SLL_insert(&list,"11",34);
    SLL_insert(&list,"19",34);
    SLL_pop(&list,NULL,NULL);
    SLL_push(&list,"345",436);

    SLL_toString(&list);

    return 0;
}