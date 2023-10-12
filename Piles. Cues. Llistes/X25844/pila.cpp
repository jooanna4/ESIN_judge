#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename T>
class pila { // pila en memòria dinàmica
  public:
    pila();
    // Crea pila buida

    ~pila();
    // Destrueix el p.i.
 
    pila(const vector<int> &v);
    // Crea pila amb els elements de v amb el mateix ordre.
 
    nat longitud() const;
    // Retorna el nombre d’elements del p.i.
 
    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.
 
    void duplica_amb_sumes();
    // Pre: true
    // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
    // nou element que conté la suma dels elements restants de la pila original
 
  private:
    struct node {
      T info;
      node* seg;
    };
    node* _cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila
 
    // Aquí va l’especificació dels mètodes privats addicionals
};
 
// Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals
template <typename T>
void pila<T>::duplica_amb_sumes() {
    if (_cim == nullptr)
        return;
    _mida *= 2;
    node *p(_cim), *pseg;
    
    int cont = 0;
    while (p != nullptr) {
        cont += p->info;
        p = p->seg;
    }

    p = _cim;
    if (p != nullptr)
        pseg = p->seg;

    node *pcont = new node;
    pcont->info = cont;
    pcont->seg = _cim;
    _cim = pcont;
    while (pseg != nullptr) {
        cont -= p->info;
        pcont = new node;
        pcont->info = cont;
        p->seg = pcont;
        pcont->seg = pseg;
        p = pseg;
        pseg = pseg->seg;
    }
}