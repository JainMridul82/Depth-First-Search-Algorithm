#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*root=NULL;

struct Queue{
    int data;
    struct Queue *next;
}*front=NULL,*rear=NULL;

void Insert(struct Node **head,int data){
    struct Node *node=(struct Node *)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    if(*head==NULL)
        *head=node;
    else{
        struct Node *p=*head;
        while(p->next!=NULL)
            p=p->next;
        p->next=node;
    }
}

void Insert_AL(struct Node **AL,int index,int data){
    Insert(&AL[index],data);
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

void Display_AL(struct Node **AL){
    int i;
    for(i=1;i<8;i+=1){
        Display(AL[i]);
        printf("\n");
    }
}

void DFS(struct Node **AL,int visited[],int u){
    int v;
    printf("%d\t",u);
    visited[u]=1;
    struct Node *p=AL[u];
    while(p!=NULL){
        if(visited[p->data]==0)
            DFS(AL,visited,p->data);
        p=p->next;
    }
}

int main(){
    struct Node **AL=(struct Node **)calloc(8,sizeof(struct Node));
    Insert_AL(AL,1,2);
    Insert_AL(AL,1,3);
    Insert_AL(AL,1,4);
    Insert_AL(AL,2,1);
    Insert_AL(AL,2,3);
    Insert_AL(AL,3,1);
    Insert_AL(AL,3,2);
    Insert_AL(AL,3,4);
    Insert_AL(AL,3,5);
    Insert_AL(AL,4,1);
    Insert_AL(AL,4,3);
    Insert_AL(AL,4,5);
    Insert_AL(AL,5,3);
    Insert_AL(AL,5,4);
    Insert_AL(AL,5,6);
    Insert_AL(AL,5,7);
    Insert_AL(AL,6,5);
    Insert_AL(AL,7,5);
    int visited[]={0,0,0,0,0,0,0,0};
    DFS(AL,visited,7);
    return 0;
}
