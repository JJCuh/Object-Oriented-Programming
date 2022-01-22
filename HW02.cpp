//Justin Li

#include <iostream>
using namespace std;

class ReverseString{
private:
  string str;

public:
  //prints the reversed strings
  ReverseString(string s){
    str = s;
    char *p1;
    char *p2;
    for(int i = 0; i < s.length() / 2; i++){
      p1 = &str[i];
      p2 = &str[s.length() - 1 - i];
      char temp = *p1;
      *p1 = *p2;
      *p2 = temp;
    }
    cout << str << endl;
  }
};

class Student{
private:
  string name;
  int numClasses;
  string *classList;

public:
  Student(string n, int num, string classes[]){
    name = n;
    cout << name << endl;
    numClasses = num;
    cout << numClasses << endl;
    classList = classes;
    for(int i = 0; i < classes.size(); i++){
      cout << classList[i] << endl;
    }
  }

  string getName(){
    return name;
  }

  int getNumClasses(){
    return numClasses;
  }

  string* getClassList(){
    return classList;
  }

  void setName(string n){
    name = n;
  }

  void setNumClasses(int num){
    numClasses = num;
  }

  void setClassList(string classes[]){
    classList = classes;
  }
};



int main(){
  ReverseString("hello");
  ReverseString("four");

  Student("Bobby", 10, {"math", "eng", "span"});

  return 0;
}
