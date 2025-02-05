#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>


template<typename T>
class LinkedListNode;

template<typename T>
std::ostream &operator<<(std::ostream &, const LinkedListNode<T> &);

template<typename T>
class LinkedListNode{
  friend std::ostream &operator<< <>(std::ostream &, const LinkedListNode &);
  private:
    T data_;
    LinkedListNode* next_;
  public:
    LinkedListNode() = default;
    LinkedListNode(const T &);

    const LinkedListNode *next() const;
    LinkedListNode *setNext(LinkedListNode *const);

    LinkedListNode &operator=(const LinkedListNode &);
};


template<typename T>
inline LinkedListNode<T>::LinkedListNode(const T &data) 
: data_(data) 
{
  next_ = nullptr;
}

template<typename T>
inline const LinkedListNode<T>
*LinkedListNode<T>::next() const{
  return next_;
}

template<typename T>
inline LinkedListNode<T>
*LinkedListNode<T>::setNext(LinkedListNode *const newNext){
  next_ = newNext;
  return next_;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const LinkedListNode<T> &node){

  os << node.data_;
  if (node.next() != nullptr) os << " -> ";
  
  return os;
}

template<typename T>
inline LinkedListNode<T> 
&LinkedListNode<T>::operator=(const LinkedListNode & src){

  data_ = src.data_;
  next_ = src.next_;
  return *this;
}
#endif 

