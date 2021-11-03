#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void print(int elem) {
     cout << elem << ' ';
}

void reverse_iteratorku()
{
   cout << "################# reverse iteratorku ##############";
   //create list with elements form 1 to 9
   list<int> coll = { 1,2,3,4,5,6,7,8,9 };

   //print all elements in normal order
   for_each(coll.begin(), coll.end(),    //range
                              print);    //operation
   cout << endl;

   //print all element in reverse order
   for_each(coll.rbegin(), coll.rend(),   //range
                                print);   //operations
   cout << endl;
   cout << endl;
}
void reverse_iteratorku2()
{
   cout << "################# reverse iteratorku2 ##############\n";

   //create list with element from 1 to 9
   vector<int> coll = { 1,2,3,4,5,6,7,8,9 };

   //find position of element with value 5
   vector<int>::const_iterator pos;
   pos = find(coll.cbegin(), coll.cend(),
                                      5);

   //print iterator merujuk pos mana
   cout << "pos: " << *pos << endl;

   //convert iterator untuk membalikan iterator rpos
   vector<int>::const_reverse_iterator rpos(pos);

   //print nilai yang membalikan iterator rpos
   cout << "rpos: " << *rpos << endl;
   cout << endl;
   cout << endl;
}
void reverse_iteratorku3()
{
   cout << "################# reverse iteratorku3 ##############\n";
   deque<int> coll = { 1,2,3,4,5,6,7,8,9 };

   //find position of element with value 2
   deque<int>::const_iterator pos1;
   pos1 = find(coll.cbegin(), coll.cend(),   //range
                                       2);   //value

   //find position of element with value 7
   deque<int>::const_iterator pos2;
   pos2 = find(coll.cbegin(), coll.cend(),   //range
                                       7);   //value

   //print all elements in range (pos1, pos2)
   for_each(pos1, pos2,     //range
                print);     //operation
   cout << endl;

   //konversi iterator untuk membalikan iterator
   deque<int>::const_reverse_iterator rpos1(pos1);
   deque<int>::const_reverse_iterator rpos2(pos2);

   //print all element in range [pos1,pos2] in reverse order
   for_each(rpos2, rpos1,   //range
                  print);   //operation
   cout << endl;
   cout << endl;
}

int main()
{
   reverse_iteratorku();
   reverse_iteratorku2();
   reverse_iteratorku3();
}
