#include "dbiguint.h"
#include <iostream>
#include <cassert>
#include <sstream>

 dbiguint::dbiguint() 
 {
     for(std::size_t i = 0; i<CAPACITY; i++){

             _data[i] = 0;
     }
 }
 dbiguint::dbiguint (const std::string & s)
 {
     for (int i = 0; i < CAPACITY; ++i)
         _data[i] = 0;

     if (s.size() == 0)
         return;

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < CAPACITY && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
 }


 unsigned short dbiguint::operator [](std::size_t pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int dbiguint::compare(const dbiguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;
     }
     return 0;
 }


 void dbiguint::operator += (const dbiguint & b)
 {
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string dbiguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const dbiguint & b)
 {

     for (int i = dbiguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, dbiguint & b)
 {
     std::string s;
     is >> s;
     b = dbiguint(s);
     return is;
 }

 bool operator <(const dbiguint& a, const dbiguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const dbiguint & b1, const dbiguint & b2)
 {
     return (b1.compare(b2) != 0);
 }

//You do > and >=

  int main(){
    string s = "12345";
    dbiguint b = new dbiguint(s);
    cout << b << endl;
  }
