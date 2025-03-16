#include<iostream>
#include<list>
#include<string>
#include<cmath>

using namespace std;

class ChainingHash {
    private:
        list<int> *table;
        int m;
    
    public:
        ChainingHash(int m): m{m} {
            table = new list<int>[m];
        }

        ~ChainingHash() {
            delete [] table;
        }

        void add(int k) {
            int i = k % m;
            table[i].emplace_back(k);
        }

        void show_distribution() {
            for (int i = 0; i < m; ++i) {
                cout << i << ") ";
                for (auto k : table[i]) {
                    cout << '*';
                }
                cout << endl;
            }
        }
};

class LinearHash {
    private:
        int *table; // Tabela Hash
        int m; // Tamanho inicial
    public:
        // Construtor
        LinearHash(int m): m{m} {
            table = new int[m];
            fill(table, table + m, -1); // Inicializa com -1
        }

        ~LinearHash() {
            delete [] table;
        }

        void add (int k) {
            int i = 0;

            // Funcao hash linear: incrementa o indice ate encontrar um local disponivel
            while( table[ (k + i) % m ] != -1 ) ++i;
            table[(k + i) % m] = k;
        }

        void show_distribution() {
            for (auto i = 0; i < m; ++i) {
                if      (table[i] == -1) cout << "-";
                else    cout << "*"; 
            }
            cout << endl;
        }
};

class QuadraticHash {
    private:
        int *table; // Tabela Hash
        int m; // Tamanho inicial
        int c1, c2; // Coeficientes
    public:
        // Construtor
        QuadraticHash(int m, int c1, int c2): m{m}, c1{c1}, c2{c2} {
            table = new int[m];
            fill(table, table + m, -1); // Inicializa com -1
        }

        ~QuadraticHash() {
            delete [] table;
        }

        void add (int k) {
            int i = 0;

            // Funcao hash quadratica: incrementa o indice ate encontrar um local disponivel
            auto index = (k + c1 * i + c2 * i*i) % m;
            while( table[index] != -1 ) {
                ++i;
                index = (k + c1 * i + c2 * i*i) % m;
            }
            table[index] = k;
        }

        void show_distribution() {
            for (auto i = 0; i < m; ++i) {
                if      (table[i] == -1) cout << "-";
                else    cout << "*"; 
            }
            cout << endl;
        }
};

class DoubleHash {
    private:
        int *table; // Tabela Hash
        int m; // Tamanho inicial

    public:
        // Construtor
        DoubleHash(int m): m{m} {
            table = new int[m];
            fill(table, table + m, -1); // Inicializa com -1
        }

        ~DoubleHash() {
            delete [] table;
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

        void add (int k) {
            int i = 0;

            // Funcao hash quadratica: incrementa o indice ate encontrar um local disponivel
            auto index = hash(k, i);
            while( table[index] != -1 ) {
                ++i;
                index = hash(k, i);
            }
            table[index] = k;
        }

        void show_distribution() {
            for (auto i = 0; i < m; ++i) {
                if      (table[i] == -1) cout << "-";
                else    cout << "*"; 
            }
            cout << endl;
        }
};

int main() {
    auto m{97};
    
    ChainingHash chaining_hash(m);
    
    for (int k = 0; k < 1000; ++k) {
        if (k % 2 == 0) {
            chaining_hash.add(k);
        }
    }
    
    //chaining_hash.show_distribution();
    
    /*
    *********************************************************************************************************
    */
    
    LinearHash linear_hash(m);
    auto initial_value = 10;
    
    for (int i = 0; i < 60; ++i) {
        linear_hash.add(initial_value);
        initial_value += m;
    }
    
    linear_hash.show_distribution();

    /*
    *********************************************************************************************************
    */
    
    QuadraticHash quadratic_hash(m, 0, 1);
    initial_value = 10;
    
    for (int i = 0; i < 60; ++i) {
        quadratic_hash.add(initial_value);
        initial_value += m;
    }
    
    quadratic_hash.show_distribution();

    /*
    *********************************************************************************************************
    */

    DoubleHash double_hash(m);
    initial_value = 10;
    
    for (int i = 0; i < 60; ++i) {
        double_hash.add(initial_value);
        initial_value += m;
    }
    
    double_hash.show_distribution();

    return 0;
}