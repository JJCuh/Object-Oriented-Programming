#include <iostream>
using namespace std;
 class ModInt{
 public:
   ModInt(){
     mod = 1;
     numValue = 0;
   }

   ModInt(int modV, int numV){
     mod = modV;
     numValue = numV;
   }

   int getMod(){
     return mod;
   }

   int getNumValue(){
     return numValue;
   }

 private:
   int mod;
   int numValue;
 };

bool operator ==(ModInt lhs, ModInt rhs){
  if(lhs.getMod() == rhs.getMod() && lhs.getNumValue() == rhs.getNumValue()){
    return true;
  }
  return false;
}

 int main(){
   ModInt modInt1;
   ModInt modInt2(21,69);
   cout << modInt1.getMod() << endl;
   cout << modInt1.getNumValue() << endl;
   cout << modInt2.getMod() << endl;
   cout << modInt2.getNumValue() << endl;

   ModInt modInt3(21,69);
   if (modInt1 == modInt2){
     cout << "true" << endl;
   }
   else{
     cout << "false" << endl;
   }

   if (modInt3 == modInt2){
     cout << "true" << endl;
   }
   else{
     cout << "false" << endl;
   }

   return 0;
 }
