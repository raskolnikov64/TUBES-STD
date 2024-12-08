#include "TUBES.h"

adrDokter newNodeDokter(dataDokter z){
    adrDokter k;
    k = new NodeDokter;
    k->info.idDokter = z.idDokter;
    k->info.namaDokter = z.namaDokter;
    k->info.spesialisasi = z.spesialisasi;
    k->dokterDari = NULL;
    k->next = NULL;
    k->prev = NULL;
    return k;
}

void newListDokter(ListDokter &L){
    L.head = NULL;
    L.tail = NULL;
}

void insertFirstDokter(ListDokter &L, adrDokter d){
    if(L.head == NULL){
        L.head = d;
        L.tail = d;
    } else {
        d->next = L.head;
        L.head = d;
    }
}

void insertLastDokter(ListDokter &L, adrDokter d){
    if(L.head == NULL){
        L.tail = d;
        L.head = d;

    } else {
        L.tail->next = d;
        d->prev = L.tail;
        L.tail = d;
    }
}

void insertAfterDokter(ListDokter &L, adrDokter prec, adrDokter d){
    if(L.head == NULL){
        L.head = d;
        L.tail = d;
    } else if(prec == L.tail) {
        insertLastDokter(L, d);
    } else {
        d->next = prec->next;
        d->prev = prec;
        if(prec->next != NULL) {
            prec->next->prev = d;
        }
        prec->next = d;
    }
}

void deleteFirstDokter(ListDokter &L){
    if(L.head == NULL){
        cout << "List is empty" << "\n";
    } else {
        adrDokter temp = L.head;
        L.head = L.head->next;
        if(L.head != NULL){
            L.head->prev = NULL;
        }
        delete temp;
    }
}

void deleteLastDokter(ListDokter &L){
    if(L.head == NULL){
        cout << "Nothing to delete as list is empty" << "\n";
    } else if (L.head == L.tail){
        L.head = NULL;
        L.tail = NULL;
    } else {
        adrDokter temp = L.tail;
        L.tail = L.tail->prev;
        L.tail->next = NULL;
        delete temp;
    }
}

void deleteAfterDokter(ListDokter &L, adrDokter prec){
    if(L.head == NULL || prec == NULL || prec->next == NULL) {
        cout << "Nothing to delete after, as list is empty" << "\n";
    } else {
        adrDokter temp = prec->next;
        prec->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = prec;
        }
        delete temp;
    }
}


void displayDLL(ListDokter L){
    if(L.head == NULL || L.tail == NULL){
        cout << "Cannot display as List is empty" << "\n";
    } else {
        adrDokter p = L.head;
        while(p != NULL){
            cout << p->info.namaDokter << " " << p->info.idDokter << " " << p->info.spesialisasi << "\n";
            p = p->next;
        }
    }
}