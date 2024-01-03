 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   // Diccionari implementat en un BST on les claus poden estar repetides.
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Imprimeix el contingut del diccionari: Nombre d’elements i
     // totes les claus de més petita a més gran separades per un espai
     void print() const;
 
     void insereix(const Clau &k);
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari.
 
     nat quantes(const Clau &k) const;
     // Pre: Cert
     // Post: Retorna el nombre de claus iguals a k
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
     };
     node *_arrel;
     nat _n;       // Nombre d’elements del diccionari
 
     // Elimina els nodes del subarbre apuntat per p
     static void esborra_nodes(node* p);
     // Imprimeix ordenades les claus del subarbre apuntat per p
     static void print(node* p);
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static node* insert(node *n, const Clau &k);
     static void cuantas(node *n, nat &i, const Clau &k);
 };
 
 // Aquí va la implementació dels mètodes públics i dels mètodes privats addicionals
 template <typename Clau>
 void dicc<Clau>::insereix(const Clau &k) {
    _arrel = insert(_arrel, k);
    _n++;
 }

 template <typename Clau>
 typename dicc<Clau>::node* dicc<Clau>::insert(node *n, const Clau &k) {
    if (n != nullptr) {
        if (k < n->_k) n->_esq = insert(n->_esq, k);
        else n->_dret = insert(n->_dret, k);
    }
    else {
        n = new node;
        n->_k = k;
        n->_esq = nullptr;
        n->_dret = nullptr;
    }
    return n;
 }


 template <typename Clau>
 nat dicc<Clau>::quantes(const Clau &k) const {
    nat i = 0;
    cuantas(_arrel, i, k);
    return i;
 }

 template <typename Clau>
 void dicc<Clau>::cuantas(node *n, nat &i, const Clau &k) {
    if (n != nullptr) {
        if (k == n->_k) {
            i++;
            cuantas(n->_dret, i, k);
        }
        else if (k < n->_k)
            cuantas(n->_esq, i, k);
        else
            cuantas(n->_dret, i, k);
    }
 }
