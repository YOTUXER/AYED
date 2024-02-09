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

rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

inline int rational_t::get_num() const { return num_; }

inline int rational_t::get_den() const { return den_; }

void rational_t::set_num(const int n) { num_ = n; }

void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

inline double rational_t::value() const {
  return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const {
  return rational_t((-1) * get_num(), get_den());
}

rational_t rational_t::reciprocal() const {
  return rational_t(get_den(), get_num());
}

// comparaciones
bool rational_t::is_equal(const rational_t& r, const double precision) const {
  return fabs(value() - r.value()) < precision;
}

bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}

bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}

// operaciones
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(),
                    get_den() * r.get_den());
}

rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}

rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}

// FASE I: operadores
rational_t operator+(const rational_t& a, const rational_t& b) {
  rational_t result;
  result.set_den(a.get_den() * b.get_den());
  result.set_num(a.get_num() * b.get_den() + b.get_num() * a.get_den());
  return result;
}

rational_t operator-(const rational_t& a, const rational_t& b) {
  rational_t result;
  result.set_den(a.get_den() * b.get_den());
  result.set_num(a.get_num() * b.get_den() - b.get_num() * a.get_den());
  return result;
}

rational_t operator*(const rational_t& a, const rational_t& b) {
  rational_t result;
  result.set_den(a.get_den() * b.get_den());
  result.set_num(a.get_num() * b.get_num());
  return result;
}

rational_t operator/(const rational_t& a, const rational_t& b) {
  rational_t result;
  result.set_den(a.get_den() * b.get_num());
  result.set_num(a.get_num() * b.get_den());
  return result;
}

// E/S
void rational_t::write(std::ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << std::endl;
}

void rational_t::read(std::istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

std::ostream& operator<<(std::ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

std::istream& operator>>(std::istream& is, rational_t& r) {
  r.read(is);
  return is;
}