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

adrDokter searchNodeRelasiForDokter(ListRelasi L, string namaDokter){
    if(L.head == NULL){
        cout << "Can't do search on list relasi as its empty!" << "\n";
        return NULL;
    } else if(L.head->nextRelasiToDokter->info.namaDokter == namaDokter) {
        return L.head->nextRelasiToDokter;
    } else {
        adrRelasi k = L.head;
        while(k != NULL){
            if(k->nextRelasiToDokter->info.namaDokter == namaDokter){
                return k->nextRelasiToDokter;
            }
            k = k->next;
        }
    }
    return NULL;
}

adrPasien searchNodeRelasiForPasien(ListRelasi L, string namaPasien){
    if(L.head == NULL){
        cout << "Can't do search on list relasi as its empty!" << "\n";
        return NULL;
    } else if(L.head->nextRelasiToPasien->info.namaPasien == namaPasien) {
        return L.head->nextRelasiToPasien;
    } else {
        adrRelasi k = L.head;
        while(k != NULL){
            if(k->nextRelasiToPasien->info.namaPasien == namaPasien){
                return k->nextRelasiToPasien;
            }
            k = k->next;
        }
    }
    return NULL;
}

void connectDokterToPasien(ListRelasi &L, adrDokter d, adrPasien p){
    //asumsikan jika list relasi tidak kosong.
    //cara kerjanya ialah, fungsi akan mencari node yang kosong untuk menghubungkan antara dokter dengan pasien sesuai dengan spesialisasi dokter dan penyakit pasien
    adrRelasi k = searchForEmptyRelasi(L);
    k->nextRelasiToPasien = p;
    k->nextRelasiToDokter = d;
}

adrRelasi searchForEmptyRelasi(ListRelasi L){
    if(L.head == NULL){
        cout << "Can't do search for empty relasi as list relasi is empty!" << "\n";
        return NULL;
    } else if(L.head->nextRelasiToPasien == NULL && L.head->nextRelasiToDokter == NULL){
        return L.head;
    } else {
        adrRelasi k = L.head;
        while(k->nextRelasiToDokter != NULL && k->nextRelasiToPasien != NULL){
            if(k->nextRelasiToDokter == NULL && k->nextRelasiToPasien == NULL){
                return k;
            }
            k = k->next;
        }
    }
    return NULL;
}