#include <iostream>
using namespace std;

int main(){
    int a, b;

    cout << "Masukkan jumlah baris: ";
    cin >> a;
    cout << "Masukkan jumlah kolom: ";
    cin >> b;

    int matriks[a][b];

    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; j++)
        {
            matriks[i][j] = 0;
        }
    }

    for (int k = 0; k < a; ++k)
    {
        for (int l = 0; l < b; l++)
        {
            cout << matriks[k][l] << endl;
        }
    }

    return 0;
}
