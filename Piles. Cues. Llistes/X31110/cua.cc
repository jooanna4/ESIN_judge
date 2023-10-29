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
    node *p1(_pri), *p2(c2._pri), *pant;
    if (p2 == nullptr)
      return;
    else if (p1 == nullptr) {
      _pri = new node;
      _pri->info = p2->info;
      _pri->seg = nullptr;
      _ult = _pri;
      p1 = _pri;
      p2 = p2->seg;
      while (p2 != nullptr) {
        node *pnou = new node;
        pnou->info = p2->info;
        p1->seg = pnou;
        pnou->seg = nullptr;
        _ult = pnou;
        p1 = p1->seg;
        p2 = p2->seg;
      }
      _mida = c2._mida;
      return;
    }
    else {
      node *pnou = new node;
      if (p2->info < p1->info) {
        pnou->info = p2->info;
        pnou->seg = p1;
        _pri = pnou;
        pant = pnou;
        p2 = p2->seg;
        _mida++;
      }
      else {
        pant = p1;
        p1 = p1->seg;
      }
      while (p2 != nullptr) {
        if (p1 == nullptr) {
          pnou = new node;
          pnou->info = p2->info;
          pant->seg = pnou;
          pnou->seg = p1;
          pant = pant->seg;
          p2 = p2->seg;
          _ult = pnou;
          _mida++;
        }
        else if (p2->info < p1->info) {
          pnou = new node;
          pnou->info = p2->info;
          pant->seg = pnou;
          pnou->seg = p1;
          pant = pant->seg;
          p2 = p2->seg;
          _mida++;
        }
        else {
          p1 = p1->seg;
          pant = pant->seg;
        }
      }
    }
}