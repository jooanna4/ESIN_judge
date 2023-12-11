#include <iostream>
using namespace std;

class Abin {
    private:
        struct node {
            int _info;
            node *_esq;
            node *_dret;
        };
        node *_arrel;
    public:
        Abin(): _arrel(nullptr);
        ~Abin();
        node* copia_nodes(node *n);
        node* esborra_nodes(node *n);
};

Abin::node* Abin::copia_nodes(node *n) {
    node *m(nullptr);
    if (n != nullptr) {
        m = new node;
        m->_info = n->_info;
        m->_esq = copia_nodes(n->_esq);
        m->_dret = copia_nodes(n->_dret);
    }
    return m;
}

Abin::node* Abin::esborra_nodes(node *n) {
    if (n != nullptr) {
        esborra_nodes(n->_esq);
        esborra_nodes(n->_dret);
        delete(n);
    }
}

int main () {

}