#include"../../include/DList/DList.h"

namespace EWUSG{

DbLinkedList::DbLinkedList(){
       head_=new DbListNode;
       tail_=new DbListNode;
       head_->next_=tail_;
       tail_->pre_=head_; 
}


DbLinkedList::~DbLinkedList(){


}


bool DbLinkedList::empty(){
    if(head_->next_==tail_)return true;
    else return false;
}

void DbLinkedList::push_back(int key,std::string val){
    DbListNode*newNode=new DbListNode(key,val);
    //尾插
    newNode->next_=tail_;
    newNode->pre_=tail_->pre_;
    tail_->pre_->next_=newNode;
    tail_->pre_=newNode;
}

void DbLinkedList:: push_front(int key,std::string val){
    DbListNode*newNode=new DbListNode(key,val);
    //头插
    newNode->pre_=head_;
    newNode->next_=head_->next_;
    head_->next_->pre_=newNode;
    head_->next_=newNode;
}


bool DbLinkedList::find(int key){
    DbListNode*current=head_->next_;
    while(current!=tail_){
        if(current->key_==key)return true;
        current=current->next_;
    }
    return false;
}


void DbLinkedList::makeEmpty(){
     DbListNode*del=head_->next_;
     while(del){
        //拉链
        head_->next_=del->next_;
        del->next_->pre_=head_;
        //删除
        delete del;
        del=head_->next_;
     }
}

void DbLinkedList::clear(){
       makeEmpty();
}

}
