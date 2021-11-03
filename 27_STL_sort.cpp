#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

void usingset()
{
   //create a string set
   //-inisialisasi oleh semua kata dari input standar
   set<string> coll((istream_iterator<string>(cin)),
                    istream_iterator<string>());

   //print all elements
   copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}

void usingvector()
{
   //create a string set
   //-inisialisasi oleh semua kata dari input standar
   vector<string> coll((istream_iterator<string>(cin)),
                    istream_iterator<string>());

   //sort elemnts
   sort(coll.begin(), coll.end());

   //print semua elemen dan abaikna dublikat berikutnya
   unique_copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}

int main() {
   usingvector();
}
