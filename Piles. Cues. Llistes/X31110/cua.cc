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
    node *pi(_pri), *p2(c2._pri), *pant;
    if (c2._pri == nullptr)
      return;
    
    _mida += c2._mida;

    if (p2->info < pi->info) {
      node *pnou = new node;
      pnou->info = p2->info;
      pnou->seg = pi;
      _pri = pnou;
      pant = _pri;
      p2 = p2->seg;
    }
    else {
      pant = pi;
      pi = pi->seg;
    }

    while (p2 != nullptr) {
      if (pi == nullptr) {
        node *pnou = new node;
        pnou->info = p2->info;
        pant->seg = pnou;
        pnou->seg = nullptr;
        _ult = pnou;
        p2 = p2->seg;
      }
      else if (p2->info < pi->info) {
        node *pnou = new node;
        pnou->info = p2->info;
        pant->seg = pnou;
        pnou->seg = pi;
        pant = pant->seg;
        p2 = p2->seg;
      }
      else {
        pi = pi->seg;
        pant = pant->seg;
      }
    }
}