#include "Arduino.h"
#include "ArdArray.h"

template <class T>
ArdArray<T>::ArdArray(T* array, int size) {
  _array = array;
  _size = size;
}

template <class T>
int ArdArray<T>::search(T value) {
  for(int i = 0; i < _size; i++) {
    if(_array[i] == value) {
      return i;
    }
  }
  return -1; // Return -1 if the value is not found
}

template <class T>
T ArdArray<T>::max() {
  T maxValue = _array[0];
  for(int i = 1; i < _size; i++) {
    if(_array[i] > maxValue) {
      maxValue = _array[i];
    }
  }
  return maxValue;
}

template <class T>
T ArdArray<T>::min() {
  T minValue = _array[0];
  for(int i = 1; i < _size; i++) {
    if(_array[i] < minValue) {
      minValue = _array[i];
    }
  }
  return minValue;
}

template <class T>
float ArdArray<T>::average() {
  float sum = 0;
  for(int i = 0; i < _size; i++) {
    sum += _array[i];
  }
  return sum / _size;
}

template <class T>
void ArdArray<T>::sort(bool ascending) {
  for(int i = 0; i < _size - 1; i++) {
    for(int j = i + 1; j < _size; j++) {
      if((ascending && _array[i] > _array[j]) || (!ascending && _array[i] < _array[j])) {
        T temp = _array[i];
        _array[i] = _array[j];
        _array[j] = temp;
      }
    }
  }
}

template <class T>
void ArdArray<T>::reverse() {
  for(int i = 0; i < _size / 2; i++) {
    T temp = _array[i];
    _array[i] = _array[_size - i - 1];
    _array[_size - i - 1] = temp;
  }
}
template <class T>
void ArdArray<T>::shuffle() {
  for(int i = _size - 1; i > 0; i--) {
    int j = random(i + 1);
    T temp = _array[i];
    _array[i] = _array[j];
    _array[j] = temp;
  }
}
template <class T>
T* ArdArray<T>::subarray(int start, int end) {
  if(start < 0 || end >= _size || start > end) {
    Serial.println("Error: Invalid indices");
    return NULL;
  }
  
  T* subarray = new T[end - start + 1];
  
  for(int i = start; i <= end; i++) {
    subarray[i - start] = _array[i];
  }
  
  return subarray;
}
template <class T>
void ArdArray<T>::remove(int index) {
  if(index < 0 || index >= _size) {
    Serial.println("Error: Index out of bounds");
    return;
  }
  
  // Shift elements to the left of the index
  for(int i = index; i < _size - 1; i++) {
    _array[i] = _array[i + 1];
  }
  
  // Decrease the size
  _size--;
}
template <class T>
void ArdArray<T>::insert(int index, T value) {
  if(index < 0 || index > _size) {
    Serial.println("Error: Index out of bounds");
    return;
  }
  
  // Shift elements to the right of the index
  for(int i = _size; i > index; i--) {
    _array[i] = _array[i - 1];
  }
  
  // Insert the new value and increase the size
  _array[index] = value;
  _size++;
}
