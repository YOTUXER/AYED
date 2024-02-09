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
#include <cmath>
#include <iostream>

#define EPSILON 1e-6

class rational_t {
 public:                                     // elementos publicos
  rational_t(const int = 0, const int = 1);  // Constructor
  ~rational_t() {}                           // destructor

  // getters
  int get_num() const;  // metodo para acceder al atributo
  int get_den() const;  // metodo para acceder al atributo

  // setters
  void set_num(const int);  // metodo para acceder a los atributos
  void set_den(const int);  // metodo para acceder a los atributos

  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  rational_t add(const rational_t&) const;
  rational_t substract(const rational_t&) const;
  rational_t multiply(const rational_t&) const;
  rational_t divide(const rational_t&) const;

  void write(std::ostream& os = std::cout) const;  // metodo leer por pantalla
  void read(std::istream& is = std::cin);  // metodo escribir por pantalla

 private:          // elementos privados
  int num_, den_;  // atributos privados
};

// sobrecarga de los operadores de E/S
std::ostream& operator<<(std::ostream& os, const rational_t&);  // sobrecarga del operador <<
std::istream& operator>>(std::istream& is, rational_t&);  // sobrecarga del operador >>

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);  // sobrecarga del operador +
rational_t operator-(const rational_t&, const rational_t&);  // sobrecarga del operador -
rational_t operator*(const rational_t&, const rational_t&);  // sobrecarga del operador *
rational_t operator/(const rational_t&, const rational_t&);  // sobrecarga del operador /