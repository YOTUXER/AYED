 /*
 AUTOR: Javier Farrona Cabrera
 FECHA: 11/02/2024
 EMAIL: alu0101541983@ull.edu.es
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 1
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
public: // elementos publicos
  rational_t(const int = 0, const int = 1); // constructor con parámetros
  ~rational_t() {} // destructor por defecto
  
  // usaremos 2 espacios indentados
  // getters
  int get_num() const; // metodo para adquirir numerador
  int get_den() const; // metodo para adquirir denominador

  // setters
  void set_num(const int); // metodo para implantar el numerador
  void set_den(const int); // metodo para implantar el denominador

  double value(void) const; // metodo que devuelve el valor del racional

  // FASE II
bool is_equal(const rational_t&, const double precision = EPSILON) const; // metodo para saber si dos racionales son iguales
bool is_greater(const rational_t&, const double precision = EPSILON) const; // metodo para saber si un racional es mayor que otro
bool is_less(const rational_t&, const double precision = EPSILON) const; // metodo para saber si un racional es menor que otro
  
  // FASE III
rational_t add(const rational_t&); // metodo para sumar
rational_t substract(const rational_t&); // metodo para restar
rational_t multiply(const rational_t&); // metodo para multiplicar
rational_t divide(const rational_t&); // metodo para dividir
  
void write(ostream& = cout) const; // metodo de escritura de numeros racionales
void read(istream& = cin); // metodo de lectura de numeros racionales

rational_t resta(rational_t&); // metodo para restarle la unidad a un racional
  
private: // elementos privados
  // atributos finalizados con "_"
  int num_, den_; //atributos privados del numero racional
};
