#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id;
}Data;
typedef struct tagNode{
	Data infor;
	struct tagNode *next, *prev;
}Node;
typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}Queue;
void initQ(Queue *Q){
	Q->pHead=NULL;
	Q->pTail=NULL;
	Q->spt=0;
}
int emptyQ(Queue Q){
	return (Q.spt==0);
}
void addQ(Queue *Q, Data x){
	Node *pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->prev=NULL;
	if (emptyQ(*Q)){
		Q->pHead=pp;
		Q->pTail=pp;
	}
	else{
		Q->pTail->next=pp;
		pp->prev=Q->pTail;
		Q->pTail=pp;
	}
	Q->spt++;
}
void delQ(Queue *Q){
	Node *pp;
	if (emptyQ(*Q)) return;
	else{
		pp=Q->pHead;
		Q->pHead=pp->next;
		free(pp);
		Q->spt--;
		if (Q->pHead==NULL) Q->pTail==NULL;
	}
}
void Nhap(Data *x){
	scanf("%d", &(x->id));
}
void In(Data x){
	printf("%d ", x.id);
}
void fifo(Queue *Q){
	Data x;
	initQ(Q);
	do{
		Nhap(&x);
		if (x.id!=0) addQ(Q, x);
	}
	while (x.id!=0);
}
void duyet(Queue Q){
	Node *pp=Q.pHead;
	while (pp!=NULL){
		In(pp->infor);
		pp=pp->next;
	}
}
int main(){
	Queue qu1;
	initQ(&qu1);
	fifo(&qu1);
	duyet(qu1);
	delQ(&qu1);
	delQ(&qu1);
	printf("\n\n");
	duyet(qu1);
}
