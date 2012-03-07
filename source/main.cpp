#include<iostream>
using namespace std;
#include "lista_pokazivac.h"
//#include "lista_polje.h"
void sortIispis(lista *k){
     int i=0;
     osoba polje[100];
   element pozicija= FirstL(k);
   while (pozicija != EndL(k)){
       polje[i]=RetrieveL(pozicija, k);
       pozicija = NextL(pozicija, k);
       i++;    
       }  
   bool zamjena = true;
    for (int j = i-1; j > 0 && zamjena; j--) {
        zamjena = false;
        for (int k = 0; k < j; k++)
            if (polje[k].mat > polje[k+1].mat) {
               osoba pom = polje[k];
               polje[k] = polje[k+1];
               polje[k+1] = pom;
               zamjena = true;
            }
    }   
    for(int j=0;j<i;j++){
            cout<<"Maticni broj: "<<polje[j].mat<<endl;
            cout<<"Ime i prezime: "<<polje[j].ime<<endl;
            cout<<"Godine: "<<polje[j].god<<endl;
            cout<<"-------------------------------"<<endl;
            }
   }
void unos(lista *k){
     bool vrati;
     cout<<"maticni broj"<<endl;
     cin >> pacijent.mat;
     cout<<"ime i prezime"<<endl;
     cin.ignore();
     cin.getline(pacijent.ime,50);
     cout<<"godine"<<endl;
     cin >> pacijent.god;
     vrati = InsertL(pacijent,FirstL(k),k);
}
void pretrazi(lista *k){
     int i=0,br=0;
      osoba polje[100];
   element pozicija= FirstL(k);
   while (pozicija != EndL(k)){
       polje[i]=RetrieveL(pozicija, k);
       pozicija = NextL(pozicija, k);
       i++;    
       }  
   for(int j=0;j<i;j++){
           if(polje[j].god<18){
           br++;
           cout<<"Maticni broj: "<<polje[j].mat<<endl;
            cout<<"Ime i prezime: "<<polje[j].ime<<endl;
            cout<<"Godine: "<<polje[j].god<<endl;
            cout<<"-------------------------------"<<endl;
            }
            }
            cout<<"Ukupan broj pacijenata mladjih od 18 godina je "<<br<<endl;
     }
void brisi(lista *k){
     bool nasao,c;
     cout<<"Unesite maticni broj pacijenta kojeg zelite izbrisati:"<<endl;
     osoba broj;
     cin >> broj.mat;
     nasao = DeleteL(LocateL(broj,k),k); 
     if(!nasao) cout<<"Brisanje neuspjelo"<<endl;
     if(nasao) cout<<"Brisanje uspjelo"<<endl;
     }
int main(){
    int izbor;
    lista *k = InitL(k);
    do{
    cout<<"1. Unos pacijenata/ispis pacijenata"<<endl;
    cout<<"2. Ispis od najmanjeg maticnog broja"<<endl;
    cout<<"3. Ispis mladjih od 18god"<<endl;
    cout<<"4. Brisanje pacijenata"<<endl;
    cout<<"0. Izlaz iz programa"<<endl;
    cin >> izbor;
    switch(izbor){
                  case 1:
                  unos(k);
                  break;
                  case 2:
                       sortIispis(k);
                       break;
                  case 3:
                       pretrazi(k);
                       break;
                  case 4:
                       brisi(k);
                  }
    }while(izbor!=0);
    system("PAUSE");
    return 0;
}
