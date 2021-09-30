/*
Semua contoh di bagian ini hanya berfungsi karena
Anda tahu bahwa POS25 ada di depan POS35.
Jika tidak, [POS25, POS35) tidak akan menjadi kisaran
yang valid. Jika Anda tidak yakin elemen mana yang ada
di depan, hal-hal menjadi lebih rumit, dan perilaku yang
tidak terdefinisi dapat dengan mudah terjadi.
*/


#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
   list<int> coll;

   // masukan elemen dari 20 - 40
   for (int i=20; i<=40; ++i)
       coll.push_back(i);

   // find position of element with value 3
   // -there is none, so pos3 gets coll.end()
   auto pos3 = find(coll.begin(), coll.end(),  // range
					  3);  // value

   // membalik urutan elemen antara elemen yg ditemukan diakhir
   // -karena pos3 adalah coll.end() itu membalikan rentang kosong
   reverse(pos3, coll.end());

   // find posititon of values 25 and 35
   list<int>::iterator pos25, pos35;
   pos25 = find(coll.begin(), coll.end(), 25);
   pos35 = find(coll.begin(), coll.end(), 35);

   // print rentang maximum yang sesuai
   // -note: termasuk pos25 tapi tidak termasuk pos35
   cout << "max: " << *max_element(pos25, pos35) << endl;

   // process elemen termasuk posisi terakhir
   cout << "max: " << *max_element(pos25, ++pos35) << endl;
}
