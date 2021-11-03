#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void simple() {
   int vals[] = { 32, 67, -4, 13, 5, 2 };

   //use begin() and end() for ordinary C arrays
   vector<int> v(begin(vals), end(vals));

   //use global begin() and end() for container
   copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
   cout << endl;
}

int main()
{
   int coll[] = { 5,6,2,4,1,3 };

   //square all elements
   transform(coll, coll+6,       //first source
             coll,               //second source
             coll,               //destination
             multiplies<int>()); //operation

   //sort dimulai dengan elemen kedua
   sort(coll+1, coll+6);

   //print all elemen
   copy(coll, coll+6, ostream_iterator<int>(cout, " "));
   cout << endl;
}
