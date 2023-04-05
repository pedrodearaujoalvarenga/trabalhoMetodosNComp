#include <stdio.h>
#include <math.h>

double funcao(double x) {
    // Função cuja raiz queremos encontrar
    return exp(x)*-x;  // f(x) = e^x * -x.
}

double derivada(double x) {
    // Derivada da função
    return exp(x)*-x - exp(x);  // f'(x) = e^x * -x - e^x.
}

double metodoNewton(double x0, double tol) {
    double x1;
    int iteracao = 0;
    
    printf("Iteração\tX0\t\tX1\t\tf(x1)\n");
    
    do {
        x1 = x0 - funcao(x0) / derivada(x0); // Fórmula do método de Newton
        
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\n", iteracao + 1, x0, x1, funcao(x1));
        
        if (fabs(funcao(x1)) < tol) {
            printf("Raiz encontrada: %.6lf\n", x1);
            return x1;
        }
        
        x0 = x1;
        iteracao++;
    } while (iteracao < 1000); // Adicionamos um limite de iterações para evitar loop infinito
    
    printf("Atingido o limite máximo de iterações.\n");
    printf("Melhor aproximação encontrada: %.6lf\n", x1);
    return x1;
}

int main() {
    double x0 = 10.0; // Valor inicial
    double tol = 0.000001; // Tolerância
    
    printf("Método de Newton\n");
    printf("Valor inicial: x0 = %.2lf\n", x0);
    printf("Tolerância: %.6lf\n", tol);
    
    metodoNewton(x0, tol);
    
    return 0;
}