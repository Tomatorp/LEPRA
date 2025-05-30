/* en task.json se deben agregar todos los .cpp despues de main.cpp, quedando entre el main.cpp
 y -0, ejemplo
 -g
 main.cpp
 archivo1.cpp
 archivo2.cpp
-0 */

#include <iostream>    // PAra entrada/salida estandar
#include <string>      // Para manipular cadenas de texto
#include <vector>      // Para usar el contenedor/lista Vector
#include <algorithm>   // para funciones como find, reverse, etc
#include <cmath>       // Para operaciones matematicas como pow
#ifdef _WIN32          
#include <cstdlib>     // En caso de usar windows, esta libreria permite usar system("pause")
#else
#include <unistd.h>    // Lo mismo que system("pause") pero para sistemas unix
#endif
using namespace std;

// Aqui declaramos las funciones para poder trabajarlas por debajo de la funcion principal main
void ingreso(vector<int> &xs);                             // Permite ingresar valores al vector
void mostrar(const vector<int> &xs);                       // Muestra los valores del vector
void eliminar(vector<int> &xs, int pos);                   // Elimina un elemento en la posición dada
int head(const vector<int> &xs);                           // Retorna el primer elemento
int last(const vector<int> &xs);                           // Retorna el último elemento
vector<int> tail(const vector<int> &xs);                   // Retorna todos los elementos excepto el primero
vector<int> init(const vector<int> &xs);                   // Retorna todos los elementos excepto el último
int length(const vector<int> &xs);                         // Retorna el tamaño del vector
bool null(const vector<int> &xs);                          // Verifica si el vector está vacío
bool elem(int x, const vector<int> &xs);                   // Verifica si un elemento está en el vector
vector<int> reverse(const vector<int> &xs);                // Retorna el vector en orden inverso
vector<int> take(int n, const vector<int> &xs);            // Toma los primeros n elementos
vector<int> drop(int n, const vector<int> &xs);            // Elimina los primeros n elementos
vector<int> replicate(int n, int x);                       // Crea un vector con x replicado n veces
vector<int> map(const vector<int> &xs, char operacion);    // Aplica una operación a todos los elementos
void pausar();                                             // Espera al usuario para continuar 

int main() {
    vector<int> xs;   // Aqui declaramos la lista principal
    int opcion;       // Variable para poder usar el menu
    // do while para crear el menu interactivo con el usuario
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
        // Aqui la variable invoca una funcion dependiendo del caso con el que coincida
        switch (opcion) {
            case 1: // Ingresa elementos al vector
                ingreso(xs);
                break;
            case 2: // Muesta los elementos del vector
                mostrar(xs);
                break;
            case 3: { // Elimina elementos del vector segun posicion
                int pos;
                cout << "Posicion a eliminar (a partir de 0): ";
                cin >> pos;
                eliminar(xs, pos);
                break;
            }  
            case 4: // Muestra el primer elemento del vector
                cout << "Head: " << head(xs) << endl;
                break;
            case 5: // Muestra el ultimo elemento del vector
                cout << "Last: " << last(xs) << endl;
                break;
            case 6: // Muestra todos los elementos menos el primero
                mostrar(tail(xs));
                break;
            case 7: // Muestra todos los elementos menos el ultimo
                mostrar(init(xs));
                break;
            case 8: // Muestra el tamaño del vector
                cout << "Length: " << length(xs) << endl;
                break;
            case 9: // Verifica si el vector esta vacio
                cout << (null(xs) ? "True" : "False") << endl;
                break;
            case 10: { // Verifica si el vector contiene x elemento
                int x;
                cout << "Elemento a buscar: ";
                cin >> x;
                cout << (elem(x, xs) ? "True" : "False") << endl;
                break;
            }
            case 11: // Muestra el vector con las pocisiones invertidas
                mostrar(reverse(xs));
                break;
            case 12: { // Muestra los primero n elementos del vector
                int n;
                cout << "Cuantos elementos tomar: ";
                cin >> n;
                mostrar(take(n, xs));
                break;
            }
            case 13: { // Muestra el vector luego de eliminar los primeros n elementos
                int n;
                cout << "Cuantos elementos eliminar: ";
                cin >> n;
                mostrar(drop(n, xs));
                break;
            }
            case 14: { // Crea un vector nuevo cullos elementos son todos x y se repetie n veces
                int n, x;
                cout << "Valor a replicar: ";
                cin >> x;
                cout << "Cuantas veces: ";
                cin >> n;
                mostrar(replicate(n, x));
                break;
            }
            case 15: { // Muestra el vector luego de aplicarle una de las operaciones matematicas dadas por la misma opcion
                char op;
                cout << "Operacion (+, -, *, ^): ";
                cin >> op;
                mostrar(map(xs, op));
                break;
            }
            case 0: // salir del programa
                cout << "Saliendo...\n";
                break;
            default: // en caso de ingresar un valor que no coincida con alguno de los casos
                cout << "Opcion invalida.\n";
        }
        if (opcion != 0) pausar(); // pausa el programa para esperar al usuario
    } while (opcion != 0);
    return 0;
}
// Pide al usuario que ingrese n elementos y los agrega al vector mediante un for que itera n veces 
// En cada interacion solicita un valor y lo inserta mediante xs.push_(valor)
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
// Imprime el contenido del vector en formato [x, y, z]
// Usa un bucle for para recorrer todos los indices del vector y los imprime, si no es el ultimo imprime una coma despues
void mostrar(const vector<int> &xs) {
    cout << "[";
    for (size_t i = 0; i < xs.size(); ++i) {
        cout << xs[i];
        if (i < xs.size() - 1) cout << ", ";
    }
    cout << "]\n";
}
// Elimina un elemento en una posición dada (si es válida)
// Verifica si la posicion (pos) esta dentro del rango valido del vector, si es asi, llama a xs.erase(xs.being() + pos), si no muestra un mensaje de posicion no valida
void eliminar(vector<int> &xs, int pos) {
    if (pos >= 0 && pos < (int)xs.size()) {
        xs.erase(xs.begin() + pos);
        cout << "Elemento en la posicion " << pos << " eliminado.\n";
    } else {
        cout << "Posicion invalida.\n";
    }
}
int head(const vector<int> &xs) { // Devuelve el primer elemento del vector usando xs.front()
    return xs.front();
}

int last(const vector<int> &xs) { // Devuelve el último elemento del vector con xs.back()
    return xs.back();
}

vector<int> tail(const vector<int> &xs) { // Usa el constructor de vector<int> con begin()+1 hasta end(), Esto copia todos los elementos excepto el primero.
    return vector<int>(xs.begin() + 1, xs.end());
}

vector<int> init(const vector<int> &xs) { // Similar a tail, pero esta vez desde begin() hasta end() - 1, Copia todos los elementos menos el ultimo
    return vector<int>(xs.begin(), xs.end() - 1);
}

int length(const vector<int> &xs) { // Retorna el tamaño del vector con xs.size()
    return xs.size();
}

bool null(const vector<int> &xs) { // Usa xs.empty() para retornar true si está vacío, false si tiene elementos.
    return xs.empty();
}
// Usa find(xs.begin(), xs.end(), x) Si encuentra x, devuelve un iterador distinto a end() → devuelve true, sino devulve false
bool elem(int x, const vector<int> &xs) { 
    return find(xs.begin(), xs.end(), x) != xs.end();
}
// Crea una copia local del vector con vector<int> rev(xs); Usa reverse(rev.begin(), rev.end()); para invertir el orden de los elementos y los imprime
vector<int> reverse(const vector<int> &xs) { 
    vector<int> rev(xs);
    std::reverse(rev.begin(), rev.end());
    return rev;
}
// Usa min(n, (int)xs.size()) para evitar acceder fuera del rango
// Crea un nuevo vector con los primeros n elementos desde xs.begin() hasta xs.begin() + n
vector<int> take(int n, const vector<int> &xs) { 
    return vector<int>(xs.begin(), xs.begin() + min(n, (int)xs.size()));
}

vector<int> drop(int n, const vector<int> &xs) { // Similar a take, pero devuelve los elementos después de los primeros n, va desde xs.being() + n hasta xs.end()
    return vector<int>(xs.begin() + min(n, (int)xs.size()), xs.end());
}

vector<int> replicate(int n, int x) { // Usa el constructor vector<int>(n, x) para crear un vector de n elementos con el valor x
    return vector<int>(n, x);
}
// Aplica una operación a cada elemento del vector con un valor dado por el usuario, eh imprime un vector nuevo result inicialmente vacio
vector<int> map(const vector<int> &xs, char operacion) {
    vector<int> result;
    int valor;
    cout << "Ingrese el valor a aplicar con el operador '" << operacion << "': "; // Pide al usuario un valor para usar con la operación
    cin >> valor;

    for (int x : xs) { // Recorre cada elemento x en el vector xs con un for.
        switch (operacion) {
            case '+':
                result.push_back(x + valor); // Para sumar el valor dado por el usuaria a cada elemento
                break;
            case '-':
                result.push_back(x - valor); // Le resta n a cada elemento del vector
                break;
            case '*':
                result.push_back(x * valor);     // Multiplica por n a cada elemento del vector
                break;
            case '^':
                result.push_back(pow(x, valor)); // Aplica un exponente n a cada elemento del vector
                break;
            default:
                cout << "Operacion no valida.\n"; // En caso de que ingrese alguna operacion no valida
                return {};
        }
    }
    return result;
}
// Pausa el programa hasta que el usuario presione ENTER
void pausar() {
    cout << "\nPresione ENTER para volver al menu...";
    cin.ignore(); // Llama a cin.ignore() → limpia cualquier carácter pendiente (como el salto de línea)
    cin.get(); // Luego llama a cin.get() → espera a que el usuario presione ENTER.
}
