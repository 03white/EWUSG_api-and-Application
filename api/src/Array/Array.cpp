#include"../../include/Array/Array.h"
namespace EWUSG{

Array::Array(size_t capacity=100):
       capacity_(capacity),
       number_(0),
       maxLoadFactor_(0.7){
    this->array_=new DbLinkedList*[capacity_];
    this->prime_=this->caculateMaxPrime();   //计算当下最大的素数
}

Array::~Array(){


}

bool Array::emplace(int key,std::string val){
    int pos=this->primeMode(key);           //计算“哈希桶”的下标
    DbLinkedList*list=nullptr;
    if(isBucketEmpty(pos)){                //如果当前“哈希桶”为空
      array_[pos]=new DbLinkedList;         //创建一个空的“哈希桶”
    }
    list=array_[pos];
    list->push_back(key,val);               //插入哈希表中
    number_++;
    return true;
}

bool Array::find(int key){
    int pos=this->primeMode(key);
    DbLinkedList*list=array_[pos];
    return list&&list->find(pos);          //两者都为true时，哈希表中存在该元素
}

int Array::primeMode(int key){
    return key%prime_;                     //通过 [除留余数法]来计算“哈希桶"的位置
}

//   判断“哈希桶”是否为空
bool Array::isBucketEmpty(int pos){
    if(array_[pos]==nullptr)return true;
    else return false;
}

//计算最大素数
size_t Array::caculateMaxPrime(){
    size_t maxPrime=1;
    for(size_t i=capacity_;i>=1;i--){
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

double Array::caculateLoadFactor(){
       return static_cast<double>(number_)/static_cast<double>(capacity_);
}
}