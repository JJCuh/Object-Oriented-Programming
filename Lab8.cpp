//Justin Li

#include <iostream>
using namespace std;

//Precondition: n >= 0
double water(int n){
  if(n == 0){
    return 10;
  }
  return water(n - 1) / 2 + 1;
}

//Precondition: n > 0
bool isSorted(int a[], int n){
  //cout <<  a[n - 1] << " ";
  if(n == 1){
    cout << "true\n";
    return true;
  }
  if(a[n - 1] < a[n - 2]){
    cout << "false\n";
    return false;
  }
  return isSorted(a, n - 1);
}

int main(){
  for(int i = 0; i < 5; i++){
    cout << water(i) << endl;
  }

  int a[] = {1,2,3,3,4};
  int b[] = {2,5,1,6,7,8};
  isSorted(a, 5);
  isSorted(b, 6);

  return 0;
}
