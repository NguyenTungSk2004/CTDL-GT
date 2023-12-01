#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ten[30];
	int msv;
	float d1,d2,d3;
}Data;

typedef struct TagNode{
	Data infor;
	struct TagNode *link;
}Node;

typedef struct {
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

void insert_head(LList *L, Data x){
	Node *pp;
	pp = (Node*)malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if (L->spt == 0){
		L->pHead = pp;
		L->pTail = pp;
	}else{
		pp->link = L->pHead;
		L->pHead = pp;
	}
	L->spt++;
}

void nhap(Data *x){
	printf("Nhap msv: "); scanf("%d",&x->msv);
	if (x->msv == 0) return;
	fflush(stdin);
	printf("Nhap ten: "); scanf("%[^\n]",x->ten);
	printf("Nhap d1: "); scanf("%f",&x->d1);
	printf("Nhap d2: "); scanf("%f",&x->d2);
	printf("Nhap d3: "); scanf("%f",&x->d3);
}

float diemtb(Data x){
	return (x.d1 + x.d2 + x.d3)/3;
}

void indl(Data x){
	printf("%d %s %.2f %.2f %.2f %.2f\n",x.msv,x.ten,x.d1,x.d2,x.d3,diemtb(x));
}

void duyet(LList L){
	Node *pp = L.pHead;
	while (pp != NULL){
		indl(pp->infor);
		pp = pp->link;
	}
}

void init(LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

void taods(LList *L){
	init(L);
	Data x;
	do{
		nhap(&x);
		if (x.msv != 0) insert_head(L,x);
	}while(x.msv !=0);
}

void selection_sort(LList *L){
	for (Node *i = L->pHead; i->link != NULL; i = i->link){
		Node *k = i;
		for (Node *j = i->link; j != NULL; j = j->link){
			if (strcmp(k->infor.ten,j->infor.ten) > 0 ||
				strcmp(k->infor.ten,j->infor.ten) == 0 && 
				diemtb(k->infor) < diemtb(j->infor))
				k =j;
		}
		if (k != i){
			Data tmp;
			tmp = k->infor;
			k->infor = i->infor;
			i->infor = tmp;
		}
	}
}

int main(){
	LList L;
	taods(&L);
	selection_sort(&L);
	duyet(L);
}