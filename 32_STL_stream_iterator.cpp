#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

void ostream_iteratorku()
{
   cout << "\n############ ostream iterator ################\n";
   //buat iterator ostream untuk stream cout
   //-nilai dipisahkan oleh karakter baris baru
   ostream_iterator<int> intWriter(cout, "\n");

   //menulis elemen dengan antarmuka iterator yg biasa
   *intWriter = 42;
   intWriter++;
   *intWriter = 77;
   intWriter++;
   *intWriter = -5;

   //create collection dari 1-9
   vector<int> coll = { 1,2,3,4,5,6,7,8,9 };

   //tulis semua elemen tanpa pembatas
   copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout));
   cout << endl;

   //write all elements with " < " as delimiter
   copy(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " < "));
   cout << endl;
   cout << endl;
}

void istream_iteratorku()
{
   cout << "\n############ istream iterator ################\n";
   //create istream iterator that reads integers from cin
   istream_iterator<int> intReader(cin);

   //create end-of-stream iterator
   istream_iterator<int> intReaderEOF;

   //sambil bisa membaca token dengan istream iterator
   //-tulis dua kali
   while (intReader != intReaderEOF)
   {
       cout << "once:       " << *intReader << endl;
       cout << "once again: " << *intReader << endl;
       ++intReader;
   }
   cout << endl;
   cout << endl;
}

void gabungan()
{
   cout << "\n############ gabungan ################\n";

   istream_iterator<string> cinPos(cin);
   ostream_iterator<string> coutPos(cout, " ");

   //while input is not at the end of the file
   //-tulis setiap string ketiga
   while (cinPos != istream_iterator<string>())
   {
       //abaikan dua string berikut
       advance(cinPos, 2);

       //read dan write string ketiga
       if (cinPos != istream_iterator<string>())
           *coutPos++ = *cinPos++;
   }
   cout << endl;
   cout << endl;
}

int main()
{
   ostream_iteratorku();
//   istream_iteratorku();
   gabungan();
}
