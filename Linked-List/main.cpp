#include "linkedList.cpp"
#include <iostream>
using namespace std;


int main() {

  bool inner = true;
  bool outer = true;
  
  do {
    LinkedList<int>* list = new LinkedList<int>();
    cout<<"A linkedList is created"<<endl;

    do {
      int x, val, i, j;
      cout<<"Here are the options: "<<endl;
      cout<<"1) insert an element"<<endl;
      cout<<"2) delete an element"<<endl;
      cout<<"3) find the middle element"<<endl;
      
      cin>>x;
      switch(x) {
        case 1: {
          cout<<"Enter a value (between 0 and 99) to be inserted:"<<endl;
          cin >> val;
          while (val < 0 || val > 99) {
            cout << "Invalid input vlaue, pelase enter again" << endl;
            cin >> val;
          }
          cout << "Enter the position where you want to insert?" <<endl;
          cin >> i;
          list->insertNode(val, i);
          list->Print();
          break;
        }
        case 2: {
          cout << "Enter the position where you want to delete?" <<endl;
          cin >> j;
          list->deleteNode(j);
          list->Print();
          break;
        }
        case 3: {
          list->findMid();
          break;
        }
        default: {
          cout<<"Invalid Choice!"<<endl;
        }
      }

      cout << "Do you want to continue? type any number to continue or type 0 to exit the manual." <<endl;
      int a;
      cin >> a;
      if (a == 0) {
        inner = false;
        delete list;
      } else {
        inner = true;
      }
    }while(inner);    

    cout << "Do you want to continue? type any number to restart or type 0 to exit the program." <<endl;
    int b;
    cin >> b;
    if (b == 0) {
      outer = false;
    } else {
      outer = true;
    }
  }while (outer);

  cout << "the porgam is ending..." <<endl;

  return 0;
}