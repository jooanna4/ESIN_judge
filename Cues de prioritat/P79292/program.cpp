#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

enum GRADUACIO {soldat, sergent, capita, coronel};

GRADUACIO stringToEnum(const std::string &graduacioStr) {
    static const std::unordered_map<std::string, GRADUACIO> graduacioMap = {
        {"soldat", soldat},
        {"sergent", sergent},
        {"capita", capita},
        {"coronel", coronel}
        // Puedes agregar más mapeos aquí según tus necesidades
    };

    auto it = graduacioMap.find(graduacioStr);
    if (it != graduacioMap.end()) {
        return it->second;
    } else {
        // Devolver un valor por defecto o manejar el error según tus necesidades
        return soldat; // Valor por defecto en caso de error
    }
}

struct node {
    string nom;
    GRADUACIO gradu;
    node *seg;
};

node *insereix(string client, GRADUACIO gradu, node *n) {
    node *pnou = new node, *aux(n);
    pnou->nom = client;
    pnou->gradu = gradu;
    pnou->seg = nullptr;

    if (aux == nullptr || gradu > aux->gradu) {
        pnou->seg = aux;
        return pnou;
    }
    
    else {
        node *ant = nullptr;
        while (aux != nullptr && aux->gradu >= gradu) {
            ant = aux;
            aux = aux->seg;
        }

        if (ant != nullptr) ant->seg = pnou;
        else n = pnou;
        pnou->seg = aux;
        
        return n;
    }
}

string elimina(node* &n) {
    string aux = "";
    if (n != nullptr) {
        aux = n->nom;
        node *elim = n;
        n = n->seg;
        delete(elim);
    }
    return aux;
}

void imprimeix (node *n) {
    node *aux(n);
    while (aux != nullptr) {
        cout << " " << aux->nom;
        aux = aux->seg;
    }
}

int main () {
    int n;
    cin >> n;
    cin.ignore();

    string line, client, gradu;
    node *cua[n] = {nullptr};

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream mycin(line);

        while (mycin >> client) {
            if (not client.empty()) {
                mycin >> gradu;
                cua[i] = insereix(client, stringToEnum(gradu), cua[i]);
            }
        }
    }

    string ins;
    int ncua;
    vector <string> sortides;
    while (getline(cin, line)) {
        istringstream mycin(line);
        mycin >> ins;
        if (ins == "SURT") {
            mycin >> ncua;
            if (ncua <= n && ncua >= 1) {
                client = elimina(cua[ncua-1]);
                if (client != "")
                    sortides.push_back(client);
            }
        }
        else if (ins == "ENTRA") {
            mycin >> client;
            mycin >> gradu;
            mycin >> ncua;
            if (ncua <= n && ncua >= 0)
                cua[ncua-1] = insereix(client, stringToEnum(gradu), cua[ncua-1]);
        }

    }
    
    cout << "SORTIDES" << endl;
    cout << "--------" << endl;
    for (int i = 0; i < sortides.size(); i++) {
        cout << sortides[i] << endl;
    }
    cout << endl;
    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "cua " << i+1 << ":";
        imprimeix(cua[i]);
        cout << endl;
    }
}
