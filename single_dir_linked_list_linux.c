#include <stdio.h>
#include <stdlib.h>
#include "cs50.h" // needed for get_string and get_char
#include <string.h>

typedef struct node{//remeber to add name of stuct as well as at the end
    string content;
    struct node* next;
} node;

void visualize(node* position);
node* add_first(node* list);
node* append(node* list);
void free_memo(node* list);
node* decide(char x, node* list);
node* pop_first(node* list);
node* pop_last(node* list);

int main(void){
    node* list = NULL;

    while (true){ // saking user what to do 
        printf("what you want to do:\n");
        char c;
        if (list == NULL){
            printf("add first element? 'f'\n");
            printf("quit ? 'q'\n");
            c = get_char("insert here your anwser: ");
            if (c=='f'){
                list = decide(c,list); // passing the imput to the function
                continue;
            }
            else if (c=='q'){
                printf("Exiting programs\n");
                break;
            }
            else{
                continue;
            }
        }
        else if(list !=NULL){
            printf("append to the list? 'a'\n");
            printf("add as first? 'f' \n");
            // printf("insert inside? 'i'\n");
            printf("delete an element? 'd'\n");
            printf("quit ? 'q'\n");
            c = get_char("insert here your anwser: ");
            if (c=='f'||c=='a'|| c=='d'){
                list = decide(c,list);
                continue;
            }
            else if (c=='q'){
                printf("Exiting programs\n");
                break;
            }
            else{
                continue;
            }
        }
    }

    visualize(list);
    free_memo(list);
    return 0;
}

void visualize(node* position){
    printf("\n+----List Visualise----+\n\n");
    while(position != NULL){
        printf("Location:%p\n", position);
        printf("Phrase:\"%s\"\n", position->content);
        printf("Next: %p\n\n", position->next);
        position = position->next;
    }
    printf("\n+---------------------+\n\n");
}

node* add_first(node* list){
    string word;
    node *n;
    word = get_string("Enter your list element: ");
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
    }
    n->content = word;
    n->next = NULL;
    n->next = list;
    list = n;
    return list;
}

node* append(node* list){
    string word;
    node *n;
    node* tmp;
    tmp = list;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    word = get_string("Enter your list element: ");
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
    }
    n->content = word;
    n->next = NULL;
    tmp->next = n;
    return list;
}

void free_memo(node* list){
    while(list != NULL){
        node* tmp = list->next;
        free(list);
        list = tmp;
        
    }
    printf("memory is freed\n\n");
}

node* decide(char x, node* list){
    if (x=='f'){
        list=add_first(list);
        visualize(list);
        return list;
    }
    else if(x=='a'){
        list = append(list);
        visualize(list);
        return list;
    }
    else if(x=='d'){
        char d;
        d=get_char("woud you like to delete the first 'f' or last element 'l': ");
        if(d == 'f'){
            list = pop_first(list);
        }
        else if(d == 'l'){
            list = pop_last(list);
        }
        visualize(list);
        return list;
    }
    else{
        return list;
    }
    printf("\n-------------------------\n");
}

node* pop_first(node* list){
    if(list->next != NULL){
        node* tmp = list->next;
        free(list);
        list = tmp;
    }
    else if(list->next == NULL){
        free(list);
        list = NULL;
    }
    else{
    }
    return list;
}

node* pop_last(node* list){
    if (list == NULL){
        return list=NULL;
    }
    else if (list->next == NULL){
        free(list);
        return list=NULL;
    }
    node* last=list;
    node* before_last = NULL;
    while(last->next!=NULL){
        before_last =last;
        last = last->next;
    }
    before_last->next = NULL;
    free(last);
    return list;
}