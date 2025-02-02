#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

template<typename T>
class LinkedListNode{
  private:
    T data_;
    LinkedListNode* next_;
  public:
    LinkedListNode() = default;
    LinkedListNode(const T &);

    LinkedListNode *next();
    LinkedListNode *setNext(const LinkedListNode *const);
    void print(); 

    LinkedListNode &operator=(const LinkedListNode &);
};


template<typename T>
inline LinkedListNode<T>::LinkedListNode(const T &data) 
: data_(data) 
{
  next_ = nullptr;
}

template<typename T>
inline LinkedListNode<T> *LinkedListNode<T>::next(){
  return next_;
}

template<typename T>
inline LinkedListNode<T>
*LinkedListNode<T>::setNext(const LinkedListNode *const newNext){
  next_ = newNext;
}

template<typename T>
inline void LinkedListNode<T>::print(){
  print(data_); // Streaming better. (Whatever)
}

template<typename T>
inline LinkedListNode<T> 
&LinkedListNode<T>::operator=(const LinkedListNode & src){

  data_ = src.data_;
  next_ = src.next_;
  return *this;
}
#endif 

