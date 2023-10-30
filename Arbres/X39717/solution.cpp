#include "abin.hpp"

template <typename T>
list<T> Abin<T>::preordre() const {
  list<T> aux;
  node *n = _arrel;
  if (n != nullptr) aux.push_back(n->info);
  while (n != nullptr) {
    if (not n->thread_esq) {
      n = n->f_esq;
      aux.push_back(n->info);
    }
    else if (not n->thread_dret) {
      n = n->f_dret;
      aux.push_back(n->info);
    }
    else {
      while (n->thread_dret) {
        n = n->f_dret;
        if (n == nullptr) break;
      }
      if (n != nullptr) {
        n = n->f_dret;
        aux.push_back(n->info);
      }
    }
  }
  return aux;
}
