#include <stdio.h>
#include <stdlib.h>
/* self-referential structure */
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
        printf("%d: ",n+1);
        printf(p->key);
        printf(", %d\n",p->value);
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

void SLL_insert(struct List *list, char *key, int value);

int main(){
    
    struct List list = SLL_new();

    SLL_push(&list, "234534512", 78);
    SLL_push(&list,"89778",95);
    SLL_length(&list);

    return 0;
}