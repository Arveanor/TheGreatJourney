#include "list.h"
#include <iostream>
using namespace std;

Node* List::Current() {
   return current;
}

void List::Next() {
   current = current->Next();
}

void List::Print() {

   Reset();
   
   if(current == NULL) {
      cout << "EMPTY" << endl;
	  return;
	}
   
   if(end()) {
      cout << current->Tag();
	  cout << " --> ";
	  cout << "NULL" << endl;
	}
	
	else {
	   while(!(end())) {
	      cout << current->Tag();
		  cout << " --> ";
		  current = current->Next();
	    }
	   cout << current->Tag();
	   cout << " --> NULL" << endl;
	   
    }
}

void List::Push(void *_new, string _tag) {
   
   Node *tmp = new Node;
   tmp->setData(_new);
   tmp->setTag(_tag);
   tmp->setNext(NULL);
      
   if(head == NULL) {
      head = tail = current = tmp;
	  return;
	}
   else {
      tail->setNext(tmp);
	  current = tmp;
	  tail = tail->Next();
	}
	
	tmp = NULL;
	delete tmp;
}

void List::Pop() {

   if(head == NULL) { 
      return;	  
	}

	Node *tmp = head;

    if(head->Next() == NULL) {
	  delete tmp; 
	  head = NULL;
	  return;
	}

   Reset();
   while(current->Next() != tail) {	
	  current = current->Next();
    }
	

   tmp = tail;
   delete tmp;

   current->setNext(NULL);
   tail = current;

   Reset();   
}	

void  List::Remove_node(string _tag) {
   Reset();
   
   Node *tmp = current->Next();
   
   if(head == NULL) { return; }
   if(head->Next() == NULL) {
      if(head->Tag() == _tag) {
         delete head;
         head = NULL;
         return;
      }
   }
   
   while(!(end())) {
      if(tmp->Tag() == _tag) {
         current->setNext(tmp->Next());
         delete tmp;
         return;
      }
      current = tmp;
      tmp = tmp->Next();
   }
}

void  List::Delete() {
   while(!(end())) {
      Pop();
      current = current->Next();
   }
   delete this;
}
   
   Node* List::getbyTag(List *list, string _tag) {
      if(head->Next() == NULL) {
         return head;
      }
      Reset();
      while(!(end())) {
         if(_tag == current->Tag()) {
            return current;
         }
         current = current->Next();
      }   
   }
   
void  List::Reset() {
   current = head;
}
bool  List::end() {
   if(current->Next() == NULL) {  
      return true; 
   }
   return false;
}
