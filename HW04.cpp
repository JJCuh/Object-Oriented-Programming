//Justin Li

#include <iostream>
using namespace std;

//#1
//Precondition: a[lowEnd] through a{highEnd] are sorted in increasing order.
//Template parameter type must represent a number e.g. int or double
//Postcondition: If key isn't 1 of the values a[lowEnd] through a[highEnd], then found == false;
//otherwise, a[location] == true & found == true
template<class T>
void search1(const T a[], int lowEnd, int highEnd, T key, bool& found, int& location){
  int first = lowEnd;
  int last = highEnd;
  int mid;
  found = false;//so far
  while((first <= last) && !(found)){
    mid = (first + last)/2;
    if(key == a[mid]){
      found = true;
      location = mid;
      cout << location << endl;
    }
    else if(key < a[mid]){
      last = mid - 1;
    }
    else if(key > a[mid]){
      first = mid + 1;
    }
  }
  if(!found){
    cout << "false" << endl;
  }
}

//#2
//Precondition: a[lowEnd] through a{highEnd] are sorted in increasing order.
//Template parameter type must represent a number (e.g. int or double)
//Postcondition: If key isn't 1 of the values a[lowEnd] through a[highEnd], then found == false;
//otherwise, a[location] == true & found == true
template<class T>
void search2(const T a[], int first, int last, T key, bool& found, int& location){
  int mid;
  if(first > last){
    found = false;
    cout << "false" << endl;
  }
  else{
    mid = (first + last)/2;
    if(key == a[mid]){
      found = true;
      location = mid;
      cout << location << endl;
    }
    else if(key < a[mid]){
      search2(a, first, mid-1, key, found, location);
    }
    else if(key > a[mid]){
      search2(a, mid + 1, last, key, found, location);
    }
  }
}

//#3
template<class T>
class Temp{
private:
  T* set;
  int numItems;
  int capacity;

public:
  Temp() : set(new T[10]), numItems(0), capacity(10){}

  Temp(int cap) : set(new T[cap]), numItems(0), capacity(cap){}

  void addItem(T item){
    if(numItems < 10){
      set[numItems] = item;
      numItems++;
    }
    else{
      cout << "No more space left in the array.";
    }
  }

  int getNumItems() const{
    return numItems;
  }

  T* getPointer() const{
    return set;
  }
};

//#4
template<class T>
class DynamicTemplateArray{
private:
  T* dynamicArray;
  int size;

public:
  DynamicTemplateArray() : dynamicArray(nullptr), size(0){}

  //copy constructor
  DynamicTemplateArray(const DynamicTemplateArray &dArr) : dynamicArray(new T[dArr.getSize()]), size(dArr.getSize()){
    for(int i = 0; i < size; i++){
      dynamicArray[i] = dArr.getEntry(i);
    }
  }

  int getSize() const{
    return size;
  }

  void addEntry(T input){
    T* temp = new T[++size];
    for(int i = 0; i < size - 1; i++){
      temp[i] = dynamicArray[i];
    }
    temp[size - 1] = input;
    delete [] dynamicArray;
    dynamicArray = temp;
  }

  bool deleteEntry(T input){
    for(int i = 0; i < size; i++){
      if(dynamicArray[i] == input){
        T* temp = new T[--size];
        for(int j = 0; j < i; j++){
          temp[j] = dynamicArray[j];
        }
        for(int j = i; j < size; j++){
          temp[j] = dynamicArray[j + 1];
        }
        delete [] dynamicArray;
        dynamicArray = temp;
        return true;
      }
    }
    return false;
  }

  T getEntry(int input) const{
    if(input < 0 || input >= size){
      return nullptr;
    }
    return dynamicArray[input];
  }

  DynamicTemplateArray& operator=(const DynamicTemplateArray &rhs){
    size = rhs.getSize();
    T* temp = new T[size];
    for(int i = 0; i < size; i++){
      temp[i] = rhs.getEntry(i);
    }
    delete [] dynamicArray;
    dynamicArray = temp;
    return *this;
  }

  ~DynamicTemplateArray(){
    delete [] dynamicArray;
    dynamicArray = nullptr;
  }
};


//Driver
int main(){
  //testing #1
  int a[9] = {1,2,3,4,5,6,7,8,9};
  int l;
  bool f;
  search1(a,0,8,8,f,l);//location is 7, found is true
  l = 0;
  f = false;
  search1(a,0,8,0,f,l);//found is false
  l = 0;
  f = false;

  //testing #2
  double b[9] = {1,2,3,4,5,6,7,8,9};
  search2(b,0,8,4.0,f,l);//location is 3, found is true
  l = 0;
  f = false;
  search2(b,0,8,10.0,f,l);//found isn't true
  l = 0;
  f = false;

  //testing #3
  Temp<int> t;//creates set of ints
  t.addItem(10);
  t.addItem(4);
  t.addItem(-3);
  cout << t.getNumItems() << endl;//prints 3
  int *p1 = t.getPointer();//makes new pointer to t's dynamic array set
  for(int i = 0; i < t.getNumItems(); i++){
    cout << p1[i] << endl;//prints the values of the set in the dynamic array
  }
  delete [] p1;
  p1 = nullptr;

  Temp<string> s;//creates set of strings
  s.addItem("hello");
  s.addItem("hi");
  s.addItem("bye");
  s.addItem("cya");
  cout << s.getNumItems() << endl;//prints 4
  string *p2 = s.getPointer();//makes new pointer to s's dynamic array set
  for(int i = 0; i < s.getNumItems(); i++){
    cout << p2[i] << endl;//prints the values of the set in the dynamic array
  }
  delete [] p2;
  p2 = nullptr;

  //testing #4
  DynamicTemplateArray<string> d;
  d.addEntry("hello");
  d.addEntry("hi");
  d.addEntry("bye");
  d.addEntry("cya");
  cout << d.getSize() << endl;//prints 4
  for(int i = 0; i < d.getSize(); i++){//tests & prints getEntry() for all values in the dynamic array
    cout << d.getEntry(i) << endl;
  }
  d.deleteEntry("cya");//deletes
  d.deleteEntry("cow");//doesn't delete
  cout << d.getSize() << endl;//prints 3

  DynamicTemplateArray<string> d2(d);//testing copy constructor
  cout << d2.getSize() << endl;
  for(int i = 0; i < d2.getSize(); i++){
    cout << d2.getEntry(i) << endl;
  }

  DynamicTemplateArray<string> d3;//testing overloaded assignment operator
  d3 = d;
  cout << d3.getSize() << endl;
  for(int i = 0; i < d3.getSize(); i++){
    cout << d3.getEntry(i) << endl;
  }

  return 0;
}
