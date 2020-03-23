#include <iostream>
#include<cstring>

using namespace std;

int d[100][100][100];
struct vector {
    char cod[225];
} al[100];

bool evaluate(bool automata) {
    if (automata)
        return true;
    else
        return false;
}

void found(char lit, vector sir[], int l, int poz) {
    for (int i = 0; i < l; i++) {
        int cifin = (int) sir[i].cod[0];
        int ciffin = (int) sir[i].cod[strlen(sir[i].cod) - 2];
        if (sir[i].cod[1] == '$') {
            int cont = 0;

            while (d[cifin][poz][cont] != -1)
                cont++;
            d[cifin][poz][cont] = ciffin;
        } else {
            if (strstr(sir[i].cod, reinterpret_cast<const char *>(lit)) != NULL) {
                int cont = 0;
                while (d[cifin][poz][cont] != -1)
                    cont++;
                d[i][poz][cont] = ciffin;
            }
        }
    }
}

int stare(char lit, int q, int m, char alf[]) {
    for (int j = 0; j < m; j++)
        if (lit == alf[j])
            q = d[q][j][0];
        else
            q = -1;
    return q;
}

void $nfa(int m, char alf[], int q0, int k, int stf[], int l, vector al[], char word[]) {
    for (int j = 0; j < m; j++)
        found(alf[j], al, l, j);
    int q = q0;
    for (int i = 0; i < strlen(word) - 1; i++) {
        q = stare(word[i], q, m, alf);
        if (q == -1)
            cout << evaluate(false);
    }
    for (int i = 0; i < k; i++)
        if (stf[i] == q)
            cout << evaluate(true);
    cout << evaluate(false);
}

int main() {
    int n, m, q0, k, stf[100], l;
    char alf[225], word[225];
    cin >> n >> m >> q0 >> k >> l;
    for (int i = 0; i < k; i++)
        cin >> stf[i];
    cin.get(alf, 225);
    cin.get();
    cin.get(word, 225);
    cin.get();
    for (int i = 0; i < l; i++)
        cin.get(al[i].cod, 225);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int g = 0; g < strlen(alf); g++)
                d[i][j][g] = -1;
    $nfa(m, alf, q0, k, stf, l, al, word);
    return 0;
}
