#include <chrono>
#include <iostream>
#include <iomanip>

template <typename C>
void printClockData() {
   using namespace std;

   cout << "- precision: ";

   // jika unit kurang atau sama dg satu milidetik
   typedef typename C::period P;	// type of time unit
   if (ratio_less_equal<P, milli>::value)
   {
       // convert to and print as miliseconds
       typedef typename ratio_multiply<P, kilo>::type TT;
       cout << fixed << double(TT::num)/TT::den << " milliseconds" << endl;
   }
   else {
       // print as seconds
       cout << fixed << double(P::num)/P::den << " seconds" << endl;
   }
   cout << "- is_steady: " << boolalpha << C::is_steady << endl;
}

int main() {
   std::cout << "system_clock: " << std::endl;
   printClockData<std::chrono::system_clock>();

   std::cout << "\nhigh_resolution_clock: " << std::endl;
   printClockData<std::chrono::high_resolution_clock>();

   std::cout << "\nsteady_clock: " << std::endl;
   printClockData<std::chrono::steady_clock>();

   auto system_start = std::chrono::system_clock::now();
   auto diff = std::chrono::system_clock().now() - system_start;
   auto sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
   std::cout << "this program runs: " << sec.count() << " seconds" << std::endl;

}
