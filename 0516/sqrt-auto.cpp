/* test-template2.cpp */
#include <iostream>

/*
class Square {
public:
  int data;
  Square (int _data) { data = _data * _data; }
  ~Square () {};
};

template <class T> class Square {
public:
  T data;
  Square (T _data) { data = _data * _data; }
  ~Square () {};
};
*/
template<class T>
class Square {
public:
  auto data;
  Square (auto _data) { data = _data * _data; }
  ~Square () {};
};

main () {
  Square a;
  Square b;

  std::cerr << a.data << std::endl;
  std::cerr << b.data << std::endl;
}
