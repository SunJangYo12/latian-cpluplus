#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

//type for runtime sorting criterion
class RuntimeCmp {
   public:
      enum cmp_mode {normal, reverse};
   private:
      cmp_mode mode;
   public:
      //constructor for sorting criterion
      //-default criterion uses value normal
      RuntimeCmp(cmp_mode m=normal) : mode(m) {
      }

      //comparison of elements
      //-member function for any element type
      template <typename T>
      bool operator() (const T &t1, const T &t2) const {
           return mode==normal ? t1 < t2
                               : t2 < t1;
      }

      //comparison of sorting criteria
      bool operator == (const RuntimeCmp &rc) const {
           return mode == rc.mode;
      }
};
//jenis satu set yang menggunakan kriteria penyortiran ini
typedef set<int,RuntimeCmp> IntSet;

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

void setku()
{
   cout << "############ SETKU ############" << endl;
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
   cout << endl;
}

int main()
{

   mySample();
   setku();

   cout << "############ ADVENDED ############" << endl;
   //create, fill, dan print set dengan urutan elemen normal
   //-menggunakan kriteria penyortiran default
   IntSet coll1 = { 4,7,5,1,6,2,5 };

   cout << "coll1: ";
   for (auto elem : coll1)
       cout << elem << ' ';
   cout << endl;

   //buat kriteria penyortiran dg urutan elemen terbalik
   RuntimeCmp reverse_order(RuntimeCmp::reverse);

   //create, fill dan print set dengan urutan terbalik
   IntSet coll2(reverse_order);
   coll2 = { 4,7,5,1,6,2,5 };

   cout << "coll2: ";
   for (auto elem : coll2)
       cout << elem << ' ';
   cout << endl;

   //menetapkan elemen dan sorting
   coll1 = coll2;
   coll1.insert(3);

   cout << "coll1: ";
   for (auto elem : coll1)
       cout << elem << ' ';
   cout << endl;

   //hanya untuk memastikan
   if (coll1.value_comp() == coll2.value_comp())
       cout << "coll1 dan coll2 memiliki kriteria penyortiran yang sama " << endl;
   else
       cout << "coll1 dan coll2 memiliki kriteria penyortiran yang berbeda " << endl;
   cout << endl;
   cout << endl;

}
