#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

class Foo {
   public:
      Foo (tuple<int, float>) {
         cout << "Foo::Foo(tuple)" << endl;
      }
      template <typename... Args>

      Foo (Args... args) {
         cout << "Foo::Foo(args...)" << endl;
      }
};

int main()
{
    // create tupple t:
    tuple<int, float> t(1, 2.22);

    // lewati tuple secara keseluruhan ke konstruktor Foo:
    pair<int, Foo> p1(42, t);

    // lulus element tuple ke konstruktor foo:
    pair<int, Foo> p2(piecewise_construct, make_tuple(42), t);
}
