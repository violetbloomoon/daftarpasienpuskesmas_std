#include "puskesmas.h"

//child
void createListK(listPoliklinik &K){
    firstC(K) = nil;
}

adrC createElmK(string jenis){
    adrC p = new elmlistPoliklinik;
    infotypeK x;
    x.jenis = jenis;
    infoC(p) = x;
    nextC(p) = nil;
    return p;
}
void insertLastK(listPoliklinik &K, adrC P){
    if(firstC(K) == nil){
        firstC(K) = P;
        nextC(P) = nil;
    }else{
        adrC Q = firstC(K);
        while(nextC(Q) != nil){
            Q = nextC(Q);
        }
        nextC(Q) = P;
    }
}

int countK(listPasien P, int noPasien){
    adrP p = findP(P, noPasien);
    adrR c = child(p);
    int total = 0;
    while(c != nil){
        c = nextR(c);
        total++;
    }
    return total;
}
void deleteconditionK(listPoliklinik &K, string jenis){
    if(firstC(K) == nil){
        cout << "Data poliklinik tidak ditemukan" << endl;
    }else{
        adrC p = firstC(K);
        while(infoC(p).jenis != jenis && infoC(nextC(p)).jenis != jenis){
            p = nextC(p);
        }
        adrC q = nextC(p);
        nextC(p) = nextC(q);
        nextC(q) = nil;
    }
}

adrC findK(listPoliklinik K, string jenis){
    adrC p = firstC(K);
    if(firstC(K) == nil){
        cout << "Data klinik tidak ditemukan" << endl;
    }else{
        while(p != nil){
            if(infoC(p).jenis == jenis){
                return p;
            }
            p = nextC(p);
        }
    }
    return nil;
}


adrR searchK(listPasien P, int noPasien, string jenis){
    adrP p = findP(P, noPasien);
    adrR c = child(p);
    while(c != nil){
        if(infoC(poli(c)).jenis == jenis){
            return c;
        }
        c = nextR(c);
    }
    return nil;
}

void showK(listPoliklinik K){
    int i = 1;
    adrC P = firstC(K);
    cout << " Daftar Poliklinik" << endl;
    cout << " --------------------------------------------------" << endl;
    while (P != nil){
        cout << " " << i << ". " << infoC(P).jenis << endl;
        P = nextC(P);
        i++;
    }
    cout << endl << endl;
}

void connectChild(listPasien &P, listPoliklinik &K, int noPasien, string jenis){
    adrR r = new elmRelasi;
    nextR(r) = nil;
    adrP a = findP(P, noPasien);
    adrC b = findK(K, jenis);
    if(child(a) == nil){
        child(a) = r;
    }else{
        adrR c = child(a);
        while(nextR(c) != nil){
            c = nextR(c);
        }
        nextR(c) = r;
        poli(r) = b;
    }
}

void showConnect(listPasien P){
    adrP p = firstP(P);
    int i= 1;
    while(p != nil){
        cout << " Data Pasien ke-" << i << endl;
        cout << " Nama : " << infoP(p).nama << endl;
        cout << " NIK : " << infoP(p).nik << endl;
        cout << " Umur : " << infoP(p).umur << endl;
        cout << " Nomor Pasien : " << infoP(p).noPasien << endl;
        cout << " Keluhan : " << infoP(p).keluhan << endl << endl;
        adrR c = child(p);
        int j = 1;
        while(c != nil){
            cout << "Poliklinik ke-" << j << " : " << infoC(poli(c)).jenis << endl;
            c = nextR(c);
        }
        p = nextP(p);
    }
}

void deleteChild(listPasien &P, listPoliklinik &K, string jenis, int noPasien) {
    adrP p = findP(P, noPasien);
    adrR c = child(p);
    if (infoC(poli(c)).jenis == jenis){
        if(nextR(child(p)) == nil){
            c = child(p);
            child(p) = nil;
        }else{
            c = child(p);
            child(p) = nextC(c);
            nextR(c) = nil;
        }
    }else{
        while(infoC(nextR(c)).jenis != jenis){
            c = nextR(c);
        }
        adrC d = nextR(c);
        if (nextR(d) == nil){
            adr c = child(p);
            while (nextR(nextR(c)) != nil){
                c = nextR(c);
            }
            nextR(c) = nil;
        }else{
            nextR(c) = nextR(d);
            d = nil;
        }
    }
 };

 // Pasien
void createListP(listPasien &P){
    firstP(P) = nil;
}

adrP createElmP(string nama, int nik, int umur, string keluhan, int noPasien){
    adrP p = new elmlistPasien;
    infotypeP y;
    y.nama = nama;
    y.nik = nik;
    y.umur = umur;
    y.noPasien = noPasien;
    y.keluhan = keluhan;
    infoP(p) = y;
    nextP(p) = nil;
    return p;
}

/*void insertLastP(listPasien &P, adrP p) {
    if (firstP(P) == nil){
        firstP(P) = p;
    }else{
        adrP q = firstP(P);
        while(nextP(q) != NULL){
            q = nextP(q);
        }
        nextP(q) = p;
    }
};
*/

void insertPasien(listPoliklinik &K, string jenis, adrP P){
    adrC c = findK(K, jenis);
    if(c != nil){
        if(child(c) == nil){
            child(c) = p;
        }
    }
}

void deleteconditionP(listPasien &P, int noPasien){
    if(firstP(P) == nil){
        cout << "Data pasien tidak ditemukan" << endl;
    }else if(nextP(firstP(P))== nil){
        adrP p = firstP(P);
        firstP(P) = nil;
    }else{
        adrP Q = firstP(P);
        while(infoP(Q).noPasien != noPasien && infoP(nextP(Q)).noPasien != noPasien){
            Q = nextP(Q);
        }
        adrP r = nextP(Q);
        nextP(Q) = nextP(r);
        nextP(r) = nil;
    }
}


adrP findP(listPasien P, int noPasien){
    if(firstP(P) == nil){
        cout << "Data Pasien Kosong";
    }else{
        adrP Q = firstP(P);
        while(Q != nil){
            if(infoP(Q).noPasien == noPasien){
                return Q;
            }
            Q = nextP(Q);
        }
    }
    return nil;
}

void showP(listPasien P) {
    adrP p = firstP(P);
    int i = 1;
    cout << " Daftar Pasien" << endl;
    cout << " --------------------------------------------------" << endl;
    while(p != nil){
        cout << " Data pasien ke-" << i << endl;
        cout << " Nama : " << infoP(p).nama << endl;
        cout << " NIK : " << infoP(p).nik << endl;
        cout << " Umur : " << infoP(p).umur << endl;
        cout << " Nomor Pasien : " << infoP(p).noPasien << endl;
        cout << " Keluhan : " << infoP(p).keluhan << endl << endl;
        p = nextP(p);
        i++;
    }
};

int selectMenu(){
    cout << " 1. Menambah data pasien" << endl;
    cout << " 2. Menambah data poliklinik" << endl;
    cout << " 3. Menampilkan data pasien" << endl;
    cout << " 4. Menampilkan data poliklinik" << endl;
    cout << " 5. Menghapus data pasien" << endl;
    cout << " 6. Menghapus data poliklinik" << endl;
    cout << " 7. Mencari data pasien" << endl;
    cout << " 8. Mencari data poliklinik" << endl;
    cout << " 9. Mencari data poliklinik pada pasien" << endl;
    cout << " 10. Menghapus data poliklinik pada pasien" << endl;
    cout << " 11. Menghitung poliklinik pada pasien" << endl;
    cout << " 12. Hubungkan Pasien dan Poliklinik yang terdaftar" << endl;
    cout << " 13. Menampilkan Data yang telah terhubung" << endl;
    cout << " 0. Exit" << endl;
    cout << " Masukkan menu : ";

    int input = 0;
    cin >> input;

    return input;
}

void selectMenu2(int &pilihan){
    cout << " Kembali ke menu utama? (Y/N) : ";
    char input;
    cin >> input;
    cout << endl;
    if(input == 'Y' || input == 'y'){
        pilihan = selectMenu();
    }else if(input == 'N' || input == 'n'){
        pilihan = 0;
    }
}
