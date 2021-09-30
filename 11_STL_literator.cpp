/*

Penjelasan singkat:
   literator adalah fitur pencarian elemen tanpa proses
loop semua elemen serta dapat menyimpan posisi ini


NOTE: SAAT INI SAYA TIDAK PAHAM LIHAT KEMBALI PAGE 197
*/

#include <list>
#include <iostream>
#include <set>
using namespace std;

void oldSet() {
   typedef set<int> IntSet;
   IntSet coll;

   //Masukan elemen dari 1-6 dalam urutan arbitrer
   //-perhatikan ada dua panggilan insert() dengan nilai 1
   coll.insert(3);
   coll.insert(1);
   coll.insert(5);
   coll.insert(4);
   coll.insert(1);
   coll.insert(6);
   coll.insert(2);

   // print all elements
   // -iterate over all elements
   IntSet::const_iterator pos;
   for (pos = coll.begin(); pos != coll.end(); ++pos)
       cout << *pos << ' ';

   cout << endl;
}


int main()
{
   list<char> coll;

   // append elements from 'a' to 'z'
   for (char c='a'; c<='z'; ++c)
       coll.push_back(c);

   // print all elements:
   // -iterate over all elements
   for (list<char>::const_iterator pos = coll.begin(); pos != coll.end(); ++pos)
       cout << *pos << ' ';
   cout << endl;

   // change all elements
   list<char>::iterator pos; // iterator bukan const
   for (pos = coll.begin(); pos != coll.end(); ++pos)
   {
       *pos = toupper(*pos);
       cout << *pos << ' ';
   }

   cout << endl;

   oldSet();
}
