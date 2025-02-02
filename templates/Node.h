#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{

  private:
    T data_;
    Node* children_;


  public:
    Node() = default;
    Node(const T &);
    
};


template<typename T>
inline Node<T>::Node(const T &data)
: data_(data) 
{
  children = nullptr;

}

template<typename T>
Node<T>:: addChild(const Node *child){

  // pushback child, (children is linkedList)
}   
#endif 

