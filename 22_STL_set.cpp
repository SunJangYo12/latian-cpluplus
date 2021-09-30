#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

void mySample()
{
   cout << "############ MYSAMPLE ############" << endl;
   set<int> c;

   c.insert(1);
   c.insert(2);
   c.insert(3);
   c.insert(4);
   c.insert(5);
   c.insert(6);

   cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
   cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
   cout << "equal_range(3): " << *c.equal_range(3).first << " "
                              << *c.equal_range(3).second << endl;
   cout << endl;
   cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
   cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
   cout << "equal_range(5): " << *c.equal_range(5).first << " "
                              << *c.equal_range(5).second << endl;
   cout << endl;

   set<double> d;

   d.insert(4.4);

   if (d.insert(3.3).second)
       cout << "3.3 inserted" << endl;
   else
       cout << "3.3 already exits" << endl;

   cout << "data: ";
   for (auto elem : d)
       cout << elem << ' ';
   cout << endl;
   cout << endl;
}

int main()
{
   //type of collection
   //-no duplicate
   //-elements are integral values
   //-descending order
   set<int,greater<int>> coll1;

   //masukan elemen dalam urutan acak menggunakan
   //fungsi anggota yang berbeda
   coll1.insert( {4,3,5,1,6,2} );
   coll1.insert(5);

   //print all elements
   for (int elem : coll1)
      cout << elem << ' ';
   cout << endl;

   //masukkan 4 lagi dan proses pengembalian nilai
   auto status = coll1.insert(4);
   if (status.second) {
      cout << "4 inserted as element "
           << distance(coll1.begin(), status.first) + 1 << endl;
   }
   else {
      cout << "4 already exists" << endl;
   }

   //tetapkan elemen ke set lain dengan urutan naik
   set<int> coll2(coll1.cbegin(), coll1.cend());

   //print semua elemen dari salianan menggunakan iterator stream
   copy(coll2.cbegin(), coll2.cend(),
        ostream_iterator<int>(cout, " "));
   cout << endl;

   //hapus semua elemen hingga elemen dengan nilai 3
   coll2.erase(coll2.begin(), coll2.find(3));

   //hapus semua elemen dengan nilai 5
   int num;
   num = coll2.erase(5);
   cout << num << " element(s) removed" << endl;

   //print all elements
   copy(coll2.cbegin(), coll2.cend(),
        ostream_iterator<int>(cout, " "));
   cout << endl;
}
