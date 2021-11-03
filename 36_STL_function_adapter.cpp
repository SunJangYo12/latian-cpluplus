#include <functional>
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
#include <vector>
#include <cmath>
#include <iterator>
using namespace std;
using namespace std::placeholders;

void bindku()
{
   cout << endl << "############# bindku ################" << endl;
   auto plus10 = std::bind(std::plus<int>(),
                           std::placeholders::_1,
                                              10);
   std::cout << "+10    :   " << plus10(7) << std::endl;

   auto plus10times2 = std::bind(std::multiplies<int>(),
                                  std::bind(std::plus<int>(),
                                  std::placeholders::_1,
                                                     10),
                                                      2);
   std::cout << "+10 * 2:   " << plus10times2(7) << std::endl;

   auto pow3 = std::bind(std::multiplies<int>(),
                         std::bind(std::multiplies<int>(),
                                   std::placeholders::_1,
                                   std::placeholders::_1),
                         std::placeholders::_1);
   std::cout << "x*x*x   :   " << pow3(7) << std::endl;

   auto inversDivide = std::bind(std::divides<double>(),
                                 std::placeholders::_2,
                                 std::placeholders::_1);
   std::cout << "invdiv  :   " << inversDivide(49, 7) << std::endl;
   cout << endl << endl;
}

char myToupper(char c)
{
   std::locale loc;
   return std::use_facet<std::ctype<char> >(loc).toupper(c);
}
void bind_call_global_function()
{
   cout << "############# bind call global function ################" << endl;
   string s("Internationalization");
   string sub("Nation");

   //cari substring tidak casesensitif
   string::iterator pos;
   pos = search(s.begin(), s.end(),
                sub.begin(), sub.end(),
                bind(equal_to<char>(),
                     bind(myToupper,_1),
                     bind(myToupper,_2)));

   if (pos != s.end())
       cout << "\"" << sub << "\" is part of \"" << s << "\"" << endl;
   cout << endl;
   cout << endl;
}

class Person {
   private:
      string name;
   public:
      Person (const string &n) : name(n) {
      }
      void print() const {
         cout << name << endl;
      }
      void print2(const string &prefix) const {
         cout << prefix << name << endl;
      }
};
void bind_call_member_function()
{
   cout << "############# bind call member function ################" << endl;
   vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };

   //call member function print() for each person
   for_each(coll.begin(), coll.end(),
            bind(&Person::print, _1));
   cout << endl;

   //call member function print2() dengan argumen tambahan untuk setiap person
   for_each(coll.begin(), coll.end(),
            bind(&Person::print2, _1, "Person: "));
   cout << endl;

   //call print2 for temporary Person
   bind(&Person::print2, _1, "This is: ")(Person("nico"));
   cout << endl << endl;
}

template <typename T1, typename T2>
struct fopow
{
   T1 operator() (T1 base, T2 exp) const {
      return std::pow(base, exp);
   }
};
void object_fungsi_yang_ditentukan_pengguna()
{
   cout << "############# object_fungsi_yang_ditentukan_pengguna ################" << endl;
   vector<int> coll = { 1,2,3,4,5,6,7,8,9 };

   //print 3d dinaikan ke kekuatan semua elemen
   transform(coll.begin(), coll.end(),            //source
             ostream_iterator<float>(cout, " "),  //destination
             bind(fopow<float,int>(), 3, _1));    //opration
   cout << endl;

   //print all element dinaikan ke kekuatan 3
   transform(coll.begin(), coll.end(),            //source
             ostream_iterator<float>(cout, " "),  //destination
             bind(fopow<float,int>(), _1, 3));    //opreration
   cout << endl;
   cout << endl;
}

int main()
{
   bindku();
   bind_call_global_function();
   bind_call_member_function();
   object_fungsi_yang_ditentukan_pengguna();
}
