//
// Created by ching on 18/11/2024.
//

#ifndef TUBES_STD_TUBES_H
#define TUBES_STD_TUBES_H
#include <bits/stdc++.h>

using namespace std;
typedef struct NodeDokter * adrDokter;
typedef struct NodePasien * adrPasien;
typedef struct NodeRelasi * adrRelasi;

struct dataDokter{
    string idDokter;
    string namaDokter;
    string spesialisasi;
};

struct dataPasien{
    string idPasien;
    string namaPasien;
    int umur;
    string riwayatPenyakit;
    string alergi;
};

struct NodeDokter{
    dataDokter info;
    adrRelasi dokterDari;
    adrDokter next;
    adrDokter prev;
};

struct NodePasien{
    dataPasien info;
    adrRelasi pasienDari;
    adrPasien next;
};


struct NodeRelasi{
    adrDokter nextRelasiToDokter;
    adrPasien nextRelasiToPasien;
    adrRelasi next;
};

struct ListDokter{
    adrDokter head;
    adrDokter tail;
};

struct ListPasien{
    adrPasien head;
};

struct ListRelasi{
    adrRelasi head;
};

adrDokter newNodeDokter(dataDokter z);
adrPasien newNodePasien(dataPasien z);
adrRelasi newNodeRelasi(adrPasien p, adrDokter d); // k->nextRelasiToDokter = NULL, k->nextRelasiToPasien = NULL, k->next = NULL;
void newListDokter(ListDokter &L);
void newListPasien(ListPasien &L);
void newListRelasi(ListRelasi &L);

//DLL Dokter
void insertFirstDokter(ListDokter &L, adrDokter d);
void insertLastDokter(ListDokter &L, adrDokter d);
void insertAfterDokter(ListDokter &L, adrDokter prec, adrDokter d);
void deleteFirstDokter(ListDokter &L);
void deleteLastDokter(ListDokter &L);
void deleteAfterDokter(ListDokter &L, adrDokter prec);
void displayDLL(ListDokter L);


//SLL Pasien
void insertFirstPasien(ListPasien &L, adrPasien p);
void insertLastPasien(ListPasien &L, adrPasien p);
void insertAfterPasien(ListPasien &L, adrPasien prec, adrPasien p);
void deleteFirstPasien(ListPasien &L);
void deleteLastPasien(ListPasien &L);
void deleteAfterPasien(ListPasien &L, adrPasien prec);
void displaySLLPasien(ListPasien L);

//SLL Relasi

void insertFirstRelasi(ListRelasi &L, adrRelasi r);
void insertLastRelasi(ListRelasi &L, adrRelasi r);
void insertAfterRelasi(ListRelasi &L, adrRelasi prec, adrRelasi r);
void deleteFirstRelasi(ListRelasi &L);
void deleteLastRelasi(ListRelasi &L);
void deleteAfterRelasi(ListRelasi &L, adrRelasi prec);
void displaySLLRelasi(ListRelasi L);
//Buat function yang berfungsi untuk menghubungkan dokter dengan pasien
void connectDokterToPasien(ListRelasi &L, adrDokter d, adrPasien p);
adrDokter searchNodeRelasiForDokter(ListRelasi L, string namaDokter);
adrPasien searchNodeRelasiForPasien(ListRelasi L, string namaPasien);
adrRelasi searchForEmptyRelasi(ListRelasi L); //building blocks untuk prosedur connectDokterToPasien

//Bersifat temporary 😁😁😁

#endif //TUBES_STD_TUBES_H
