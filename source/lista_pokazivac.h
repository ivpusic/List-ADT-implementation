#include <iostream>
using namespace std;

struct osoba{
       char ime[50];
       int god;
       int mat;
};

osoba pacijent;

struct lista {
		int mat,god;
		char ime[50];
	    lista *next;
	};

typedef struct lista* element;

element EndL(lista *l){
	lista *p=l;
	while (p)
		p=p->next;
	return p;
}

element FirstL(lista *l){
	if(l->next==NULL) return EndL(l);
    return l->next;
}


element NextL(element e, lista *l){
		return e->next;
}


element PreviousL(element e, lista *l){
	lista *p=l->next;
	if(e==l->next){
		exit(0);
	}
	while(e!=p->next && p->next!=NULL)
		p=p->next;
	return p;
}

element LocateL(osoba x, lista *l){
	lista *p=l->next;
	while(p!=NULL&p->mat!=x.mat)
		p=p->next;
	return p;
}


bool InsertL(osoba x, element e, lista *l){
    
 	lista *p=l, *n=new lista;
	while(p->next!=e)
		p=p->next;
	n->mat=x.mat;
	n->god=x.god;
	strcpy(n->ime,x.ime);
	n->next=e;
	p->next=n;
	return 1;
   
}

bool DeleteL(element e, lista *l){
	lista *p=l;
	while(p->next!=e)
	p=p->next;
    p->next=e->next;
	delete e;
	return 1;
}


osoba RetrieveL(element e, lista *l){
 pacijent.mat = e->mat;
 pacijent.god = e->god;
 strcpy(pacijent.ime,e->ime);
 return pacijent;
}

void DeleteAllL(lista *l){
	element p;
	while (l->next != NULL) {
		p=l->next;
		l->next = l->next->next;
		delete p;
	}
}


lista* InitL(lista *l){
	l = new lista;
    l->next = NULL;
    return l;
}


