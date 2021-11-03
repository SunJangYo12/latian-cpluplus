#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <string>
#include <iostream>
#include <cstdlib>  //minmax
using namespace std;

//INSERT_ELEMETS(collection, first, last)
//-isi nilai dari first ke last ke dalam koleksi
//-tidak ada rentang setengah terbuka
template <typename T>
inline void INSERT_ELEMENTS(T &coll, int first, int last)
{
   for (int i=first; i<=last; ++i)
        coll.insert(coll.end(), i);
}

//PRINT_ELEMENTS()
//-print oprasi optcstr string diikuti oleh
//-semua elemen koleksi coll
//-dipisahkan oleh spasi
template <typename T>
inline void PRINT_ELEMENTS(const T &coll, const string &optcstr="")
{
   cout << optcstr;
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
}

//PRINT_MAPPED_ELEMENTS()
//-print optcstr string opsional diikuti oleh
//-semua elemen koleksi key/value
//-dipisahkan oleh spasi
template <typename T>
inline void PRINT_MAPPED_ELEMENTS(const T &coll, const string &optcstr="")
{
   cout << optcstr;
   for (auto elem : coll)
        cout << '[' << elem.first
             << ',' << elem.second << "] ";
   cout << endl;
}

class MeanValue {
   private:
      long num;
      long sum;
   public:
      MeanValue() : num(0), sum(0) {
      }
      //function call
      //-memproses satu elemen lagi dari urutan
      void operator() (int elem) {
           num++;
           sum += elem;
      }
      //return mean value (implicit type conversion)
      operator double() {
           return static_cast<double>(sum) / static_cast<double>(num);
      }
};


void al_for_each()
{
   cout << endl;
   cout << "############ algoritma for_each() ############"<< endl;
   vector<int> coll;
   INSERT_ELEMENTS(coll, 1,9);

   //call print() for each element
   for_each(coll.cbegin(), coll.cend(),   //range
           [](int elem) {                 //operation
               cout << elem << ' ';
           });
   cout << endl;

   //tambahkan 10 ke setiap elemen
   for_each(coll.begin(), coll.end(),     //range
           [](int &elem) {                //operation
                elem += 10;
           });
   PRINT_ELEMENTS(coll);

   //tambahkan nilai elemen pertama ke setiap elemen
   for_each(coll.begin(), coll.end(),     //range
           [=](int &elem) {               //operation
//         [&](int &elem) {               //niali untuk ditambahkan akan berubah saat elemen diproses
                elem += *coll.begin();
           });
   PRINT_ELEMENTS(coll);

   vector<int> collMean;
   INSERT_ELEMENTS(collMean, 1,8);
   cout << "mean init : ";
   PRINT_ELEMENTS(collMean);

   //process and print mean value
   double mv = for_each(collMean.begin(), collMean.end(),  //range
                                            MeanValue());  //operation
   cout << "mean value: " << mv << endl;
   cout << endl;
}

void al_count_if()
{
   cout << "############ algoritma count_if() ############"<< endl;
   vector<int> coll;
   int num;
   INSERT_ELEMENTS(coll, 1,9);
   PRINT_ELEMENTS(coll, "coll: ");

   //count element dengan nilai 4
   num = count(coll.cbegin(), coll.cend(),        //range
                                       4);        //value
   cout << "jumlah elemen sama dengan 4           : " << num << endl;

   //count element dengan nilai genap
   num = count_if(coll.cbegin(), coll.cend(),     //range
                 [](int elem) {                   //criterion
                     return elem % 2 == 0;
                 });
   cout << "jumlah elemen dengan nilai genap      : " << num << endl;

   //count(hitung) elemen yang lebih besar dari nilai 4
   num = count_if(coll.cbegin(), coll.cend(),     //range
                 [](int elem) {
                     return elem > 4;
                 });
   cout << "jumlah elemen yang lebih beesar dari 4: " << num << endl;
   cout << endl;
}

bool absLess(int elem1, int elem2)
{
   return abs(elem1) < abs(elem2);
}
void al_min_max()
{
   cout << "############ algoritma minmax ############"<< endl;
   deque<int> coll;
   INSERT_ELEMENTS(coll, 2,6);
   INSERT_ELEMENTS(coll, -3,6);
   PRINT_ELEMENTS(coll);

   //process and print minimum and maximum
   cout << "minimum: " << *min_element(coll.cbegin(), coll.cend()) << endl;
   cout << "maximum: " << *max_element(coll.cbegin(), coll.cend()) << endl;

   //print min dan max serta jaraknya menggunakan minmax_element()
   auto mm = minmax_element(coll.cbegin(), coll.cend());
   cout << "min: " << *(mm.first) << endl;
   cout << "max: " << *(mm.second) << endl;
   cout << "distance: " << distance(mm.first, mm.second) << endl;

   //proses dan prunt minimum dan maximum nilai absolut
   cout << "minimum of absolute values: "
        << *min_element(coll.cbegin(), coll.cend(), absLess) << endl;
   cout << "maximum of absolute values: "
        << *max_element(coll.cbegin(), coll.cend(), absLess) << endl;

   cout << endl;

   /* NOTE:
   perhatikan bahwa algoritma masing-masing mengembalikan
   posisi elemen maximum atau minimum. Dengan demikian
   anda harus menggunakan operator unary * untuk mencetak
   nilai-nilai mereka
   */
}

//cek apakah suatu elemen aneh atau bukan
bool checkEven(int elem, bool even)
{
   if (even)
      return elem % 2 == 0;
   else
      return elem % 2 == 1;
}
void al_find()
{
   cout << "############ algoritma find ############"<< endl;
   cout << "--- search first matching element ---" << endl;

   list<int> coll;
   INSERT_ELEMENTS(coll, 1,9);
   INSERT_ELEMENTS(coll, 1,9);

   PRINT_ELEMENTS(coll, "coll: ");

   //temukan elemen pertama dengan nilai 4
   list<int>::iterator pos1;
   pos1 = find(coll.begin(), coll.end(),  //range
                                     4);  //value

   //temukan elemen kedua dengan nilai 4
   list<int>::iterator pos2;
   if (pos1 != coll.end()) {
       pos2 = find(++pos1, coll.end(),    //range
                                   4);    //value
   }

   //print semua elemen dari pertama kedua 4(keduanya termasuk)
   //-Note: sekarang kita membutuhkan posisi 4 pertama lagi(jika ada)
   if (pos1 != coll.end() && pos2 != coll.end())
   {
       copy(--pos1, ++pos2, ostream_iterator<int>(cout, " "));
       cout << endl;
   }

   cout << endl;

   vector<int> collku;
   vector<int>::iterator posku;

   INSERT_ELEMENTS(collku, 1,9);
   PRINT_ELEMENTS(collku, "coll: ");

   //temukan elemen pertama yang lebih besar dari 3
   posku = find_if(collku.begin(), collku.end(),   //range
               bind(greater<int>(), placeholders::_1, 3));   //critarion

   //print its position
   cout << "the " << distance(collku.begin(), posku) + 1
        << ". element adalah yang pertama lebih dari 3" << endl;

   //temukan elemen pertama yang dibagi dengan 3
   posku = find_if(collku.begin(), collku.end(),
                  [](int elem) {
                       return elem % 3 == 0;
                  });

   //print its position
   cout << "the "
        << distance(collku.begin(), posku) + 1
        << ". element adalah yang pertama dibagi dengan 3" << endl;

   //temukan elemen pertama tidak < 5
   posku = find_if_not(collku.begin(), collku.end(),
                       bind(less<int>(), placeholders::_1, 5));
   cout << "first value >= 5: " << *posku << endl;
   cout << endl;

   cout << "--- search first n matching consecutive element ---" << endl;
   deque<int> collmu;
   collmu = { 1,2,7,7,6,3,9,5,7,7,7,3,6 };
   PRINT_ELEMENTS(collmu);

   //temukan tiga elemen berturut turut dengan nilai 7
   deque<int>::iterator posmu;
   posmu = search_n(collmu.begin(), collmu.end(),    //range
                                               3,    //count
                                              7);    //value

   //print result
   if (posmu != collmu.end()) {
       cout << "tiga elemen berturut-turut dengan nilai 7 "
            << "mulai dari " << distance(collmu.begin(), posmu) + 1
            << ". element" << endl;
   }
   else {
       cout << "tidak ada empat elemen berturut-turut dengan nilai 7 ditemukan" << endl;
   }

   //cari empat elemen aneh berturut-turut
   posmu = search_n(collmu.begin(), collmu.end(),     //range
                                               4,     //count
                                               0,     //value
                    [](int elem, int value) {
                           return elem % 2 == 1;
                    });

   //print result
   if (posmu != collmu.end()) {
       cout << "empat elemen pertaman aneh perturut-turut: ";
       for (int i=0; i<4; ++i,++posmu)
            cout << *posmu << ' ';
   }
   else {
       cout << "tidak ada empat elemen berturut-turut dengan nilai > 3 ditemukan";
   }
   cout << endl;
   cout << endl;

   cout << "--- search first subrange ---" << endl;

   deque<int> collx;
   list<int> subcoll;

   INSERT_ELEMENTS(collx, 1,7);
   INSERT_ELEMENTS(collx, 1,7);
   INSERT_ELEMENTS(subcoll, 3,6);

   PRINT_ELEMENTS(collx, "collx:  ");
   PRINT_ELEMENTS(subcoll,"subcoll:  ");

   //cari kejadian pertama subcoll di collx
   deque<int>::iterator posx;
   posx = search(collx.begin(), collx.end(),      //range
                 subcoll.begin(), subcoll.end()); //subrange

   //while loop subcoll ditemukan sebagai subrange dari collx
   while (posx != collx.end())
   {
       //print elemen posisi pertama
       cout << "subcoll ditemukan dimulai dengan elemen "
            << distance(collx.begin(), posx) + 1 << endl;

       //cari kejadian berikutnya dari subcoll
       ++posx;
       posx = search(posx, collx.end(),                 //range
                     subcoll.begin(), subcoll.end());   //subrange
   }
   cout << endl;

   vector<int> colly;
   INSERT_ELEMENTS(colly, 1,9);
   PRINT_ELEMENTS(colly, "colly: ");

   //arguments for checkEven()
   //-check for: even odd even(bahkan aneh bahkan)
   bool checkEvenArgs[3] = { true, false, true };

   //cari subrange pertama di colly
   vector<int>::iterator posy;
   posy = search(colly.begin(), colly.end(),      //range
                 checkEvenArgs, checkEvenArgs+3, //subrange values
                 checkEven);                     //subrange criterion

   //loop saat subrange ditemukan
   while (posy != colly.end())
   {
       //print posisi elemen pertama
       cout << "subrange ditemukan dimulai dengan elemen "
            << distance(colly.begin(), posy) + 1 << endl;

       //cari subrange berikutnya dalam colly
       posy = search(++posy, colly.end(),             //range
                     checkEvenArgs, checkEvenArgs+3,  //subr. values
                     checkEven);                      //subr. criterion
   }
   cout << endl;
   cout << "--- search last subrange ---" << endl;
   deque<int> collz;
   list<int> subcollz;

   INSERT_ELEMENTS(collz, 1,7);
   INSERT_ELEMENTS(collz, 1,7);
   INSERT_ELEMENTS(subcollz, 3,6);

   PRINT_ELEMENTS(collz,    "collz   : ");
   PRINT_ELEMENTS(subcollz, "subcollz: ");

   //cari kejadian terakhir subcollz di collz
   deque<int>::iterator posz;
   posz = find_end(collz.begin(), collz.end(),        //range
                   subcollz.begin(), subcollz.end()); //subrange

   //loop while subcollz ditemukan sebagai subrange of collz
   deque<int>::iterator end(collz.end());
   while(posz != end)
   {
      //cetak posisi elemen pertama
      cout << "subcoll ditemukan dimulai dengan elemen "
           << distance(collz.begin(), posz) + 1 << endl;

      //cari kejadian berikutnya dari subcollz
      end = posz;
      posz = find_end(collz.begin(), end,                 //range
                      subcollz.begin(), subcollz.end());  //subrange
   }
   cout << endl;

   cout << "--- search first of several posible elements ---" << endl;
   vector<int> colla;
   list<int> searchcolla;

   INSERT_ELEMENTS(colla, 1,11);
   INSERT_ELEMENTS(searchcolla, 3,5);

   PRINT_ELEMENTS(colla,       "colla      : ");
   PRINT_ELEMENTS(searchcolla, "searchcolla: ");

   //cari kejadian pertaman dari elemen searchcolla di colla
   vector<int>::iterator posa;
   posa = find_first_of(colla.begin(), colla.end(),    //range
                        searchcolla.begin(),           //awal set pencarian
                        searchcolla.end());            //akhir set pencarian

   cout << "elemen pertaman dari searchcolla di colla adalah elemen "
        << distance(colla.begin(), posa) +1 << endl;

   //cari kejadian terakhir dari elemen searchcolla dicolla
   vector<int>::reverse_iterator rposa;
   rposa = find_first_of(colla.rbegin(), colla.rend(),   //range
                                   searchcolla.begin(),  //awal set pencarian
                                   searchcolla.end());   //akhir set pencarian

   cout << "elemen terakhir dari searchcolla dicolla adalah elemen "
        << distance(colla.begin(), rposa.base()) << endl;
   cout << endl;

}

int main()
{
   al_for_each();
   al_count_if();
   al_min_max();
   al_find();
}
