#ifndef HASHMAP_H
#define HASHMAP_H
#include"../Array/Array.h"
namespace EWUSG{

class HashMap{
public:
  HashMap(size_t capacity);
  ~HashMap();
private:
  Array*hashTable_;
  size_t capacity_;
};
}





















#endif