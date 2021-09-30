#include <iostream>

using namespace std;

class CRectangle {
     int x, y;
   public:
     void setvalue(int, int);
     int area() {
         return (x * y);
     }
};
void CRectangle::setvalue(int a, int b) {
   x = a;
   y = b;
}

int main() {
   CRectangle rect, rectb;
   rect.setvalue(2, 4);
   rectb.setvalue(3, 5);
   cout << "area: " << rect.area() << endl;
   cout << "areab: " << rectb.area() << endl;

   return 0;
}
