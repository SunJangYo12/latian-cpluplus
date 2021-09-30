#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   vector<int> coll1;   //empty collection
   vector<int> coll2;   //empty collection

   //RUNTIME ERROR:
   //-awal ada dibelakang ujung kisaran
   vector<int>::iterator pos = coll1.begin();
   reverse(++pos, coll1.end());

   //insert elemets from 1 to 9 into coll1
   for (int i=1; i<=9; ++i)
       coll1.push_back(i);

   //RUNTIME ERROR:
   //-menimpa elemen yang tidak ada
   copy(coll1.cbegin(), coll1.cend(), //source
                      coll2.begin()); //destination

   //RUNTIME ERROR:
   //-koleksi yang salah
   //-cbegin() dan cend() mengacu pada koleksi yang berbeda
   copy(coll1.cbegin(), coll2.cend(), //source
                        coll1.end()); //destination

}
