#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;
 
template <typename T>
class cua { // Cua no circular en memòria dinàmica
  public:
    cua();
    // Construeix una cua buida.
 
    ~cua();
    // Destrueix el p.i.
 
    cua(const vector<int> &v);
    // Crea cua amb els elements de v amb el mateix ordre.
 
    nat longitud() const;
    // Retorna el nombre d’elements del p.i.
 
    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.
 
    void fusiona(const cua<T> &c2);
    // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica
 
  private:
    struct node {
      T info;
      node* seg;
    };
    node* _pri; // Apunta al primer element de la cua
    node* _ult; // Apunta al darrer element de la cua
    nat _mida;
      // Aquí va l’especificació dels mètodes privats addicionals
};
 
// Aquí va la implementació del mètode públic fusiona i privats addicionals
template <typename T>
void cua<T>::fusiona(const cua<T> &c2) {
    if (c2._pri == nullptr and c2._ult == nullptr) return;

    _mida += c2._mida;
    node *pi = _pri, *pj = c2._pri, *aux = pi->seg;

    if (_pri == nullptr and _ult == nullptr) {
        node *pnou = new node;
        pnou->info = pj->info;
        _pri = pnou;
        _ult = pnou;
        _pri->seg = nullptr;
    }
    else if (pj->info < pi->info) {
        node *pnou = new node;
        pnou->info = pj->info;
        pnou->seg = pi;
        _pri = pnou;
        pi = _pri;
        aux = pi->seg;
        pj = pj->seg;
    }

    while (pj != nullptr) {
        if (aux == nullptr) {
            node *pnou = new node;
            pnou->info = pj->info;
            pi->seg = pnou;
            pnou->seg = nullptr;
            _ult = pnou;
            pj = pj->seg;
        }

        else if (pj->info < aux->info) {
            node *pnou = new node;
            pnou->info = pj->info;
            pnou->seg = aux;
            pi->seg = pnou;
        }

        else
            aux = aux->seg;
        
        pi = pi->seg;
    }
}