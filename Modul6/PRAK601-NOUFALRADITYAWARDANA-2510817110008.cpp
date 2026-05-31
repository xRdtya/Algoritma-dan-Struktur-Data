#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <conio.h>

using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequential() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }
    
    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("Pada indeks ke-%d", save);
    } else {
        printf("Data tidak ada!\n");
    }
}

void binary() {
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
            
        }
        
    }
    cout << "=======================================\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n======================================\n";
    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }
    if (ketemu == true) {
        cout << "Angka ditemukan! ";
    } else
        cout << "Angka tidak ditemukan!";
   
}

void penjelasan() {
    cout << "Sequential searching dan binary searching merupakan algoritma pencarian data. \nSequential searching cocok untuk data yang tidak terurut, sedangkan binary searching lebih efisien untuk data yang sudah terurut. \nSequential searching membandingkan elemen satu per satu, sedangkan binary searching membagi data menjadi dua bagian hingga menemukan elemen yang dicari. " << endl;
    cout << "\nKelebihan dan Kekurangan Sequential Searching:" << endl;
    cout << "Kelebihan:\n -Sederhana dan mudah dipahami.\n -Tidak memerlukan data yang terurut. " << endl;
    cout << "Kekurangan:\n -Kurang efisien untuk data besar.\n -Membutuhkan waktu pencarian yang lebih lama. " << endl;
    cout << "\nKelebihan dan Kekurangan Binary Searching:" << endl;
    cout << "Kelebihan:\n -Lebih efisien untuk data besar.\n -Memiliki waktu pencarian yang lebih cepat. " << endl;
    cout << "Kekurangan:\n -Memerlukan data yang terurut.\n -Membutuhkan persiapan data sebelum proses pencarian." << endl;
}

int main() {
    int pil;

    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searcing dan Binary Searching?" << endl;
        cout << "4. Quit" << endl;
        cout << "Pilih" << endl;
        cin >> pil;

        switch (pil) {
            case 1:
            sequential();
            break;
            case 2:
            binary();
            break;
            case 3:
            penjelasan();
            break;
            default:
            cout << "Terima Kasih" << endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pil<4);
}