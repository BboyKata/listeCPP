#include <iostream>

using namespace std;
struct nodo
{
    int x; //valore del nodo della lista
    nodo *next; //indirizzo dell'elemento successivo
};

struct lista{
    nodo *T; //indirizzo della testa della lista
    nodo *C; //indirizzo della coda della lista
    int nElem; //numero di nodi della lista
};

lista initLista(){
    lista l; //creo una lista
    l.T = NULL; //inizialmente la testa non punta da nessuna parte
    l.C = NULL; //idem per la coda
    l.nElem = 0; //numero di elementi iniziali: nessuno
    return l;
}

void addElement(int x, lista &l){
    nodo *p = new nodo; //creo un nuovo nodo da aggiungere alla lista
    p->next=NULL; //siccome non so quale sarà il nodo successivo lo setto a null
    p->x=x; //setto il suo valore
    if(l.nElem == 0){ //se non è stato ancora inserito nessun nodo (l.T == NULL)
        l.T = p; //coda e testa coincidono con l'indirizzo del primo nodo aggiunto, la testa
        l.C = p;
    }else{//in caso ci sia già più di un elemento
        l.C->next = p;//il nodo precedente(salvato nella coda) ora punta al nuovo nodo aggiunto
        l.C = p; //la coda si sposta sull'ultimo nodo aggiunto
    }
    l.nElem++;//incremento il numero di elementi della lista
}

void stampaLista(lista l){
    nodo *p = l.T; //creo un puntatore a nodi per stamparne il contenuto iniziando dalla testa
    for(int i=0; i < l.nElem && p != NULL; i++){
        cout<<p->x<<endl; //stampo il valore del nodo
        p = p->next; //mi sposto sul nodo successivo
    }
}

int main()
{
    lista l = initLista();;
    addElement(1,l);
    addElement(2,l);
    addElement(3,l);
    stampaLista(l);
    return 0;
}
