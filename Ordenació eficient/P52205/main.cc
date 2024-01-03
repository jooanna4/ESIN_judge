#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double>& v, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<double> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double>& v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        merge(v, l, m, r);
    }
}

void ordena_per_fusio(vector<double>& v) {
    int n = v.size();
    mergeSort(v, 0, n - 1);
}

int main()
{
    cout << fixed << setprecision(1);
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        ordena_per_fusio(v);
        for (int i = 0; i < n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}
