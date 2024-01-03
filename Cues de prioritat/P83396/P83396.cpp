#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct node {
    string nom;
    float edat;
    node *seg;
};

node *insereix(string client, float edat, node *n) {
    node *pnou = new node;
    pnou->nom = client;
    pnou->edat = edat;
    pnou->seg = nullptr;
    
    if (n == nullptr)
        return pnou;

    else if (edat > n->edat) {
        pnou->seg = n;
        return pnou;
    }
    
    else {
        node *ant = n, *aux = n->seg;

        while (aux != nullptr && aux->edat > edat) {
            ant = aux;
            aux = aux->seg;
        }

        if (ant != nullptr) ant->seg = pnou;
        else aux = pnou;
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
    while (n != nullptr) {
        cout << " " << n->nom;
        n = n->seg;
    }
}

int main () {
    int n;
    cin >> n;
    cin.ignore();

    string line, client, sedat;
    float edat;
    vector<node*> cua(n, nullptr);

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream mycin(line);

        while (mycin >> client) {
            if (not client.empty()) {
                mycin >> sedat;
                edat = stof(sedat);
                cua[i] = insereix(client, edat, cua[i]);
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
                if (not client.empty())
                    sortides.push_back(client);
            }
        }
        else if (ins == "ENTRA") {
            mycin >> client;
            mycin >> edat;
            mycin >> ncua;
            if (ncua <= n && ncua >= 0)
                cua[ncua-1] = insereix(client, edat, cua[ncua-1]);
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
