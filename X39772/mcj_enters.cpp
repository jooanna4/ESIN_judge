#include "mcj_enters.hpp"

// Constructora per defecte. Crea un multiconjunt buit.
mcj_enters::mcj_enters() { size = 0; }

// Les tres grans: Constructora per còpia, destructora, operador d'assignació
mcj_enters::mcj_enters(const mcj_enters &cj) {
    for (int i = 0; i < size; i++) {
        v[i] = cj.v[i];
    }
    size = cj.size;
}

mcj_enters::~mcj_enters() { }

mcj_enters& mcj_enters::operator=(const mcj_enters &cj) {
    size = cj.size;
    for (int i = 0; i < size; i++) {
        v[i] = cj.v[i];
    }
    return *this;
}

// Insereix l’enter e en el multiconjunt.
void mcj_enters::insereix(int e) {
    int aux;
    for (int i = 0; i < size; i++) 
        if (e <= v[i]) aux = i;
    for (int i = size; aux < i; i--) {
        v[i+1] = v[i];
    }
    v[aux] = e;
    size++;
}

// Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt sobre el que s’aplica
// el mètode, usant el segon multiconjunt com argument. P.e.: a.restar(b) fa que el nou valor d’a sigui
// A - B, on A i B són els valors originals dels objectes a i b.
void mcj_enters::unir(const mcj_enters& B) {
    if (*this == B) return;
    else {
        int aux[size];
        int i = 0, j = 0, it = 0;
        while ((i < size) or (j < B.size)) {
            if (v[i] == B.v[j]) {
                i++; j++;
                aux[it] = v[i];
                it++;
            }
            else if (v[i] < B.v[j]) {
                i++;
                aux[it] = v[i];
                it++;
            }
            else {
                j++;
                aux[it] = B.v[j];
                it++;
            }
        }
        size = it;
        // Copia de la intersecció
        for (int i = 0; i < size; i++) {
            v[i] = aux[i];
        }
    }
}

void mcj_enters::intersectar(const mcj_enters& B) {
    if (*this == B) return;
    else {
        int aux[size];
        int i = 0, j = 0, it = 0;
        while ((i < size) or (j < B.size)) {
            if (v[i] == B.v[j]) {
                i++; j++;
                aux[it] = v[i];
                it++;
            }
            else if (v[i] < B.v[j]) i++;
            else j++;
        }
        size = it;
        // Copia de la intersecció
        for (int i = 0; i < size; i++) {
            v[i] = aux[i];
        }
    }
}

void mcj_enters::restar(const mcj_enters& B) {

}

// Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt sense modificar el con-
// junt sobre el que s’aplica el mètode. La suma de multiconjunts correspon a la unió, la resta a la
// diferència i el producte a la intersecció.
mcj_enters mcj_enters::operator+(const mcj_enters& B) const {

}

mcj_enters mcj_enters::operator*(const mcj_enters& B) const {

}

mcj_enters mcj_enters::operator-(const mcj_enters& B) const {

}

// Retorna cert si i només si e pertany al multiconjunt.
bool mcj_enters::conte(int e) const {
    for (int i = 0; i < size; i++) {
        if (v[i] == e) return true;
        if (v[i] > e) return false;
    }
    return false;
}

// Retornen els elements màxim i mínim del multiconjunt, respectivament.
// El seu comportament no està definit si el multiconjunt és buit.
int mcj_enters::max() const {
    if (size == 0) return -1;
    else return v[size-1];
}

int mcj_enters::min() const {
    if (size == 0) return -1;
    else return v[0];
}

// Retorna el nombre d’elements (la cardinalitat) del multiconjunt.
int mcj_enters::card() const {
    return size;
}


// Operadors relacionals. == retorna cert si i només si els
// dos multiconjunts (el paràmetre implícit i B) contenen els
// mateixos elements; != retorna cert si i només si els
// multiconjunts són diferents.
bool mcj_enters::operator==(const mcj_enters& B) const {
    for (int i = 0; i < size; i++) {
        if (v[i] != B.v[i]) return false;
    }
    return true;
}

bool mcj_enters::operator!=(const mcj_enters& B) const {
    return !(this == B);
}


// Imprimeix el multiconjunt d’enters, ordenats en ordre ascendent, sobre
// el canal de sortida os; el format és [e1 e2 ... en], és a dir, amb
// espais entre els elements i tancant la seqüència amb corxets.
void mcj_enters::print(ostream& os) const {
    os << "[";
    for (int i = 0; i < size; i++) {
        os << v[i];
        if (i!=size-1) os << " ";
    }
    os << "]";
}