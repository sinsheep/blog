#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int date;
    struct node *next;
}Node;
Node *creatNode(int value);
Node* insertNode(Node *head,Node *tail,int value);
void insertNode(Node *head,int value);
void priNode(Node *head);
int isLast(Node *head);
Node *find(Node *head,int value);
void deleteNodeByValue(Node *head,int value);
int main(){

    Node *head,*tail;
    head=creatNode(0);
    tail = head;
    int n;
    for(int i=0;i<4;i++){
        scanf("%d",&n);
        tail=insertNode(head,tail,n);
        priNode(head);
    }
    return 0;
}
Node *creatNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->date=value;
    newNode->next=NULL;
    return newNode;
}
Node* insertNode(Node *head,Node *tail,int value){
    Node *newNode=creatNode(value);
    tail->next=newNode;
    tail=newNode;
    head->date++;
    return tail;
}
void insertNode(Node *head,int value){
    Node *newNode =creatNode(value);
    newNode->next=head->next;
    head->next=newNode;
    head->date++;
}
void priNode(Node *head){
    printf("-------------------------------------------------\n");
    Node *tmp=head->next;
    while(tmp!=NULL){
        printf("%d\n",tmp->date);
        tmp=tmp->next;
    }
    printf("-------------------------------------------------\n");
}
int isLast(Node *head){
    return head->next==NULL;
}
Node *find(Node *head,int value){
    Node *P;
    P=head->next;
    while(P->next!=NULL&&P->date!=value) P=P->next;
    return P;
}
void deleteNodeByValue(Node *head,int value){
    Node *tmp=head;
    while(tmp->next->next!=NULL&&tmp->next->date!=value){
        tmp=tmp->next;
    }
    Node *P=tmp->next;
    tmp->next=tmp->next->next;
    free(P);
}
