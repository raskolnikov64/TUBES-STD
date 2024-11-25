#include "TUBES.h"

adrPasien newNodePasien(dataPasien z){
    adrPasien p;
    p = new NodePasien;
    p->info.idPasien = z.idPasien;
    p->info.namaPasien = z.namaPasien;
    p->info.umur = z.umur;
    p->info.riwayatPenyakit = z.riwayatPenyakit;
    p->info.alergi = z.alergi;
    p->pasienDari = NULL;
    p->next = NULL;
    return p;
}

void newListPasien(ListPasien &L){
    L.head = NULL;
}

void insertFirstPasien(ListPasien &L, adrPasien p){
    if(L.head == NULL){
        L.head = p;
    } else {
        p->next = L.head;
        L.head = p;
    }
}

void insertLastPasien(ListPasien &L, adrPasien p){
    if(L.head == NULL){
        L.head = p;
    } else {
        adrPasien k = L.head;
        while(k->next != NULL){
            k = k->next;
        }
        k->next = p;
    }
}

void insertAfterPasien(ListPasien &L, adrPasien prec, adrPasien p){
    if(L.head == NULL){
        cout << "Cant do insert after as list is empty" << "\n";
    } else if (L.head == prec){
        p->next = L.head->next;
        L.head->next = p;
    } else {
        adrPasien k = L.head;
        while(k != prec){
            k = k->next;
        }
        p->next = k->next;
        k->next = p;
    }
}

void deleteFirstPasien(ListPasien &L){
    if(L.head == NULL){
        cout << "Cant do delete first as list is empty" << "\n";
    } else {
        L.head = L.head->next;
    }
}

void deleteLastPasien(ListPasien &L){
    if(L.head == NULL){
        cout << "Cant do delete last as list is empty" << "\n";
    } else {
        adrPasien k = L.head;
        while(k->next->next != NULL){
            k = k->next;
        }

        k->next = NULL;
    }
}

void deleteAfterPasien(ListPasien &L, adrPasien prec){
    if(L.head == NULL){
        cout << "Cant do delete after as list is empty" << "\n";
    } else if (L.head == prec){
        L.head->next = L.head->next->next;
    } else {
        adrPasien k = L.head;
        while(k != prec){
            k = k->next;
        }
        k->next = k->next->next;
    }
}

void displaySLLPasien(ListPasien L){
    if(L.head == NULL){
        cout << "Cant display pasien list as its empty" << "\n";
    } else {
        adrPasien k = L.head;
        while(k != NULL){
            cout << k->info.namaPasien << " ";
            k = k->next;
        }
        cout << "\n";
    }
}