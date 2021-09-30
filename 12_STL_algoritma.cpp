#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
   // buat vektor dg elemen dari 1-6 dalam urutan arbtirer
   vector<int> coll = { 2, 5, 4, 1, 6, 3 };

   // find and print minimum and maximum elements
   auto minpos = min_element(coll.cbegin(), coll.cend());
   auto maxpos = max_element(coll.cbegin(), coll.cend());
   cout << "min: " << *minpos << endl;
   cout << "max: " << *maxpos << endl;

   // sort all elements
   sort(coll.begin(), coll.end());

   // temukan elemen pertama dengan nilai 3
   // -no cbegin() or cenf() karena nanti kita modifikasi elemen pos3 mengacu pada
   auto pos3 = find(coll.begin(), coll.end(), // range
					  3); // value

   // membalik urutan elemen yg ditemukan dg nilai 3 dan semua elemen berikut
   reverse(pos3, coll.end());

   // print all elements
   for (auto elem : coll)
       cout << elem << ' ';

   cout << endl;

}
