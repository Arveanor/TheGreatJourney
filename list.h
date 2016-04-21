#include <string>
#include <cstdlib>

class Node 
{
   void    *data;
   Node    *next;
   std::string  tag;
public:
   Node () {};
   void   setData(void *_data) { data = _data; };
   void   setNext(Node *_next) { next = _next; };
   void   setTag(std::string _tag)  {tag = _tag; };
   void*  Data() { return data; };
   Node*  Next() { if(data == NULL) { return NULL; } return next; };
   std::string Tag()  { return tag; };
};   


class List 
{
   Node *head;
   Node *tail;
   Node *current;
public:
   List() 
   { current = head = NULL; } 
   Node* Current();
   void  Next();
   void  Print();
   void  Push(void *_new, std::string _tag);
   void  Pop();
   void  Remove_node(std::string _tag);
   void  Delete();
   Node* getbyTag(List *list, std::string _tag);
   void  Reset();
   bool  end(); //determines if the current pointer is on the end of the list.
};