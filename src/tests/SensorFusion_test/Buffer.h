#ifndef BUFFER_H
#define BUFFER_H

#include <Arduino.h>


std::template<std::typename T>class CircularBuffer {
  #define CIRC_BUFF_MAX_SIZE 256
public:
  CircularBuffer(uint8_t size) : head(0), tail(0), m_size(size) {}

  void enqueue(T &value);
  T* at(uint8_t index);
  T& operator[](uint8_t index);
  void debug();

private:
  T buffer[CIRC_BUFF_MAX_SIZE] = {0};

  T* head;
  T* tail;

  uint8_t m_size;
  
};



#endif