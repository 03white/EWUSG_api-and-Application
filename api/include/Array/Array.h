#ifndef ARRAY_H
#define ARRAY_H
#include"../Dlist/DList.h"
namespace EWUSG{

class Array{
public:
  Array(size_t capacity=16);
  ~Array();
  bool emplace(int key,std::string val);
  bool find(int key);
private:
  int primeMode(int key);           //除留余数法来确定 “哈希桶” 的坐标
  bool isBucketEmpty(int pos);
  size_t caculateMaxPrime();        //计算当前容量下的最大素数
  double caculateLoadFactor();      //计算装载因子
  void expand();                    //2倍扩容
  DbLinkedList**array_;             //存储指向双链表指针的指针数组
  size_t number_;
  size_t capacity_;
  size_t prime_;
  double maxLoadFactor_;            //最大装载因子
};

}
#endif