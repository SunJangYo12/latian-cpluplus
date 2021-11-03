#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cctype>
using namespace std;

void mySample()
{
   cout << "####### MYSAMPLE #######" << endl;
   map<string,float> coll;    //empaty collection

   //masukkan "otto"/7.7 adalahkey/value
   //-pertama, ia menyisipkan "otto"/float()
   //-maka itu menetapkan 7.7
   coll["otto"] = 7.7;

   cout << coll["otto"] << endl;
   cout << endl;
   cout << endl;
}

void mapku()
{
   cout << "####### mapku #######" << endl;
   map<string,double> coll { {"tim", 9.9},
                             {"struppi", 11.77}
                           };

   //square/kuadrat nilai setiap elemen:
   for_each(coll.begin(), coll.end(),
            [](pair<const string,double> &elem) {
                    elem.second *= elem.second;
            });

   //print each element:
   for_each(coll.begin(), coll.end(),
            [](const map<string,double>::value_type &elem) {
                    cout << elem.first << ": " << elem.second << endl;
            });
   cout << endl;
   cout << endl;
}

void map_array_asosiatif()
{
   cout << "####### map_array_asosiatif #######" << endl;
   //buat map/assosiatif array
   //-keys are strings
   //-values are floats
   typedef map<string,float> StringFloatMap;

   StringFloatMap stocks;   //create empaty container

   //masukan beberapa elemen
   stocks["BASF"] = 369.50;
   stocks["VW"] = 413.50;
   stocks["Daimler"] = 819.00;
   stocks["BMW"] = 834.50;
   stocks["Siemens"] = 342.20;

   //print all elements
   StringFloatMap::iterator pos;
   cout << left;   //left-adjust values
   for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
   }
   cout << endl;

   //boom (all pricess doubled)
   for (pos = stocks.begin(); pos != stocks.end(); ++pos)
        pos->second *= 2;

   //print all elements
   for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
   }
   cout << endl;

   //rename key from "VM" to "Volkswagen"
   //-disediakan hanya dengan bertukar elemen
   stocks["Volkswagen"] = stocks["VW"];
   stocks.erase("VW");

   //print all elements
   for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << setw(12) << pos->first
             << "price: " << pos->second << endl;
   }
   cout << endl;
   cout << endl;
}

void multimap_sebagai_kamus()
{
   cout << "####### multimap_sebagai_kamus #######" << endl;
   //create multimap as string/string dictionary
   multimap<string,string> dict;

   //masukan beberapa elemen dalam urutan acak
   dict.insert( { {"day","Tag"}, {"strange","fremd"},
                  {"car","Auto"}, {"smart","elegant"},
                  {"trait","Merkmal"}, {"strange","seltsam"},
                  {"smart","raffiniert"}, {"smart","klug"},
                  {"clever","raffiniert"}
                }
              );

   //print all elements
   cout.setf(ios::left, ios::adjustfield);
   cout << ' ' << setw(10) << "english "
        << "german " << endl;

   cout << setfill('-') << setw(20) << ""
        << setfill(' ') << endl;

   for (const auto &elem : dict)
        cout << ' ' << setw(10) << elem.first << elem.second << endl;
   cout << endl;

   //print all value for key "smart"
   string word("smart");
   cout << word << ": " << endl;
   for (auto pos = dict.lower_bound(word);
             pos != dict.upper_bound(word);
             ++pos)
   {
        cout << "     " << pos->second << endl;
   }

   //print all value for key "raffiniert"
   word = ("raffiniert");
   cout << word << ": " << endl;
   for (const auto &elem : dict) {
       if (elem.second == word)
           cout << "      " << elem.first << endl;
   }
   cout << endl;
   cout << endl;
}
void menemukan_elemen_dengan_nilai_tertentu()
{
   cout << "############# menemukan_elemen_dengan_nilai_tertentu" << endl;
   //map with floats as key and value
   //-inisialisasi keys dan values secara otomatis dikonversi menjadi float
   map<float,float> coll = { {1,7}, {2,4}, {3,2}, {4,3},
                             {5,6}, {6,1}, {7,3}
                           };

   //search an element with key 3.0 (logarithmic complexity)
   auto posKey = coll.find(3.0);
   if (posKey != coll.end()) {
       cout << "key 3.0 found ("
            << posKey->first << ":"
            << posKey->second << ")"
            << endl;
   }

   //search an element with value 3.0 (linier complexity)
   auto posVal = find_if(coll.begin(), coll.end(),
                         [] (const pair<float,float> &elem) {
                             return elem.second == 3.0;
                         });
   if (posVal != coll.end()) {
        cout << "value 3.0 found ("
             << posVal->first << ":"
             << posVal->second << ")"
             << endl;
   }
   cout << endl;
   cout << endl;
}

/*
Contohnya di sini adalah untuk programmer lanjutan
daripada pemula STL. Anda dapat menganggapnya sebagai
contoh kekuatan dan masalah STL. Secara khusus, contoh ini
menunjukkan teknik berikut:
- Cara menggunakan map, termasuk antarmuka array asosiatif
- Cara menulis dan menggunakan objek fungsi
- Cara menentukan kriteria penyortiran saat runtime
- Cara membandingkan string dengan cara yang tidak sensitif
*/

//fungsi object untuk membandingkan string
//-memungkinkan anda mengatur kriteria perbandingan saat runtime
//-memungkinkan anda membandingkan huruf peka besar/kecil
class RuntimeStringCmp {
    public:
        //konstanta untuk kriteria perbandingan
        enum cmp_mode {normal, nocase};
    private:
        //mode perbandingan aktual
        const cmp_mode mode;

        //fungsi tambahan untuk membandingkan huruf peka besar/kecil
        static bool nocase_compare(char c1, char c2) {
            return toupper(c1) < toupper(c2);
        }
    public:
        //konstructor: menginisialisasi kriteria perbandingan
        RuntimeStringCmp(cmp_mode m = normal) : mode(m) {
        }

        //the comparison
        bool operator() (const string &s1, const string &s2) const {
            if (mode == normal) {
                return s1 < s2;
            }
            else {
                return lexicographical_compare(s1.begin(), s1.end(),
                                               s2.begin(), s2.end(),
                                               nocase_compare);
            }
        }
};

//container type:
//-map with
//  -string keys
//  -string values
//  -jenis objeck perbandingan khusus
typedef map<string,string,RuntimeStringCmp> StringStringMap;

//fungsi yang mengisi dan mencetak container tersebut
void fillAndPrint(StringStringMap &coll)
{
   //masukan elemen dalam urutan acak
   coll["Deutschland"] = "Germany";
   coll["deutsch"] = "Germany";
   coll["Haken"] = "snag";
   coll["arbeiten"] = "work";
   coll["Hund"] = "dog";
   coll["gehen"] = "go";
   coll["Unternehmen"] = "enterprise";
   coll["Unternehmen"] = "undertake";
   coll["gehen"] = "walk";
   coll["Bestatter"] = "undertaker";

   //print elements
   cout.setf(ios::left, ios::adjustfield);
   for (const auto &elem : coll) {
        cout << setw(15) << elem.first << " "
             << elem.second << endl;
   }
   cout << endl;
}

//main advended
void advanded()
{
    cout << "########## Advended perbandingan string #########"<< endl;
    //buat container dengan kriteria perbandingan default
    StringStringMap coll1;
    fillAndPrint(coll1);

    //buat object untuk kasus perbandingan tidak sensitif
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

    //buat container dg kriteria perbandingan yg tidak sensitif
    StringStringMap coll2(ignorecase);
    fillAndPrint(coll2);
   cout << endl;
   cout << endl;
}
int main()
{
   mySample();
   mapku();
   map_array_asosiatif();
   multimap_sebagai_kamus();
   menemukan_elemen_dengan_nilai_tertentu();
   advanded();
}
