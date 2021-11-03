#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <memory>
using namespace std;

class Item {
    private:
      string name;
      float price;
    public:
      Item(const string &n, float p=0) : name(n), price(p) {
      }
      string getName() const {
          return name;
      }
      void setName(const string &n) {
          name = n;
      }
      float getPrice() const {
          return price;
      }
      void setPrice(float p) {
          price = p;
      }
};

template <typename Coll>
void printItems(const string &msg, const Coll &coll)
{
    cout << msg << endl;
    for (const auto &elem : coll) {
         cout << ' ' << elem->getName() << ": "
                     << elem->getPrice() << endl;
    }
}

//using shared pointers
int main()
{
    //dua barang berbagi koleksi yang berbeda
    typedef shared_ptr<Item> ItemPtr;
    set<ItemPtr> allItems;
    deque<ItemPtr> bestsellers;

    //insert object into the collections
    //-buku terlaris ada di kedua koleksi
    bestsellers = { ItemPtr(new Item("Kong Yize", 20.10)),
                    ItemPtr(new Item("A Midsummer Night's Dream", 14.99)),
                    ItemPtr(new Item("The Maltese Falcon", 9.88)) };

    allItems = { ItemPtr(new Item("Water", 0.44)),
                 ItemPtr(new Item("Pizza", 2.22)) };

    allItems.insert(bestsellers.begin(), bestsellers.end());

    //print contents of both collections
    printItems("bestsellers: ", bestsellers);
    printItems("all: ", allItems);
    cout << endl;

    //harga bestseller ganda
    for_each(bestsellers.begin(), bestsellers.end(),
             [] (shared_ptr<Item> &elem) {
                 elem->setPrice(elem->getPrice() * 2);
             });

    //ganti buku terlaris kedua dengan item pertama dengan nama "pizza"
    bestsellers[1] = *(find_if(allItems.begin(), allItems.end(),
                               [] (shared_ptr<Item> elem) {
                                   return elem->getName() == "Pizza";
                               }));
    //tetapkan harga bestseller pertama
    bestsellers[0]->setPrice(44.77);

    //print content
    printItems("bestsellers: ", bestsellers);
    printItems("all: ", allItems);
}

