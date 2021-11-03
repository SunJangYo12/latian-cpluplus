#include <iterator>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void advanceku()
{
   cout << "########## advance ############" << endl;

   list<int> coll;

   //insert elements dari 1 ke 9
   for (int i=1; i<=9; ++i)
        coll.push_back(i);

   list<int>::iterator pos = coll.begin();

   //print actual element
   cout << *pos << endl;

   //langkah tiga elemen ke depan
   advance(pos, 3);

   //print actual element
   cout << *pos << endl;

   //langkah satu elemen mundur
   advance(pos, -1);

   //print actual element
   cout << *pos << endl;
   cout << endl;
}

void distanceku()
{
   cout << "########## distance ############" << endl;
   list<int> coll;

   //insert elements from -3 to 9
   for (int i=-3; i<=9; ++i)
        coll.push_back(i);

   //search element with value 5
   list<int>::iterator pos;
   pos = find(coll.begin(), coll.end(),  //range
                                    5);  //value

   if (pos != coll.end())
       //proses dan cetak perbedaan dari awal
       cout << "perbedaan antara awal dan 5: "
            << distance(coll.begin(), pos) << endl;
   else
       cout << "5 not found" << endl;
   cout << endl;
   cout << endl;
}
void iter_swapku()
{
   cout << "######### iter_swap ############" << endl;
   list<int> coll;

   //insert elements from 1 to 9
   for (int i=1; i<=9; ++i)
        coll.push_back(i);

   //print all element
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //swap nilai pertama dan kedua
   iter_swap(coll.begin(), next(coll.begin()));

   //print all element
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //swap nilai pertama dan terakhir
   iter_swap(coll.begin(), prev(coll.end()));

   //print all element
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
   cout << endl;
}

int main()
{
   advanceku();
   //next()_prev(); lihat bab 7.6.2
   distanceku();    //jarak()
   iter_swapku();   //menukar
}
