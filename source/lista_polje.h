
struct osoba{
       char ime[50];
       int god;
       int mat;
};

osoba pacijent;

struct lista {
	   char ime[50][50];
	   int mat[50];
       int god[50];
	   int cursor;
};
typedef int element;


element EndL(lista *l){
		return l->cursor;
}

element FirstL(lista *l){
        if(l->cursor==0) EndL(l);
		return 0;
}

element NextL(element p, lista *l){
		if ((p>=l->cursor) || (p<0))
		   return 0;
		return(p+1);
}


element PreviousL(element p, lista *l){
	if ((p>l->cursor) || (p<=0))
		return 0;
	return (p-1);
}

element LocateL(osoba x, lista *l){
	int i=0;
	while ((i!= l->cursor) && (l->mat[i]!=x.mat))
           i++;  
	return i;
}

bool InsertL(osoba x, element e, lista *l){
	int i;
	if ((e<=l->cursor) && (e>=0)) {
		for (i=l->cursor; i>=e; i--) {
			l->mat[i]=l->mat[i-1];
		    l->god[i]=l->god[i-1];
		    strcpy(l->ime[i],l->ime[i-1]);
        }        
		l->cursor++;
		l->mat[e]=x.mat;
		l->god[e]=x.god;
		strcpy(l->ime[e],x.ime);
		return 1;
	}
	else {
		return 0;
	}
}


bool DeleteL(element e, lista *l){
	int i;
	if ((e<l->cursor) && (e>=0)) {
		for (i=e; i<l->cursor; i++){
			l->mat[i]=l->mat[i+1];
			l->god[i]=l->god[i+1];
			strcpy(l->ime[i],l->ime[i+1]);
        }
		l->cursor--;
    
		return 1;
	}
	else {
		return 0;
	}
}


osoba RetrieveL(element e, lista *l){
	if ((e<l->cursor) && (e>=0)) {
		pacijent.mat = l->mat[e];
		pacijent.god= l->god[e];
		strcpy(pacijent.ime,l->ime[e]);		
        return pacijent;
	}
}


void DeleteAllL(lista *l){
	l->cursor=0;
}


lista* InitL(lista *l){
	 l = new lista;
     l->cursor=0;
     return l;
}
