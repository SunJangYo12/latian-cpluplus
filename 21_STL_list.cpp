#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <forward_list>
using namespace std;

void printLists(const list<int> &l1, const list<int> &l2)
{
    cout << "list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;
}

void printListForward(const string &s, const forward_list<int> &l1,
                                        const forward_list<int> &l2)
{
    cout << s << endl;

    cout << " list1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
    cout << endl;

    cout << " list2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
    cout << endl;
}

void listku()
{
    cout << endl<< "###### LIST ######" << endl << endl;
    //create two empty lists
    list<int> list1, list2;

    //isi kedua list dengan elemen
    for (int i=0; i<6; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    printLists(list1, list2);

    //masukkan semua elemen list1 sebelum elemen pertama
    //dengan nilai 3 dari list2
    //-find() mengembalikan iterator ke elemen pertama dg nilai 3
    list2.splice(find(list2.begin(), list2.end(),   //destination position
                                              3),
                                          list1);   //source list
    printLists(list1, list2);

    //pindahkan elemen pertama dari list2 sampai akhir
    list2.splice(list2.end(),       //destination position
                 list2,             //source list
                 list2.begin());    //source position

    printLists(list1, list2);

    //sortir list kedua, tetapkan ke list1 dan hapus duplicat
    list2.sort();
    list1 = list2;
    list2.unique();
    printLists(list1, list2);

    //gabungkan kedua list yang diurutkan kedalam list pertama
    list1.merge(list2);
    printLists(list1, list2);
}

// adalah list super ringan tapi di hanya bisa maju
void mySample_forward_listku()
{
    cout << endl<< "###### SAMPLE FORWARD LIST ######" << endl << endl;
    forward_list<int> list = { 1,2,3,4,5,97,98,99 };

    bool useSimple = true;    //sejak c++11

    //temukan posisi sebelum elemen genap pertama
    auto posBefore = list.before_begin();
    if (!useSimple) {
       for (auto pos = list.begin(); pos!=list.end(); ++pos,++posBefore)
       {
           if (*pos % 2 == 0)
              break;  //elemen found
       }
    }
    else {
       for (; next(posBefore) != list.end(); ++posBefore)
       {
          if (*next(posBefore) % 2 == 0)
              break;  //elemen found
       }
    }

    //dan masukan elemen baru didepan elemen genap pertama
    list.insert_after(posBefore, 42);

    //print list
    for (auto elem : list)
        cout << elem << ' ';
    cout << endl;
}
void mySample_forward_list_spliceku()
{
    cout << endl<< "###### SAMPLE FORWARD LIST SPLICE ######" << endl << endl;
    forward_list<int> l1 = { 1,2,3,4,5 };
    forward_list<int> l2 = { 97,98,99 };

    bool useSimple = false;

    if (!useSimple)
    {
        //cari 3 di list l1
        auto pos1 = l1.before_begin();
        for (auto pb1=l1.begin(); pb1 != l1.end(); ++pb1,++pos1)
        {
           if (*pb1 == 3)
              break;   //found
        }

        //cari 99 di list l2
        auto pos2 = l2.before_begin();
        for (auto pb2=l2.begin(); pb2 != l2.end(); ++pb2,++pos2)
        {
           if (*pb2 == 99)
              break;   //found
        }

        //sambungan 3 dari l1 ke l2 sebelum 99
        l1.splice_after(pos2, l2,    //destination
                        pos1);       //source
    }
/*    else {
        l1.splice_after(l2.find_before(99), 12,  //destination
                        l1.find_before(3));      //source
    }
*/
    cout << "l1: ";
    for (auto elem : l1)
        cout << elem << ' ';
    cout << endl;

    cout << "l2: ";
    for (auto elem : l2)
        cout << elem << ' ';
    cout << endl;
}

void forward_listku()
{
    cout << endl<< "###### FORWARD LIST ######" << endl << endl;
    //create two forward lists
    forward_list<int> list1 = { 1,2,3,4 };
    forward_list<int> list2 = { 77,88,99 };
    printListForward("initial: ", list1, list2);

    //masukan 6 elmen baru di awal list2
    list2.insert_after(list2.before_begin(), 99);
    list2.push_front(10);
    list2.insert_after(list2.before_begin(), {10,11,12,13} );
    printListForward("6 new elems: ", list1, list2);

    //masukan semua elemen list2 diawal list1
    list1.insert_after(list1.before_begin(),
                       list2.begin(), list2.end());
    printListForward("list2 into list1: ", list1, list2);

    //hapus elemen kedua setelah elemen bernilai 99
    list2.erase_after(list2.begin());
    list2.erase_after(find(list2.begin(), list2.end(),
                                                  99),
                                          list2.end());
    printListForward("delete 2nd and after 99: ", list1, list2);

    //sortir list1, tetapkan ke list2 dan hapus duplicat
    list1.sort();
    list2 = list1;
    list2.unique();
    printListForward("sorted and unique: ", list1, list2);

    //gabungkam kedua list yg diurutkan ke dalam list1
    list1.merge(list2);
    printListForward("merged: ", list1, list2);
}

int main()
{
    listku();
    mySample_forward_listku();
    mySample_forward_list_spliceku();
    forward_listku();
}
