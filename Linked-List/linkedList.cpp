#include <iostream>
using namespace std;

template <typename T>

class LinkedList {

    struct Node {
    T data;
    Node* next;
  }; 

  int size = 0;
  Node* head = NULL;


  public:
  void insertNode(T data, int n) {
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    if (size == 0) {
      head = newNode;
      size ++;
    } else if (n == 1) {
      newNode -> next = head;
      head = newNode;
      size ++;
    } else {
      if (n > size + 1) {
        n = size + 1;
      }
      Node* current = head;
      for (int i = 1; i < n-1; i++) {
        current = current -> next;
      }
      newNode -> next = current -> next;
      current -> next = newNode;
      size ++;
      delete current;
    }
    delete newNode;
  }


  void deleteNode(int n) {
    T temp;
    if (size == 0) {
      string str = " Cannot delete any node because the liked list is emplty!";
      cout << str << endl;
      return;
    } else if (size == 1) {
      temp = head -> data;
      head = NULL;
      size --;
    } else if (n == 1) {
      temp = head -> data;
      head = head -> next;
      size --;
    } else {
      Node* current = head;
      for (int i = 1; i < n-1 ; i++) {
        current = current -> next;
      }
      temp = current -> next -> data;
      current -> next = current -> next -> next;
      size --;
      delete current;
    }
    cout << "deleted the node: " << temp << endl;
  }


  void findMid() {
    
    if (head == NULL) {
      cout << "The linkedlist is empty, so no middle element!" << endl;
      return;
    }
    
    Node* fast = head;
    Node* slow = head;
    
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    cout << "The middle is: " << slow->data << endl;

    delete fast;
    delete slow;
  }


  void Print() {
    Node* current = head;
    cout << "The linked list is: ";
    while (current != NULL) {
      cout << current -> data;
      cout << " -> ";
      current = current -> next;
    }
    cout << "NULL \n";
    delete current;
  }
};