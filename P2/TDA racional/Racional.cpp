#include "Racional.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Racional::Racional() {
  num = 0;
  den = 1;
}

// Constructor
Racional::Racional(int n, int d) {
  num = n;
  den = d;
}

// Constructor de copia
Racional::Racional(const Racional &c) {
  num = c.num;
  den = c.den;
}

// Asignaci�n
void Racional::asignar(int n, int d) {
  num = n;
  den = d;
}

// Comparaci�n
bool Racional::comparar(Racional r) {
  return ((num * r.den == den * r.num) ? 1 : 0);
}

// Impresi�n en cout
void Racional::print() { cout << '(' << this->num << '/' << this->den << ')'; }

// Operador +
Racional Racional::operator+(const Racional &r) {
  return Racional(num * r.den + den * r.num, den * r.den);
}

// Operador *
Racional Racional::operator*(const Racional &r) {
  return Racional(num * r.num, den * r.den);
}

// Operador +=
void Racional::operator+=(const Racional &r) {
  num = num * r.den + den * r.num;
  den = den * r.den;
}

// Operador ==
bool Racional::operator==(const Racional &l) {
  return ((num * l.den == den * l.num) ? 1 : 0);
}

// Operador <<
ostream &operator<<(ostream &os, const Racional &r) {
  return os << '(' << r.num << '/' << r.den << ')';
}

// Operador >>
istream &operator>>(istream &is, Racional &r) {
  char caracter;
  int numerador, denominador;
  is >> caracter >> numerador >> caracter >> denominador >> caracter;
  r = Racional(numerador, denominador);
  return is;
}

// Simplificaci�n a forma irreducible
Racional Racional::simplifica() {
  int a, b;

  /* Casos base */
  if (num == 0)
    return Racional(0, den);
  else if (num == den)
    return Racional(1, 1);
  else if (num > den) {
    a = num;
    b = den;
  } else {
    a = den;
    b = num;
  }

  /* Algoritmo de Euclides */
  int r;
  do {
    r = a % b;
    a = b;
    b = r;
  } while (r > 0);

  return Racional(num /= a, den /= a);
}

double Racional::valorReal() {
  double d = den, n = num, r = 0;
  if (d != 0)
    r = n / d;
  return r;
}

Racional Racional::operator-(const Racional &r) {
  if (den != 0 && r.den != 0) {
    Racional rs(num * r.den - r.num * den, den * r.den);
    rs.simplifica();
    return rs;
  }
}

Racional Racional::operator/(const Racional &r) {
  if (r.num != 0) {
    Racional rs(num * r.den, den * r.num);
    rs.simplifica();
    return rs;
  }
}

bool Racional::es_irreducible() {
  bool irreducible = true;
  int menor = den < num ? den : num;

  if (num != 0) {
    for (int i = 2; i <= menor && irreducible; i++)
      if (num % i == 0 && den % i == 0)
        irreducible = false;
  }

  return irreducible;
}
