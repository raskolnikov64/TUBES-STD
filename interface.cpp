#include "TUBES.h"

void firstInterface(){
    int choice = -1;
    ListDokter D;
    ListPasien P;
    ListRelasi R;
    newListDokter(D);
    newListPasien(P);
    newListRelasi(R);
    while(choice != 0) {
        daftarPilihan();
        cout << "Masukkan Pilihan : ";
        cin >> choice;
        cases(choice, D, P, R);
    }
}

void daftarPilihan(){
    cout << "---------------" << "\n";
    cout << "Selamat Datang Admin di Aplikasi Admin Rumah Sakit M65" << "\n";
    cout << "Pilih Prosedur yang akan dilakukan :" << "\n";
    cout << "1. Tambah Pasien" << "\n";
    cout << "2. Tambah Dokter" << "\n";
    cout << "3. Print Data Dokter" << "\n";
    cout << "4. Print Data Pasien" << "\n";
    cout << "5. Print semua data Dokter" << "\n";
    cout << "6. Print semua data Pasien" << "\n";
    cout << "7. Print Dokter yang menangani Pasien" << "\n";
    cout << "8. Print Pasien yang ditangani Dokter" << "\n";
    cout << "0. End Program" << "\n";
}

void cases(int choice, ListDokter D, ListPasien P, ListRelasi R){
    if(choice == 1) {
        adrPasien _m;
        dataPasien dp;
        cout << "Masukkan ID Pasien : ";
        cin >> dp.idPasien;
        cout << "\n";
        cout << "Masukkan Nama Pasien : ";
        cin >> dp.namaPasien;
        cout << "\n";
        cout << "Masukkan Umur Pasien : ";
        cin >> dp.umur;
        cout << "\n";
        cout << "Masukkan Riwayat Penyakit Pasien : ";
        cin >> dp.riwayatPenyakit;
        cout << "\n";
        cout << "Masukkan penyakit yang didertia : ";
        cin >> dp.penyakit;
        cout << "\n";
        cout << "Masukkan Alergi Pasien : ";
        cin >> dp.alergi;
        cout << "\n";
        cout << "Data sedang dimasukkan.\n";
        _m = newNodePasien(dp);
        insertLastPasien(P, _m);
    } else if (choice == 2){
        adrDokter _k;
        dataDokter dd;
        cout << "Masukkan ID Dokter : ";
        cin >> dd.idDokter; cout << "\n";
        cout << "Masukkan Nama Dokter : ";
        cin >> dd.namaDokter; cout << "\n";
        cout << "Masukkan Spesialisasi Dokter : ";
        cin >> dd.spesialisasi; cout << "\n";
        _k = newNodeDokter(dd);
        cout << "Data Dokter sedang dimasukkan.\n";
        insertLastDokter(D, _k);
    } else if(choice == 3){
        adrDokter edok;
        string id;
        cout << "Masukkan ID Dokter yang ingin dicari : ";
        cin >> id;
        cout << "\n";
        edok = findDokter(D, id);
        if(edok == NULL){
            cout << "Data dokter tidak ditemukan!\n";
        } else {
            cout << edok->info.namaDokter << " " << edok->info.spesialisasi <<"\n";
        }
    } else if(choice == 4){
        adrPasien pas;
        string id;
        cout << "Masukkan ID Pasien yang ingin dicari : ";
        cin >> id;
        cout << "\n";
        pas = findPasien(P, id);
        if(pas == NULL){
            cout << "Data pasien tidak ditemukan!\n";
        } else {
            cout << pas->info.namaPasien << " " << pas->info.penyakit << " " << pas->info.umur << " " << pas->info.alergi << "\n";
        }
    } else if(choice == 5){
        displayDLL(D);
    } else if(choice == 6){
        displaySLLPasien(P);
    } else if(choice == 7){
        string idDokter, idPasien;
        cout << "Masukkan ID Dokter yang menangani pasien : ";
        cin >> idDokter;
        cout << "\n";
        cout << "Masukkan ID Pasien yang ditangani : ";
        cin >> idPasien;
        cout << "\n";
        adrRelasi owk = searchDokterHandle(R, idDokter, idPasien);
        if(owk == NULL){
            cout << "Tidak ditemukan Dokter yang menangani pasien dengan id tersebut!\n";
        } else {
            cout << "Dokter " << owk->nextRelasiToDokter->info.namaDokter << " menangani pasien " << owk->nextRelasiToPasien->info.namaPasien << "\n";
        }
    } else if(choice == 8){

    }

}