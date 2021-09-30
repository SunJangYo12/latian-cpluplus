#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <vector>
#include <cstdlib>  // for abs()
#include <iostream>
using namespace std;

void remove_element(bool example2)
{
    list<int> coll;

    // masukan elemen dari 6-1 dan 1-6
    for (int i=1; i<=6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    // print all elements of the collection
    cout << endl;
    cout << "data:  ";
    copy(coll.cbegin(), coll.cend(),    //source
      ostream_iterator<int>(cout, " ")); //destination

    cout << endl;
    cout << endl;

    // hapus semua elemen dg nilai 3

    if (example2) {
       cout << "########### REMOVE EX2 #############" << endl;
       // pertahankan ujung baru
       list<int>::iterator end = remove(coll.begin(), coll.end(), 3);

       // print resulting elements of the collection
       copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
       cout << endl;

       // print number of removed elements
       cout << "number of removed elemets: "
            << distance(end, coll.end()) << endl;

       // remove "removed" elements
       coll.erase(end, coll.end());

       // print semua elemen dari koleksi yg dimodifikasi
       copy(coll.cbegin(), coll.cend(),
            ostream_iterator<int>(cout, " "));

       cout << endl;
    }
    else {
       cout << "########### REMOVE EX1 #############" << endl;
       remove(coll.begin(), coll.end(),   // range
                                    3);   // value

       // print all elements of the collection
       cout << "post: ";
       copy(coll.cbegin(), coll.cend(),     //source
         ostream_iterator<int>(cout, " ")); //destination

       cout << endl;
    }

    cout << endl;
    cout << endl;
}

void asosiatif_remove_element() {
    cout << "########### ASOSIATIF REMOVE #############" << endl;
    // unondered set with elements from 1 to 9
    set<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // print all elements of the collection
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements with value 3
    // -algorithm remove() does not work
    // -instead member function erase() works
    int num = coll.erase(3);

    // print number of removed elements
    cout << "number of removed elements: " << num << endl;

    // print all elements of the modified collection
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "));

    cout << endl;
    cout << endl;
}
void member_remove()
{
    cout << "########### MEMBER REMOVE #############" << endl;
    list<int> coll;

    // insert element dari 6-1 dan 1-6
    for (int i=1; i<=6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    // remove all elements with value 3 (buruk performance)
    coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());

    // remove all elemets with value 4 (bagus performance)
    coll.remove(4);

    for (auto elem : coll)
        cout << elem << ' ';

    cout << endl;
    cout << endl;
}

void argumen_print(int elem)
{
    cout << elem << ' ';
}
void argumen() {
    cout << "########### ARGUMEN #############" << endl;
    vector<int> coll;

    // insert elements from 1 - 9
    for (int i=1; i<=9; ++i)
        coll.push_back(i);

    // print all elements
    for_each(coll.cbegin(), coll.cend(),  //range
                          argumen_print);  //operation

    cout << endl;
    cout << endl;
}

bool unary_predicates_isPrime(int number)
{
    // abaikan tanda negatif
    number = abs(number);

    // 0 dan 1 bukan bilangan prime
    if (number == 0 || number == 1)
       return false;

    // temukan pembagi yang membagi tanpa sisa
    int divisor;
    for (divisor = number/2;  number % divisor != 0; --divisor)
    {
       ;
    }

    // jika tidak ada pembagi yg lebih besar dari 1 ditemukan, itu adalah bilangan prima
    return divisor == 1;
}
void unary_predicates()
{
    cout << "########### UNARY PREDICATRE #############" << endl;
    list<int> coll;

    // insert elements from 24 to 30
    for (int i=24; i<=30; ++i)
       coll.push_back(i);

    // search for prime number
    auto pos = find_if(coll.cbegin(), coll.cend(),   //range
                        unary_predicates_isPrime);  //prediate

    if (pos != coll.end()) // found
       cout << *pos << " is first prime number found" << endl;
    else // not found
       cout << "no prime number found" << endl;

    cout << endl;
    cout << endl;
}
int main()
{
    remove_element(true);
    asosiatif_remove_element();
    member_remove();
    argumen();
    unary_predicates();
}
