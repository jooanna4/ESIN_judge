#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    vector<nat> freq_longituds() const;
    // Pre: True
    // Post: Retorna un vector amb les freqüències de les longituds de les claus.
    // La mida del vector és igual a la longitud de la clau més llarga més un. 

  private:
    struct node {
      char _c;   // Símbol posició i-èssima de la clau
      node* _pf; // Primer fill, apunta a símbols de la següent posició
      node* _sg; // Següent germà, apunta a símbols de la mateixa posició
      node(const char &c, node* pf = NULL, node* sg = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    nat long_max(node *n);
};

// Aquí va la implementació del mètode públic freq_longituds i privats addicionals
vector<nat> dicc::freq_longituds() const {
    nat long_max(_arrel);
    vector<nat> res;
    
}

nat dicc::long_max(node *n) {
  if (n != nullptr) {
    
  }
}