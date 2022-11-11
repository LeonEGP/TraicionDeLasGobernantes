//Programa que: Implementa un algoritmo solución para el Problema: "N Reinas", mediante BackTracking y Poda Pesada.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Viernes 11 de Noviembre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    cout << endl;
}

//Función que imprimie en consola un tablero (matriz). Recibe una matriz, en forma de vector de vectores de interos, no tiene valor de retorno. 
void imprimirTablero(vector<vector <int>> tablero) { //Complejidad Computacional: O(n), siendo n cada elemento en el vector de vectores de enteros. (Se realiza mediante un ciclo for anidado dentro de otro ciclo for, que permite tomar cada elemento de la matriz).

    for (int i = 0; i < tablero.size(); i++) {

        cout << "{ ";

        for (int j = 0; j < tablero[i].size(); j++) {

            if (j+1 == tablero[i].size()){
                cout << tablero[i][j] << " ";
            } else {
                cout << tablero[i][j] << ", ";
            }
 
        }

        cout << "}";

        espacio();
    }

}

//Función que verifica si es seguro, comprobando si existe una Reyna en la fila actual, o en la diagonal izquierda o en la diagonal derecha, recibe el entero n que es representantivo de las dimensiones del tablero (nxn), un entero fila y tres vectores de booleanos que son las filas, diagonales izquierdas y diagonales derechas. Retorna false si existe otra Reina, retorna true si no existe otra Reina.
bool esSeguro(int n, int fila, int columna, vector<bool>filas, vector<bool>diagonalesIzquierda, vector<bool>diagonalesDerecha) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    
    if (filas[fila] == true || diagonalesIzquierda[fila+columna] == true || diagonalesDerecha[columna-fila+n-1] == true) {
        return false;
    }
    else {
        return true;
    }

}

//Función que posiciona las Reynas en el tablero, recibe un vector de vectores de enteros (matriz) referenciado, un entero columna y tres vectores de booleanos que son las filas, diagonales izquierdas y diagonales derechas. Retorna true si se logra realizar el acomodo de las Reinas, si no, retorna false.
bool posicionarReinas(vector<vector <int>>& tablero, int columna, vector<bool> filas, vector<bool>diagonalesIzquierda, vector<bool>diagonalesDerecha) { //Complejidad Computacional: O(n!), siendo n el tamaño del tablero (Considerando el tamaño como: nxn).

    int n;
    n = tablero.size();

    if (columna >= n) {
        return true;
    }

    for (int i = 0; i < n; i++) {

        if (esSeguro(n, i, columna, filas, diagonalesIzquierda, diagonalesDerecha) == true) {

            filas[i] = true;
            diagonalesIzquierda[i+columna] = true;
            diagonalesDerecha[columna-i+n-1] = true;
            tablero[i][columna] = 1;

            if (posicionarReinas(tablero, columna + 1, filas, diagonalesIzquierda, diagonalesDerecha) == true) {
                return true;
            }

            filas[i] = false;
            diagonalesIzquierda[i+columna] = false;
            diagonalesDerecha[columna-i+n-1] = false;
            tablero[i][columna] = 0;

        }

    }

    return false;
}

//Función que crea un tablero y lo soluciona, en torno al problema de N Reinas, recibe un entero n, que es las dimensiones del tablero (nxn), no tiene valor de retorno.
void nReinas(int n) { //Complejidad Computacional: O(n!), siendo n el tamaño del tablero (Considerando el tamaño como: nxn).

    vector<vector <int>> tablero (n, vector<int> (n, 0));
    vector<bool> filas (n, false);
    vector<bool> diagonalesIzquierda (2*n-1, false);
    vector<bool> diagonalesDerecha (2*n-1, false);

    bool respuesta = posicionarReinas(tablero, 0, filas, diagonalesIzquierda, diagonalesDerecha); //Complejidad Computacional: O(n!).


    if (respuesta == true) {
        imprimirTablero(tablero); //Complejidad Computacional: O(n).
    }
    else {
        cout << "No se logra encontrar alguna solucion!!!" << endl;
    }

}

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. Dentro de esa ejecución, la función nReinas, tiene una Complejidad Computacional: O(n!), siendo n el tamaño del tablero (Considerando el tamaño como: nxn).

    int n;

    cout << "Input: " << endl;
    cin >> n;

    espacio();

    cout << "Output: " << endl;
    nReinas(n); //Complejidad Computacional: O(n!).

    espacio();

    return 0;
}
