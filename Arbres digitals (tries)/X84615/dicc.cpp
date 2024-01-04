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
      char _c;    // Símbol posició i-èssima de la clau
      node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
      node* _cen; // Fill central, apunta a símbols següent posició
      node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
      node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    static void maxima_longitud(node *n, int it, int &max);
    static void frequencies(node *n, vector<nat>&vec, int it);
};

// Aquí va la implementació del mètode públic freq_longituds i privats addicionals
vector<nat> dicc::freq_longituds() const {
    int max = 0;
    maxima_longitud(_arrel, 0, max);
    vector<nat> freq;
    if (max > 0) {
        freq = vector<nat> (max+1, 0);
        frequencies(_arrel, freq, 0);
    }

    return freq;
}

void dicc::maxima_longitud(node *n, int it, int &max) {
    if (n != nullptr) {
        maxima_longitud(n->_esq, it, max);

        if (n->_c == '#' && it > max)
            max = it;
        
        maxima_longitud(n->_cen, it+1, max);
        maxima_longitud(n->_dre, it, max);
    }
}

void dicc::frequencies(node *n, vector<nat>&vec, int it) {
    if (n != nullptr) {
        frequencies(n->_esq, vec, it);

        if (n->_c == '#')
            vec[it] += 1;

        frequencies(n->_cen, vec, it+1);
        frequencies(n->_dre, vec, it);
    }
}