#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"
#include <string.h>

typedef struct node{//remeber to add name of stuct as well as at the end
    string content;
    struct node* next;
} node;

void visualize( node* position);

int main(void){
    node* list = NULL;
    //inserting first element
    string word;
    node *n;
    //___________________________________________________

    //add first
    word = get_string("Enter your list element: ");
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
        return 1;
    }
    n->content = word;
    n->next = NULL;
    n->next = list;
    list = n;
    //___________________________________________________

    //add at the head od the list
    word = get_string("Enter your list element: ");
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
        return 1;
    }
    n->content = word;
    n->next = NULL;
    n->next = list;
    list = n;
    //___________________________________________________

    //append TODO
    word = get_string("Enter your list element: ");
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
        return 1;
    }
    n->content = word;
    n->next = NULL;
    n->next = list;
    list = n;

    node* ptr = list;
    int i = 0;
    while(i!=3){
        printf("ppointer position: %p\n",ptr);
        ptr = list->next;//correct
        
        
        i++;
    }//---------------- that is not dooing good

    visualize(list);
    free(list);
    // free(n);

}

void visualize(node* position){
    printf("\n+--List Visualise--+\n\n");
    while(position != NULL){
        printf("Location:%p\n", position);
        printf("Phrase:\"%s\"\n", position->content);
        printf("Next: %p\n\n", position->next);
        position = position->next;
    }
    printf("\n+-----------------+\n\n");
}



// void decide(char x, node* list){
//     if ( x=='q'){
//         printf("exiting program\n");
//         free_memo();
//         exit(0);
//     }
//     else if(x=='f'){
//         //fun element a the head of l. list
//     }
//     else if(x=='a'){
//         //fun element that appends element
//     }
//     else if(x=='i'){
//         //fun element that inserts element
//     }
//     else if(x=='i'){
//         //fun element that inserts element
//     }
//     else if(x=='q'){
//         //fun element that inserts element
//     }
//     else if(x=='d'){
//         //fun to delete elements
//     }
// }

// void free_memo(void){
//     //memory freeing
// }

// void add_at_beginig(string str){
//     //add at the begining if no elements or not
// }

// void append(string str){
//     //add element a te the end
// }






    // while (true){
    //     printf("what you want to do:");
    //     char c;
    //     if (list == NULL){
    //         printf("add first element? 'f'\n");
    //         printf("quit ? 'q'\n");
    //         c = get_char("insert here your anwser: ");
    //         if (c=='q' || c=='f'){
    //             decide(c,list);
    //         }
    //         else{
    //             continue;
    //         }
    //     }
    //     else if(list !=NULL){
    //         printf("append to the list? 'a'\n");
    //         printf("add as first? 'f' \n");
    //         printf("insert inside? 'i'\n");
    //         printf("delete an element? 'd'\n");
    //         printf("quit ? 'q'\n");
    //         c = get_char("insert here your anwser: ");
    //         decide(c,list);
    //         continue;
    //     }
    // }



