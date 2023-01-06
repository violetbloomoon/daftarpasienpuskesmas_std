#ifndef PUSKESMAS_H_INCLUDED
#define PUSKESMAS_H_INCLUDED

#include <iostream>

using namespace std;

#define firstP(P) ((P).firstP)
#define firstC(K) ((K).firstC)
#define infoP(P) (P) -> infoP
#define infoC(C) (C) -> infoC
#define nextP(P) (P) -> nextP
#define nextC(C) (C) -> nextC
#define nextR(Q) (Q) -> nextR
#define child(P) (P) -> child
#define poli(C) (C) -> poli
#define nil NULL

typedef struct dataPoliklinik infotypeK;
struct dataPoliklinik{
    string jenis;
};

struct dataPasien{
    string nama;
    int nik;
    int umur;
    string keluhan;
    int noPasien;
};

typedef struct elmlistPasien *adrP;
typedef struct elmlistPoliklinik *adrC;
typedef struct elmRelasi *adrR;

struct elmlistPasien{
    dataPasien infoP;
    adrP nextP;
    adrR child;
};

struct elmlistPoliklinik{
    dataPoliklinik infoC;
    adrC nextC;
};

struct elmRelasi{
    adrR nextR;
    adrC poli;
};

struct listPasien{
    adrP firstP;
};

struct listPoliklinik{
    adrC firstC;
};

// Poliklinik | Child
void createListK(listPoliklinik &K);
adrC createElmK(string jenis);
void insertLastK(listPoliklinik &K, adrC P);
void deleteconditionK(listPoliklinik &K, string jenis);
adrC findK(listPoliklinik K, string x);
void showK(listPoliklinik K);
int countK(listPasien P, int noPasien);
adrR searchK(listPasien P, int noPasien, string jenis);

void connectChild(listPasien &P, listPoliklinik &K, int noPasien, string jenis);
void deleteChild(listPasien &P, listPoliklinik &K, string jenis, int noPasien);

// Pasien | Parent
void createListP(listPasien &P);
adrP createElmP(string nama, int nik, int umur, string keluhan, int noPasien);
void insertLastP(listPasien &P, adrP p);
void deleteconditionP(listPasien &P, int noPasien);
adrP findP(listPasien P, int y);
void showP(listPasien P);
void showConnect(listPasien P);
void insertPasien(listPoliklinik &K, string jenis, adrP P);

int selectMenu();
void selectMenu2(int &pilihan);

#endif // PUSKESMAS_H_INCLUDED
