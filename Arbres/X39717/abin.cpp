#include "abin.hpp"

template <typename T>
typename Abin<T>::node* Abin<T>::copia_nodes(node* m,
         node* ant_in, node* seg_in, node* &pri_in, node* &ult_in) {
/* Pre: ant_in apunta a l'anterior en inordre de l'arbre copiat,
        seg_in apunta al següent en inordre de l'arbre copiat*/
/* Post: si m és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un arbre binari enfilat
   de nodes que són còpia de l'arbre apuntat per m,
   pri_in apunta al primer en inordre de l'arbre còpia,
   ult_in apunta a l'últim en inordre de l'arbre còpia */
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    try {
      n->info = m->info;
      n->thread_esq  = m->thread_esq;
      n->thread_dret = m->thread_dret;
      if (n->thread_esq) {
        n->f_esq = ant_in;
        if (ant_in == NULL) pri_in = n;
      } else {
        n->f_esq = copia_nodes(m->f_esq, ant_in, n, pri_in, ult_in);
      }
      if (n->thread_dret) {
        n->f_dret = seg_in;
        if (seg_in == NULL) ult_in = n;
      } else {
        n->f_dret = copia_nodes(m->f_dret, n, seg_in, pri_in, ult_in);
      }
    } catch(...) {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void Abin<T>::esborra_nodes(node* m) {
/* Pre: cert */
/* Post: no fa res si m és NULL, sinó allibera
   espai dels nodes de l'arbre binari apuntat per m */
  if (m != NULL) {
    if (not m->thread_esq)  esborra_nodes(m->f_esq);
    if (not m->thread_dret) esborra_nodes(m->f_dret);
    delete m;
  }
};

template <typename T>
Abin<T>::Abin(Abin<T>& ae, const T& x, Abin<T>& ad) {
/* Pre: cert */
/* Post: el resultat és un arbre amb x com arrel, ae com a fill
esquerre i ad com a fill dret. No fa còpia dels arbres ae i ad */
  _arrel = new node;
  try {
    _arrel->info = x;
  }
  catch (...) {
    delete _arrel;
    throw;
  }
  _arrel->f_esq = ae._arrel;
  _arrel->f_dret = ad._arrel;
  if (ae._arrel == NULL) {
    _arrel->thread_esq = true;
    _pri_inordre = _arrel;
  }
  else {
    _arrel->thread_esq = false;
    _pri_inordre = ae._pri_inordre;
    ae._ult_inordre->f_dret = _arrel;
  }
  if (ad._arrel == NULL) {
    _arrel->thread_dret = true;
    _ult_inordre = _arrel;
  } else {
    _arrel->thread_dret = false;
    _ult_inordre = ad._ult_inordre;
    ad._pri_inordre->f_esq = _arrel;
  }
  ae._arrel = NULL;
  ad._arrel = NULL;
}

template <typename T>
Abin<T>::Abin(const Abin<T> &a) {
  _pri_inordre = _ult_inordre = NULL;
  _arrel = copia_nodes(a._arrel, NULL, NULL, _pri_inordre, _ult_inordre);
};

template <typename T>
Abin<T>::~Abin() {
  esborra_nodes(_arrel);
};

template <typename T>
Abin<T>& Abin<T>::operator=(const Abin<T>& a) {
  if (this != &a) {
    node* aux;
    _pri_inordre = _ult_inordre = NULL;
    aux = copia_nodes(a._arrel, NULL, NULL, _pri_inordre, _ult_inordre);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
};
