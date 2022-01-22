#include "dbiguint.h"
#include <iostream>

  dbiguint :: dbiguint(){
    capacity_ = 1;
    data_ = new unsigned short[capacity_];
      data_[0] = 0;
      std::cout << data_[0] << std::endl;
  }

  dbiguint :: dbiguint (const std::string& bigNum){
    capacity_ = bigNum.length();
    data_ = new unsigned short[capacity_];
    int i = 0;
    for (i = 0 ; i < capacity_; i++){
      data_[capacity_ - i - 1] = bigNum[i]-'0';
      std::cout << data_[capacity_ - i - 1] << std::endl;
    }
  }
