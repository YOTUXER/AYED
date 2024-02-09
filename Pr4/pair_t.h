/* 
AUTOR: Javier Farrona Cabrera
FECHA: 05-04-23
EMAIL: alu0101541983@ull.edu.es
VERSION: 1.0
ASIGNATURA: Algoritmos y Estructuras de Datos
PRÁCTICA Nº: 4
ESTILO: Google C++ Style Guide
COMENTARIOS:
*/

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); //constructor por defecto
  pair_t(T, int); //constructor por parámetros

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const; //getter del coeficiente
  int get_inx(void) const; // getter del grado
  void set(T, int); //setter de la pareja

  // E/S
  std::istream& read(std::istream& is = std::cin); //metodo para recibir una pareja
  std::ostream& write(std::ostream& os = std::cout) const; //metodo para mostrar una pareja

 private:
  T val_;
  int inx_;
};


template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

template<class T> pair_t<T>::~pair_t() {}

template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

template<class T> T pair_t<T>::get_val() const {
  return val_;
}

template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
