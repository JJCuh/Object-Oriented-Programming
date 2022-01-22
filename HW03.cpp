//Justin Li

#include <iostream>
#include "Employee.h"
#include "SalariedEmployee.h"
using namespace std;

//#1
class Doctor : public SalariedEmployee{
private:
  string specialty;
  double officeVisitFee;

public:
  Doctor() : SalariedEmployee(), specialty("N/A"), officeVisitFee(25){
    //deliberately empty
  }

  Doctor(const string& theName, const string& theNumber, double theWeeklyPay, const string& spec, double fee)
  : SalariedEmployee(theName, theNumber, theWeeklyPay), specialty(spec), officeVisitFee(fee){
    //deliberately empty
  }

  string getSpecialty( ) const{
    return specialty;
  }

  double getOfficeVisitFee( ) const{
    return officeVisitFee;
  }

  void setSpecialty(const string& newSpecialty){
    specialty = newSpecialty;
  }

  void setOfficeVisitFee(double newFee){
    officeVisitFee = newFee;
  }
};

//#2
class Person{
private:
  string name;

public:
  Person() : name("n/a"){}

  Person(string n) : name(n){}

  Person(const Person& theObject);

  Person& operator=(const Person& rtSide);
};

class Vehicle{
private:
  string brand;
  int numCylinders;
  Person owner;

public:
  Vehicle() : brand("n/a"), numCylinders(4), owner(){}

  Vehicle(string b, int num, Person p) : brand(b), numCylinders(num), owner(p){}

  string getBrand() const{
    return brand;
  }

  int getNumCylinders() const{
    return numCylinders;
  }

  Person getOwner() const{

  }

  void setBrand(const string b){
    brand = b;
  }

  void setNumCylinders(int num){
    numCylinders = num;
  }

  void setOwner(const Person o){
    owner = o;
  }
};

//#3
  class Patient : public Person{
  private:
    Doctor doctor;
  };

  class Billing{
  private:
    Patient patient;
    Doctor doctor;
    double due;
  };

int main(){
  Doctor doctor1;
  cout << doctor1.getSpecialty() << endl;
  cout << doctor1.getOfficeVisitFee() << endl;
  Doctor doctor2("Bobby", "2169", 1000, "Pediatrician", 10);
  cout << doctor2.getSpecialty() << endl;
  cout << doctor2.getOfficeVisitFee() << endl;
  doctor1.setSpecialty("Practitioner");
  doctor1.setOfficeVisitFee(5);
  cout << doctor1.getSpecialty() << endl;
  cout << doctor1.getOfficeVisitFee() << endl;

  Vehicle vehicle1;
  cout << vehicle1.getBrand() << endl;
  cout << vehicle1.getNumCylinders() << endl;
  cout << vehicle1.getOwner() << endl;
  Vehicle vehicle2;


  return 0;
}
