#include "TUBES.h"

adrRelasi newNodeRelasi(adrPasien p, adrDokter d){
    adrRelasi k;
    k = new NodeRelasi;
    k->nextRelasiToDokter = d;
    k->nextRelasiToPasien = p;
    p->pasienDari = k;
    d->dokterDari = k;
    k->next = NULL;
    return k;
}

void newListRelasi(ListRelasi &L){
    L.head = NULL;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi r){
    if(L.head == NULL){
        L.head = r;
    } else {
        r->next = L.head;
        L.head = r;
    }
}

void insertLastRelasi(ListRelasi &L, adrRelasi r){
    if(L.head == NULL){
        L.head = r;
    } else if(L.head->next = NULL){
        L.head = NULL;
    }else {
        adrRelasi k = L.head;
        while(k->next != NULL){
            k = k->next;
        }
        k->next = r;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi prec, adrRelasi r){
    if(L.head == NULL){
        cout << "Cant do insert after on list relasi as its empty" << "\n";
    } else if(L.head == prec){
        r->next = L.head->next;
        L.head->next = r;
    } else {
        adrRelasi k = L.head;
        while(k != prec){
            k = k->next;
        }
        r->next = k->next;
        k->next = r;
    }
}

void deleteFirstRelasi(ListRelasi &L){
    if(L.head == NULL){
        cout << "Cant do delete first on list relasi as its empty" << "\n";
    } else {
        L.head = L.head->next;
    }
}

void deleteLastRelasi(ListRelasi &L){
    if(L.head == NULL){
        cout << "Cant do delete last on list relasi as its empty" << "\n";
    } else {
        adrRelasi k = L.head;
        while(k->next->next != NULL){
            k->next = k;
        }
        k->next = NULL;
    }
}

void deleteAfterRelasi(ListRelasi &L, adrRelasi prec){
    if(L.head == NULL){
        cout << "Cant do delete after as list relasi is empty" << "\n";
    } else if (L.head == prec){
        L.head->next = L.head->next->next;
    } else {
        adrRelasi k = L.head;
        while(k != prec){
            k = k->next;
        }
        k->next = k->next->next;
    }
}

void displaySLLRelasi(ListRelasi L){
    if(L.head == NULL) {
        cout << "Nothing to display list relasi as its empty" << "\n";
    } else {
        adrRelasi k = L.head;
        while(k != NULL) {
            if (k->nextRelasiToPasien != NULL && k->nextRelasiToDokter != NULL) {
                cout << k->nextRelasiToPasien->info.namaPasien << " ditangani oleh "
                     << k->nextRelasiToDokter->info.namaDokter << "\n";
            }
            k = k->next;
        }
    }
}