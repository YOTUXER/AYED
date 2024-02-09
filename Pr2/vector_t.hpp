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
#include "rational_t.hpp"

#pragma once

#include <cassert>
#include <iostream>

template <class T>
class vector_t {
 public:                    // elementos y metodos publicos
  vector_t(const int = 0);  // constructor
  ~vector_t();              // destructor

  void resize(const int); //metodo para reescalar el vector

  // getters
  T get_val(const int) const;  // metodo acceder a los atributos
  int get_size(void) const;    // metodo acceder a los atributos

  // setters
  void set_val(const int, const T);  // metodo acceder a los atributos

  // getters-setters
  T& at(const int);          // metodo acceder a los atributos
  T& operator[](const int);  // metodo acceder a los atributos

  // getters constantes
  const T& at(const int) const;          // metodo acceder a los atributos
  const T& operator[](const int) const;  // metodo acceder a los atributos

  void write(std::ostream& = std::cout) const;  // metodo lectura por pantalla
  void read(std::istream& = std::cin);          // metodo escritura por teclado

 private:   // elementos y metodos privados
  T* v_;    // valor del vector
  int sz_;  // atributo tamaño

  void build(void); //atributo constructor
  void destroy(void); //atributo destructor
};

template <class T> vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}

template <class T> vector_t<T>::~vector_t() {
  destroy();
}

template <class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template <class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> inline int vector_t<T>::get_size() const {
  return sz_;
}

template <class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template <class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}

template <class T> const T& vector_t<T>::at(const int i) const {
  //assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

template <class T> void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++) os << at(i) << "\t";
  os << std::endl;
}

template <class T> void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i) is >> at(i);
}

// FASE II: producto escalar
template <class T> T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  T resultado = 0;
  int i;
  for (i = 0; i < v.get_size(); i++) {
      resultado = resultado + (v[i] * w[i]);
  }
  return resultado;
}

double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  double resultado2 = 0;
  for (int i = 0; i < v.get_size(); i++) {
    resultado2 = resultado2 + ((v[i]).value() * (w[i]).value());
  }
  return resultado2;
}

//MODIFICACIÓN

vector_t<double> sumar_los_elementos_de_un_vector_2_a_2(const vector_t<double>& v) {
  assert (v.get_size() % 2 == 0);
  std::cout << "(";
  for (int i = 0; i < (v.get_size()-1); i++){
    double resultado3 = v[i] + v[i+1];
    std::cout << resultado3 << ", ";
  }
  std::cout << ")" << std::endl;
  return v;
}