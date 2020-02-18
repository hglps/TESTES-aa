#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
using namespace std;

// CODIGO SEMI COMPLETO
// FALTA VERIFICAR QUANDO SO TEM AS HEADS Q N FORAM REFERENCIADAS :/

#define MAX_SIZE 101
#define SIZEHASH 1000

typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct element element;
typedef struct hashtable hashtable;

int arr[200];

struct adj_list
{
    char item[17];
    int pos;
    adj_list *next;
};

struct graph
{
    adj_list *vertices[MAX_SIZE];
    short visited[MAX_SIZE];
};

struct element
{
    char word[17];
    int pos; //???
};

struct hashtable
{
    element *table[SIZEHASH];
    int size;
};

hashtable* create_hash()
{
    hashtable *new_hash = (hashtable*) malloc(sizeof(hashtable));
    int i;
    new_hash->size = 0;
    for(i=0;i<SIZEHASH;i++)
    {
        new_hash->table[i]= NULL;
    }
    return new_hash;
}

graph* create_graph()
{
    graph *n_graph = (graph*) malloc(sizeof(graph));
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        n_graph->vertices[i] = NULL;
        n_graph->visited[i] = 0;
    }
    return n_graph;
}

adj_list* create_adj_list(char *item, int pos)
{
    adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
    strcpy(new_adj_list->item,item);
    new_adj_list->pos = pos;
    new_adj_list->next = NULL;
    return new_adj_list;
}

void add_edge(graph *graph, char *v1, char *v2, int index1, int index2)
{
    adj_list *vex = create_adj_list(v2, index2);

    if(graph->vertices[index1] == NULL){
        graph->vertices[index1] = vex;
    }
    else{
        while(graph->vertices[index1]->next != NULL){
//            printf("entrou no while\n");
            graph->vertices[index1] = graph->vertices[index1]->next;
        }
        graph->vertices[index1]->next = vex;

    }

//    vex->next = graph->vertices[index1];
//    graph->vertices[index1] = vex;
}

void put_in_hash(graph *gp, hashtable *hs, char *word1, char *word2)
{
    int i=0,posHash1 = -1, posHash2 = -1;
    while(hs->table[i] != NULL)
    {
        if(!strcmp(hs->table[i]->word, word1)){
            posHash1= hs->table[i]->pos;
            break;
        }
        i+=1;
    }
    if(posHash1 == -1)
    {
        element *new_element = (element*) malloc(sizeof(element));
        strcpy(new_element->word, word1);
        new_element->pos = hs->size; // estranho....
        posHash1 = new_element->pos;
        hs->table[hs->size] = new_element;
        hs->size+=1;
    }


    i=0;
    while(hs->table[i] != NULL)
    {
        if(!strcmp(hs->table[i]->word, word2)){
            posHash2 = hs->table[i]->pos;
            break;
        }
        i+=1;
    }
    if(posHash2 == -1)
    {
        element *new_ele2 = (element*) malloc(sizeof(element));
        strcpy(new_ele2->word, word2);
        new_ele2->pos = hs->size;
        posHash2 = new_ele2->pos;
        hs->table[hs->size] = new_ele2;
        hs->size+=1;
    }

    add_edge(gp, word1, word2, posHash1, posHash2); ////////////////parei aqui

}

void dfs(graph *graph, hashtable *hs, int source)
{
    if(graph->visited[source] != -1){
        graph->visited[source] = 1;
    }
//    printf("visited: %s\n", hs->table[source]->word);

    adj_list *n_adj_list = graph->vertices[source];
    //caso de lista vazia
    if(n_adj_list == NULL)
        graph->visited[source] = -1;

    while(n_adj_list != NULL)
    {
        if (graph->visited[n_adj_list->pos] == 0 )
        {
            dfs(graph, hs, n_adj_list->pos);
        }
        n_adj_list = n_adj_list->next;
    }


}

int timeToStop(graph *gp, hashtable *hs){
    int i;
    for(i=0; i<MAX_SIZE; i++){
        if(gp->vertices[i] != NULL)
            return 0;
    }

//    for(i=0; i<hs->size; i++){
//        if(hs->table[i] != NULL)
//            return 0;
//    }

//    for(i=0; i<hs->size; i++){
//        if(strcmp(hs->table[i]->word, "") != 0)
//            return 0;
//    }
    return 1;
}

void swap(int *array1, int *array2)
{
    int aux;
    aux = *array1;
    *array1 = *array2;
    *array2 = aux;
}

void bbsort(int *ar, hashtable *hs, int size){
    int i,j;
    for(i=0; i<size; i++){
        for(j=i+1; j< size; j++)
        if( strcmp(hs->table[ar[i]]->word, hs->table[ar[j]]->word ) > 0 ){
            swap(&ar[i], &ar[j]);
        }
    }
}

void remover(graph *gp, hashtable *hs, int *array, int size){
    int i,j;
//    printf("SIZE  : %d \n", size);

    for(j=0;j < MAX_SIZE; j++){
//        if(hs->table[j] != NULL)  printf("%s -> ", hs->table[j]->word);
//        adj_list *list = gp->vertices[j];
//        while(list != NULL){
////            printf("%s -> ", list->item);
//            list = list->next;
//        }
//        if(hs->table[j] != NULL) printf("\n");
    }

//    printf("\n\n");

    for(i=0; i< size; i++){
//        printf("searching for: %s\n", hs->table[array[i]]->word);
        for(j=0; j<MAX_SIZE; j++){
            adj_list *list1 = gp->vertices[j];
            while(list1 != NULL){
                if (list1->next != NULL && strcmp(list1->next->item, hs->table[array[i]]->word) == 0) {
                    gp->vertices[j]->next = gp->vertices[j]->next->next;
                    break;
                }
                else if (strcmp(list1->item, hs->table[array[i]]->word) == 0) {
                    gp->vertices[j] = gp->vertices[j]->next;
                }

                list1 = list1->next;
            }
        }
    }

    for(i=0; i<MAX_SIZE; i++){
        gp->visited[i] = 0;
    }
}

void formArray(graph* gp, hashtable *hs, int size){
    int i,j=0;
    int arr[size];
    for(i=0; i<MAX_SIZE; i++){
        if(gp->visited[i] == -1){
            arr[j] = i;
            j++;
        }
    }

    bbsort(arr, hs, j);
    //PRINT FINAL
    for(i=0; i<j; i++){
            printf("%s\n", hs->table[arr[i]]->word);
    }
    //PRINT FINAL

    remover(gp, hs, arr, j);
//    printf("\n\n apos\n\n");

//    for(i=0; i<MAX_SIZE; i++){
//        adj_list *list = gp->vertices[i];
//        if(list != NULL) printf("i=%d  : ", i);
//        while(list != NULL){
//            printf("%s -> ", list->item);
//            list = list->next;
//        }
//        if(list != NULL) printf("\n");
//    }
//    printf("----------------------------------------");

}

int notMissingHeads(graph *gp, hashtable *hs){
    int i,j;
//    for(i=0; i<hs->size; i++){
//        if
//    }

    return 1;
}




int main()
{
    graph *gp = create_graph();
    hashtable *htable = create_hash();
    int i=0,j=0,n;

    char word1[18];
    char word2[18];
//    printf("PUT n:\n");
    scanf("%d", &n);

    while(n--)
    {
        scanf("%s %s", word1, word2);
        put_in_hash(gp, htable, word1, word2);
    }

//    for(i=0; i<htable->size; i++){
//            adj_list *list = gp->vertices[i];
//            if(list != NULL) printf("i=%d  : %s -> ", i, htable->table[i]->word);
//            while(list != NULL){
//                printf("%s -> ", list->item);
//                list = list->next;
//            }
//            printf("\n");
//        }

    while(true){
        if(timeToStop(gp, htable))
            if(notMissingHeads(gp, htable))
                break;
//        for(i=0; i< htable->size; i++)
//            if(gp->vertices[i] != NULL)

        dfs(gp, htable, i);

        formArray(gp, htable, n*2 + 1);

//
    }

    printf("\n\n");
        for(i=0; i<htable->size; i++){
            adj_list *list = gp->vertices[i];
            if(list != NULL) printf("i=%d  : %s -> ", i, htable->table[i]->word);
            while(list != NULL){
                printf("%s -> ", list->item);
                list = list->next;
            }
            printf("\n");
        }
    printf("\n----------------------------------------");




    return 0;


}

