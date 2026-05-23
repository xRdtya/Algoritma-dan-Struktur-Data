#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

struct ElemenData {
    string isiData;
    ElemenData *selanjutnya;
    ElemenData *sebelumnya;
};

ElemenData *titikAwal, *titikAkhir;

void initH();
void initHT();
bool isEmptyH();
bool isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main() {
    int pilihanProgram, pilihanAksi;
    bool statusBerjalan = true;

    while (statusBerjalan) {
        cout << "Double Linked List Non Circular (DLLNC)\n";
        cout << "=======================================\n";
        cout << "Silahkan pilih program DLLNC yang ingin dijalankan!\n";
        cout << "1. DLLNC dengan Head (Titik Awal)\n";
        cout << "2. DLLNC dengan Head dan Tail (Awal & Akhir)\n";
        cout << "3. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihanProgram;
        system("cls");

        if (pilihanProgram == 1) {
            initH();
            do {
                cout << "=== DLLNC Mode HEAD ===\n";
                cout << "1. Tambah Depan (Bisa banyak data)\n";
                cout << "2. Tambah Belakang (Bisa banyak data)\n";
                cout << "3. Tampilkan Data\n";
                cout << "4. Hapus Depan\n";
                cout << "5. Hapus Belakang ke-N (Sistem mundur)\n";
                cout << "6. Hapus Berdasarkan Target\n";
                cout << "7. Kosongkan List (Hapus Bergantian)\n";
                cout << "8. Kembali ke Menu Utama\n";
                cout << "Masukkan Pilihan : ";
                cin >> pilihanAksi;

                switch (pilihanAksi) {
                    case 1: tambahDepanH(); break;
                    case 2: tambahBelakangH(); break;
                    case 3: tampilkanH(); break;
                    case 4: hapusDepanH(); break;
                    case 5: hapusBelakangH(); break;
                    case 6: hapusTargetH(); break;
                    case 7: clearH(); break;
                    case 8: break;
                    default: cout << "Pilihan tidak valid!\n";
                }

                if (pilihanAksi != 8) {
                    cout << "\nTekan sembarang tombol untuk melanjutkan...";
                    getch();
                    system("cls");
                }
            } while (pilihanAksi != 8);
            system("cls");

        } else if (pilihanProgram == 2) {
            initHT();
            do {
                cout << "=== DLLNC Mode HEAD & TAIL ===\n";
                cout << "1. Tambah Depan (Bisa banyak data)\n";
                cout << "2. Tambah Belakang (Bisa banyak data)\n";
                cout << "3. Tampilkan Data\n";
                cout << "4. Hapus Depan\n";
                cout << "5. Hapus Belakang ke-N (Sistem mundur)\n";
                cout << "6. Hapus Berdasarkan Target\n";
                cout << "7. Kosongkan List (Hapus Bergantian)\n";
                cout << "8. Kembali ke Menu Utama\n";
                cout << "Masukkan Pilihan : ";
                cin >> pilihanAksi;

                switch (pilihanAksi) {
                    case 1: tambahDepanHT(); break;
                    case 2: tambahBelakangHT(); break;
                    case 3: tampilkanHT(); break;
                    case 4: hapusDepanHT(); break;
                    case 5: hapusBelakangHT(); break;
                    case 6: hapusTargetHT(); break;
                    case 7: clearHT(); break;
                    case 8: break;
                    default: cout << "Pilihan tidak valid!\n";
                }

                if (pilihanAksi != 8) {
                    cout << "\nTekan sembarang tombol untuk melanjutkan...";
                    getch();
                    system("cls");
                }
            } while (pilihanAksi != 8);
            system("cls");

        } else if (pilihanProgram == 3) {
            cout << "Terima kasih telah menggunakan program ini.\n";
            statusBerjalan = false;
        } else {
            cout << "Input salah, silahkan coba lagi.\n";
            system("pause");
            system("cls");
        }
    }
    return 0;
}

void initH() {
    titikAwal = NULL;
}

void initHT() {
    titikAwal = NULL;
    titikAkhir = NULL;
}

bool isEmptyH() {
    return (titikAwal == NULL);
}

bool isEmptyHT() {
    return (titikAkhir == NULL);
}

void tambahDepanH() {
    cout << "Input data (pisahkan dengan spasi): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputBaris;
    getline(cin, inputBaris);

    stringstream ss(inputBaris);
    string kata;
    vector<string> kumpulanData;
    while (ss >> kata) {
        kumpulanData.push_back(kata);
    }

    for (int i = kumpulanData.size() - 1; i >= 0; i--) {
        ElemenData *elemenBaru = new ElemenData;
        elemenBaru->isiData = kumpulanData[i];
        elemenBaru->selanjutnya = NULL;
        elemenBaru->sebelumnya = NULL;

        if (isEmptyH()) {
            titikAwal = elemenBaru;
        } else {
            elemenBaru->selanjutnya = titikAwal;
            titikAwal->sebelumnya = elemenBaru;
            titikAwal = elemenBaru;
        }
    }
    cout << "Berhasil menyisipkan data di awal list sesuai urutan.\n";
}

void tambahDepanHT() {
    cout << "Input data (pisahkan dengan spasi): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputBaris;
    getline(cin, inputBaris);

    stringstream ss(inputBaris);
    string kata;
    vector<string> kumpulanData;
    while (ss >> kata) {
        kumpulanData.push_back(kata);
    }

    for (int i = kumpulanData.size() - 1; i >= 0; i--) {
        ElemenData *elemenBaru = new ElemenData;
        elemenBaru->isiData = kumpulanData[i];
        elemenBaru->selanjutnya = NULL;
        elemenBaru->sebelumnya = NULL;

        if (isEmptyHT()) {
            titikAwal = elemenBaru;
            titikAkhir = elemenBaru;
        } else {
            elemenBaru->selanjutnya = titikAwal;
            titikAwal->sebelumnya = elemenBaru;
            titikAwal = elemenBaru;
        }
    }
    cout << "Berhasil menyisipkan data di awal list sesuai urutan.\n";
}

void tambahBelakangH() {
    cout << "Input data (pisahkan dengan spasi): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputBaris;
    getline(cin, inputBaris);

    stringstream ss(inputBaris);
    string kata;
    vector<string> kumpulanData;
    while (ss >> kata) {
        kumpulanData.push_back(kata);
    }

    for (int i = 0; i < kumpulanData.size(); i++) {
        ElemenData *elemenBaru = new ElemenData;
        elemenBaru->isiData = kumpulanData[i];
        elemenBaru->selanjutnya = NULL;
        elemenBaru->sebelumnya = NULL;

        if (isEmptyH()) {
            titikAwal = elemenBaru; 
        } else {
            ElemenData *elemenBantu = titikAwal;
            while (elemenBantu->selanjutnya != NULL) {
                elemenBantu = elemenBantu->selanjutnya;
            }
            elemenBantu->selanjutnya = elemenBaru;
            elemenBaru->sebelumnya = elemenBantu;
        }
    }
    cout << "Berhasil menyisipkan data di akhir list sesuai urutan.\n";
}

void tambahBelakangHT() {
    cout << "Input data (pisahkan dengan spasi): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string inputBaris;
    getline(cin, inputBaris);

    stringstream ss(inputBaris);
    string kata;
    vector<string> kumpulanData;
    while (ss >> kata) {
        kumpulanData.push_back(kata);
    }

    for (int i = 0; i < kumpulanData.size(); i++) {
        ElemenData *elemenBaru = new ElemenData;
        elemenBaru->isiData = kumpulanData[i];
        elemenBaru->selanjutnya = NULL;
        elemenBaru->sebelumnya = NULL;

        if (isEmptyHT()) {
            titikAwal = elemenBaru;
            titikAkhir = elemenBaru;
        } else {
            titikAkhir->selanjutnya = elemenBaru;
            elemenBaru->sebelumnya = titikAkhir;
            titikAkhir = elemenBaru;
        }
    }
    cout << "Berhasil menyisipkan data di akhir list sesuai urutan.\n";
}

void tampilkanH() {
    if (isEmptyH()) {
        cout << "List masih kosong!\n";
        return;
    }
    
    ElemenData *elemenBantu = titikAwal;
    cout << "Isi List: ";
    while (elemenBantu != NULL) {
        cout << elemenBantu->isiData << " <-> ";
        elemenBantu = elemenBantu->selanjutnya;
    }
    cout << "NULL\n";
}

void tampilkanHT() {
    if (isEmptyHT()) {
        cout << "List masih kosong!\n";
        return;
    }
    
    ElemenData *elemenBantu = titikAwal;
    cout << "Isi List: ";
    while (elemenBantu != NULL) {
        cout << elemenBantu->isiData << " <-> ";
        elemenBantu = elemenBantu->selanjutnya;
    }
    cout << "NULL\n";
}

void hapusTargetH() {
    if (isEmptyH()) {
        cout << "List masih kosong!\n"; return;
    }
    string target;
    cout << "Masukkan target data yang ingin dihapus: ";
    cin >> target;

    bool ditemukan = false;
    ElemenData *elemenBantu = titikAwal;
    
    while (elemenBantu != NULL) {
        if (elemenBantu->isiData == target) {
            ditemukan = true;
            ElemenData *elemenTarget = elemenBantu;
            elemenBantu = elemenBantu->selanjutnya; 

            if (elemenTarget->sebelumnya != NULL) {
                elemenTarget->sebelumnya->selanjutnya = elemenTarget->selanjutnya;
            } else {
                titikAwal = elemenTarget->selanjutnya; 
            }

            if (elemenTarget->selanjutnya != NULL) {
                elemenTarget->selanjutnya->sebelumnya = elemenTarget->sebelumnya;
            }

            delete elemenTarget;
        } else {
            elemenBantu = elemenBantu->selanjutnya;
        }
    }

    if (ditemukan) cout << "Semua node dengan data [" << target << "] berhasil dihapus.\n";
    else cout << "Data [" << target << "] tidak ditemukan dalam list.\n";
}

void hapusTargetHT() {
    if (isEmptyHT()) {
        cout << "List masih kosong!\n"; return;
    }
    string target;
    cout << "Masukkan target data yang ingin dihapus: ";
    cin >> target;

    bool ditemukan = false;
    ElemenData *elemenBantu = titikAwal;
    
    while (elemenBantu != NULL) {
        if (elemenBantu->isiData == target) {
            ditemukan = true;
            ElemenData *elemenTarget = elemenBantu;
            elemenBantu = elemenBantu->selanjutnya; 

            if (elemenTarget->sebelumnya != NULL) {
                elemenTarget->sebelumnya->selanjutnya = elemenTarget->selanjutnya;
            } else {
                titikAwal = elemenTarget->selanjutnya; 
            }

            if (elemenTarget->selanjutnya != NULL) {
                elemenTarget->selanjutnya->sebelumnya = elemenTarget->sebelumnya;
            } else {
                titikAkhir = elemenTarget->sebelumnya; 
            }

            delete elemenTarget;
        } else {
            elemenBantu = elemenBantu->selanjutnya;
        }
    }

    if (ditemukan) cout << "Semua node dengan data [" << target << "] berhasil dihapus.\n";
    else cout << "Data [" << target << "] tidak ditemukan dalam list.\n";
}

void hapusDepanH() {
    if (isEmptyH()) {
        cout << "Gagal menghapus, list kosong!\n"; return;
    }
    ElemenData *elemenTarget = titikAwal;
    string catatan = elemenTarget->isiData;
    
    if (titikAwal->selanjutnya != NULL) {
        titikAwal = titikAwal->selanjutnya;
        titikAwal->sebelumnya = NULL;
    } else {
        titikAwal = NULL;
    }
    delete elemenTarget;
    cout << "Data [" << catatan << "] berhasil dicabut dari posisi depan.\n";
}

void hapusDepanHT() {
    if (isEmptyHT()) {
        cout << "Gagal menghapus, list kosong!\n"; return;
    }
    ElemenData *elemenTarget = titikAwal;
    string catatan = elemenTarget->isiData;
    
    if (titikAwal->selanjutnya != NULL) {
        titikAwal = titikAwal->selanjutnya;
        titikAwal->sebelumnya = NULL;
    } else {
        titikAwal = NULL;
        titikAkhir = NULL;
    }
    delete elemenTarget;
    cout << "Data [" << catatan << "] berhasil dicabut dari posisi depan.\n";
}


void hapusBelakangH() {
    if (isEmptyH()) {
        cout << "Gagal menghapus, list kosong!\n"; return;
    }
    
    int N;
    cout << "Masukkan urutan N dari belakang yang ingin dihapus: ";
    cin >> N;

    int panjangList = 0;
    ElemenData *hitung = titikAwal;
    while (hitung != NULL) {
        panjangList++; hitung = hitung->selanjutnya;
    }

    int efekN = (N - 1) % panjangList + 1; 
    int posisiDariDepan = panjangList - efekN + 1;

    ElemenData *elemenTarget = titikAwal;
    for (int i = 1; i < posisiDariDepan; i++) {
        elemenTarget = elemenTarget->selanjutnya;
    }
    
    string catatan = elemenTarget->isiData;
    
    if (elemenTarget->sebelumnya != NULL) elemenTarget->sebelumnya->selanjutnya = elemenTarget->selanjutnya;
    else titikAwal = elemenTarget->selanjutnya; 

    if (elemenTarget->selanjutnya != NULL) elemenTarget->selanjutnya->sebelumnya = elemenTarget->sebelumnya;

    delete elemenTarget;
    cout << "Node ke-" << N << " dari belakang (Data: [" << catatan << "]) berhasil dicabut.\n";
}

void hapusBelakangHT() {
    if (isEmptyHT()) {
        cout << "Gagal menghapus, list kosong!\n"; return;
    }

    int N;
    cout << "Masukkan urutan N dari belakang yang ingin dihapus: ";
    cin >> N;

    int panjangList = 0;
    ElemenData *hitung = titikAwal;
    while (hitung != NULL) {
        panjangList++; hitung = hitung->selanjutnya;
    }

    int efekN = (N - 1) % panjangList + 1; 

    ElemenData *elemenTarget = titikAkhir;
    for (int i = 1; i < efekN; i++) {
        elemenTarget = elemenTarget->sebelumnya;
    }
    
    string catatan = elemenTarget->isiData;
    
    if (elemenTarget->sebelumnya != NULL) elemenTarget->sebelumnya->selanjutnya = elemenTarget->selanjutnya;
    else titikAwal = elemenTarget->selanjutnya; 

    if (elemenTarget->selanjutnya != NULL) elemenTarget->selanjutnya->sebelumnya = elemenTarget->sebelumnya;
    else titikAkhir = elemenTarget->sebelumnya; 

    delete elemenTarget;
    cout << "Node ke-" << N << " dari belakang (Data: [" << catatan << "]) berhasil dicabut.\n";
}

void clearH() {
    if (isEmptyH()) {
        cout << "List sudah kosong.\n"; return;
    }
    
    int urutan = 1;
    bool dariDepan = true;

    while (!isEmptyH()) {
        ElemenData *elemenTarget;
        if (dariDepan) {
            elemenTarget = titikAwal;
            titikAwal = titikAwal->selanjutnya;
            if (titikAwal != NULL) titikAwal->sebelumnya = NULL;
            
            cout << "Urutan hapus ke-" << urutan << " (Dari Depan)   : Data [" << elemenTarget->isiData << "]\n";
        } else {
            elemenTarget = titikAwal;
            while (elemenTarget->selanjutnya != NULL) {
                elemenTarget = elemenTarget->selanjutnya;
            }
            
            if (elemenTarget->sebelumnya != NULL) {
                elemenTarget->sebelumnya->selanjutnya = NULL;
            } else {
                titikAwal = NULL;
            }
            cout << "Urutan hapus ke-" << urutan << " (Dari Belakang): Data [" << elemenTarget->isiData << "]\n";
        }
        delete elemenTarget;
        urutan++;
        dariDepan = !dariDepan;
    }
    cout << "Seluruh data dalam list telah dibersihkan secara bergantian.\n";
}

void clearHT() {
    if (isEmptyHT()) {
        cout << "List sudah kosong.\n"; return;
    }
    
    int urutan = 1;
    bool dariDepan = true;

    while (titikAwal != NULL) {
        ElemenData *elemenTarget;
        if (dariDepan) {
            elemenTarget = titikAwal;
            titikAwal = titikAwal->selanjutnya;
            if (titikAwal != NULL) {
                titikAwal->sebelumnya = NULL;
            } else {
                titikAkhir = NULL; 
            }
            cout << "Urutan hapus ke-" << urutan << " (Dari Depan)   : Data [" << elemenTarget->isiData << "]\n";
        } else {
            elemenTarget = titikAkhir;
            titikAkhir = titikAkhir->sebelumnya;
            if (titikAkhir != NULL) {
                titikAkhir->selanjutnya = NULL;
            } else {
                titikAwal = NULL;
            }
            cout << "Urutan hapus ke-" << urutan << " (Dari Belakang): Data [" << elemenTarget->isiData << "]\n";
        }
        delete elemenTarget;
        urutan++;
        dariDepan = !dariDepan;
    }
    cout << "Seluruh data dalam list telah dibersihkan secara bergantian.\n";
}