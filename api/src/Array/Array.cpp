#include"../../include/Array/Array.h"
namespace EWUSG{

Array::Array(int capacity=100){
    this->capacity_=capacity;
    this->array_=new DbLinkedList*[capacity_];
}

bool Array::isElementEmpty(int pos){
    if(array_[pos]==nullptr)return true;
    else return false;
}

int Array::primeMode(int key){
    return key%capacity_;
}

//计算最大素数
int Array::caculateMaxPrime(){
    int maxPrime=1;
    for(int i=1;i<capacity_;i++){
       bool flag=false;
       for(int j=2;j<i;j++){
                    
       }
    }
}

bool Array::emplace(int key,int val){
     int pos=this->primeMode(key);
}


}