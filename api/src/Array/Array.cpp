#include"../../include/Array/Array.h"
namespace EWUSG{

Array::Array(int capacity=100):capacity_(capacity),size_(0){
    this->array_=new DbLinkedList*[capacity_];
    this->prime_=this->caculateMaxPrime();   //计算当下最大的素数
}

bool Array::isElementEmpty(int pos){
    if(array_[pos]==nullptr)return true;
    else return false;
}

int Array::primeMode(int key){
    return key%prime_;    //通过 [除留余数法]来计算“哈希桶"的位置
}

//计算最大素数
int Array::caculateMaxPrime(){
    int maxPrime=1;
    for(int i=capacity_;i>=1;i--){
       bool flag=true;
       for(int j=2;j<i;j++){
          if(i%j==0){
            flag=false;
            break;
          }         
       }
       if(flag)return i;
    }
}

bool Array::emplace(int key,std::string val){
    int pos=this->primeMode(key);           //计算“哈希桶”的下标
    DbLinkedList*list=nullptr;
    if(isElementEmpty(pos)){                //如果当前“哈希桶”为空
      array_[pos]=new DbLinkedList;         //创建一个空的“哈希桶”
    }
    list=array_[pos];
    list->push_back(key,val);               //插入哈希表中
    return true;
}


}