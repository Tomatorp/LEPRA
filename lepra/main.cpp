/* en task.json se deben agregar todos los .cpp despues de main.cpp, quedando entre el main.cpp
 y -0, ejemplo
 -g
 main.cpp
 archivo1.cpp
 archivo2.cpp
-0 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#ifdef _WIN32
#include <cstdlib> 
#else
#include <unistd.h>
#endif
using namespace std;


void ingreso(vector<int> &xs);
void mostrar(const vector<int> &xs);
void eliminar(vector<int> &xs, int pos);
int head(const vector<int> &xs);
int last(const vector<int> &xs);
vector<int> tail(const vector<int> &xs);
vector<int> init(const vector<int> &xs);
int length(const vector<int> &xs);
bool null(const vector<int> &xs);
bool elem(int x, const vector<int> &xs);
vector<int> reverse(const vector<int> &xs);
vector<int> take(int n, const vector<int> &xs);
vector<int> drop(int n, const vector<int> &xs);
vector<int> replicate(int n, int x);
vector<int> map(const vector<int> &xs, char operacion);
void pausar();

int main() {
    vector<int> xs;
    int opcion;

    do {
        cout << "\nMENU:\n";
        cout << "1. Ingresar elementos\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Eliminar elemento\n";
        cout << "4. Head\n";
        cout << "5. Last\n";
        cout << "6. Tail\n";
        cout << "7. Init\n";
        cout << "8. Length\n";
        cout << "9. Null\n";
        cout << "10. Elem\n";
        cout << "11. Reverse\n";
        cout << "12. Take\n";
        cout << "13. Drop\n";
        cout << "14. Replicate\n";
        cout << "15. Map (operaciones +, -, *, ^)\n";
        cout << "0. Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingreso(xs);
                break;
            case 2:
                mostrar(xs);
                break;
            case 3: {
                int pos;
                cout << "Posicion a eliminar (a partir de 0): ";
                cin >> pos;
                eliminar(xs, pos);
                break;
            }  
            case 4:
                cout << "Head: " << head(xs) << endl;
                break;
            case 5:
                cout << "Last: " << last(xs) << endl;
                break;
            case 6:
                mostrar(tail(xs));
                break;
            case 7:
                mostrar(init(xs));
                break;
            case 8:
                cout << "Length: " << length(xs) << endl;
                break;
            case 9:
                cout << (null(xs) ? "True" : "False") << endl;
                break;
            case 10: {
                int x;
                cout << "Elemento a buscar: ";
                cin >> x;
                cout << (elem(x, xs) ? "True" : "False") << endl;
                break;
            }
            case 11:
                mostrar(reverse(xs));
                break;
            case 12: {
                int n;
                cout << "Cuantos elementos tomar: ";
                cin >> n;
                mostrar(take(n, xs));
                break;
            }
            case 13: {
                int n;
                cout << "Cuantos elementos eliminar: ";
                cin >> n;
                mostrar(drop(n, xs));
                break;
            }
            case 14: {
                int n, x;
                cout << "Valor a replicar: ";
                cin >> x;
                cout << "Cuantas veces: ";
                cin >> n;
                mostrar(replicate(n, x));
                break;
            }
            case 15: {
                char op;
                cout << "Operacion (+, -, *, ^): ";
                cin >> op;
                mostrar(map(xs, op));
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
        if (opcion != 0) pausar();
    } while (opcion != 0);
    return 0;
}

void ingreso(vector<int> &xs) {
    int n, valor;
    cout << "Cantidad de elementos: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Elemento " << i+1 << ": ";
        cin >> valor;
        xs.push_back(valor);
    }
}

void mostrar(const vector<int> &xs) {
    cout << "[";
    for (size_t i = 0; i < xs.size(); ++i) {
        cout << xs[i];
        if (i < xs.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void eliminar(vector<int> &xs, int pos) {
    if (pos >= 0 && pos < (int)xs.size()) {
        xs.erase(xs.begin() + pos);
        cout << "Elemento en la posicion " << pos << " eliminado.\n";
    } else {
        cout << "Posicion invalida.\n";
    }
}

int head(const vector<int> &xs) {
    return xs.front();
}

int last(const vector<int> &xs) {
    return xs.back();
}

vector<int> tail(const vector<int> &xs) {
    return vector<int>(xs.begin() + 1, xs.end());
}

vector<int> init(const vector<int> &xs) {
    return vector<int>(xs.begin(), xs.end() - 1);
}

int length(const vector<int> &xs) {
    return xs.size();
}

bool null(const vector<int> &xs) {
    return xs.empty();
}

bool elem(int x, const vector<int> &xs) {
    return find(xs.begin(), xs.end(), x) != xs.end();
}

vector<int> reverse(const vector<int> &xs) {
    vector<int> rev(xs);
    std::reverse(rev.begin(), rev.end());
    return rev;
}

vector<int> take(int n, const vector<int> &xs) {
    return vector<int>(xs.begin(), xs.begin() + min(n, (int)xs.size()));
}

vector<int> drop(int n, const vector<int> &xs) {
    return vector<int>(xs.begin() + min(n, (int)xs.size()), xs.end());
}

vector<int> replicate(int n, int x) {
    return vector<int>(n, x);
}

vector<int> map(const vector<int> &xs, char operacion) {
    vector<int> result;
    int valor;
    cout << "Ingrese el valor a aplicar con el operador '" << operacion << "': ";
    cin >> valor;

    for (int x : xs) {
        switch (operacion) {
            case '+':
                result.push_back(x + valor);
                break;
            case '-':
                result.push_back(x - valor);
                break;
            case '*':
                result.push_back(x * valor);
                break;
            case '^':
                result.push_back(pow(x, valor));
                break;
            default:
                cout << "Operacion no valida.\n";
                return {};
        }
    }
    return result;
}

void pausar() {
    cout << "\nPresione ENTER para volver al menu...";
    cin.ignore();
    cin.get();
}
