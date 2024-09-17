#include <iostream>
using namespace std;


int menaraHanoi(int jumlahPiringan, string asal, string sementara, string tujuan){
    if (jumlahPiringan == 0)
        return 0;

    menaraHanoi(jumlahPiringan-1, asal, tujuan, sementara);
    cout << "Pindahkan piringan " << jumlahPiringan << " dari menara " << asal << " ke menara " << tujuan << endl;
    menaraHanoi(jumlahPiringan-1, sementara, asal, tujuan);

    return 0;
}


int main(){
    int jumlahPiringan = 3;
    string asal = "asal";
    string sementara = "sementara";
    string tujuan = "tujuan";

    menaraHanoi(jumlahPiringan, asal, sementara, tujuan);
    return 0;
}