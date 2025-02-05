#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedListNode.h"
#include <iostream>

// TODO: implement iterator.
// TODO: implement exception handling.
// TODO: Access should be thru iterator.
// TODO: Too much branching when deleting and inserting. Need generalization. Maybe through encoding? Bitmask maybe.

template<typename T>
class LinkedList;

template<typename T>
std::ostream &operator<<(std::ostream &, const LinkedList<T> &);

template<typename T>
class LinkedList{

  friend std::ostream &operator<< <>(std::ostream &, const LinkedList &);
  private:
   LinkedListNode<T> *start_;
   LinkedListNode<T> *end_;

  public:
    LinkedList() = default;
    LinkedList(const T &);

    // Insertion
    const LinkedListNode<T> *insertHead(const T &);
    const LinkedListNode<T> *insertTail(const T &);
    
    // Deletion
    const LinkedListNode<T> *deleteNode(const T &);
    const LinkedListNode<T> *deleteHead();
    const LinkedListNode<T> *deleteTail();

    // Access (Const) 
      // TODO
};

template<typename T>
LinkedList<T>::LinkedList(const T &data) {

  start_ = new LinkedListNode<T>(data);
  LinkedListNode<T> *tmpPtr = start_;
  while(tmpPtr -> next() != nullptr){
    tmpPtr = tmpPtr -> next();
  }
  end_ = tmpPtr; 
}

template<typename T>
const LinkedListNode<T>
*LinkedList<T>::deleteNode(const T &data){

  // Nothing to delete
  if (start_ == nullptr) throw 123;
  else {
    // These have automatic storage lifetime anyways.
    LinkedListNode<T> *prev = nullptr;
    LinkedListNode<T> *curr = start_;

    while ( curr -> getData() != data && curr -> next() != nullptr){
      prev = curr;
      curr = curr -> next();
    }
    // head
    if (prev == nullptr) {
      start_ = curr -> next();
      if(start_ == nullptr) end_ = nullptr;
    }
    else {
      if (curr -> next() != nullptr)
        prev -> setNext(curr -> next());
      else 
        prev -> setNext(nullptr);
    }
    curr -> setNext(nullptr);
    return curr;
  }
} 

template<typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &ds) {
  const auto *node = ds.start_;
  if (node == nullptr) os << "NULL\n";
  else {
    while(node -> next() != nullptr){
      os << *node;
      node = node -> next(); 
    }
    os << *node << std::endl;
  }
  return os;
}

template<typename T>
const LinkedListNode<T>
*LinkedList<T>::deleteHead(){
  if (start_ == nullptr) throw 123;

  LinkedListNode<T> *tmp = start_;
  start_ = start_ -> next();
  tmp -> setNext(nullptr);
  return start_;
}

template<typename T>
const LinkedListNode<T> 
*LinkedList<T>::deleteTail(){

  if (start_ == nullptr) throw 123;
  LinkedListNode<T> *prev = nullptr;
  LinkedListNode<T> *curr = start_;
  while(curr -> next() != nullptr) {
    prev = curr;
    curr = curr -> next();
  }
  if (curr == nullptr) throw 123;
  else prev -> setNext(nullptr);
  curr -> setNext(nullptr);
  return curr; 
}

template<typename T>
const LinkedListNode<T> 
*LinkedList<T>::insertHead(const T &data){
  LinkedListNode<T> *node = new LinkedListNode<T>(data);
  node -> setNext(start_);
  // It had nothing before if start_ == nullptr.
  if (start_ == nullptr) end_ = node;
  start_ = node;
  return start_;
}

template<typename T>
const LinkedListNode<T> 
*LinkedList<T>::insertTail(const T &data){
  
  LinkedListNode<T> *node = new LinkedListNode<T>(data);
  if(end_ != nullptr) {
    end_ -> setNext(node);
    end_ = node;
  }
  else {
    start_ = node;
    end_ = node;
  }
  return end_;
}
#endif 

