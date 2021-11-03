#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <complex>
#include <unordered_set>
#include <numeric>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>
using namespace std;

void mySample()
{
   unordered_map<string,float> coll;

   coll["oke"] = 4.3;
   coll["zzz"] = 1.0;
   coll["xxx"] = 2.0;

   for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << "key: " << pos->first << "\t"
             << "value: " << pos->second << endl;
   }

   if (coll.insert(make_pair("otto", 22.3)).second)
       cout << endl << "OK, could insert otto/22.3" << endl;
   else
       cout << endl << "Opps, could not insert otto/22.3 "
            << "key otto alreay exists" << endl;

   for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << "key: " << pos->first << "\t"
             << "value: " << pos->second << endl;
   }
   cout << endl;
   cout << endl;

   unordered_map<string,complex<float>> m;
   m.emplace(piecewise_construct,     //pass tuple elements as arguments
             make_tuple("hello"),     //elemen for the key
             make_tuple(3.4, 7.8));   //elemen for the value

   for (auto pos = m.begin(); pos != m.end(); ++pos) {
        cout << "key: " << pos->first << "\t"
             << "value: " << pos->second << endl;
   }
   cout << endl;
   cout << endl;
}

void unordered_setku() {
   //create and initialize unordered set
   unordered_set<int> coll = { 1,2,3,5,7,11,13,17,19,77 };

   //print elemens
   //-urutan elemen dalam sewenang-wenang
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //masukan beberapa elemen tambahan
   //-mungkin menyebabkan pengulangan dan membuat urutan yang berbeda
   coll.insert( {-7,14,33,-11,17,19,1,13} );
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //hapus elemen dengan nilai spesifik
   coll.erase(33);

   //sisipkan jumlah semua nilai yang ada
   coll.insert(accumulate(coll.begin(), coll.end(), 0));
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //cek apakah nilai 19 ada di set
   if (coll.find(19) != coll.end())
       cout << "19 is available" << endl;

   //hapus semua nilai negatif
   unordered_set<int>::iterator pos;
   for (pos=coll.begin(); pos != coll.end();) {
        if (*pos < 0)
            pos = coll.erase(pos);
        else
            ++pos;
   }
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
}

//output generik untuk pasangan (map elemen)
template <typename T1, typename T2>
ostream  &operator << (ostream &strm, const pair<T1,T2> &p)
{
   return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState(const T &cont)
{
   //basic layout data
   cout << "size:              " << cont.size() << "\n";
   cout << "buckets:           " << cont.bucket_count() << "\n";
   cout << "load factor:       " << cont.load_factor() << "\n";
   cout << "max load factor:   " << cont.max_load_factor() << "\n";

   //iterator category
   if (typeid(typename iterator_traits<typename T::iterator>::iterator_category) ==
       typeid(bidirectional_iterator_tag)) {
       cout << "chaining style: double-linked" << "\n";
   }
   else {
       cout << "chaining style: singly-linked" << "\n";
   }

   //elemen per bucket
   cout << "data: " << "\n";
   for (auto idx=0; idx != cont.bucket_count(); ++idx)
   {
       cout << " b[" << setw(2) << idx << "]: ";
       for (auto pos=cont.begin(idx); pos!=cont.end(idx); ++pos)
            cout << *pos << " ";
       cout << "\n";
   }
   cout << endl;
}

void buckets() {
   //create and initialize an unordered set
    unordered_set<int> intset = { 1,2,3,5,7,11,13,17,19 };
    printHashTableState(intset);

   //masukan beberapa nilai tambahan (mungkin menyebabkan rehasing)
    intset.insert( {-7,17,33,4} );
    printHashTableState(intset);
}
void buckets_dua() {
    //buat dan inisiasisasi multimap yg tidak terurut sebagai dictinory/kamus
    unordered_multimap<string,string> dict = {
                   {"day", "Tag"},
                   {"strange", "fremd"},
                   {"car", "Auto"},
                   {"smart", "elegant"},
                   {"trait", "Merkmal"},
                   {"strange", "seltsam"}
    };
    printHashTableState(dict);

    //masukan beberapa nilai tambahan (mungkin menyebabkan rehasing)
    dict.insert( { {"smart", "raffiniert"},
                   {"smart", "klug"},
                   {"clever", "raffiniert"}
                 }
               );
    printHashTableState(dict);

    //modifiy maximum load factor (mungkin menyebabkan rehasing)
    dict.max_load_factor(0.7);
    printHashTableState(dict);
}
int main()
{
   buckets_dua();
}

