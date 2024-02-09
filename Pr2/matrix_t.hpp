/*
AUTOR:JAVIER FARRONA CABRERA
FECHA: 02-03-23
EMAIL: alu0101541983@ull.edu.es
VERSION: 1.0
ASIGNATURA: Algoritmos y Estructuras de Datos
PRÁCTICA Nº: 2
  COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
 COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2
*/

#pragma once

#include <cassert>
#include <iostream>

#include "vector_t.hpp"

template <class T>
class matrix_t {
 public:  // elementos publicos
  matrix_t(const int = 0, const int = 0); //constructor
  ~matrix_t();//destructor

  void resize(const int, const int);//metodo para reescalar la matriz

  // getters
  int get_m(void) const;//metodo para obtener el numero de columnas
  int get_n(void) const;//metodo para obtener el numero de filas

  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);

  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;

  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&); //metodo para multiplicar matrices

 

  void write(std::ostream& = std::cout) const; //metodo para redactar la matriz
  void read(std::istream& = std::cin); //metodo 

 private:      // elementos privados
  int m_, n_;  // m_ filas y n_ columnas
  vector_t<T> v_;

  int pos(const int, const int) const;
};

template <class T>
matrix_t<T>::matrix_t(const int m, const int n) {
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T>
matrix_t<T>::~matrix_t() {}

template <class T>
void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T>
inline int matrix_t<T>::get_m() const {
  return m_;
}

template <class T>
inline int matrix_t<T>::get_n() const {
  return n_;
}

template <class T>
T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

template <class T>
T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template <class T>
const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

template <class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

template <class T>
void matrix_t<T>::write(std::ostream& os) const {
  os << get_m() << "x" << get_n() << std::endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j) os << at(i, j) << "\t";
    os << std::endl;
  }
  os << std::endl;
}

template <class T>
void matrix_t<T>::read(std::istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j) is >> at(i, j);
}

template <class T>
inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}

// FASE III: producto matricial
template <class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  T result;

  assert(A.get_n() == B.get_m());
  m_ = A.get_m();
  n_ = B.get_n();
  v_.resize(m_ * n_);
  for (int i = 1; i <= A.get_m(); i++) {
    for (int j = 1; j <= B.get_n(); j++) {
      for (int a = 1; a <= B.get_m(); a++) {
        at(i, j) = at(i, j) + A(i, a) * B(a, j);
      }
    }
  }
}