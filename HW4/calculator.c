#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* gcc -ansi -Wall -Wextra -Wpedantic -Werror calculator.c
./a.out midterm01.csv midterm02.csv finalexam.csv finalgrade.csv */

struct Node {
    char *key;
    int value;
    struct Node *next;
};
struct List {
    struct Node *head;
};
struct List SLL_new() {
    struct List list;
    list.head = NULL;
    return list;
}
int SLL_length(struct List *list) {

    struct Node *p;
    int n = 0;
    for (p = list->head; p != NULL; p = p->next) {
        ++n;
    }
    return n;
}
int SLL_empty(struct List *list) {
    return list->head == NULL;
}

void SLL_pop(struct List *list, char *key, int *value){

    struct Node *node = list->head;
    list->head = node->next;

    if(key != NULL){
        strcpy(key,node->key);
    }
    if(value != NULL){
        *value = node->value;
    }

    free(node->key);
    free(node);
}

void SLL_clear(struct List *list) {

    while (!SLL_empty(list)) {
        SLL_pop(list,NULL,NULL);
    }
}

void SLL_push(struct List *list, char *key, int value){

    struct Node *node = malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    if(!SLL_empty(list)){
        node->next = list->head;
    }
    list->head = node;
}

void SLL_insert(struct List *list, char *key, int value){

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

void readFile(struct List *list, char* fileName){

    FILE * file = fopen(fileName,"r");
    char row[256+1+sizeof(int)];

    while(fgets(row, sizeof(row), file)){

        char *studentID = strtok(row,",");
        double doubleGrade = atof(strtok(NULL,","));
        int grade = (int)(doubleGrade+0.5);
        SLL_insert(list,studentID,grade);
    }

    fclose(file);
}

void writeFile(struct List *list, char* fileName){

    FILE * writeFile = fopen(fileName,"w");
    char currentID[256];
    int currentGrade;
    int sum = 0;

    while(!SLL_empty(list)){

        SLL_pop(list,currentID,&currentGrade);
        sum = sum + currentGrade;

        if(SLL_empty(list) || strcmp(currentID, list->head->key) != 0){

            int finalGrade = (int)((sum/3.0)+0.5);
            char finalOutput[sizeof(currentID)+sizeof(finalGrade)];
            sprintf(finalOutput,"%s,%d\n",currentID,finalGrade);
            fputs(finalOutput,writeFile);
            sum = 0;
        }
    }

    fclose(writeFile);
}

int main(int argc, char* argv[]){

    struct List list = SLL_new();
    
    readFile(&list,argv[argc-4]);
    readFile(&list,argv[argc-3]);
    readFile(&list,argv[argc-2]);

    writeFile(&list,argv[argc-1]);

    return 0;
}