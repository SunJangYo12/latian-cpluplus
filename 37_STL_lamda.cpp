#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <locale>
#include <string>
#include <functional>
using namespace std;

/*
Hanya untuk membandingkan satu fungsi deklarasi objek: menyatakan untuk "menambahkan 10 dan kalikan dengan 2" terlihat dengan binder sebagai berikut
auto plus10times2 = std::bind(std::multiplies<int>(),
                    std::bind(std::plus<int>(),
                              std::placeholders::_1,
                              10),
                               2);
*/
void lamda_vs_binder()
{
   cout << "######### lamda vs binder" << endl;
   auto plus10 = [] (int i) {
                    return i+10;
                 };
   cout << "+10 :  " << plus10(7) << endl;

   auto plus10times2 = [] (int i) {
                           return (i+10) * 2;
                       };
   cout << "+10 * 2 :  " << plus10times2(7) << endl;

   auto pow3 = [] (int i) {
                   return i*i*i;
                };
   cout << "x*x*x :  " << pow3(7) << endl;

   auto inversDivide = [] (double d1, double d2) {
                           return d2/d1;
                       };
   cout << "invdiv :  " << inversDivide(49,7) << endl;
   cout << endl << endl;
}

void lamda_vs_function_object()
{
   cout << endl << "######### lamda vs function object" << endl;

   vector<int> coll = { 1,2,3,4,5,6,7,8 };

   //proses dan print nilai rata-rata
   long sum = 0;
   for_each(coll.begin(), coll.end(),   //range
           [&sum] (int elem) {
               sum += elem;
           });

   double mv = static_cast<double>(sum) / static_cast<double>(coll.size());
   cout << "mean value: " << mv << endl;
   cout << endl << endl;
}
void lamda_remove_criteria()
{
   cout << "######### lamda remove criteria" << endl;
   list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };
   cout << "coll:        ";
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //remove third element
   list<int>::iterator pos;
   int count = 0;           //call counter
   pos = remove_if(coll.begin(), coll.end(),    //range
                  //[count] (int) mutable {     //mutable bikin 6 ikut kehapus
                  [&count] (int) {               //remove criterion
                        return ++count == 3;
                  });
   coll.erase(pos, coll.end());

   cout << "3rd removed: ";
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
   cout << endl;
}
char myToupper(char c)
{
   std::locale loc;
   return std::use_facet<std::ctype<char> >(loc).toupper(c);
}
void lamda_calling_global_and_member_function()
{
   cout << "######### lamda calling global and member" << endl;
   string s("Internationalization");
   string sub("Nation");

   //search substring case insensitive
   string::iterator pos;
   pos = search(s.begin(), s.end(),       //string to search in
                sub.begin(), sub.end(),   //substring to search
                [] (char c1, char c2) {   //compare criterion
                    return myToupper(c1) == myToupper(c2);
                });

   if (pos != s.end())
       cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
   cout << endl;
}
class Person {
   private:
      string name;
   public:
      Person(const string &n) : name(n) {
      }
      void print() const {
          cout << name << endl;
      }
      void print2(const string &prefix) const {
          cout << prefix << name << endl;
      }
};
void lamda_calling_global_and_member_function2()
{
   cout << "######### lamda calling global and member2" << endl;
   vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };

   //call member function print() for each person
   for_each(coll.begin(), coll.end(),
            [] (const Person &p) {
                p.print();
            });
   cout << endl;

   //call member functio print2 with additional argument for each person
   for_each(coll.begin(), coll.end(),
            [] (const Person &p) {
                p.print2("Person: ");
            });
   cout << endl;
}

int main()
{
   lamda_vs_binder();
   lamda_vs_function_object();
   lamda_remove_criteria();
   lamda_calling_global_and_member_function();
   lamda_calling_global_and_member_function2();
}
