#include <iostream>
using namespace std;
typedef unsigned int nat;

class Abin {
  public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<int> &ae, const int &x, Abin<int> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres
 
    // Les tres grans
    Abin(const Abin<int> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);
 
    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);
 
  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);
};

int main () {

}