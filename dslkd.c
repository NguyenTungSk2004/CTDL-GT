#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char ten[30];
	int msv;
	float d1, d2, d3;
    float tb;
}Data;
typedef struct tagNode{
	Data infor;
	struct tagNode *link;
}Node;
typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

//Tao danh sach rong
void initList(LList*L){
	L->pHead=NULL;
	L->pTail=NULL;
	L->spt=0;
}

//Kiem tra danh sach rong
int emptyList(LList L){
	return (L.spt==0);
}

//Nhap
void Nhap(Data *x){
	scanf("%d", &(x->msv));
	if (x->msv>0){
		scanf("%s", x->ten);
		scanf("%f", &(x->d1));
		scanf("%f", &(x->d2));
		scanf("%f", &(x->d3));
        x->tb=(x->d1+x->d2+x->d3)/3;
	}
}

//In
void In(Data x){
	printf("%s %d %.2f %.2f %.2f\n", x.ten, x.msv, x.d1, x.d2, x.d3);
}

//Chen X vao dau danh sach
void insert_Head(LList*L, Data x){
	//Tao pp
	Node *pp;
	pp=(Node*) malloc(sizeof(Node)); //Cap bo nho size Node
	pp->infor=x;
	pp->link=NULL;
	//Chen dau
	if (emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		pp->link=L->pHead;
		L->pHead=pp;	
	}
	L->spt++;
}

//Chen X vao cuoi danh sach
void insert_Tail(LList*L, Data x){
	//Tao pp
	Node *pp;
	pp=(Node*) malloc(sizeof(Node)); //Cap bo nho size Node
	pp->infor=x;
	pp->link=NULL;
	//Chen cuoi
	if (emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		L->pTail->link=pp;
		L->pTail=pp;
	}
	L->spt++;
}

//Chen sau q
void insert_After(LList *L, Node *q, Data x){
    Node *pp;
    if (q==NULL) return;
    else{
        pp=(Node*) malloc(sizeof(Node));
        pp->infor=x;
        pp->link=q->link;
        q->link=pp;
        if (q==L->pTail) L->pTail=pp;
        L->spt++;
    }
}

//Tao danh sach LIFO
void tao_ds(LList *L){
	initList(L); //17
	Data x;
	do{
		Nhap(&x);
		if (x.msv>0) insert_Head(L, x); //27
	}
	while (x.msv>0);
    //printf("%d", L->spt);
}

//Chen tang
void chen_tang(LList *L, Data x){
    Node *pp=L->pHead, *q;
    while (pp != NULL && pp->infor.tb < x.tb){
        q=pp;
        pp=pp->link;
    }
    if (pp==NULL || pp==L->pHead) insert_Head(L, x);
    else insert_After(L, q, x);
}

//Tron 2 danh sach
LList merge(LList L1, LList L2){
    Node *i =L1.pHead; 
    while(i != NULL){
        chen_tang(&L2, i->infor);
        i = i->link;
    }
    return L2;
}

//Duyet danh sach
void duyet_ds(LList L){
	Node *pp=L.pHead;
	while (pp!=NULL){
		In(pp->infor);
		pp=pp->link;
	}
}

//Main
int main(){
	LList ds1; LList ds2; LList ds;
	initList(&ds1); initList(&ds2); ;initList(&ds);
	tao_ds(&ds1); tao_ds(&ds2);
    ds=merge(ds1, ds2);
    duyet_ds(ds);
}