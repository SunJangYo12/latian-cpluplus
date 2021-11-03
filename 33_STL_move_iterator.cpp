#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
   list<string> s = { "oke","zzz","aaa" };

   for (auto elem : s)
        cout << elem << ' ';
   cout << endl;

   vector<string> v1(s.begin(), s.end());

   for (auto elem : v1)
        cout << elem << ' ';
   cout << endl;

   vector<string> v2(make_move_iterator(s.begin()),
                     make_move_iterator(s.end()));

   for (auto elem : v2)
        cout << elem << ' ';
   cout << endl;

}
