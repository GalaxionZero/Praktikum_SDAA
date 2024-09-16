#include <iostream>
using namespace std;


int menaraHanoi(int n, string asal, string sementara, string tujuan){
    if (n == 0)
        return 0;

    menaraHanoi(n-1, asal, tujuan, sementara);
    cout << "Pindahkan piringan " << n << " dari menara " << asal << " ke menara " << tujuan << endl;
    menaraHanoi(n-1, sementara, asal, tujuan);

    return 0;
}


int main(){
    int n = 3;
    string asal = "asal";
    string sementara = "sementara";
    string tujuan = "tujuan";

    menaraHanoi(n, asal, sementara, tujuan);
    return 0;
}