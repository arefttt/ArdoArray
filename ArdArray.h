#ifndef ArdArray_h
#define ArdArray_h

#include "Arduino.h"

template <class T>
class ArdArray {
  public:
    ArdArray(T* array, int size);
    int search(T value);
    T max();
    T min();
    float average();
    void sort(bool ascending = true);
    void insert(int index, T value);
    void remove(int index);
    T* subarray(int start, int end);
    void shuffle();
    void reverse();
  private:
    T* _array;
    int _size;
};

#endif
