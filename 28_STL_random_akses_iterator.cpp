#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> coll;

    //masukan elemen dari -3 ke 9
    for (int i=-3; i<=9; ++i)
         coll.push_back(i);

    //print jumlah elemen dg memproses jarak antara awal dan akhir
    //-NOTE: uses operator - for iterator
    cout << "number/distance: " << coll.end() - coll.begin() << endl;

    //print all elements
    //-NOTE: uses operator < alih-alih of operator !=
    vector<int>::iterator pos;
    for (pos=coll.begin(); pos<coll.end(); ++pos)
         cout << *pos << ' ';
    cout << endl;

    //print all elements
    //-NOTE: uses operator [] alih-alih of operator *
    for (int i=0; i<coll.size(); ++i)
         cout << coll.begin()[i] << ' ';
    cout << endl;

    //print setiap elemen kedua
    //-NOTE: uses operator +=
    for (pos=coll.begin(); pos < coll.end()-1; pos+=2)
         cout << *pos << ' ';
    cout << endl;
}
