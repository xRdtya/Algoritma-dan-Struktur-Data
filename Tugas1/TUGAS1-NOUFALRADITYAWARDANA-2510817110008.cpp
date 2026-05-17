#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct NodeCircular {
    string nilai;
    NodeCircular *lanjut;
};

NodeCircular *awal, *akhir;
int opsi;
string inputBaru, inputHapus;

void inisialisasi();
bool cekKosong();
int hitungTotalNode();
void tambahDepan(); 
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void cetakSemua();
void bersihkanList();
void temukanElemen();
void hapusElemenSpesifik();
void insertSebelum();
void insertSesudah();
void jedaLayar();

int main() {
    inisialisasi();
    string pilihanStr;

    do {
        system("cls");
        cout << "==========================================\n";
        cout << "    PROGRAM SINGLE CIRCULAR LINKED LIST   \n";
        cout << "==========================================\n";
        cout << "[1]  Tambah Depan\n";
        cout << "[2]  Tambah Belakang\n";
        cout << "[3]  Hapus Depan\n";
        cout << "[4]  Hapus Belakang\n";
        cout << "[5]  Tampilkan Seluruh Data\n";
        cout << "[6]  Hapus Seluruh Data\n";
        cout << "[7]  Cari Sebuah Data\n";
        cout << "[8]  Hapus Data Tertentu\n";
        cout << "[9]  Sisipkan Sebelum Data Tertentu\n";
        cout << "[10] Sisipkan Setelah Data Tertentu\n";
        cout << "[11] Keluar Program\n";
        cout << "==========================================\n";
        cout << "Masukkan pilihan Anda : ";
        
        cin >> pilihanStr;
        opsi = atoi(pilihanStr.c_str());
        
        cout << "\n";
        switch(opsi) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: hapusDepan(); break;
            case 4: hapusBelakang(); break;
            case 5: cetakSemua(); break;
            case 6: bersihkanList(); break;
            case 7: temukanElemen(); break;
            case 8: hapusElemenSpesifik(); break;
            case 9: insertSebelum(); break;
            case 10: insertSesudah(); break;
            case 11:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak tersedia. Silakan coba lagi.\n";
        }

        if (opsi != 11) {
            jedaLayar();
        }

    } while (opsi != 11);

    return 0;
}

void inisialisasi() {
    awal = NULL;
    akhir = NULL;
}

bool cekKosong() {
    return (awal == NULL);
}

int hitungTotalNode() {
    if (cekKosong()) return 0;
    int jumlah = 0;
    NodeCircular *jalan = awal;
    do {
        jumlah++;
        jalan = jalan->lanjut;
    } while (jalan != awal);
    return jumlah;
}

void tambahDepan() {
    cout << "Ketik beberapa data (pisahkan dengan spasi): ";
    string baris;
    cin >> ws;
    getline(cin, baris);

    stringstream ss(baris);
    string kata;
    vector<string> dataInput;

    while (ss >> kata) {
        dataInput.push_back(kata);
    }

    for (int i = dataInput.size() - 1; i >= 0; i--) {
        NodeCircular *nodeBaru = new NodeCircular;
        nodeBaru->nilai = dataInput[i];
        
        if(cekKosong()) {
            awal = nodeBaru;
            akhir = nodeBaru;
            nodeBaru->lanjut = awal;
        } else {
            nodeBaru->lanjut = awal;
            awal = nodeBaru;
            akhir->lanjut = awal;
        }
    }
    cout << "=> Berhasil memasukkan " << dataInput.size() << " data di posisi depan.\n";
}

void tambahBelakang() {
    cout << "Ketik data yang ingin ditambah: ";
    cin >> inputBaru;

    NodeCircular *nodeBaru = new NodeCircular;
    nodeBaru->nilai = inputBaru;
    
    if(cekKosong()) {
        awal = nodeBaru;
        akhir = nodeBaru;
        nodeBaru->lanjut = awal;
    } else {
        akhir->lanjut = nodeBaru;
        akhir = nodeBaru;
        akhir->lanjut = awal;
    }
    cout << "=> Elemen \"" << inputBaru << "\" sukses diletakkan di BELAKANG.\n";
}

void hapusDepan() {
    if(cekKosong()) {
        cout << "=> Operasi gagal: Linked List masih kosong!\n";
        return;
    }

    int n;
    cout << "Masukkan nilai N (hapus posisi ke-N dari DEPAN): ";
    cin >> n;

    int totalNode = hitungTotalNode();

    if (n > totalNode) {
        NodeCircular *hapus = akhir;
        inputHapus = hapus->nilai;

        if (awal == akhir) {
            inisialisasi();
        } else {
            NodeCircular *bantu = awal;
            while(bantu->lanjut != akhir) {
                bantu = bantu->lanjut;
            }
            akhir = bantu;
            akhir->lanjut = awal;
        }
        delete hapus;
        cout << "=> N > jumlah node. Menghapus Tail: \"" << inputHapus << "\".\n";
        return;
    }

    if (n == 1) {
        NodeCircular *hapus = awal;
        inputHapus = hapus->nilai;
        if(awal == akhir) {
            inisialisasi();
        } else {
            awal = awal->lanjut;
            akhir->lanjut = awal;
        }
        delete hapus;
        cout << "=> Menghapus node ke-1 dari depan: \"" << inputHapus << "\".\n";
        return;
    }

    NodeCircular *curr = awal;
    NodeCircular *prev = akhir;
    for(int i = 1; i < n; i++) {
        prev = curr;
        curr = curr->lanjut;
    }

    inputHapus = curr->nilai;
    prev->lanjut = curr->lanjut;
    if (curr == akhir) akhir = prev;
    delete curr;
    
    cout << "=> Menghapus node ke-" << n << " dari depan: \"" << inputHapus << "\".\n";
}

void hapusBelakang() {
    if(cekKosong()) {
        cout << "=> Operasi gagal: Linked List masih kosong!\n";
        return;
    }

    int n;
    cout << "Masukkan nilai N (hapus posisi ke-N dari BELAKANG): ";
    cin >> n;

    int totalNode = hitungTotalNode();

    if (n > totalNode) {
        NodeCircular *hapus = awal;
        inputHapus = hapus->nilai;

        if (awal == akhir) {
            inisialisasi();
        } else {
            awal = awal->lanjut;
            akhir->lanjut = awal;
        }
        delete hapus;
        cout << "=> N > jumlah node. Menghapus Head: \"" << inputHapus << "\".\n";
        return;
    }

    int targetPos = totalNode - n + 1;
    
    NodeCircular *curr = awal;
    NodeCircular *prev = akhir;

    for (int i = 1; i < targetPos; i++) {
        prev = curr;
        curr = curr->lanjut;
    }

    inputHapus = curr->nilai;
    
    if (curr == awal) {
        awal = curr->lanjut;
        akhir->lanjut = awal;
    } else {
        prev->lanjut = curr->lanjut;
        if (curr == akhir) akhir = prev;
    }

    delete curr;
    if (totalNode == 1) inisialisasi();
    
    cout << "=> Menghapus node ke-" << n << " dari belakang: \"" << inputHapus << "\".\n";
}

void cetakSemua() {
    if(!cekKosong()) {
        NodeCircular *jalan = awal;
        cout << "Isi Linked List saat ini:\n[ ";
        do {
            cout << jalan->nilai;
            jalan = jalan->lanjut;
            if (jalan != awal) cout << " -> ";
        } while(jalan != awal);
        cout << " ]\n";
    } else {
        cout << "=> Linked List dalam keadaan kosong.\n";
    }
}

void bersihkanList() {
    if(!cekKosong()) {
        int langkah = 1;
        while (!cekKosong()) {
            NodeCircular *hapusNode = awal;
            cout << "- Langkah " << langkah << ": Menghapus node berisi \"" << hapusNode->nilai << "\"\n";
            
            if (awal == akhir) {
                inisialisasi();
            } else {
                awal = awal->lanjut;
                akhir->lanjut = awal;
            }
            delete hapusNode;
            langkah++;
        }
        cout << "=> Seluruh elemen telah tuntas dibersihkan.\n";
    } else {
        cout << "=> Linked List sudah kosong, tidak ada yang perlu di-reset.\n";
    }
}

void temukanElemen() {
    if(!cekKosong()) {
        string target;
        cout << "Masukkan data target pencarian: ";
        cin >> target;

        NodeCircular *jalan = awal;
        bool statusKetemu = false;

        do {
            if(target == jalan->nilai) {
                statusKetemu = true;
                break;
            }
            jalan = jalan->lanjut;
        } while(jalan != awal);

        if(statusKetemu) {
            cout << "\nData ditemukan! Posisinya ditandai dengan tanda kurung siku: \n";
            NodeCircular *cetak = awal;
            do {
                if(target == cetak->nilai)
                    cout << "[" << cetak->nilai << "] ";
                else
                    cout << cetak->nilai << " ";
                cetak = cetak->lanjut;
            } while(cetak != awal);
            cout << "\n";
        } else {
            cout << "=> Data \"" << target << "\" tidak ada di dalam Linked List.\n";
        }
    } else {
        cout << "=> Pencarian dibatalkan: Linked list kosong.\n";
    }
}

void hapusElemenSpesifik() {
    if(!cekKosong()) {
        string target;
        cout << "Ketik data yang mau dibuang: ";
        cin >> target;

        NodeCircular *curr = awal;
        NodeCircular *prev = akhir;
        bool ditemukan = false;

        do {
            if(curr->nilai == target) {
                ditemukan = true;
                if(curr == awal) {
                    if (awal == akhir) {
                        delete curr;
                        inisialisasi();
                        break;
                    }
                    awal = awal->lanjut;
                    akhir->lanjut = awal;
                    delete curr;
                    curr = awal;
                } else {
                    NodeCircular *temp = curr;
                    prev->lanjut = curr->lanjut;
                    if (curr == akhir) akhir = prev;
                    curr = curr->lanjut;
                    delete temp;
                }
            } else {
                prev = curr;
                curr = curr->lanjut;
            }
        } while(curr != awal && !cekKosong());

        if(ditemukan) {
            cout << "=> Semua kemunculan data \"" << target << "\" berhasil dilenyapkan.\n";
        } else {
            cout << "=> Data \"" << target << "\" tidak ditemukan.\n";
        }
    } else {
        cout << "=> Linked List kosong!\n";
    }
}

void insertSebelum() {
    if(!cekKosong()) {
        string patokan;
        cout << "Sisipkan sebelum data: ";
        cin >> patokan;

        NodeCircular *jalan = awal, *sebelum = akhir;
        bool adaTarget = false;

        do {
            if(jalan->nilai == patokan) {
                adaTarget = true;
                break;
            }
            sebelum = jalan;
            jalan = jalan->lanjut;
        } while(jalan != awal);

        if(adaTarget) {
            cout << "Input data sisipan: ";
            cin >> inputBaru;

            NodeCircular *nodeBaru = new NodeCircular;
            nodeBaru->nilai = inputBaru;
            nodeBaru->lanjut = jalan;
            sebelum->lanjut = nodeBaru;

            if(jalan == awal) {
                awal = nodeBaru;
            }
            cout << "=> \"" << inputBaru << "\" diselipkan sebelum \"" << patokan << "\".\n";
        } else {
            cout << "=> Data patokan \"" << patokan << "\" tidak ditemukan.\n";
        }
    } else {
        cout << "=> Linked List kosong!\n";
    }
}

void insertSesudah() {
    if(!cekKosong()) {
        string patokan;
        cout << "Sisipkan setelah data: ";
        cin >> patokan;

        NodeCircular *jalan = awal;
        bool adaTarget = false;

        do {
            if(jalan->nilai == patokan) {
                adaTarget = true;
                break;
            }
            jalan = jalan->lanjut;
        } while(jalan != awal);

        if(adaTarget) {
            cout << "Input data sisipan: ";
            cin >> inputBaru;

            NodeCircular *nodeBaru = new NodeCircular;
            nodeBaru->nilai = inputBaru;
            nodeBaru->lanjut = jalan->lanjut;
            jalan->lanjut = nodeBaru;

            if(jalan == akhir) {
                akhir = nodeBaru;
            }
            cout << "=> \"" << inputBaru << "\" diselipkan sesudah \"" << patokan << "\".\n";
        } else {
            cout << "=> Data patokan \"" << patokan << "\" tidak ditemukan.\n";
        }
    } else {
        cout << "=> Linked List kosong!\n";
    }
}

void jedaLayar() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore(10000, '\n'); 
    cin.get();
}