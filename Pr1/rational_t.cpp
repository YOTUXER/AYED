 /*
 AUTOR: Javier Farrona Cabrera
 FECHA: 18/02/2023
 EMAIL: alu0101541983@ull.edu.es
 VERSION: 1.0
 ASIGNATURA: Algoritmos y Estructuras de Datos
 PRÁCTICA Nº: 1
 COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) // constructor por parametros
{
  assert(d != 0);
  num_ = n, den_ = d;
}

int rational_t::get_num() const { // metodo que expresa el numerador
  return num_;
}

int rational_t::get_den() const { // metodo que expresa el denominador
  return den_;
}

void rational_t::set_num(const int n) { // metodo que define el numerador
  num_ = n;
}

void rational_t::set_den(const int d) { // metodo que define el denominador
  assert(d != 0);
  den_ = d;
}

double rational_t::value() const {  // metodo que expresa el numero racional
  return double(get_num()) / get_den();
}

// comparaciones
bool rational_t::is_equal(const rational_t& r, const double error) const { 
  if (num_ != r.num_) { //pasa a ser float
    double a = static_cast<double>(num_) / static_cast<double>(den_); // convierto a float para operar
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_); // pasa a ser float

    //si la diferencia es menor o igual que el error es true
    return (std::abs(a - b) <= error); // std::abs == valor absoluto 
  } else {
    return num_ == r.num_;
  }
}

bool rational_t::is_greater(const rational_t& r, const double error) const {
  if (num_ != r.num_) { //pasa a ser float
    double a = static_cast<double>(num_) / static_cast<double>(den_);
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_);

    // si la diferencia es menor que el error es true
    return ((a - b) < error); 
  } else {
    return false;
    }
}

bool rational_t::is_less(const rational_t& r, const double error) const {
  if (num_ != r.num_) { //pasa a ser float
    double a = static_cast<double>(num_) / static_cast<double>(den_);
    double b = static_cast<double>(r.num_) / static_cast<double>(r.den_);

    // si la diferencia es menor que error negativa es true
    return ((b - a) < error);
  } else {
    return false;
  }
}

// operaciones implementadas
rational_t rational_t::add(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = ((a * d) + (b * c));
  int new_den = (b * d);
  rational_t add(new_num, new_den);
  return add;
}

rational_t rational_t::substract(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (c - a);
  int new_den = (d - b);
  rational_t substract(new_num, new_den);
  return substract;
}

rational_t rational_t::multiply(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (a * c);
  int new_den = (b * d);
  rational_t multiply(new_num, new_den);
  return multiply;
}

rational_t rational_t::divide(const rational_t& r) {
  int a, b, c, d;
  a = num_;
  b = den_;
  c = r.num_;
  d = r.den_;
  int new_num = (a * d);
  int new_den = (b * c);
  rational_t divide(new_num, new_den);
  return divide;
}


void rational_t::write(ostream& os) const {// metodo para mostrar un racional
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is) {// metodo para leer el racional
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

rational_t rational_t::resta(rational_t& r) {
  int a, b;
  a = num_;
  b = den_;
  int new_num = a - b;
  rational_t resta(new_num, b);
  return resta;
}
