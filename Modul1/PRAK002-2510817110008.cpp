#include<iostream>

using namespace std;

struct Kendaraan
{
    char PlatNomor[15];
    char JenisKendaraan[30];
    char NamaPemilik[50];
    char Alamat[100];
    char Kota[30];
};

int main(){
    Kendaraan data;

    cout << "\n------------------------------------------------\n";
    cout << "a. Plat Nomor Kendaraan : ";
    cin.getline(data.PlatNomor, 15);
    cout << "b. Jenis Kendaraan      : ";
    cin.getline(data.JenisKendaraan, 30);
    cout << "c. Nama Pemilik         : ";
    cin.getline(data.NamaPemilik, 50);
    cout << "d. Alamat               : ";
    cin.getline(data.Alamat, 100);
    cout << "e. Kota                 : ";
    cin.getline(data.Kota, 30);
    cout << "------------------------------------------------\n\n";

    cout << "------------------------------------------------\n";
    cout << "a. Plat Nomor Kendaraan : " << data.PlatNomor << endl;
    cout << "b. Jenis Kendaraan      : " << data.JenisKendaraan << endl;
    cout << "c. Nama Pemilik         : " << data.NamaPemilik << endl;
    cout << "d. Alamat               : " << data.Alamat << endl;
    cout << "e. Kota                 : " << data.Kota << endl;
    cout << "------------------------------------------------\n";

    return 0;
}