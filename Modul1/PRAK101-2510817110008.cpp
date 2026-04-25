#include <iostream>

using namespace std;

struct mhs
{
    char NamaMHS[55], NIMMHS[15], JurusanMHS[10]; 
    int SKS, Program;
};

struct mhs bayar[2];

int main() { 
    int var, tetap;

    for (int i = 0; i < 2; i++) 
    {
        cout << "\n\n---------------------------------------------\n";
        
        cout << "Nama mhs             = "; 
        cin >> ws; 
        cin.getline(bayar[i].NamaMHS, 55);
        
        cout << "NIM                  = "; cin >> bayar[i].NIMMHS;
        cout << "Jurusan [TI, PTK]    = "; cin >> bayar[i].JurusanMHS;

        input:
            cout << "Program [1=D3, 2=S1] = "; cin >> bayar[i].Program;

            if (bayar[i].Program < 1 || bayar[i].Program > 2) 
            {
                cout << "Program tidak sesuai\n";
                goto input;
            }

        cout << "Jumlah sks           = "; cin >> bayar[i].SKS;

        if (bayar[i].Program == 1) 
        {
            tetap = 500000;
            var = bayar[i].SKS * 25000;
        } 
        else if (bayar[i].Program == 2) 
        {
            tetap = 750000;
            var = bayar[i].SKS * 50000;
        }

        cout << "\n\n---------------------------------------------\n";
        cout << " Output ";
        cout << "\n---------------------------------------------\n";
        cout << "Nama mhs       = " << bayar[i].NamaMHS << endl;
        cout << "NIM            = " << bayar[i].NIMMHS << endl;
        cout << "Jurusan        = " << bayar[i].JurusanMHS << endl;
        cout << "Program        = " << bayar[i].Program << endl;
        cout << "Jumlah sks     = " << bayar[i].SKS << endl;
        cout << "SPP tetap      = " << tetap << endl;
        cout << "SPP variabel   = " << var << endl;
        cout << "---------------------------------------------\n";
    } 

    return 0;
}