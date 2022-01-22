#include <iostream>
using namespace std;

struct Time{//military time, no am/pm
  int hour;
  int minute;
};

struct Carpool{
  string names[5];
  int numPeople;
  Time arrival;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

Carpool combineCarpool(Carpool car1, Carpool car2){
  Carpool car3;
  int combo;
  combo = car1.numPeople + car2.numPeople;
  if(combo <= 5){
    car3.numPeople = combo;
    car3.arrival = earlier(car1.arrival, car2.arrival);
    for(int i = 0; i < car1.numPeople; i++){
      car3.names[i] = car1.names[i];
    }
    for(int j = 0; j < car2.numPeople; j++){
      car3.names[car1.numPeople + j] = car2.names[j];
    }
  }
  return car3;
}

int main(){
  Carpool car1;
  car1.names[0] = "a";
  car1.names[1] = "b";
  car1.names[2] = "c";
  car1.numPeople = 3;
  car1.arrival.hour = 14;
  car1.arrival.minute = 0;

  Carpool car2;
  car2.names[0] = "d";
  car2.names[1] = "e";
  car2.numPeople = 2;
  car2.arrival.hour = 13;
  car2.arrival.minute = 0;

  for(int i = 0; i < car1.numPeople; i++){
    cout << car1.names[i] << endl;
  }
  cout << car1.numPeople << endl;
  cout << car1.arrival.hour << endl;
  cout << car1.arrival.minute << endl;

  for(int j = 0; j < car2.numPeople; j++){
    cout << car2.names[j] << endl;
  }
  cout << car2.numPeople << endl;
  cout << car2.arrival.hour << endl;
  cout << car2.arrival.minute << endl;

  Carpool car3 = combineCarpool(car1, car2);

  for(int k = 0; k < car3.numPeople; k++){
    cout << car3.names[k] << endl;
  }
  cout << car3.numPeople << endl;
  cout << car3.arrival.hour << endl;
  cout << car3.arrival.minute << endl;

  car1.arrival.hour = 5;
  car1.arrival.minute = 0;
  car2.arrival.hour = 5;
  car2.arrival.minute = 1;

  for(int i = 0; i < car1.numPeople; i++){
    cout << car1.names[i] << endl;
  }
  cout << car1.numPeople << endl;
  cout << car1.arrival.hour << endl;
  cout << car1.arrival.minute << endl;

  for(int j = 0; j < car2.numPeople; j++){
    cout << car2.names[j] << endl;
  }
  cout << car2.numPeople << endl;
  cout << car2.arrival.hour << endl;
  cout << car2.arrival.minute << endl;

  car3 = combineCarpool(car1, car2);

  for(int k = 0; k < car3.numPeople; k++){
    cout << car3.names[k] << endl;
  }
  cout << car3.numPeople << endl;
  cout << car3.arrival.hour << endl;
  cout << car3.arrival.minute << endl;
}
