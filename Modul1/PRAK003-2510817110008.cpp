#include<iostream>

using namespace std;

struct Inputan
{
    char huruf;
    string kata;
    int angka;
};

int main(){
    Inputan data;

    cout << "\n------------------------------------------\n";
    cout << "a. Masukkan Sebuah huruf = ";
    cin >> data.huruf;
    cout << "b. Masukkan Sebuah kata = ";
    cin >> data.kata;
    cout << "c. Masukkan Angka = ";
    cin >> data.angka;

    cout << "d. Huruf yang Anda masukkan adalah " << data.huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << data.kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << data.angka << endl;
    cout << "------------------------------------------\n";
    return 0;
}