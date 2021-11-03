#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class IntSequence {
   private:
      int value;
   public:
      IntSequence(int initialValue) : value(initialValue) {
      }
      int operator() () {    //function call
          return ++value;
      }
};

//The return value of for_each()
//Ini menunjukan cara memproses nilai rata-rata suatu urutan
//functio object to process the mean value
class MeanValue {
   private:
      long num;     //number of elements
      long sum;     //sum of all element values
   public:
      //constructor
      MeanValue () : num(0), sum(0) {
      }
      //function call
      //-process one more element of the sequence
      void operator() (int elem) {
          ++num;         //increment count
          sum += num;    //add value
      }

      //return mean value
      double value() {
          return static_cast<double>(sum) /
                 static_cast<double>(num);
      }
};

//functioon object that returns true for the nth call
class Nth {
   private:
      int nth;    //call for which to return true
      int count;  //call counter;
   public:
      Nth(int n) : nth(n), count(0) {
      }
      bool operator() (int) {
          return ++count == nth;
      }
};

void sequence1()
{
   cout << "############## sequence ##############" << endl;
   list<int> coll;

   //insert values from 1 to 9
   generate_n(back_inserter(coll),  //start
                                9,  //number of elements
                  IntSequence(1));  //generate values, starting with 1

   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;

   //ganti kedua ke elemen terakhir tetapi satu dengan nilai mulai dari 42
   generate(next(coll.begin()),   //start
            prev(coll.end()),     //end
            IntSequence(42));     //generate values, starting with 42

   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;

   IntSequence seq(1);      //urutan integral dimulai dg nilai 1
   generate_n(back_inserter(coll), 9, seq);

   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;

   //sisipkan urutan dimulai dengan 1 lagi
   generate_n(back_inserter(coll), 9, seq);
   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;
   cout << endl;
}

void sequence2()
{
   cout << "############## sequence2 ##############" << endl;
   list<int> coll;
   IntSequence seq(1);    //integral sequence starting with 1

   //insert value from 1 to 4
   //-pass function object by reference
   //-sehingga akan berlanjut dengan 5
   generate_n<back_insert_iterator<list<int>>, int,
              IntSequence &>(back_inserter(coll),   //start
                                               4,   //number of elements
                                            seq);   //generate values
   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;

   //insert values from 42 to 45
   generate_n(back_inserter(coll),      //start
                                4,      //number of elements
                 IntSequence(42));      //generate values

   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;


   //continue with first sequence
   //-pass function object by value
   //-sehingga akan berlanjut dengan 5 lagi
   generate_n(back_inserter(coll),      //start
                                4,      //number of elements
                             seq);      //generate values
   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;


   //continue with first sequence again
   generate_n(back_inserter(coll),      //start
                                4,      //number of elements
                             seq);      //generates values
   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;
   cout << endl;
}

void proses_nilai_rata2()
{
   cout << "############## MEAN PROCESS ##############" << endl;
   vector<int> coll = { 1,2,3,4,5,6,7,8 };

   //process and print mean value
   MeanValue mv = for_each(coll.begin(), coll.end(),   //range
                                       MeanValue());   //operaion

   cout << "mean value: " << mv.value() << endl << endl;
}

void predicate_vs_function_object()
{
   cout << "############## predicate vs functionobj ##############" << endl;
   list<int> coll = { 1,2,3,4,5,6,7,8,9,10 };

   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;

   //remove third element
   list<int>::iterator pos;
   pos = remove_if(coll.begin(), coll.end(),   //range
                                    Nth(3));   //remove criterion
   coll.erase(pos, coll.end());
   for (auto elem : coll) {
      cout << elem << ' ';
   }
   cout << endl;
   cout << endl;
}

int main()
{
   sequence1();
   sequence2();
   proses_nilai_rata2();
   predicate_vs_function_object();
}
