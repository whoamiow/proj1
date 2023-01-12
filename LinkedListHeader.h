#ifndef LL_H
#define LL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

template <class T>
class LL;

template <class T>
struct node{
  T elem;
  node<T>* next;
};

template <class T>
class LL{
 private:
  node<T>* front;
  node<T>* rear;
  int count;
  void queueError(string msg);
 public:
  class listError{};
  LL();
  ~LL();
  void addFront(T el);
  void addRear(const T &el);
  void addInOrderAscend(T e);
  void addInOrderDescend(T e);
  bool search(T e);
  T deleteRear();
  LL(const LL& source);
  void deleteNode(T el);
  T deleteFront();
  bool isEmpty() const;
  void displayAll() const;
  node<T>* getFront();
  node<T>* getRear();
  node<T>* getNext(node<T>* p);
};

template <class T>
node<T>* LL<T>::getFront() {
  return front;
}

template <class T>
node<T>* LL<T>::getRear() {
  return rear;
}

template <class T>
node<T>* LL<T>::getNext(node<T>* p) {
  return p->next;
}

template <class T>
void LL<T>::deleteNode(T el){
  if(count == 0){
    return;
  }
  T temp;
  if(front->elem == el){
    temp = deleteFront();
    return;
  }
  if(count == 1){
    cout << "In 1" << endl;
    if(front->elem == el){
      temp = deleteFront();
      return;
    } else {
      return;
    }
  }
  
  node<T>* pre;
  node<T>* del;
  for(pre = front, del = front->next; del!=NULL && del->elem != el; pre = del, del = del->next);
  
  if(del != NULL) {
  pre->next = del->next;
  delete del;
  count--;
  }
}

template <class T>
void LL<T>::addInOrderAscend(T e){
  if(isEmpty()){
    addFront(e);
    return;
  }
  if(e < front->elem){
    addFront(e);
    return;
  }
  node<T>* p = front;
  while(p->next !=NULL && p->next->elem < e){
    p = p->next;
  }
  node<T>* ptr = new node<T>();
  ptr->elem = e;
  ptr->next = p->next;
  p->next = ptr;
}

template <class T>
void LL<T>::addInOrderDescend(T e){
  if(isEmpty()){
    addFront(e);
    return;
  }
  if(e > front->elem){
    addFront(e);
    return;
  }
  node<T>* p = front;
  while(p->next !=NULL && p->next->elem > e){
    p = p->next;
  }
  node<T>* ptr = new node<T>();
  ptr->elem = e;
  ptr->next = p->next;
  p->next = ptr;
}

template <class T>
bool LL<T>::search(T e){
  if(isEmpty()) {
    return false;
  }
  node<T>* ptr = front;
  int num = 0;
  while(ptr != NULL){
    num++;
    if(ptr->elem == e){
      cout << num << endl;
      return true;
    }
    ptr = ptr->next;
  }
  cout << num << endl;
  return false;
}

template <class T>
LL<T>::LL(const LL& source){
  front = rear = NULL;
  count = 0;
  node<T> * p = source.front;
  while(p!=NULL){
    this->addRear(p->elem);
    p = p->next;
  }
}

template <class T>
void LL<T>::queueError(string msg){
  cout << msg << endl;
  exit(1);
}

template <class T>
LL<T>::LL(){
  front = NULL;
  rear = NULL;
  count = 0;
}

template <class T>
LL<T>::~LL(){
  T temp;
  while(!isEmpty()){
    temp = deleteFront();
  }
}

template <class T>
void LL<T>::addFront(T el){
  if(isEmpty()){
    front = new node<T>();
    front->elem = el;
    front->next = NULL;
    rear = front;
    count++;
  } else {
    node<T> * ptr = new node<T>();
    ptr->elem = el;
    ptr->next = front;
    front = ptr;
    count++;
  }
}

template <class T>
T LL<T>::deleteRear(){
  if(isEmpty()){
    //queueError("Error: list is empty.");
    //return 0;
    throw listError();
  }
  if(count == 1){
    T temp = front->elem;
    delete front;
    front = NULL;
    rear = NULL;
    count--;
    return temp;
  } 
  node<T> * ptr = front;
  while(ptr->next != rear){
    ptr = ptr->next;
  }
  T temp = rear->elem;
  delete rear;
  rear = ptr;
  rear->next = NULL;
  count--;
  return temp;
}

template <class T>
void LL<T>::addRear(const T &el){
  if(isEmpty()){
    front = new node<T>();
    rear = front;
    count++;
    rear->elem = el;
    rear->next = NULL;
  } else {
    rear->next = new node<T>();
    count++;
    rear = rear->next;
    rear->elem = el;
    rear->next = NULL;
  }
}

template <class T>
T LL<T>::deleteFront() {
  if(isEmpty()){
    //queueError("Error: list is empty.");
    throw listError();
    //return 0;
  }
  if(count == 1){
    T temp = front->elem; 
    delete front;
    rear = NULL;
    front = NULL;
    count = 0;
    return temp;
  } else {
    node<T>* ptr = front->next;
    T temp = front->elem;
    delete front;
    front = ptr;
    count--;
    return temp;
  }
}

template <class T>
bool LL<T>::isEmpty() const{
  if(count == 0 && front == NULL && rear == NULL){
    return true;
  } else {
    return false;
  }
}

template <class T>
void LL<T>::displayAll() const{
  if(isEmpty()){
    cout << "[ empty ]" << endl;
  } else {
  node<T>* ptr = front;
  cout << "[";
  while(ptr != NULL){
    cout << ptr->elem << " ";
    ptr = ptr->next;
  } cout << "]" << endl;
  }
}

#endif
