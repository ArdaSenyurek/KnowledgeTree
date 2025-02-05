#include "LinkedList.h"
#include <iostream>
int main(){

  LinkedList<double> ds = {};
  ds.insertHead(1.3);
  ds.insertTail(7.6);

  std::cout << ds;
  

  std::cout << std::endl;
  
  return 0;
}
