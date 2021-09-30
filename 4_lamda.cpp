#include <functional>
#include <iostream>

std::function<int(int, int)> returnLamda()
{
   return [] (int x, int y) {
      return x * y;
   };
}

int main()
{
   auto lf = returnLamda();
   std::cout << lf(6, 7) << std::endl;
}
