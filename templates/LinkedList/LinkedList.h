#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedListNode.h"

// TODO: bound checking. i.e start_ =? nullptr.
// TODO: implement iterator.


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
    const LinkedListNode<T> *insert(const unsigned int, const T &);
    const LinkedListNode<T> *insertHead(const T &);
    const LinkedListNode<T> *insertTail(const T &);
    
    // Deletion
    const LinkedListNode<T> *deleteNode(const unsigned int);
    const LinkedListNode<T> *deleteNode(const T &);
    const LinkedListNode<T> *deleteHead();
    const LinkedListNode<T> *deleteTail();

    void print() const;
    
    
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
*LinkedList<T>::insert(const unsigned int index, const T &data){

  LinkedListNode<T> *node = start_;
  LinkedListNode<T> *ptr = new LinkedListNode<T>(data);
  unsigned int i = 0;
  if (index != 0) {
    while(i++ < index -1 && node -> next() != nullptr){
      node = node -> next();
    }
    ptr -> setNext(node -> next());
    return node -> setNext(ptr);
  }
  else {
    LinkedListNode<T> *startPtr = start_;
    start_ = ptr;
    ptr -> setNext(startPtr);
    return start_;
  }
}

  
template<typename T>
const LinkedListNode<T>
*LinkedList<T>::deleteNode(const T &data){

  // These have automatic storage lifetime anyways.
  LinkedListNode<T> *prev = nullptr;
  LinkedListNode<T> *curr = start_;
  
  // Nothing to delete
  if (curr == nullptr) throw 123;

  unsigned int i = 0;
  while ( curr -> getData() != data || curr -> next() != nullptr){
    
    prev = curr;
    curr = curr -> next();
  }
  
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

template<typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &ds) {
  const auto *node = ds.start_;
  while(node -> next() != nullptr){
    os << *node;
    node = node -> next(); 
    }
    os << *node;
  return os;
}
template<typename T>
const LinkedListNode<T>
*LinkedList<T>::deleteNode(const unsigned int index){
  LinkedListNode<T> *prev = nullptr;
  LinkedListNode<T> *curr = start_;
  
  // Nothing to delete
  if (curr == nullptr) throw 123;

  unsigned int i = 0;
  while ( i++ < index || curr -> next() != nullptr){
    
    prev = curr;
    curr = curr -> next();
  }
  
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

template<typename T>
const LinkedListNode<T>
*LinkedList<T>::deleteHead(){
  if (start_ == nullptr) throw 123;

  LinkedListNode<T> *tmpStart = start_;
  start_ = start_ -> next();
  tmpStart -> setNext(nullptr);
  return start_;
}

template<typename T>
const LinkedListNode<T> 
*LinkedList<T>::deleteTail(){

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
  end_ -> setNext(node);
  end_ = node;
  return end_;

}
#endif 

