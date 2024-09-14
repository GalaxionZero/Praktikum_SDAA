#include <iostream>
using namespace std;


int menaraHanoi(int n, char asal, char sementara, char tujuan){
    if (n == 0)
        return 0;

    menaraHanoi(n-1, asal, tujuan, sementara);
    cout << "Pindahkan piringan " << n << " dari menara " << asal << " ke menara " << tujuan << endl;
    menaraHanoi(n-1, sementara, asal, tujuan);

    return 0;
}


int main(){
    int n = 3;

    menaraHanoi(n, 'A', 'B', 'C');
    return 0;
}