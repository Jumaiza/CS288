#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* gcc -ansi -Wall -Wextra -Wpedantic -Werror calculator.c
./a.exe midterm01.csv midterm02.csv finalexam.csv finalgrade.csv */

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

    free(node->key);
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
    node->next = NULL;

    if(SLL_empty(list)==0){
        node->next = list->head;
    }
    list->head = node;

}

void SLL_insert(struct List *list, char *key, int value){
    /* insert node in ascending order */
    struct Node *newNode = malloc(sizeof(struct Node));
    char *keyCopy = malloc(sizeof(char)*strlen(key));
    strcpy(keyCopy,key);
    newNode->key = keyCopy;
    newNode->value = value;
    newNode->next = NULL;

    if(SLL_empty(list)){
        free(newNode);
        SLL_push(list,keyCopy,value);

    }else if(strcmp(list->head->key, newNode->key) > 0){
        free(newNode);
        SLL_push(list,keyCopy,value);
        
    }else if(SLL_length(list)==1){
        list->head->next=newNode;

    }else{
        struct Node *current;
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
        printf("%s",p->key);
        printf("->%d\n",p->value);
        ++n;
    }
    printf("\n");
}

int main(int argc, char* argv[]){

    struct Node *currentNode;
    int sum = 0;
    char *currentID = NULL;
    char finalOutput[256];
    FILE * writeFile = fopen(argv[4],"w");

    struct List list = SLL_new();
    int i;
    for(i = 1; i < argc-1; i++){

        FILE * readFile = fopen(argv[i],"r");
        char row[256];

        while(fgets(row, sizeof(row), readFile)){

            char *studentID = strtok(row,",");
            double doubleGrade = atof(strtok(NULL,","));
            int grade = floor(doubleGrade+0.5);
            SLL_insert(&list,studentID,grade);
        }

        fclose(readFile);
    }
    
    SLL_toString(&list);

    for (currentNode = list.head; currentNode != NULL; currentNode = currentNode->next) {

        if(currentNode->next==NULL){
            sum = sum + currentNode->value;
        }
        if(currentID==NULL){
            currentID = currentNode->key;
        }
        else if(strcmp(currentID,currentNode->key) != 0 || currentNode->next==NULL){

            int finalGrade = floor((sum/3.0)+0.5);
            sprintf(finalOutput,"%s,%d\n",currentID,finalGrade);
            fputs(finalOutput,writeFile);

            currentID = currentNode->key;
            sum = 0;
        }
        sum = sum + currentNode->value;
    }

    fclose(writeFile);

    return 0;
}