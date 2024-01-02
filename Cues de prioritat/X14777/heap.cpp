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
    static void enfonsa(node *n);
};

// Aquí va la implementació del mètode elim_min
template <typename T>
void heap<T>::elim_min() {
    node *ult, *pare_ult;
    ultim(ult, pare_ult);
    if (ult == nullptr)                 // no té cap element
        return;
    else if (pare_ult == nullptr) {     // té un element
        delete (_arrel);
        _arrel = nullptr;
    }
    else {                              // té més d'un element
        if (pare_ult->fesq == ult)
            pare_ult->fesq = nullptr;
        else
            pare_ult->fdret = nullptr;
        _arrel->info = ult->info;
        delete(ult);
        enfonsa(_arrel);
    }
    _nelems--;
}

template <typename T>
void heap<T>::enfonsa(node *n) {
  if (n->fdret == nullptr && n->fesq == nullptr)                  // No té fills
    return;
  
  else if (n->fesq == nullptr || n->fdret == nullptr) {           // Te un fill
    if (n->fesq != nullptr && n->fesq->info < n->info) {
      T aux = n->info;
      n->info = n->fesq->info;
      n->fesq->info = aux;
      enfonsa(n->fesq);
    }

    else if (n->fdret != nullptr && n->fdret->info < n->info) {
      T aux = n->info;
      n->info = n->fdret->info;
      n->fdret->info = aux;
      enfonsa(n->fdret);
    }
    return;
  }

  else {
    if (n->fesq->info < n->fdret->info) {
      if (n->fesq->info < n->info) {
        T aux = n->info;
        n->info = n->fesq->info;
        n->fesq->info = aux;
        enfonsa(n->fesq);
      }
    }
    else {
      if (n->fdret->info < n->info) {
        T aux = n->info;
        n->info = n->fdret->info;
        n->fdret->info = aux;
        enfonsa(n->fdret);
      }
    }
  }
}
