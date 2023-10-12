#include "cua.hpp"

cua::cua() : _ult(nullptr), _long(0) {   
}

cua::cua(const cua &c) : _ult(nullptr), _long(c._long) {
  if (c._ult != nullptr) {
    _ult = new node;
    try {
      _ult->info = c._ult->info;
      _ult->seg = copiar(c._ult->seg, c._ult, _ult);
    }
    catch (...) {
      delete(_ult);
      throw;
    }
  }
}

cua::node* cua::copiar(node* n, node* fi, node* ini) {
  node* aux;
  if (n != fi) {
    aux = new node;
    try {
      aux->info = n->info;
      aux->seg = copiar(n->seg, fi, ini); 
    }
    catch (...) {
      delete aux;
      throw;
    }
  }
  else {
    aux = ini;
  }
  return aux;
}

cua& cua::operator=(const cua &c) {
  if (this != &c) {
    cua caux(c);
    node* naux = _ult;
    _ult = caux._ult;
    caux._ult = naux;
    nat l = _long;
    _long = caux._long;
    caux._long = l;
  }
  return *this;
}

cua::~cua() {
  if (_ult != nullptr) {
    node* fi = _ult;
    _ult = _ult->seg;
    while (_ult != fi) {
      node* aux = _ult;
      _ult = _ult->seg;
      delete aux;
    }
    delete(_ult);
  }
}

void cua::desencuar() { 
  if (_ult==nullptr) {
    throw CuaBuida;
  }
  node* p = _ult->seg;
  if (p == _ult) {
    _ult = nullptr; // desencuem una cua que tenia un únic 
  }              // element
  else {  
    _ult->seg = p->seg;
  }
  delete(p);
  _long--;
}

const int& cua::primer() const { 
  if (_ult==nullptr) { 
    throw CuaBuida;
  }
  return (_ult->seg->info);
}

bool cua::es_buida() const {  
  return (_ult==nullptr);
}

nat cua::longitud() const {
  return _long;
}
