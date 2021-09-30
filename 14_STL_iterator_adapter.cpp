#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

void insert_iterators()
{
   cout << endl;
   cout << "########### INSERT ITERATOR ############";
   cout << endl;
   list<int> coll1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   // salin elemen coll1 ke coll2 dengan menambahkanya
   vector<int> coll2;
   copy(coll1.cbegin(), coll1.cend(),   // source
                back_inserter(coll2));  // destination


   // salin elemen-elemen coll1 ke dalam coll3 dg memasukkanya didepan
   // -reverses the order of the elements
   deque<int> coll3;
   copy(coll1.cbegin(), coll1.cend(),   // source
               front_inserter(coll3));  // destination

   // salin elemen coll1 ke coll4
   // -hanya inserter yang berfungsi untuk koleksi asosiatif
   set<int> coll4;
   copy(coll1.cbegin(), coll1.cend(),            // source
               inserter(coll4, coll4.begin())); // destination

   for (auto elem : coll1)
       cout << elem << ' ';
   cout << endl;

   for (auto elem : coll2)
       cout << elem << ' ';
   cout << endl;

   for (auto elem : coll3)
       cout << elem << ' ';
   cout << endl;

   for (auto elem : coll4)
       cout << elem << ' ';

   cout << endl;
   cout << endl;
}

void stream_iterators()
{
   cout << "########### STREAM ITERATOR ############";
   cout << endl;
   vector<string> coll;

   // baca semua kata dari input standar
   // -source: semua string sampai akhir file (on error)
   // -destinatio: coll(inserting)
   copy(istream_iterator<string>(cin),    // start of source
        istream_iterator<string>(),       // end of source
        back_inserter(coll));             // destination

   // sort elements
   sort(coll.begin(), coll.end());

   // print all elements without duplicates
   // -source: coll
   // -destination: standart output(with newline betwen antara elemen
   unique_copy(coll.cbegin(), coll.cend(),    // source
   ostream_iterator<string>(cout, "\n")); // destination
}

void reverse_iterators()
{
   cout << "########### REVERSE ITERATOR ############" << endl;
   vector<int> coll;

   // masukan elemen dari 1 - 9
   for (int i=1; i<=9; ++i)
       coll.push_back(i);

   // print all elemen in reverse order/urutan terbalik
   copy(coll.crbegin(), coll.crend(),        // source
    ostream_iterator<int>(cout, " ")); //destination

   for (auto elem : coll)
       cout << elem << ' ';

   cout << endl;
   cout << endl;
}

int main()
{
   insert_iterators();
   //stream_iterators(); /* ini mengharuskan input keyboard
   reverse_iterators();
}
