#include<stdio.h>
#include<iostream>
#include<stdlib.h>

class LinkedList;
class Node {
public:
  Node() {
    this->next = NULL;
  }
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
  int getData() {
    return this->data;
  }
  void setData(int data) {
    this->data = data;
  }
  Node* getNext() {
    return this->next;
  }
  void setNext(Node *node) {
    this->next = node;
  }
  friend std::ostream&
  operator<<(std::ostream& os,
	     const Node& n);
private:
  int data;
  Node* next;
};


std::ostream&
operator<<(std::ostream &os,
           const Node& n) {
  os << n.data;
}


class LinkedList {
public:
  LinkedList() {}

  void insertNode(Node& target, Node *new_node) {
    for(Node* p = &head;
        p != NULL;
        p = p->getNext()) {
      if ( p == &target) {
        new_node->setNext(p->getNext());
        p->setNext(new_node);
      }
    }
  }


  void removeNode(Node& node) {
    for(Node *p0 = &head, *p1 = head.getNext();
        p1 != NULL;
        p0 = p1, p1 = p1->getNext() ) {
      if ( p1 == &node ) {
        p0->setNext(p1->getNext());
      }
    }
  }

  Node* getHead() {
    return &(this->head);
  }


  friend std::ostream&
  operator<<(std::ostream& os,
             LinkedList& l);

private:
  Node head;
};


std::ostream&
operator<<(std::ostream &os,
           LinkedList& l) {
  for (Node* p = l.getHead()->getNext();
       p != NULL;
       p = p->getNext() ) {
    os << *(p) << " -> ";
  }
  os << "NULL";
}




class Stack {
public:
  int pop() {
    if ( stack.getHead()->getNext() == NULL ) {
      return -1;
    }
    int ret = stack.getHead()->getNext()->getData();
    stack.removeNode(*(stack.getHead()->getNext()));
    return ret;
  }
  void push(int data) {
    Node* node = new Node(data);
    stack.insertNode(*(stack.getHead()), node);
  }
  friend std::ostream& operator<<(std::ostream& os, Stack& s);
private:
  LinkedList stack;
};
std::ostream &operator<<(std::ostream &os, Stack& s) {
  os << s.stack;
}



int corn(char i){
  if( (i=='+') || (i=='-') ||(i=='*') ||(i=='/')||(i=='m')||(i=='d')){
    return 0;
  }else{
    return 1;
  }
}//演算子と数字を判定する                                                                           


int po(int n, char** a){
  int i=1, x, y,z;
  printf("the presumed number of cycle n= %d\n",n);
  Stack stn;
  while(1){
    if(i==n){
      printf("cycle i= %d\n",i);
      return stn.pop();

    }else if(corn(a[i][0])==1){
      z=atoi(a[i]);
      stn.push(z);
      i++;

    }else if(a[i][0]=='+'){
      x=stn.pop();
      y=stn.pop();
      stn.push(x+y);
      i++;

    }else if(a[i][0]=='-'){
      x=stn.pop();
      y=stn.pop();
      stn.push(y-x);
      i++;

    }else if((a[i][0]=='*')||(a[i][0]=='m')){
      //' * 'を使うとうまく行かないのでmを積の演算子として定義。                              
    //mulは多重定義のため使用できなかった。念の為' * 'も定義                                      
      //'*'と表記すればうまくいく模様                                                               
      x=stn.pop();
      y=stn.pop();
      stn.push(x*y);
      i++;

    }else if((a[i][0]=='/')||(a[i][0]=='d')){//' / 'は使用できるが積と対応するように定義            
      x=stn.pop();
      y=stn.pop();
      stn.push(y/x);
      i++;

    }else{
      printf("i= %d\n",i);
      printf("wrong\n");
      return -1;
    }
  }


}

int main(int argc, char *argv[]){
#if 0
  printf("test for stack queue\n");

  Stack stack;
  stack.push(12); // std::cout << stack << std::endl;                                               
  stack.push(99); // std::cout << stack << std::endl;                                               
  stack.push(37); // std::cout << stack << std::endl;                                               
  std::cout << "stack : ";
  std::cout << stack.pop() << " "; // std::cout << stack << std::endl;                              
  std::cout << stack.pop() << " "; // std::cout << stack << std::endl;                              
  std::cout << stack.pop() << std::endl; // std::cout << stack << std::endl;                        
#endif
 

  //以下poland                                                                                      
  printf("below: about poland\n");

  printf("argc= %d\n", argc);
  for(int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  printf("answer= %d \n", po(argc, argv) );

}




