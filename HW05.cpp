//Justin Li

#include <iostream>
using namespace std;

//#1
//Precondition: n >= 0
int recRetFib(int n){
  if (n < 0){
    cout << "Illegal argument in Fibonacci sequence.\n";
    exit(1);
  }
  else if (n > 1){
    return recRetFib(n - 2) + recRetFib(n - 1);
  }
  else { //n == 0 || 1
    return 1;
  }
}

//#2
//Precondition: n > 0, r > 0, n >= r
int C(int n, int r){
  if (n < 1 || r < 1 || n < r){
    cout << "Illegal arguments. Conditions: (n > 0, r > 0, n >= r)\n";
    exit(1);
  }
  else if (n > 1 && r > 1){
    return C(n - 1, r - 1) * n / r;
  }
  else if (n > 1){
    return C(n - 1, r) * n / (n - r);
  }
  else {
    return 1;
  }
}

//#3
//Precondition: n > 0
void TOH(int n, char first, char second, char third)
{
  if(n < 1){
    cout << "Error. (n < 1)";
  }
  else if(n > 1){
    TOH(n - 1, first, third, second);
  	cout << "Move Disk " << n << " from post " << first << " to post " << second << endl;
  	TOH(n - 1, third, second, first);
  }
  else{ //n == 1
		cout << "Move Disk " << n << " from post " << first << " to post " << second << endl;
  }
}

//#4
//Precondition: n >= 0
int itRetFib(int n){
  if (n < 0){
    cout << "Illegal argument in Fibonacci sequence.\n";
    exit(1);
  }
  int first = 0;
  int sum = 1;
  int temp = 0;
  for(int i = 0; i < n; i++){
    temp = sum;
    sum += first;
    first = temp;
  }
  return sum;
}

//#5
//Precondition: n >= 0
int arrRetFib(int n){
  int arr[n];
  arr[0] = 0;
  if (n < 0){
    cout << "Illegal argument in Fibonacci sequence.\n";
    exit(1);
  }
  else if (n > 1){
    arr[n - 1] = arrRetFib(n - 2);
    return arr[n - 1] + arrRetFib(n - 1);
  }
  else { //n == 0 || 1
    return 1;
  }
}

//#6

int main(){
  //testing #1
  for(int i = 1; i < 16; i += 2){
    cout << recRetFib(i) << " ";
  }
  cout << endl;

  //testing #2
  for(int i = 1; i <= 10; i++){
    cout << C(10, i) << " ";
  }
  cout << endl;

  //testing #3
  TOH(5, 'A', 'B', 'C');

  //testing #4
  for(int i = 1; i < 16; i += 2){
    cout << itRetFib(i) << " ";
  }
  cout << endl;

  //testing #5
  for(int i = 1; i < 16; i += 2){
    cout << arrRetFib(i) << " ";
  }
  cout << endl;

  //#6
  char board[4][4] = {{'A', 'B', 'C', 'D'}, {'E', 'F', 'G', 'H'}, {'I', 'J', 'J', 'K'}, {'L', 'M', 'N', 'O'}};
  return 0;
}
