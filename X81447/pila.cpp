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
 
     void fusiona(const pila<T> &p2);
     // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic fusiona i privats addicionals
void pila<T>::fusiona(const pila<T> &p2) {
    if (_cim == nullptr and p2._cim == nullptr) return;
    
    node *pi = _cim, *pj = p2._cim, *aux = _cim;
    while() {
        if (pi != nullptr or pi->info > pj->info) {
            aux = pi;
            pi = pi->seg;
        }
        else {
            node *pnou = new node;
            pnou->info = pj->info;
            if (pi == _cim) {
                pnou->seg = _cim;
                _cim = pnou;
                aux = pnou;
            }
            else {
                aux->seg = pnou;
                pnou->seg = pi;
                aux = aux->seg;
            }
            pj = pj->seg;
        }
    }

}