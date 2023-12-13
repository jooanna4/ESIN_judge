#include <cstdlib>
using namespace std;
typedef unsigned int nat;

template <typename T>
class heap {
  public:
    heap(): _arrel(NULL), _nelems(0) {};
    // Pre: Cert
    // Post: El resultat és un heap sense cap element

    heap(heap<T> &he, const T &x, heap<T> &hd);
    // Pre: Cert
    // Post: El resultat és un heap amb x com arrel, he com a fill
    // esquerre i hd com a fill dret. No fa còpia dels heaps he i hd

    heap(const heap<T> &h);
    // Pre: Cert
    // Post: Crea un heap que és una còpia de h

    ~heap();
    // Pre: Cert
    // Post: El heap ha estat destruït

    bool empty() const;
    // Pre: Cert
    // Post: Retorna un booleà indicant si el heap està buit

    T min() const;
    // Pre: El heap no és buit
    // Post: Retorna l’element mínim del heap

    void elim_min();
    // Pre: El heap no és buit
    // Post: S’ha eliminat l’element mínim del heap o qualsevol d’ells si està repetit

  private:
    struct node {
      node* fesq;  // Punter al fill esquerre
      node* fdret; // Punter al fill dret
      node* pare;  // Punter al pare
      T info;
    };
    node* _arrel; // Arrel de l’arbre binari del heap
    int _nelems;  // Nombre d’elements del heap

    static node* copia_nodes(node* m, node *n_pare);
    static void esborra_nodes(node* m);

    void ultim(node* &ult, node* &pare_ult) const;
    // Pre: Cert
    // Post: ult conté el punter de l’últim element del heap (NULL si està buit)
    // pare_ult conté el punter del pare de l’últim element del heap (NULL si no en té)

    // Aquí va l’especificació dels mètodes privats addicionals
    static node *ajunta(node *ne, node *nd);
    static node* troba_maxim(node *n);
    static void enfonsa(node *n);
};

// Aquí va la implementació del mètode elim_min
template <typename T>
void heap<T>::elim_min() {
    if (_nelems == 0)
        return;
    else if (_nelems == 1) {
        delete(_arrel);
        _arrel = nullptr;
        _nelems = 0;
    }
    else {
        node *elim = _arrel;
        _arrel = ajunta(_arrel->fesq, _arrel->fdret);
        delete(elim);
        enfonsa(_arrel);
        --_nelems;
    }
}

template <typename T>
typename heap<T>::node* heap<T>::ajunta(node *ne, node *nd) {
    node *n;
    if (nd == nullptr) 
        n = ne;
    else if (ne == nullptr)
        n = nd;
    else if (ne->fdret ==  nullptr) {
        n = ne;
        n->fdret = nd;
    }
    else {
        n = troba_maxim(ne);
        n->fdret = nd;
    }
    return n;
}

template <typename T>
typename heap<T>::node* heap<T>::troba_maxim(node *n) {
// Pre: n != nullptr
    node *aux = n, *pare(nullptr);
    while (aux->fdret != nullptr) {
        pare = aux;
        aux = aux->fdret;
    }

    if (pare != nullptr)
        pare->fdret = aux->fesq;
    
    aux->fesq = n;

    return aux;
}

template <typename T>
void heap<T>::enfonsa(node *n) {
    node *enfonsat(n), *aux(n->fesq);
    if (aux == nullptr)
        aux = n->fdret;
    while (aux != nullptr) {
        if (aux->info < enfonsat->info) {
            T canvi(enfonsat->info);
            enfonsat->info = aux->info;
            aux->info = canvi;
            enfonsat = aux;
            aux = aux->fdret;
        }
        else
            break;
    }
}