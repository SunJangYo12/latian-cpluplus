#include <vector>
#include <algorithm>
#include <deque>
#include <functional>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;

// simple function object that prints the passet argument
class PrintInt {
   public:
      void operator() (int elem) const {
           cout << elem << ' ';
      }
};

void add10(int &elem)
{
   elem += 10;
}

template <int theValue>
void addBebas(int &elem)
{
   elem += theValue;
}

//Object fungsi yang menambahkan nilai yang diinisialisasi
class AddValue {
   private:
      int theValue; //the value to add
   public:
      //Konstruktor minginisialisasi nilai untuk menambah
      AddValue(int v) : theValue(v) {
      }

      //Panggilan fungsi untuk elemen menambah nilai
      void operator() (int &elem) const {
          elem += theValue;
      }
};

void function_object()
{
   cout << endl;
   cout << "######### FUNCTION OBJECT ########";
   cout << endl;
   vector<int> coll;

   //masukan elemen dari 1-9
   for (int i=1; i<=9; ++i)
       coll.push_back(i);

   //print all elements
   for_each(coll.cbegin(), coll.cend(), // range
                           PrintInt()); // operation
   cout << endl;

   //Menambahkan operation menggunkana fungsi biasa
   for_each(coll.begin(), coll.end(),   // range
                              add10);   // operation
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   //Menambakna operation menggunakan fungsi object
   for_each(coll.begin(), coll.end(),   // range
                         addBebas<10>); // operation

   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   //Sama kaya diatas tapi berbeda
   for_each(coll.begin(), coll.end(),   // range
                       AddValue(10));   // operation
   cout << "after adding 10: ";
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   //tambah satu
   for_each(coll.begin(), coll.end(),   // range
              AddValue(*coll.begin())); //operation

   cout << "after adding first element: ";
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;
   cout << endl;

}

void predefined_function_object()
{
   cout << "######### PREDEFINED FUNCTION OBJECT ########";
   cout << endl;
   deque<int> coll = { 1,2,3,5,7,11,13,17,19 };
   cout << "initialized: ";
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   // negate all values in coll / Meniadakan semua nilai dalam coll
   transform(coll.cbegin(), coll.cend(),   //source
                          coll.begin(),    //destination
                          negate<int>());  //operation
   cout << "negated: ";
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   // square all values in coll /
   transform(coll.cbegin(), coll.cend(),   //source
                            coll.cbegin(), //second source
                            coll.begin(),  //destination
                            multiplies<int>()); //oprtation

   cout << "squared: ";
   for(auto elem : coll)
       cout << elem << ' ';
   cout << endl;
   cout << endl;
}

//Binder atau pengikat
void binders()
{
   cout << endl;
   cout << "######### BINDER ########";
   cout << endl;

   set<int, greater<int>> coll1 = { 1,2,3,4,5,6,7,8,9};
   deque<int> coll2;

   // Note: due to the sorting criterion greater<>() elements have reverse order:
   cout << "initialized: ";
   for (auto elem : coll1)
      cout << elem << ' ';
   cout << endl;

   //transform all elements into coll2 by multiplying them with 10
   //translate:
   //ubah semua elemen ke dalam coll2 dengan mengalikan dengan 10
   transform(coll1.cbegin(), coll1.cend(),    //source
                   back_inserter(coll2),    //destination
                   bind(multiplies<int>(), placeholders::_1, 10)); //operation
   cout << "transformed: ";
   for (auto elem : coll2)
       cout << elem << ' ';
   cout << endl;

   //Ganti nilai sama dengan 70 dengan 42
   replace_if(coll2.begin(), coll2.end(),                //range
           bind(equal_to<int>(), placeholders::_1, 70),  //replace criterion
                                                   42);  //new value
   cout << "replaced: ";
   for (auto elem : coll2)
       cout << elem << ' ';
   cout << endl;

   //Hapus semua elemen dengan nilai antara 50 dan 80
   coll2.erase(remove_if(coll2.begin(), coll2.end(),
               bind(logical_and<bool>(),
                      bind(greater_equal<int>(), placeholders::_1, 50),
                          bind(less_equal<int>(),placeholders::_1, 80)
                      )
               ),
               coll2.cend());

   cout << "removed: ";
   for (auto elem : coll2)
       cout << elem << ' ';
   cout << endl;

   //Simple
   auto f = bind(multiplies<int>(), placeholders::_1, 10);
   cout << f(99) << endl;

   cout << endl;
   cout << endl;
}

int main()
{
   function_object();
   predefined_function_object();
   binders();
}
