#include "puskesmas.h"
#include <iostream>

using namespace std;

int main()
{
    listPasien P;
    listPoliklinik K;
    int N, masukan;

    createListP(P);
    createListK(K);
    masukan = selectMenu();
    while(masukan != 0){
        if(masukan == 1){
            cout << " Jumlah data yang dimasukan: ";
            cin >> N;
            cout << " =================================================================" << endl << endl;
            for(int i = 1; i <= N; i++){
                string nama, keluhan;
                int nik, umur, noPasien;
                cout << " # Pasien ke-" << i << ":" << endl;
                cout << " Nama : ";
                cin >> nama;
                cout << " NIK : ";
                cin >> nik;
                cout << " Umur : ";
                cin >> umur;
                cout << " Keluhan : ";
                cin >> keluhan;
                cout << " No Pasien : ";
                cin >> noPasien;
                adrP p = createElmP(nama, nik, umur,keluhan,noPasien);
                insertLastP(P, p);
                cout << endl;
            }
             cout << " =================================================================" << endl << endl;
             selectMenu2(masukan);
             cout << endl;
        }else if(masukan == 2){
            cout << " Jumlah data poliklinik yang dimasukan: ";
            cin >> N;
            cout << " =================================================================" << endl << endl;
            for(int i = 1; i <= N; i++){
                string jenis;
                cout << " # Poliklinik ke-" << i << ": ";
                cin >> jenis;
                adrC p = createElmK(jenis);
                insertLastK(K, p);
            }
            cout << endl;
            cout << " =================================================================" << endl << endl;
            selectMenu2(masukan);

        }else if(masukan == 3){
            cout << endl;
            showP(P);
            cout << endl;
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 4){
            cout << endl;
            cout << endl;
            showK(K);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 5){
            cout << " Data Pasien yang akan dihapus (noPasien): ";
            int noPasien;
            adrP q;
            cin >> noPasien;

            deleteconditionP(P, noPasien);
            showP(P);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 6){
            cout << " Data poliklinik yang akan dihapus: ";
            string jenis;
            cin >> jenis;
            adrC q;
            deleteconditionK(K, jenis);
            showK(K);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 7){
            cout << " Nomor Pasien yang ingin dicari: ";
            int noPasien;
            cin >> noPasien;
            cout << " Nama : " << infoP(findP(P, noPasien)).nama << endl;
            cout << " NIK : " << infoP(findP(P, noPasien)).nik << endl;
            cout << " Umur : " << infoP(findP(P, noPasien)).umur << endl;
            cout << " Nomor Pasien : " << infoP(findP(P, noPasien)).noPasien << endl;
            cout << " Keluhan : " << infoP(findP(P, noPasien)).keluhan << endl;
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 8){
            cout << " Poli yang ingin dicari: ";
            string jenis;
            cin >> jenis;

            cout << " Nama poliklinik: " << infoC(findK(K, jenis)).jenis;
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 9){
            cout << " Poli yang ingin dicari: ";
            string jenis;
            cin >> jenis;
            cout << " pada pasien: ";
            int noPasien;
            cin >> noPasien;
            cout << searchK(P, noPasien, jenis);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 10){
            cout << " Data poliklinik yang akan dihapus: ";
            int noPasien;
            string jenis;
            cin >> jenis;
            cout << " pada pasien: ";
            cin >> noPasien;
            deleteChild(P, K, jenis, noPasien);
            showK(K);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 11){
            cout << " Masukan Nomor Pasien : ";
            int noPasien;
            cin >> noPasien;
            cout << " Jumlah poliklinik pada pasien: ";
            countK(P, noPasien);
            cout << endl;
            selectMenu2(masukan);
        }else if(masukan == 12){
            cout << " Pasien yang ingin dihubungkan: ";
            int noPasien;
            cin >> noPasien;
            cout << " Terdaftar di klinik: ";
            string jenis;
            cin >> jenis;
            connectChild(P,K, noPasien,jenis);
            cout << endl;
            showConnect(P);
            selectMenu2(masukan);
        }else if(masukan == 13){
            cout << " Data pasien yang telah terhubung: ";
            showConnect(P);
        }
    }
    return 0;
}
