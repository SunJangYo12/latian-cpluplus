#include <array>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

void clasicalC()
{
   cout << endl;
   cout << "############ CHAR C++ to C STRING ############";
   cout << endl;
   std::array<char,41> a;  //create static array 41 chars

   strcpy(a.data(), "hello, world"); //copy a C-string into the aray
   printf("%s\n", a.data());         //print content of the array as C-string
   cout << endl;
   cout << endl;
}

void tupple()
{
   cout << endl;
   cout << "############ TUPPLE ############";
   cout << endl;

   //create array with 10 ints
   array<int,10> a = { 11,22,33,44 };

   cout << "initialized: ";
   for (auto elem : a)
       cout << elem << ' ';
   cout << endl;

   //modify last two elements
   a.back() = 9999999;
   a[a.size()-2] = 42;

   cout << "modify: ";
   for (auto elem : a)
       cout << elem << ' ';
   cout << endl;

   //process sum of all elements
   cout << "sum: " << accumulate(a.begin(), a.end(), 0) << endl;

   //meniadakan semua elemets
   transform(a.begin(), a.end(),    //source
                        a.begin(),  //destination
                    negate<int>()); //operation

   cout << "show again: ";
   for (auto elem : a)
       cout << elem << ' ';
   cout << endl;

   cout << endl;
   cout << endl;
}

int main()
{
   clasicalC();
   tupple();

}
