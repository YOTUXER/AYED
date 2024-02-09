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

#include <cmath>
#include <iostream>

#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "vector_t.hpp"

int main (int argc, char** argv) {
  rational_t a(1, 2), b(3);

  // FASE I
  std::cout << "a + b: ";
  (a + b).write();

  std::cout << "b - a: ";
  (b - a).write();

  std::cout << "a * b: ";
  (a * b).write();

  std::cout << "a / b: ";
  (a / b).write();

  std::cout << std::endl;

  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();

  std::cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w)
            << std::endl
            << std::endl;

            
  std::cout << "Modificacion" << std::endl;
  sumar_los_elementos_de_un_vector_2_a_2(v);
  std::cout << "Fin Modificacion" << std::endl;


  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();

  std::cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y)
            << std::endl
            << std::endl;

  // FASE III
  matrix_t<double> A, B, C, D;
  A.read(), A.write();
  B.read(), B.write();

  C.multiply(A, B);
  std::cout << "Multiplicación de matrices A y B: " << std::endl;
  C.write();

  return 0;
}