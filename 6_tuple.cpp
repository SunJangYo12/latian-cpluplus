#include <tuple>
#include <iostream>
#include <complex>
#include <string>

using namespace std;

int main()
{
    // create a four element tuple
    // elemen diinisialiasi dg nilai default (0 untuk jenis fundamental)

    tuple<string, int, int, complex<double>> t;

    // create and initialize a tuple explicitly
    tuple<int, float, string> t1(41, 6.3, "nico");

    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;

    // create tuple menggunakan make_tuple()
    // - auto menyatakan t2 dg jenis sisi kanan
    // - dengan demikian jenis t2 adalah tuple

    auto t2 = make_tuple(22, 44, "nico");

    // tetapkan nila kedua dalan t2 ke t1
    get<1>(t1) = get<1>(t2);

    // perbandingan dan penugasan
    // - includeing type conversion from tuple<int, int, const char*> to tuple<int, float, string>

    // membandingkan nilai ke nilai
    if (t1 < t2)
       t1 = t2;
}
