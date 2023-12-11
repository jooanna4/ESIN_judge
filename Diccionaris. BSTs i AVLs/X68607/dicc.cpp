#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc() : _arrel(nullptr), _mida(0) {}

    // Les tres grans: Constructora per còpia, destructora, operador d’assignació
    dicc(const dicc &d);
    ~dicc();
    dicc& operator=(const dicc &d);

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Elimina la clau k del diccionari. Si no hi era, no fa res.
    void elimina(const Clau &k);

    // Consulta si la clau k està en el diccionari.
    bool consulta(const Clau &k) const;

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de claus del diccionari en ordre ascendent, separades per
    // un espai, començant per ’[’ i acabant per ’]’, en dues versions:
    // Imprimeix totes les claus
    void print() const;
    // Imprimeix les claus entre k1 i k2 ambdós incloses. Pre: k1 <= k2
    void print_interval(const Clau &k1, const Clau &k2) const;

    // Retorna la clau més petita i la més gran respectivament.
    // Pre: El diccionari no està buit
    Clau min() const;
    Clau max() const;

    // Retorna la clau de la posició i-èssima (comptant-les en ordre ascendent).
    // Pre: El diccionari no està buit. 1 <= i <= quants()
    Clau iessim(nat i) const;
    
private:
  // Aquí van els atributs i mètodes privats
  struct node {
    Clau _k;
    node *_esq;
    node *_dret;
  };
  node *_arrel;
  nat _mida;

  node *copia_arbre(node *n);
  node *esborra_arbre(node *n);
  node *insereix_clau(node *n, Clau k);
  node *elimina_clau(node *n, Clau k);
  node *ajunta(node *n1, node *n2);
  node *troba_maxim(node *n);
  void imprimeix(node *n);
  void imprimirinterval(node *n, Clau k1, Clau k2);

};
 
// Aquí va la implementació dels mètodes públics i privats
dicc<Clau>::node* dicc<Clau>::copia_arbre(node *n) {
    node *nou(nullptr);
    if(n != nullptr) {
        nou = new node;
        nou->_k = n->_k;
        nou->_esq = copia_arbre(n->_esq);
        nou->_dret = copia_arbre(n->_dret);
    }
    return nou;
}

dicc<Clau>::node* dicc<Clau>::esborra_arbre(node *n) {
    if (n != nullptr) {
        n->_esq = esborra_arbre(n->_esq);
        n->_dret = esborra_arbre(n->_dret);
        delete(n);
    }
}

dicc<Clau>::node* dicc<Clau>::insereix_clau(node *n, Clau k) {
    if (n != nullptr) {
        if (k < n->_k)
            n->_esq = insereix_clau(n->_esq);
        else if (k > n->_k)
            n->_dret = insereix_clau(n->_dret);
    }
    else {
        n = new node;
        n->_k = k;
        n->_esq = nullptr;
        n->_dret = nullptr;
        _mida++;
    }
    return n;
}

dicc<Clau>::node* dicc<Clau>::elimina_clau(node *n, Clau k) {
    if (n != nullptr) {
        if (k < n->_k)
            n->_esq = elimina_clau(n->_esq, k);
        else if (k > n->_k)
            n->_dret = elimina_clau(n->_dret, k);
        else {
            node *aux = n;
            n = ajunta(n->_esq, n->_dret);
            delete(aux);
            _mida--;
        }
    }
    return n;
}

dicc<Clau>::node* dicc<Clau>::ajunta(node *n1, node *n2) {
    node n;
    if (n1 == nullptr)
        n = n2;
    else if (n2 == nullptr)
        n = n1;
    else {
        n = troba_maxim(n1);
        n->_dret = n2;
    }
    return n;
}

dicc<Clau>::node* dicc<Clau>::troba_maxim(node *n) {
    node *pare(nullptr), n_orig(n);
    while (n->_dret != nullptr) {
        pare = n;
        n = n->_dret;
    }
    if (pare != nullptr) {
        pare->_dret = n->_esq;
        n->_esq = n_orig;
    }
}

void dicc<Clau>::imprimeix(node *n) {
    if (n != nullptr) {
        imprimeix(n->_esq);
        cout << n->_k << " ";
        imprimeix(n->_dret);
    }
}

void dicc<Clau>::imprimirinterval(node *n, Clau k1, Clau k2) {
    if (n != nullptr) {
        if (n->_k >= k1 && n->_k <= k2) {
            imprimirinterval(n->_esq, k1, k2);
            cout << n->_k << " ";
            imprimirinterval(n->_dret, k1, k2);
        }
    }
}

dicc<Clau>::dicc(const dicc &d) {
    _arrel = copia_arbre(d._arrel);
    _mida = d._mida;
}
dicc<Clau>::~dicc() {
    _arrel = esborra_arbre(_arrel);
    _mida = 0;
}
dicc& dicc<Clau>::operator=(const dicc &d) {
    _arrel = copia_arbre(d._arrel);
    return *this;
}

void dicc<Clau>::insereix(const Clau &k) {
    _arrel = insereix_clau(_arrel, k);
}

void dicc<Clau>::elimina(const Clau &k) {
    _arrel = elimina_clau(_arrel, k);
}

bool dicc<Clau>::consulta(const Clau &k) const {
    node *n = _arrel;
    bool found(false);
    while (n != nullptr and not found) {
        if (n->_k > k)
            n = n->_esq;
        else if (n->_k < k)
            n = n->_dret;
        else
            found = true;
    }
    return found;
}

nat dicc<Clau>::quants() const {
    return _mida;
}

void dicc<Clau>::print() const {
    cout << "[";
    imprimeix(_arrel);
    cout << "]";
}

void dicc<Clau>::print_interval(const Clau &k1, const Clau &k2) const {
    cout << "[";
    imprimirinterval(_arrel, k1, k2);
    cout << "]";
}

Clau dicc<Clau>::min() const {
    node *aux = _arrel;
    while (aux->_esq != nullptr) {
        aux = aux->_esq;
    }
    return aux->_k;
}

Clau dicc<Clau>::max() const {
    node *aux = _arrel;
    while (aux->_dret != nullptr) {
        aux = aux->_dret;
    }
    return aux->_k;
}

Clau dicc<Clau>::iessim(nat i) const {
    return _arrel->_k;
}