#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    dicc();  // Constructora per defecte. Crea un diccionari buit.

    ~dicc(); // Destructora

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    nat quantes_comencen(string inicials);
    // Pre: inicials no conté el char ’#’
    // Post: Retorna el nº de claus que comencen per algun dels caràcters que conté inicials

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
    static void comenca(node *n, char c, node* &com);
    static void conta(node *n, nat &i);
};

// Aquí va la implementació del mètode públic quantes_comencen i privats addicionals
nat dicc::quantes_comencen(string inicials) {
    nat count = 0;
    if (_arrel != nullptr) {
        for (int i = 0; i < inicials.size(); i++) {
            node *com = nullptr;
            comenca(_arrel, inicials[i], com);
            if (com != nullptr) {
                nat aux = 0;
                conta(com->_cen, aux);
                count += aux;
            }
        }
    }
    return count;
}

void dicc::comenca(node *n, char c, node* &com) {
    if (n != nullptr) {
        if (n->_c > c) comenca(n->_esq, c, com);
        else if (n->_c < c) comenca(n->_dre, c, com);
        else com = n;
    }
}

void dicc::conta(node *n, nat &i) {
    if (n != nullptr) {
        conta(n->_esq, i);
        conta(n->_dre, i);
        conta(n->_cen, i);
        if (n->_c == '#')
            i++;
    }
}
