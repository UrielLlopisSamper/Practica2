#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void cambio(const vector<int>& monedas, int N, int M) {
    vector<int> dp(M + 1, INT_MAX);
    vector<int> solution(N, 0);
    dp[0] = 0;

    // Calcular el número mínimo de monedas necesarias
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (monedas[j] <= i && dp[i - monedas[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - monedas[j]] + 1);
            }
        }
    }

    // Llenar el vector solución para indicar cuántas monedas se usan de cada tipo
    int monto = M;
    for (int i = N - 1; i >= 0 && monto > 0; --i) {
        while (monto >= monedas[i] && dp[monto] == dp[monto - monedas[i]] + 1) {
            solution[i]++;
            monto -= monedas[i];
        }
    }

    if (dp[M] == INT_MAX) {
        cout << "No se puede obtener la cantidad con las monedas dadas." << endl;
    } else {
        cout << "Número mínimo de monedas: " << dp[M] << endl;
        cout << "Distribución de monedas en la solución: ";
        for (int i = 0; i < solution.size(); ++i) {
            cout << solution[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Alternativa sin inicializadores de lista
    vector<int> monedas; 
    monedas.push_back(1);
    monedas.push_back(2);
    monedas.push_back(5);  // Ejemplo de monedas

    int N = monedas.size();
    int M = 11;  // Ejemplo de cantidad

    cambio(monedas, N, M);

    return 0;
}

