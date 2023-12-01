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
}Stack;
void initS(Stack *S){
	S->pHead=NULL;
	S->pTail=NULL;
	S->spt=0;
}
int emptyS(Stack S){
	return (S.spt==0);
}
void pushS(Stack *S, Data x){
	Node *pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor=x;
	pp->next=NULL;
	pp->prev=NULL;
	if (emptyS(*S)){
		S->pHead=pp;
		S->pTail=pp;
	}
	else{
		S->pHead->prev=pp;
		pp->next=S->pHead;
		S->pHead=pp;
	}
	S->spt++;
}
void popS(Stack *S){
	Node *pp;
	if (emptyS(*S)) return;
	else{
		pp=S->pHead;
		S->pHead=pp->next;
		free(pp);
		S->spt--;
		if (S->pHead==NULL) S->pTail==NULL;
	}
}

void Nhap(Data *x){
	scanf("%d", &(x->id));
}
void In(Data x){
	printf("%d ", x.id);
}
void lifo(Stack *S){
	Data x;
	initS(S);
	do{
		Nhap(&x);
		if (x.id!=0) pushS(S, x);
	}
	while (x.id!=0);
}
void duyet(Stack S){
	Node *pp=S.pHead;
	while (pp!=NULL){
		In(pp->infor);
		pp=pp->next;
	}
}
int main(){
	Stack st1;
	initS(&st1);
	lifo(&st1);
	duyet(st1);
	popS(&st1);
	printf("\n\n");
	duyet(st1);
}
