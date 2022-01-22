//Justin Li
#include "node.h"
#include "Polynode.h"
#include <iostream>
using namespace std;

//#1
void reverseNode(node* &h){
  node *head = h;
  node *temp = h -> link();
  h -> set_link(nullptr);
  while (temp != nullptr){
    h = temp;
    temp = temp -> link();
    h -> set_link(head);
    head = h;
  }
  temp = nullptr;
  head = nullptr;
}

//#2
//Pre: Linked list head being passed in must have at least 1 node
node* mergeLists(node* &a, node* &b){
  node *head;
  if (a -> data() < b -> data()){
    head = a;
    a = a -> link();
  }
  else {
    head = b;
    b = b -> link();
  }
  node *tail(head);
  while (!(a == nullptr && b == nullptr)){
    if (a != nullptr && b != nullptr){
      if (a -> data() < b -> data()){
        tail -> set_link(a);
        tail = a;
        a = a -> link();
      }
      else {
        tail -> set_link(b);
        tail = b;
        b = b -> link();
      }
    }
    else if (a == nullptr){
      tail -> set_link(b);
      tail = b;
      b = b -> link();
    }
    else {
      tail -> set_link(a);
      tail = a;
      a = a -> link();
    }
  }
  tail = nullptr;
  return head;
}

//#3
class Polynomial{
private:
  Polynode *head;
  Polynode *tail;

public:
  Polynomial() : head(nullptr), tail(nullptr){}

  Polynomial(const Polynomial &poly);

  Polynomial(int a){
    head = new Polynode(a, 0, nullptr);
    tail(head);
  }

  Polynomial(int a, int n){
    head = new Polynode(a, n, nullptr);
    tail(head);
  }

  int eval(int x);

  ~Polynomial();

  Polynomial& operator+(const Polynomial &rhs);

  Polynomial& operator-(const Polynomial &rhs);

  Polynomial& operator*(const Polynomial &rhs);
};

int main(){
  //making 1st linked list
  node *head = new node(5, nullptr);
  node *tail(head);
  node *temp;
  for (int i = 4; i > 0; i--){
    temp = new node(i, nullptr);
    tail -> set_link(temp);
    tail = temp;
  }

  //printing 1st linked list
  for (node *p = head; p != nullptr; p = p -> link()){
    cout << p -> data() << " ";
  }
  cout << endl;

  //testing #1
  reverseNode(head);
  for (node *p = head; p != nullptr; p = p -> link()){
    cout << p -> data() << " ";
  }
  cout << endl;

  //making 2nd linked list
  node *head2 = new node(0, nullptr);
  node *tail2(head2);
  node *temp2;
  for (int i = 2; i <= 10; i+=2){
    temp2 = new node(i, nullptr);
    tail2 -> set_link(temp2);
    tail2 = temp2;
  }

  //printing 2nd linked list
  for (node *p = head2; p != nullptr; p = p -> link()){
    cout << p -> data() << " ";
  }
  cout << endl;

  //testing #2
  //making 3rd linked list using mergeLists()
  node *head3 = mergeLists(head, head2);
  for (node *p = head3; p != nullptr; p = p -> link()){
    cout << p -> data() << " ";
  }
  cout << endl;

  //testing #3

  return 0;
}
