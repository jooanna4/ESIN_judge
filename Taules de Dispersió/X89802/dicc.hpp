 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
class dicc {
  // Taula de dispersió sinònims encadenats indirectes
  // Les llistes de sinònims estan ordenades per clau
  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de totes les claus del diccionari segons l’ordre
    // en que estan a cadascuna de les llistes encadenades indirectes
    void print() const;

    // Pre: Cert
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const int &k);

    // Pre: El diccionari res està buit
    // Post: Omple res amb la intersecció entre el p.i. i d2
    void interseccio (dicc &d2, dicc &res);

  private:
    struct node_hash {
      int _k;           // Clau
      node_hash* _seg;
    };
    node_hash **_taula; // Taula amb punters a les llistes de sinònims
    nat _M;             // Mida de la taula
    nat _quants;        // Nº d’elements guardats al diccionari

    static long const MULT = 31415926;

    // Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
    static long h(int k);

    // Destrueix la llista de nodes apuntats per p
    static void esborra_nodes(node_hash *p);

    // Aquí va l’especificació dels mètodes privats addicionals
    bool conte(int k, dicc &d2);
};
 
// Aquí va la implementació dels mètodes públics insereix, interseccio i
// dels mètodes privats addicionals
void dicc::insereix(const int &k) {
  long i = h(k) % _M;
  node_hash *p = _taula[i], *pant(nullptr);
  bool found (false);
  while (p != nullptr and not found and p->_k <= k) {
    if (p->_k == k)
      found = true;
    else {
      pant = p;
      p = p->_seg;
    }
  }
  if (not found) {
    node_hash *aux = new node_hash;
    aux->_k = k;
    aux->_seg = p;
    if (pant != nullptr) pant->_seg = aux;
    else _taula[i] = aux;
    ++_quants;
  }
}

void dicc::interseccio(dicc &d2, dicc &res) {
  for (nat i = 0; i < _M; i++) {
    node_hash *aux = _taula[i];
    while (aux != nullptr) {
      if (conte(aux->_k, d2))
        res.insereix(aux->_k);
      aux = aux->_seg;
    }
  }
}

bool dicc::conte(int k, dicc &d2) {
  long i = d2.h(k) % d2._M;
  node_hash *p = d2._taula[i];
  bool found(false);
  while (p != nullptr && not found) {
    if (p->_k == k)
      found = true;
    else 
      p = p->_seg;
  }
  
  return found;
}