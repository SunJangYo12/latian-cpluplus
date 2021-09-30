#include <iostream>

int main() {

   for (int i : { 2, 3, 5, 7, 9, 13, 17, 19 } ) // print single sum
   {
       std::cout << "Single sum: " << i << std::endl;
   }

   int array[] = { 1, 2, 3, 4, 5 };
   long sum = 0; // proses jumlah semua elemen
   for (int x : array) {
       sum += x;
   }
   for (auto elem : { sum, sum*2, sum*4 }) // print multiple of sum
   {
       std::cout << "Multiple sum: " << elem << std::endl;
   }

   return 0;
}
