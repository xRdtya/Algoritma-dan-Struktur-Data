#include <iostream>
#include <string>
#include <conio.h>
#include <limits>

using namespace std;

string nama = "NoufalRadityaWardana";
string nim = "2510817110008";

void insertionSort(string &str) {
    int n = str.size();
    for (int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }
}

void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char *L = new char[n1];
    char *R = new char[n2];

    for (int i = 0; i < n1; i++) L[i] = str[left + i];
    for (int j = 0; j < n2; j++) R[j] = str[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            str[k] = L[i];
            i++;
        } else {
            str[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { str[k] = L[i]; i++; k++; }
    while (j < n2) { str[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

void mergeSort(string &str, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(str, left, mid);
    mergeSort(str, mid + 1, right);
    merge(str, left, mid, right);
}

void shellSort(string &str) {
    int n = str.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

int partition(string &str, int low, int high) {
    char pivot = str[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (str[j] < pivot) {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(string &str, int low, int high) {
    if (low < high) {
        int pi = partition(str, low, high);
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

void bubbleSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(string &str) {
    int n = str.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (str[j] < str[min_idx]) {
                min_idx = j;
            }
        }
        swap(str[min_idx], str[i]);
    }
}

int main() {
    int pilihan;
    string temp;
    
    do {
        cout << "This Program Was Made by " << nama << " (" << nim << ")\n";
        
        cout << "---------------------------" << endl;
        cout << "!        SORTING          !" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Insertion Sort (Nama)" << endl;
        cout << "2. Merge Sort (Nama)" << endl;
        cout << "3. Shell Sort (Nama)" << endl;
        cout << "4. Quick Sort (NIM)" << endl;
        cout << "5. Bubble Sort (NIM)" << endl;
        cout << "6. Selection Sort (NIM)" << endl;
        cout << "7. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Masukkan Pilihan : ";

        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cout << "\nPress any key to continue..." << endl;
            getch();
            system("cls");
            continue;
        }

        switch (pilihan) {
            case 1:
                temp = nama;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                insertionSort(temp);
                cout << "Menggunakan Insertion Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 2:
                temp = nama;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                mergeSort(temp, 0, temp.size() - 1);
                cout << "Menggunakan Merge Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 3:
                temp = nama;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                shellSort(temp);
                cout << "Menggunakan Shell Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 4:
                temp = nim;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                quickSort(temp, 0, temp.size() - 1);
                cout << "Menggunakan Quick Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 5:
                temp = nim;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                bubbleSort(temp);
                cout << "Menggunakan Bubble Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 6:
                temp = nim;
                cout << "\nData Sebelum Diurutkan: " << temp << endl;
                selectionSort(temp);
                cout << "Menggunakan Selection Sort..." << endl;
                cout << "Data Setelah Diurutkan: " << temp << endl;
                break;
            case 7:
                cout << "\nTerima Kasih" << endl;
                break;
            default:
                cout << "\nOpsi Tidak Valid. Silakan Coba Lagi.\n";
        }

        if (pilihan != 7) {
            cout << "\nPress any key to continue..." << endl;
            getch();
            system("cls");
        }

    } while (pilihan != 7);

    return 0;
}