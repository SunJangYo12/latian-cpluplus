#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <set>
using namespace std;

void back_inserterku()
{
   cout << "############ back inserter ############\n";

   vector<int> coll;

   //create back insert for coll
   //-cara yang tidak nyaman
   back_insert_iterator<vector<int>> iter(coll);

   //insert elemen dengan iterator yang biasa
   *iter = 1;
   iter++;
   *iter = 2;
   iter++;
   *iter = 3;

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //create back inserter and insert elements
   //-cara yang mudah
   back_inserter(coll) = 44;
   back_inserter(coll) = 55;

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //gunakan kembali inserter untuk menambahkan semua elemen lagi
   //-cadangan memori yang cukup untuk menghindari realokasi
   coll.reserve(2 * coll.size());
   copy(coll.begin(), coll.end(),    //source
            back_inserter(coll));    //destination

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
   cout << endl;
}

void front_inserterku()
{
   cout << "############ front inserter ############\n";
   list<int> coll;

   //create front inserter for coll
   //cara yang tidak nyaman
   front_insert_iterator<list<int>> iter(coll);

   //masukan elemen dengan antarmuka iterator yang biasa
   *iter = 1;
   iter++;
   *iter = 2;
   iter++;
   *iter = 3;

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //create front inserter and insert elements
   //-cara yang mudah
   front_inserter(coll) = 44;
   front_inserter(coll) = 55;

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //use front inserter to insert all elements again
   copy(coll.begin(), coll.end(),   //source
           front_inserter(coll));   //destination

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
   cout << endl;

}

void general_inserterku() //insert umum
{
   cout << "########## general inserter ##############\n";
   set<int> coll;

   insert_iterator<set<int>> iter(coll, coll.begin());

   *iter = 1;
   iter++;
   *iter = 2;
   iter++;
   *iter = 3;

   cout << "set:  ";
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   inserter(coll, coll.end()) = 44;
   inserter(coll, coll.end()) = 55;

   cout << "set:  ";
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //gunakana inserter untuk memasukan semua eleme ke dalam list
   list<int> coll2;
   copy(coll.begin(), coll.end(),
        inserter(coll2, coll2.begin()));

   cout << "list: ";
   for (auto elem : coll2)
        cout << elem << ' ';
   cout << endl;

   //gunakana inserter untuk memasukan kembali semua elemen ke
   //dalam list sebelum elemen kedua
   copy(coll.begin(), coll.end(),
        inserter(coll2, ++coll2.begin()));

   cout << "list: ";
   for (auto elem : coll2)
        cout << elem << ' ';
   cout << endl;
   cout << endl;
}

int main()
{
   back_inserterku();
   front_inserterku();
   general_inserterku();
}
