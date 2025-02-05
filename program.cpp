#include "LinkedList.h"
#include <iostream>
int main(){

  LinkedList<double> ds = {};

  #ifdef DEBUG_INSERT
  // Insert

  ds.insertTail(1.7);
  ds.insertHead(1.5);

  std::cout << ds;
  #endif

  #ifdef DEBUG_DELETE
  // Delete
  std::cout << ds;
  ds.insertHead(1.2);
  std::cout << ds;
  ds.insertTail(1.5);
  std::cout << ds;
  ds.insertTail(23);
  std::cout << ds;
  ds.deleteTail();
  std::cout << ds;
  ds.deleteHead();
  std::cout << ds;
  ds.deleteNode(1.5);
  std::cout << ds;
  #endif

  #ifdef DEBUG_ACC
  // Access
  #endif



  return 0;
}
