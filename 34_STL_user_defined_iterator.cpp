#include <iterator>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

//template kelas untuk memasukan iterator untuk kontainer asosiatif dan tidak terurut
template <typename Container>
class asso_insert_iterator : public iterator<output_iterator_tag,typename Container::value_type>
{
   protected:
     Container &container;  //container dimana elemen dimasukan

   public:
     //constructor
     explicit asso_insert_iterator(Container &c) : container(c) {
     }

     //assigment operator
     //-inserts nilai kedalam container/wadah
     asso_insert_iterator<Container> &operator = (const typename Container::value_type &value)
     {
        container.insert(value);
        return *this;
     }

     //dereferencing adalah no-op yang mengembalikan iterator itu sendiri
     asso_insert_iterator<Container> &operator*() {
        return *this;
     }

     //oprasi increment adalah no-op yang mengembalikan iterator itu sendiri
     asso_insert_iterator<Container> &operator++() {
        return *this;
     }
     asso_insert_iterator<Container> &operator++(int) {
        return *this;
     }
};

//fungsi kenyamanan untuk membuat inserter
template <typename Container>
inline asso_insert_iterator<Container> asso_inserter(Container &c)
{
   return asso_insert_iterator<Container>(c);
}

int main()
{
   unordered_set<int> coll;

   //create inserter for coll
   //-cara yang tidak nyaman
   asso_insert_iterator<decltype(coll)> iter(coll);

   //masukan elemen dengan antarmuka iterator yang biasa
   *iter = 1;
   iter++;
   *iter = 2;
   iter++;
   *iter = 3;
   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;

   //use inserter with an algorithm
   vector<int> vals = { 33, 67, -4, 13, 5, 2 };
   copy(vals.begin(), vals.end(),    //source
            asso_inserter(coll));    //destination

   for (auto elem : coll)
        cout << elem << ' ';
   cout << endl;
}
