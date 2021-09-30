#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <deque>
using namespace std;

void mySample()
{
   cout << endl << "################ MY SAMPLE ###############" << endl << endl;
   vector<int> v;    //membuat vector kosong
   v.reserve(80);    //membuat memori cadangan 80 elemen

   vector<int> va(5);   //membuat vector dan menginisialiasai dengan lima nilai
                        //-panggilan lima kali onstruktor default tipe T

   vector<int> coll;

   //masukkan elemen ke vector
   for (int i=1; i<20; ++i)
      v.push_back(i);

   //menampilkan elemen vector
   for (auto elem : v)
      cout << elem << ' ';
   cout << endl;

   //menyalin coll menjadi salinan isi v
   coll.assign(v.begin(), v.end());

   //menampilkan elemen coll setelah tersalin
   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   //elemen akses
   cout << "coll[2]: " << coll[2] << endl;            //no range
   //cout << "coll.at[2]: " << coll.at[2] << endl;    //exception if out of range
   cout << "coll.front(): " << coll.front() << endl;  //return first elemen
   cout << "coll.back(): " << coll.back() << endl;      //return last elemen
   cout << "cool.size(): " << coll.size() << endl;

   //hapus elemen terakhir
   if (!coll.empty())
       coll.pop_back();

   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;

   //hapus elemen posisi 3
   vector<int>::iterator pos;
   pos = find(coll.begin(), coll.end(), 3);

   if (pos != coll.end())
       coll.erase(pos);

   for (auto elem : coll)
       cout << elem << ' ';
   cout << endl;


   //using vector as c-style array
   vector<char> ch;        //create vector as dynamic array of char
   ch.resize(41);          //buat ruang 41 karakter (termasuk '\0')

   strcpy(&ch[0], "hello, world");       //copy c-string into the vector
   printf("%s\n", &ch[0]);
   cout << endl;
   cout << endl;
}

void vectorku()
{
   cout << endl << "################ VECTORKU ###############" << endl << endl;
   //create empty vector for strings
   vector<string> sentence;

   //cadangan memori untuk 5 elemen untuk menghindari relokasi
   sentence.reserve(5);

   //append some elements
   sentence.push_back("Hello,");
   sentence.insert(sentence.end(), {"how","are","you","?"});

   //cetak elemen dengan spasi
   copy(sentence.cbegin(), sentence.cend(),
        ostream_iterator<string>(cout, " "));
   cout << endl;

   //print technical data
   cout << "  max_size(): " << sentence.max_size() << endl;
   cout << "  size()    : " << sentence.size() << endl;
   cout << "  capacity(): " << sentence.capacity() << endl;

   //swap elemen kedua dan keempat
   swap(sentence[1], sentence[3]);

   //masukkan elemen "always" sebelum elemen "?"
   sentence.insert(find(sentence.begin(), sentence.end(), "?"),
                                                     "always");

   //tetapkan (asign) "!" ke elemen terakhir
   sentence.back() = "!";

   //print elemen dengan spasi
   copy(sentence.cbegin(), sentence.cend(),
        ostream_iterator<string>(cout, " "));
   cout << endl;

   //print some technical data again
   cout << "  size()    :    " << sentence.size() << endl;
   cout << "  capacity():    " << sentence.capacity() << endl;

   cout << endl;

   //hapus dua elemen terakhir
   sentence.pop_back();
   sentence.pop_back();

   //kecilkan kapasitas (sejak c++11)
   sentence.shrink_to_fit();

   //print some technical data again
   cout << "  size()    :    " << sentence.size() << endl;
   cout << "  capacity():    " << sentence.capacity() << endl;
}

/*
Sebuah deque (diucapkan "dek") sangat mirip dengan vektor.
Ini mengelola elemen-elemennya dengan array dinamis, menyediakan
akses acak, dan memiliki antarmuka yang hampir sama dengan
vektor. Perbedaannya adalah dengan deque, array dinamis terbuka
di kedua ujungnya. Dengan demikian, sebuah deque cepat untuk
disisipkan dan dihapus di akhir dan awal
*/
void dequeku()
{
   cout << endl << "################ DEQUE ###############" << endl << endl;

   //create empaty deque of strings
   deque<string> coll;

   //masukan beberapa elemen
   coll.assign(3, string("string"));
   coll.push_back("last string");
   coll.push_front("first string");

   //print elemen dipisahkan dengan newline
   copy(coll.cbegin(), coll.cend(),
       ostream_iterator<string>(cout, "\n"));
   cout << endl;

   //remove first and last element
   coll.pop_front();
   coll.pop_back();

   //masukan 'another' ke setiap elemen tetapi yang pertama
   for (unsigned i=1; i<coll.size(); ++i)
       coll[i] = "another " + coll[i];

   //ubah elemen keempat elemen
   coll.resize(4, "resized string");

   //cetak elemen dipisah oleh newline
   copy(coll.cbegin(), coll.cend(),
        ostream_iterator<string>(cout, "\n"));
}

int main()
{
   mySample();
   vectorku();
   dequeku();
}
