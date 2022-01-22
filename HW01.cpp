//Justin Li

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//#1
class CounterType{
private:
  int count;

public:
  //sets variable count
  void setCounter(int count1){
    if(count1 < 0){
      cout << "invalid #, CounterType must be +, try again." << endl;
    }
    else{
      count = count1;
    }
  }

  //increments up 1
  void inCounter(){
    count++;
  }

  //increments down 1
  void deCounter(){
    if(count >= 1){
      count--;
    }
    else{
      cout << "CounterType must be +, so it cant be decreased at this value." << endl;
    }
  }

  //returns current count
  int getCounter(){
    return count;
  }

  //ouputs current count
  void output(){
    cout << "The count is " + to_string(count) + "." << endl;
  }
};

//#2
class Point{
private:
  double x;
  double y;

public:
  //sets the coords
  void set(double a, double b){
    x = a;
    y = b;
  }

  //moves x & y by c & d amount
  void move(double c, double d){
    x += c;
    y += d;
  }

  //rotates point 90 degrees clockwise around origin
  void rotateClockwise(){
    double tempx = x;
    x = y;
    y = -tempx;
  }

  //returns the point's x coord
  const double getx(){
    return x;
  }

  //returns the point's y coord
  const double gety(){
    return y;
  }

  //prints coords
  void printCoords(){
    cout << "(" + to_string(x) + "," + to_string(y) + ")" << endl;
  }
};

//#3
class GasPump{
private:
  double costPerGallon;
  int amountDispensed;
  double amountCharged;
  bool stopper;

public:
  //Constructors
  GasPump(): costPerGallon(3), amountDispensed(0), amountCharged(0), stopper(false){}

  GasPump(double a): costPerGallon(a), amountDispensed(0), amountCharged(0), stopper(false){}

  double getCostPerGallon(){
    return costPerGallon;
  }

  int getAmountDispensed(){
    return amountDispensed;
  }

  double getAmountCharged(){
    return amountCharged;
  }

  bool getStopper(){
    return stopper;
  }

  void reset(){
    amountDispensed = 0;
    amountCharged = 0;
    stopper = false;
  }

  void stop(){
    stopper = true;
  }

  void incAmountDispensed(){
    amountDispensed++;
    amountCharged = costPerGallon * amountDispensed;
  }
};

//#4
class Month{
private:
  int month;

public:
  Month(): month(1){}

  Month(char a, char b, char c){
    if(a == 'J' && b == 'a' && c == 'n'){
      month = 1;
    }
    else if(a == 'F' && b == 'e' && c == 'b'){
      month = 2;
    }
    else if(a == 'M' && b == 'a' && c == 'r'){
      month = 3;
    }
    else if(a == 'A' && b == 'p' && c == 'r'){
      month = 4;
    }
    else if((a == 'M' && b == 'a' && c == 'y')){
      month = 5;
    }
    else if(a == 'J' && b == 'u' && c == 'n'){
      month = 6;
    }
    else if(a == 'J' && b == 'u' && c == 'l'){
      month = 7;
    }
    else if(a == 'A' && b == 'u' && c == 'g'){
      month = 8;
    }
    else if(a == 'S' && b == 'e' && c == 'p'){
      month = 9;
    }
    else if(a == 'O' && b == 'c' && c == 't'){
      month = 10;
    }
    else if(a == 'N' && b == 'o' && c == 'v'){
      month = 11;
    }
    else if(a == 'D' && b == 'e' && c == 'c'){
      month = 12;
    }
    else{
      month = 1;
      cout << "Err: Unknown month";
    }
  }

  Month(int m){
    switch(m){
      case (1):
        month = m;
        break;
      case (2):
        month = m;
        break;
      case (3):
        month = m;
        break;
      case (4):
        month = m;
        break;
      case (5):
        month = m;
        break;
      case (6):
        month = m;
        break;
      case (7):
        month = m;
        break;
      case (8):
        month = m;
        break;
      case (9):
        month = m;
        break;
      case (10):
        month = m;
        break;
      case (11):
        month = m;
        break;
      case (12):
        month = m;
        break;
      default:
        month = 1;
        cout << "Err: month must be between 1 and 12";
    }
  }

  void setMonth(int m){
    month = m;
  }

  void setMonth(char a, char b, char c){
    if(a == 'J' && b == 'a' && c == 'n'){
      month = 1;
    }
    else if(a == 'F' && b == 'e' && c == 'b'){
      month = 2;
    }
    else if(a == 'M' && b == 'a' && c == 'r'){
      month = 3;
    }
    else if(a == 'A' && b == 'p' && c == 'r'){
      month = 4;
    }
    else if((a == 'M' && b == 'a' && c == 'y')){
      month = 5;
    }
    else if(a == 'J' && b == 'u' && c == 'n'){
      month = 6;
    }
    else if(a == 'J' && b == 'u' && c == 'l'){
      month = 7;
    }
    else if(a == 'A' && b == 'u' && c == 'g'){
      month = 8;
    }
    else if(a == 'S' && b == 'e' && c == 'p'){
      month = 9;
    }
    else if(a == 'O' && b == 'c' && c == 't'){
      month = 10;
    }
    else if(a == 'N' && b == 'o' && c == 'v'){
      month = 11;
    }
    else if(a == 'D' && b == 'e' && c == 'c'){
      month = 12;
    }
    else{
      cout << "Err: Unknown month";
    }
  }

  int getMonthInt(){
    return month;
  }

  string getMonthName(){
    switch(month){
      case (1):
        return "Jan";
        break;
      case (2):
        return "Feb";
        break;
      case (3):
        return "Mar";
        break;
      case (4):
        return "Apr";
        break;
      case (5):
        return "May";
        break;
      case (6):
        return "Jun";
        break;
      case (7):
        return "Jul";
        break;
      case (8):
        return "Aug";
        break;
      case (9):
        return "Sep";
        break;
      case (10):
        return "Oct";
        break;
      case (11):
        return "Nov";
        break;
      case (12):
        return "Dec";
        break;
    }
  }

  Month getNextMonth(){
    Month m;
    switch(month){
      case (1):
        m.month = month + 1;
        break;
      case (2):
        m.month = month + 1;
        break;
      case (3):
        m.month = month + 1;
        break;
      case (4):
        m.month = month + 1;
        break;
      case (5):
        m.month = month + 1;
        break;
      case (6):
        m.month = month + 1;
        break;
      case (7):
        m.month = month + 1;
        break;
      case (8):
        m.month = month + 1;
        break;
      case (9):
        m.month = month + 1;
        break;
      case (10):
        m.month = month + 1;
        break;
      case (11):
        m.month = month + 1;
        break;
      case (12):
        m.month = 1;
        break;
    }
  }
};

//#5
class Suitors{
private:
  vector<int> suitors;

public:
  //Constructor
  //Makes the vector of n # of Suitors
  //Finds the last remaining position of the suitors and prints it out
  Suitors(int n){
    for(int i = 0; i < n; i++){
      suitors.push_back(i + 1);
    }
    int currentPos = 0;
    while(suitors.size() > 1){
      currentPos += 2;
      while(currentPos >= suitors.size()){
        currentPos -= suitors.size();
      }
      suitors.erase(suitors.begin() + currentPos);
    }
    cout << "The position you should stand in to marry the princess if there are "
         << n << " suitors is " << suitors[0] << "." << endl;
  }
};

//#6
class ZipCode{
private:
  string code;

public:
  ZipCode(int c){
    int int1 = c / 10000 % 10;
    cout << int1 << endl;
    int int2 = c / 1000 % 10;
    cout << int2 << endl;
    int int3 = c / 100 % 10;
    cout << int3 << endl;
    int int4 = c / 10 % 10;
    cout << int4 << endl;
    int int5 = c % 10;
    cout << int5 << endl;
    int ints[] = {int1, int2, int3, int4, int5};
    code = "1";
    for(int i = 0; i < 5; i++){
      int count = 0;
      if(ints[i] >= 7 || ints[i] == 0 && count < 2){
        ints[i] -= 7;
        code += '1';
        count++;
      }
      else{
        code += '0';
      }
      if(ints[i] >= 4 || ints[i] == -7 && count < 2){
        ints[i] -= 4;
        code += '1';
        count++;
      }
      else{
        code += '0';
      }
      if(ints[i] >= 2 && count < 2){
        ints[i] -= 2;
        code += '1';
        count++;
      }
      else{
        code += '0';
      }
      if(ints[i] >= 1 && count < 2){
        ints[i] -= 1;
        code += '1';
        count++;
      }
      else{
        code += '0';
      }
      if(count < 2){
        code += '1';
      }
      else{
        code += '0';
      }
    }
    code += '1';
  }

  ZipCode(string c){
    code = c;
  }

  int getZipCodeInt(){
    string str1 = code.substr(1,5);
    string str2 = code.substr(6,5);
    string str3 = code.substr(11,5);
    string str4 = code.substr(16,5);
    string str5 = code.substr(21,5);
    string s[] = {str1, str2, str3, str4, str5};
    int zip;
    for(int i = 0; i < 5; i++){
      int sum = 0;
      sum += 7 * (s[i][0] - '0');
      sum += 4 * (s[i][1] - '0');
      sum += 2 * (s[i][2] - '0');
      sum += 1 * (s[i][3] - '0');
      sum += 0 * (s[i][4] - '0');
      if(sum == 11){
        sum = 0;
      }
      zip += sum * pow(10,4-i);
    }
    return zip;
  }

  string getZipCodeStr(){
    return code;
  }
};

int main(){
  //testing #1 here
  CounterType num;
  num.setCounter(100);//sets count to 100
  num.output();
  num.deCounter();//decreases to 99
  num.output();
  num.setCounter(100);//sets to 100 again
  num.inCounter();//increases to 101
  num.output();
  num.setCounter(-1);//doesn't set, err response
  num.output();
  num.setCounter(0);//sets to 0
  num.output();
  num.deCounter();//doesn't decrease, err response
  num.inCounter();//increases to 1
  num.output();
  num.deCounter();//decreases to 0
  num.output();
  num.deCounter();//doesn't decrease, err response
  num.output();

  //testing #2 here
  Point point();
  cout << point.getx() << endl;
  cout << point.gety() << endl;
  point.printCoords();
  point.set(1,2);
  point.printCoords();
  point.move(1,1);
  point.printCoords();
  point.rotateClockwise();
  point.printCoords();
  point.rotateClockwise();
  point.printCoords();
  point.rotateClockwise();
  point.printCoords();
  point.rotateClockwise();
  point.printCoords();

  //testing #3 here
  GasPump gasPump;
  cout << gasPump.getCostPerGallon() << endl;
  cout << gasPump.getAmountDispensed() << endl;
  cout << gasPump.getAmountCharged() << endl;
  gasPump.incAmountDispensed();
  gasPump.incAmountDispensed();
  cout << gasPump.getAmountDispensed() << endl;
  cout << gasPump.getAmountCharged() << endl;
  gasPump.reset();
  cout << gasPump.getAmountDispensed() << endl;
  cout << gasPump.getAmountCharged() << endl;

  //running #3 here
  GasPump gP;
  cout << "Hello, welcome to the gas station." << endl;
  cout << "The price per gallon of gas is $" << gP.getCostPerGallon() << "." << endl;
  char g = 'a';
  while(g != 'y' && g != 'n'){
    //Must answer y or n, or repeats
    cout << "Would you like to purchase some gas? Type 'y' for yes or 'n' for no." << endl;
    cin >> g;
    if(g == 'y'){
      gP.reset();
      gP.incAmountDispensed();
    }
    else if(g == 'n'){
      gP.stop();
    }
    else{
      cout << "Sorry, that is not a valid response. Try again and type either 'y' or 'n'." << endl;
    }
  }
  g = 'a';//resets g

  while(gP.getStopper() != true){
    cout << "Your car has been dispensed " << gP.getAmountDispensed() << " gallons and the amount charged is currently $" << gP.getAmountCharged() << "." << endl;
    while(g != 'y' && g != 'n'){
      //Must answer y or n, or repeats
      cout << "Would you like to add more gas? Type 'y' for yes or 'n' for no." << endl;
      cin >> g;
      if(g == 'y'){
        gP.incAmountDispensed();
      }
      else if(g == 'n'){
        gP.stop();
      }
      else{
        cout << "Sorry, that is not a valid response. Try again and type either 'y' or 'n'." << endl;
      }
    }
    g = 'a';//resets g
  }
  cout << "All done! You have received a total of " << gP.getAmountDispensed() << " gallons of gas and the total amount charged is $" << gP.getAmountCharged() << "." << endl;
  cout << "Thank you for purchasing our gas and we hope to see you again soon!" << endl;
  gP.reset();

  //testing #4 here
  Month month0;
  Month month1('M','a','y');
  Month month2(9);
  cout << month0.getMonthInt() << endl;
  cout << month1.getMonthInt() << endl;
  cout << month2.getMonthInt() << endl;
  cout << month0.getMonthName() << endl;
  cout << month1.getMonthName() << endl;
  cout << month2.getMonthName() << endl;
  cout << month0.getNextMonth().getMonthInt() << endl;
  cout << month1.getNextMonth().getMonthInt() << endl;
  cout << month2.getNextMonth().getMonthInt() << endl;
  month0.setMonth('F','e','b');
  month1.setMonth(11);
  cout << month0.getMonthInt() << endl;
  cout << month1.getMonthInt() << endl;
  cout << month0.getMonthName() << endl;
  cout << month1.getMonthName() << endl;
  cout << month0.getNextMonth().getMonthName() << endl;
  cout << month1.getNextMonth().getMonthName() << endl;

  //testing #5 here
  Suitors pwincess1(1);
  Suitors pwincess2(2);
  Suitors pwincess3(3);
  Suitors pwincess4(4);
  Suitors pwincess5(5);
  Suitors pwincess6(6);

  //testing #6 here
  ZipCode zipcode1("110100101000101011000010011");
  cout << zipcode1.getZipCodeStr() << endl;
  cout << zipcode1.getZipCodeInt() << endl;
  ZipCode zipcode2(99504);
  cout << zipcode2.getZipCodeStr() << endl;
  cout << zipcode2.getZipCodeInt() << endl;

  return 0;
}
