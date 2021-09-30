#include <vector>
#include <deque> // atau antrian ganda
#include <array>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set> // translate: tidak urut
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

void vectorku()
{
   cout << "##### VECTOR ######" << endl;
   vector<int> coll;	// vector container for integer elements

   // tambahkan elemen dg nilai 1 hingga 6
   for (int i=1; i<=6; ++i)
       coll.push_back(i);

   // print all elements followed by a space
   for (int i=0; i<coll.size(); ++i)
       cout << coll[i] << ' ';

   cout << endl;
   cout << endl;
}

void dequeku()
{
   cout << "##### DEQUEKU ######" << endl;
   deque<float> coll; // deque container for floating elements

   // masukan elemen dari 1.1 - 6.6 masing2 di bagian depan
   for (int i=1; i<=6; ++i)
      coll.push_front(i * 1.1); // masukan di depan

   for (int i=0; i<coll.size(); ++i)
      cout << coll[i] << ' ';

   cout << endl;
   cout << endl;
}

void arrayku()
{
   cout << "##### ARRAY ######" << endl;
   // array container of 5 string elements
   array<string, 5> coll = { "hello", "world" };

   for (int i=0; i<coll.size(); ++i)
      cout << i << ": " << coll[i] << endl;

   cout << endl;
   cout << endl;
}

void listku()
{
   cout << "##### LIST ######" << endl;
   list<char> coll; 	//list container for character elements

   // append elements from 'a' to 'z'
   for (char c='a'; c<='z'; ++c)
       coll.push_back(c);

   // print all elements:
   // - use range-based for loop
   for (auto elem : coll)
       cout << elem << ' ';

   cout << endl;

   // print all elements:
   // - while there are elements
   // - print and remove the first element
   cout << "---- print and remove first element" << endl;
   while (!coll.empty())
   {
       cout << coll.front() << ' ';
       coll.pop_front();
   }

   cout << endl;
   cout << endl;
}

void forward_listku()
{
   cout << "##### FORWARD_LIST ######" << endl;
   // buat forward_list untuk beberapa bilangan prime
   forward_list<long> coll = { 2, 3, 5, 7, 11, 13, 17 };

   // resize two times
   // - note: poor performance / pertunjukan yg buruk
   coll.resize(9);
   coll.resize(10, 99);

   // print all elements
   for (auto elem : coll)
       cout << elem << ' ';

   cout << endl;
   cout << endl;
}

void set_and_multiset()
{
   cout << "##### SET AND MULTISET ######" << endl;
   multiset<string> cities {
       "Braunshdsd", "Hanover", "Frankfurt", "New Yorl",
       "Chicago", "Toronto", "Paris", "Frankfurt"
   };

   // print each element:
   for (const auto& elem : cities)
       cout << elem << "  ";

   cout << endl;

   // insert additional values:
   cities.insert( {"London", "Munich", "Hanover", "Braunshdsd"} );

   for (const auto& elem : cities)
       cout << elem << "  ";
   cout << endl;
   cout << endl;
}

void map_and_multimap()
{
   cout << "##### MAP AND MULTIMAP ######" << endl;
   multimap<int, string> coll;	// container for int/string values

   // masukan elemen dalam urutan sewenang-wenang
   // - nilai dengan kunci 1 dimasukan dua kali
   coll = { {5, "tagged"}, // translate: yg ditandai
            {2, "a"},
            {1, "this"},
            {4, "of"},
            {6, "strings"},
            {1, "is"},
            {3, "multimap"} };

   // print all elements values
   // - anggota elemen kedua adalah nilainya
   for (auto elem : coll)
       cout << elem.second << ' ';

   cout << endl;
   cout << endl;
}

void unordered_set_and_multiset()
{
   cout << "##### UNORDERED SET AND MULTISET ######" << endl;
   unordered_multiset<string> cities {
       "Braunshdsd", "Hanover", "Frankfurt", "New Yorl",
       "Chicago", "Toronto", "Paris", "Frankfurt"
   };
   for (const auto& elem : cities)
       cout << elem << "  ";

   cout << endl;

   cities.insert( {"London", "Munich", "Hanover", "Braunshdsd"} );
   for (const auto& elem : cities)
       cout << elem << "  ";

   cout << endl;
   cout << endl;
}

void unordered_map_and_multimap()
{
   cout << "##### UNORDERED MAP AND MULTIMAP ######" << endl;
   unordered_map<string, double> coll { {"tim", 9.9 },
                                        {"struppi", 11.77}
                                      };

   // square nilai setiap elemen
   for (pair<const string, double>& elem : coll)
        elem.second *= elem.second;

   // print each element (key and value)
   for (const auto& elem : coll)
        cout << elem.first << ": " << elem.second << endl;


   // type of the container:
   // -unordered_map: elemen adalah kunci/pasangan nilai
   // -string: keys have type string
   // -float: values have type float
   unordered_map<string,float> arrcoll;

   // insert some elements into the collection
   // -using the syntax of an associative array
   arrcoll["VAT1"] = 0.16;
   arrcoll["VAT2"] = 0.07;
   arrcoll["Pi"] = 3.1415;
   arrcoll["an arbitrary number"] = 4983.223; // translate: arbitrary/sewenang-wenang
   arrcoll["Null"] = 0;

   // change value
   arrcoll["VAT1"] += 0.03;
   cout << "VAT difference: " << arrcoll["VAT1"] - arrcoll["VAT2"] << endl;

   cout << endl;
   cout << endl;
}


int main() {
   cout << endl;

   vectorku();
   dequeku();
   arrayku();
   listku();
   forward_listku();
   set_and_multiset();
   map_and_multimap();
   unordered_set_and_multiset();
   unordered_map_and_multimap();

}
