#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
template <class numeric>
numeric cuadrado(numeric x) {
  return x * x;
}

// Ejercicio 2: Pasar a templates
template <class Elem, class Contenedor>
bool contiene(Contenedor s, Elem c) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template <class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() > b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

// Ejercicio 4: Función maximo con un template contenedor y uno elemento
template<class Contenedor, class Elem>
Elem maximo(Contenedor c) {
    Elem max;
    for (int i = 0; i < c.size(); ++i) {
        if (i == 0) {
            max = c[i];
        }
        if (max < c[i]) {
            max = c[i];
        }
    }

    return max;
}
