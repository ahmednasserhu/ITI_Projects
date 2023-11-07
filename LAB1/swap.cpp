#include <iostream>
using namespace std;

void swapByValue(int num1, int num2);
void swapByAddress(int* num1, int* num2);
void swapByReference(int &num1, int &num2);
int main() {
  int x = 7;
  int y = 5;
  //swapByValue(x,y);
  //swapByAddress(&x,&y);
  swapByReference(x,y);
  cout << "x = " << x << " y = " << y << endl;
  
  
  return 0;
}
void swapByValue(int num1, int num2){
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    
    cout << "x = " << num1 << " y = " << num2 << endl;
    
  }
  
void swapByAddress(int* num1, int* num2){
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
  }
  
void swapByReference(int &num1, int &num2){
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
  }