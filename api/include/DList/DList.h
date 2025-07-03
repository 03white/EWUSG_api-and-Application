#ifndef DLIST_H
#define DLIST_H
#include<string>
namespace EWUSG{

struct DbListNode{
    int key_;
    std::string val_;
    DbListNode*pre_;
    DbListNode*next_;
    DbListNode(int key=-1,std::string val="空",DbListNode*pre=nullptr,DbListNode*next=nullptr):key_(key),val_(val){}
};

class DbLinkedList{
public:
   DbLinkedList(){}
   ~DbLinkedList();
   bool empty();
   void push_back(int key,std::string val);
   void push_front(int key,std::string val);
   bool find(int key);
   void clear();
private:
   DbListNode*head_;
   DbListNode*tail_;
   void makeEmpty();
};

}
#endif
