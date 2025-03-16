#include<iostream>
#include<list>
#include<string>
#include<cmath>

using namespace std;

class EncadeamentoHash {
    private:
        list<int> *tabela;
        int m;
    
    public:
        EncadeamentoHash(int m): m{m} {
            tabela = new list<int>[m];
        }

        ~EncadeamentoHash() {
            delete [] tabela;
        }

        void adicionar(int k) {
            int i = k % m;
            tabela[i].emplace_back(k);
        }

        void mostrar_distribuicao() {
            for (int i = 0; i < m; ++i) {
                cout << i << ") ";
                for (auto k : tabela[i]) {
                    cout << '*';
                }
                cout << endl;
            }
        }

        bool buscar(int k) {
            int i = k % m;
            for (int elemento : tabela[i]) {
                if (elemento == k) {
                    return true;
                }
            }
            return false;
        }
};

class LinearHash {
    private:
        int *tabela;
        int m;
    public:
        LinearHash(int m): m{m} {
            tabela = new int[m];
            fill(tabela, tabela + m, -1);
        }

        ~LinearHash() {
            delete [] tabela;
        }

        void adicionar(int k) {
            int i = 0;
            while(tabela[ (k + i) % m ] != -1) ++i;
            tabela[(k + i) % m] = k;
        }

        void mostrar_distribuicao() {
            for (auto i = 0; i < m; ++i) {
                if (tabela[i] == -1) cout << "-";
                else cout << "*"; 
            }
            cout << endl;
        }

        bool buscar(int k) {
            int i = 0;
            int indice;
            while (true) {
                indice = (k + i) % m;
                if (tabela[indice] == k) return true;
                else if (tabela[indice] == -1) return false;
                ++i;
            }
        }
};

class QuadraticaHash {
    private:
        int *tabela;
        int m;
        int c1, c2;
    public:
        QuadraticaHash(int m, int c1, int c2): m{m}, c1{c1}, c2{c2} {
            tabela = new int[m];
            fill(tabela, tabela + m, -1);
        }

        ~QuadraticaHash() {
            delete [] tabela;
        }

        void adicionar(int k) {
            int i = 0;
            auto indice = (k + c1 * i + c2 * i*i) % m;
            while(tabela[indice] != -1) {
                ++i;
                indice = (k + c1 * i + c2 * i*i) % m;
            }
            tabela[indice] = k;
        }

        void mostrar_distribuicao() {
            for (auto i = 0; i < m; ++i) {
                if (tabela[i] == -1) cout << "-";
                else cout << "*"; 
            }
            cout << endl;
        }

        bool buscar(int k) {
            int i = 0;
            int indice;
            while (true) {
                indice = (k + c1 * i + c2 * i * i) % m;
                if (tabela[indice] == k) return true;
                else if (tabela[indice] == -1) return false;
                ++i;
            }
        }
};

class DuploHash {
    private:
        int *tabela;
        int m;

    public:
        DuploHash(int m): m{m} {
            tabela = new int[m];
            fill(tabela, tabela + m, -1);
        }

        ~DuploHash() {
            delete [] tabela;
        }

        int hash(int k, int i) {
            return (h1(k) + i * h2(k)) % m; 
        }

        int h1(int k) {
            return k % m;
        }

        int h2(int k) {
            return 1 + (k % (m-1));
        }

        void adicionar(int k) {
            int i = 0;
            auto indice = hash(k, i);
            while(tabela[indice] != -1) {
                ++i;
                indice = hash(k, i);
            }
            tabela[indice] = k;
        }

        void mostrar_distribuicao() {
            for (auto i = 0; i < m; ++i) {
                if (tabela[i] == -1) cout << "-";
                else cout << "*"; 
            }
            cout << endl;
        }

        bool buscar(int k) {
            int i = 0;
            int indice;
            while (true) {
                indice = (h1(k) + i * h2(k)) % m;
                if (tabela[indice] == k) return true;
                else if (tabela[indice] == -1) return false;
                ++i;
            }
        }
};

int main() {
    auto m{97};
    
    EncadeamentoHash encadeamento_hash(m);
    for (int k = 0; k < 1000; ++k) {
        if (k % 2 == 0) encadeamento_hash.adicionar(k);
    }
    
    LinearHash linear_hash(m);
    auto valor_inicial = 10;
    for (int i = 0; i < 60; ++i) {
        linear_hash.adicionar(valor_inicial);
        valor_inicial += m;
    }
    linear_hash.mostrar_distribuicao();

    QuadraticaHash quadratica_hash(m, 0, 1);
    valor_inicial = 10;
    for (int i = 0; i < 60; ++i) {
        quadratica_hash.adicionar(valor_inicial);
        valor_inicial += m;
    }
    quadratica_hash.mostrar_distribuicao();

    DuploHash duplo_hash(m);
    valor_inicial = 10;
    for (int i = 0; i < 60; ++i) {
        duplo_hash.adicionar(valor_inicial);
        valor_inicial += m;
    }
    duplo_hash.mostrar_distribuicao();

    return 0;
}
