#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
  public:
    // Constructora per defecte. Crea un graf buit de n vèrtexs.
    graf(nat n);

    // Destructora
    ~graf();

    // Retorna un vector amb els successors del vèrtex v
    vector<nat> successors(nat v) const;

    // Retorna un vector amb els predecessors del vèrtex v
    vector<nat> predecessors(nat v) const;

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són menors que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
          // Si l’aresta ja existia no fa res.

  private:
    nat nv; // Nombre de vèrtexs
    struct node {
      nat orig; // Vèrtex origen 
      nat dest; // Vèrtex destí 
      node *seg_succ; // Punter al següent successor
      node *seg_pred; // Punter al següent predecessor
    };
    vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                              // La llista de successors està ordenada.
    vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                              // La llista de predecessors està ordenada.

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic insereix i privats addicionals
void graf::insereix(nat orig, nat dest) {
    if (orig >= nv || dest >= nv) return; // Si los vértices no existen, no hacemos nada
    node *nou = new node; // Creamos un nuevo nodo
    nou->orig = orig;
    nou->dest = dest;
    nou->seg_succ = nullptr;
    nou->seg_pred = nullptr;
    // Añadimos el nuevo nodo a la lista de sucesores del vértice origen
    node *act = prim_succ[orig];
    node *ant = nullptr;
    while (act != nullptr && act->dest < dest) {
        ant = act;
        act = act->seg_succ;
    }
    if (act == nullptr || act->dest != dest) { // Si la arista no existe, la añadimos
        nou->seg_succ = act;
        if (ant == nullptr) prim_succ[orig] = nou;
        else ant->seg_succ = nou;
    }
    // Añadimos el nuevo nodo a la lista de predecesores del vértice destino
    act = prim_pred[dest];
    ant = nullptr;
    while (act != nullptr && act->orig < orig) {
        ant = act;
        act = act->seg_pred;
    }
    if (act == nullptr || act->orig != orig) { // Si la arista no existe, la añadimos
        nou->seg_pred = act;
        if (ant == nullptr) prim_pred[dest] = nou;
        else ant->seg_pred = nou;
    }
    else { // Si la arista ya existe, eliminamos el nodo creado
        delete nou;
    }
}
