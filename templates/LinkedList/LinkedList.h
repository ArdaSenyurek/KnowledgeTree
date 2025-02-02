#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "LinkedListNode.h"

// TODO: bound checking. i.e start_ =? nullptr.
// TODO: implement iterator.
template<typename T>
class LinkedList{

  private:
   LinkedListNode<T> start_;
   LinkedListNode<T> end_;

  public:
    LinkedList() = default;
    LinkedList(const T &);

    // Insertion
    const LinkedListNode<T> &insert(const unsigned int, const T &);
    const LinkedListNode<T> &insertHead(const T &);
    const LinkedListNode<T> &insertTail(const T &);
    
    // Deletion
    const LinkedListNode<T> &deleteNode(const unsigned int);
    const LinkedListNode<T> &deleteHead();
    const LinkedListNode<T> &deleteTail();
    void print() const;
    
    
};

template<typename T>
LinkedList<T>::LinkedList(const T &data) : start_(data){
  LinkedListNode<T> *tmpPtr = &start_;
  while(tmpPtr -> next() != nullptr){
    tmpPtr = tmpPtr -> next();
  }
  
  end_ = *tmpPtr; // LinkedListNode needs copy assignment.
}

template<typename T>
const LinkedListNode<T> &LinkedList<T>::addNode(const unsigned int index, const T &data){

  // A -> B -> C, if index = 1, node = D, then A -> D -> B -> C
  // tmpPtr = A, oldNode = B, 

  LinkedListNode<T> &node = start_;
  LinkedListNode<T> *ptr = new LinkedListNode<T>(data);
  unsigned int i = 0;
  while(i++ < index -1 && node.next() != nullptr){
    node = *node.next();
  }
  (*ptr).setNext(node.next());
  return node.setNext(ptr);
}

  
template<typename T>
const LinkedListNode<T> &LinkedList<T>::deleteNode(const T &data){

  LinkedListNode<T> &node = start_;
  LinkedListNode<T> &PrevNode = start_;

  while(node.getData() != data || node.next() != nullptr){
    PrevNode = node;
    node = *node.next();
  }
  PrevNode.setNext(node.next());
  node.setNext(nullptr);
  return node; 
} 

template<typename T>
void LinkedList<T>::print() const {
  const LinkedListNode<T> &node = start_;
  while(node.next() != nullptr){
    node.print();
    node = *node.next(); 
    }
}
template<typename T>
const LinkedListNode<T> &deleteNode(const unsigned int index){
  if(index == 0) return deleteHead();
  else{
  
    LinkedListNode<T> &node = start_;

    unsigned int i = 0;
    while(i++ < index -1 && node.next() != nullptr){
      node = *node.next();
    }
    const LinkedListNode<T> &nNext = *(*(node.next()).next());
    node.setNext(&nNext);

    LinkedListNode<T> &delNode = *node.next();
    delNode.setNext(nullptr);
    return node; 
    }
}
template<typename T>
const LinkedListNode<T> &deleteHead(){
  const LinkedListNode<T> &newStart = *start_.next();
  
  start_ = std::move(newStart);
  return start_;
  
}
// This is a bit more involved. (Can't go back from tail.) (Need to set n-1s node's next.)
// Traverse tree and keep track of end_ node? (Everytime changed update something maybe?)
template<typename T>
const LinkedListNode<T> &deleteTail(){

  const LinkedListNode<T> &newEnd = *start_.next();
  
  start_ = std::move(newStart);
  return start_;
}
#endif 

