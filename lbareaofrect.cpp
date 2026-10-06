#include <iostream>
using namespace std;
void Area(){
  int Length, Breadth, Area;

  cout << "Enter Length: ";
  cin >> Length;

  cout << "Enter Breadth: ";
  cin >> Breadth;

  Area = Length * Breadth;
  cout << "Area of rectangle = " << Area << endl;
}
int main(){
   Area();
   Area();

return 0;
}
