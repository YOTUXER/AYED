/*
AUTOR: Javier Farrona Cabrera
FECHA: 15-03-2023
EMAIL: alu0101333021@ull.edu.es
VERSION: 1.0
ASIGNATURA: Algoritmos y Estructuras de Datos
PRÁCTICA Nº: 3
ESTILO: Google C++ Style Guide
COMENTARIOS:
*/

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <math.h>  // fabs, pow

#include <iostream>

#include "sparse_vector_t.h"
#include "vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n){};
  Polynomial(const Polynomial& pol)
      : vector_t<double>(pol){};  // constructor de copia

  // destructor
  ~Polynomial(){};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n){};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol){};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial(){};

  // E/S
  void Write(std::ostream& = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;

  //MODIFICACION
  void Mostrar_solo_elementos_pares();
};

// metodos para entrada y salida de informacion
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool end{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!end ? " + " : "") << at(i)
         << (i > 1      ? " x^"
             : (i == 1) ? " x"
                        : "");
      if (i > 1) os << i;
      end = false;
    }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {
  double resultado{0.0};
  for (size_t i = 0; i < get_size(); i++) {
    resultado += get_val(i) * pow(x, i);
  }

  return resultado;
}

// Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool son_diferentes = false;
  int end = 0;
  if ((get_size() - pol.get_size()) < 0) {
    end = get_size();
  } else {
    end = pol.get_size();
  }

  for (size_t i = 0; i < end; i++) {
    if (fabs(get_val(i) - pol.get_val(i)) >= eps) {
      son_diferentes = true;
    }
  }

  return !son_diferentes;
}

// constructor de copia
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;
}

// E/S
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool end{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!end ? " + " : "") << at(i).get_val()
       << (inx > 1      ? " x^"
           : (inx == 1) ? " x"
                        : "");
    if (inx > 1) os << inx;
    end = false;
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (size_t i = 0; i < get_nz(); i++) {
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }

  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol,
                               const double eps) const {
  bool son_diferentes = false;
  int end = 0;
  if ((get_nz() - spol.get_nz()) < 0) {
    end = get_nz();
  } else {
    end = spol.get_nz();
  }

  for (size_t i = 0; i < end; i++) {
    if (fabs(at(i).get_val() - spol.at(i).get_val()) >= eps) {
      son_diferentes = true;
    }
  }

  return !son_diferentes;
}

// Comparación si son iguales dos polinomios representados por vector disperso y vector denso
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool son_diferentes = false;
  int end = 0;
  if ((get_nz() - pol.get_size()) < 0) {
    end = get_nz();
  } else {
    end = pol.get_size();
  }

  for (size_t i = 0; i < end; i++) {
    if (fabs(at(i).get_val() - pol.at(at(i).get_inx())) >= eps) {
      son_diferentes = true;
    }
  }

  return !son_diferentes;
}


void SparsePolynomial::Mostrar_solo_elementos_pares() 
{
  for (int i = 0; i < get_nz(); i++) 
  {
    if ((at(i).get_inx() % 2) == 0) {
      std::cout << at(i).get_val() << " ";
    }
  }
}

#endif  // POLYNOMIAL_H_
