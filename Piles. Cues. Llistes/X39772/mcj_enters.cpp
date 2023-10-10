#include "mcj_enters.hpp"

// Constructora per defecte. Crea un multiconjunt buit.
mcj_enters::mcj_enters() { size = 0; }

// Les tres grans: Constructora per còpia, destructora, operador d'assignació
mcj_enters::mcj_enters(const mcj_enters &cj) {
    size = cj.size;
    for (int i = 0; i < size; i++) {
        v[i] = cj.v[i];
    }
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
    bool trobat = false;
    if (size == 0) {
        v[0] = e;
        size++;
        return;
    }
    for (int i = 0; i < size; i++) {
        if (e <= v[i]) {
            aux = i;
            trobat = true;
            break;
        }
    }
    if (trobat) {
        for (int i = size; aux < i; i--) {
            v[i] = v[i-1];
        }
        v[aux] = e;
    }
    else {
        v[size] = e;
    }
    size++;
}

// Unió, intersecció i diferència de multiconjunts. Operen modificant el multiconjunt sobre el que s’aplica
// el mètode, usant el segon multiconjunt com argument. P.e.: a.restar(b) fa que el nou valor d’a sigui
// A - B, on A i B són els valors originals dels objectes a i b.
void mcj_enters::unir(const mcj_enters& B) {
    *this = (*this)+B;
}

void mcj_enters::intersectar(const mcj_enters& B) {
    *this = (*this)*B;
}

void mcj_enters::restar(const mcj_enters& B) {
    *this = (*this)-B;
}

// Unió, intersecció i diferència de multiconjunts. Operen creant un nou multiconjunt sense modificar el con-
// junt sobre el que s’aplica el mètode. La suma de multiconjunts correspon a la unió, la resta a la
// diferència i el producte a la intersecció.
mcj_enters mcj_enters::operator+(const mcj_enters& B) const {
    mcj_enters aux;
    
    if (size == 0 and B.size != 0) aux = B;
    else if (size != 0 and B.size == 0) aux = *this;
    else if (*this == B) aux = *this;
    else if (size != 0 and B.size != 0) {
        int i = 0, j = 0, k = 0;
        while ((i < size) and (j < B.size)) {
            if (v[i] == B.v[j]) {
                aux.v[k] = v[i];
                i++; j++; k++;
            }
            else if (v[i] < B.v[j]) {
                aux.v[k] = v[i];
                i++; k++;
            }
            else {
                aux.v[k] = B.v[j];
                j++; k++;
            }
        }
        if (i == size) {
            while (j < B.size) {
                aux.v[k] = B.v[j];
                j++; k++;
            }
        }
        else {
            while (i < size) {
                aux.v[k] = v[i];
                i++; k++;
            }
        }
        
        aux.size = k;
    }

    return aux;
}

mcj_enters mcj_enters::operator*(const mcj_enters& B) const {
    mcj_enters aux;
    
    if (*this == B) aux = *this;
    else if (size != 0 and B.size != 0) {
        int i = 0, j = 0;
        while ((i < size) and (j < B.size)) {
            if (v[i] == B.v[j]) {
                aux.insereix(v[i]);
                i++; j++;
            }
            else if (v[i] < B.v[j]) i++;
            else j++;
        }
    }

    return aux;
}

mcj_enters mcj_enters::operator-(const mcj_enters& B) const {
    mcj_enters aux;
    
    if (size != 0 and B.size == 0) aux = *this;
    else if (size != 0 and B.size != 0) {
        int i = 0, j = 0;
        while ((i < size) and (j < B.size)) {
            if (v[i] == B.v[j]) {
                i++; j++;
            }
            else if (v[i] < B.v[j]) {
                aux.insereix(v[i]);
                i++;
            }
            else j++;
        }
        while (i < size) {
            aux.insereix(v[i]);
            i++;
        }
    }

    return aux;
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
    if (size != B.size) return false;
    for (int i = 0; i < size; i++) {
        if (v[i] != B.v[i]) return false;
    }
    return true;
}

bool mcj_enters::operator!=(const mcj_enters& B) const {
    return !(*this == B);
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