#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{//remeber to add name of stuct as well as at the end
    char content[20];
    char source;
    struct node* next;
} node;

void visualize(node* position);
node* add_first(node* list);
node* append(node* list);
void free_memo(node* list);
node* decide(char x, node* list);
node* pop_first(node* list);
node* pop_last(node* list);
void save(node* list, char* file_name);
node* load(node* list);

int main(void){
    node* list = NULL;

    while (1){ // saking user what to do 
        printf("what you want to do:\n");
        char c;
        if (list == NULL){
            printf("add first element? 'f'\n");
            printf("quit ? 'q'\n");
            printf("load from file (the load will be appeneding)? 'l'\n");
            printf("insert here your anwser: ");
            while ((c = getchar()) == '\n'); // that will consume the new line character by looping over it
            if (c=='f'){
                list = decide(c,list); // passing the imput to the function
                continue;
            }
            else if(c == 'l'){
                list = load(list);
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
            printf("save to file? 's' \n");
            printf("load from file (the load will be appeneding)? 'l'\n");
            printf("delete an element? 'd'\n");
            printf("quit ? 'q'\n");
            printf("insert here your anwser: ");
            while ((c = getchar()) == '\n');
            if (c=='f'||c=='a'|| c=='d'){
                list = decide(c,list);
                continue;
            }
            else if (c=='q'){
                printf("Exiting programs\n");
                break;
            }
            else if (c=='s'){
                int strlen = 50;
                char file_name[strlen];
                printf("Enter your list binary file name (.db)(up to %d char): ",strlen);
                scanf_s("%s",file_name,sizeof(file_name));
                save(list, file_name);
                continue;
            }
            else if(c == 'l'){
                list = load(list);
                continue;
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
        printf("Source: %c\n", position->source);
        printf("Next: %p\n\n", position->next);
        position = position->next;
    }
    printf("\n+---------------------+\n\n");
}

node* add_first(node* list){
    int strlen = 19;
    char word[strlen];
    printf("Enter your list element(up to 19 char): ");
    scanf_s("%s",word,sizeof(word));
    node *n;
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
    }
    strcpy_s(n->content,sizeof(word), word);
    n->source = 'i';
    n->next = NULL;
    n->next = list;
    list = n;
    return list;
}

node* append(node* list){
    node *n;
    node* tmp;
    tmp = list;
    while(tmp->next!=NULL){
        tmp = tmp->next;
    }
    int strlen = 19;
    char word[strlen];
    printf("Enter your list element(up to 19 char): ");
    scanf_s("%s",word,sizeof(word));
    n = malloc(sizeof(node));
    if(n == NULL){
        printf("no memory\n");
        free(n);
    }
    strcpy_s(n->content,sizeof(word), word);
    n->source = 'i';
    n->next = NULL;
    tmp->next = n;
    return list;
}

void free_memo(node* list){
    while(list != NULL){
        if(list->source=='l'){
            free(list->content);
        }
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
        printf("woud you like to delete the first 'f' or last element 'l': ");
        char d;
        while ((d = getchar()) == '\n');
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
        if(list->source=='l'){
            free(list->content);
        }
        node* tmp = list->next;
        free(list);
        list = tmp;
    }
    else if(list->next == NULL){
        if(list->source=='l'){
            free(list->content);
        }
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
        if(list->source=='l'){
            free(list->content);
        }
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
    if(last->source=='l'){
        free(last->content);
    }
    free(last);
    return list;
}

void save(node* list, char* file_name){
    if(list == NULL){
        return;
    }

    FILE* file;
    int a = fopen_s(&file, file_name, "wb");
    if (a!= 0 ||file == NULL){
        printf("error creating file \n");
        return;
    }

    while( list !=NULL){
        fprintf(file, "%s\n", list->content);
        list = list ->next;
    }
    fclose(file);
    printf("\nsaved to a file called: %s\n\n", file_name);
}

node* load(node* list){
    //opening a file
    
    char file_name[20];
    printf("Enter your list binary file name (.db)(up to %d char): ",20);
    scanf_s("%s",file_name,sizeof(file_name));
    FILE* file;
    int b = fopen_s(&file, file_name, "rb");
    if (b!=0 || file == NULL){
        printf("\nerror opening file \n\n");
        return list;
    }


    //looping throught the file 
    char line[100];
    node *n;
    node* tmp;
    while (fgets(line,sizeof(line),file) != NULL ){
        printf("line: %s\n",line);
        
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if(list == NULL){ // adding first elements
            n = malloc(sizeof(node));
            if(n == NULL){
                printf("no memory\n");
                fclose(file);
                return list;
            }
            strcpy_s(n->content, sizeof(line),line); 
            n->source = 'l';
            n->next = NULL;
            n->next = list;
            list = n;
        }
        else if(list != NULL){// appending the the end
            tmp = list;
            while(tmp->next!=NULL){
                tmp = tmp->next;
            }            
            n = malloc(sizeof(node));
            if(n == NULL){
                printf("no memory\n");
                fclose(file);
                return list;
            }
            strcpy_s(n->content, sizeof(line),line);
            n->source = 'l';
            n->next = NULL;
            tmp->next = n;
        }
    }

    visualize(list);
    fclose(file);
    return list;
}