#include <stdio.h>
#include <math.h>

double funcao(double x) {
    // Função cuja raiz queremos encontrar
    return exp(x)*-x;  // f(x) = e^x * -x.
}

double metodoSecante(double x0, double x1, double tol) {
    double x2;
    int iteracao = 0;
    
    printf("Iteração\tX0\t\tX1\t\tX2\t\tf(x2)\n");
    
    do {
        x2 = x1 - (funcao(x1) * (x1 - x0)) / (funcao(x1) - funcao(x0)); // Fórmula do método da secante
        
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteracao + 1, x0, x1, x2, funcao(x2));
        
        if (fabs(funcao(x2)) < tol) {
            printf("Raiz encontrada: %.6lf\n", x2);
            return x2;
        }
        
        x0 = x1;
        x1 = x2;
        iteracao++;
    } while (iteracao < 1000); // Adicionamos um limite de iterações para evitar loop infinito
    
    printf("Atingido o limite máximo de iterações.\n");
    printf("Melhor aproximação encontrada: %.6lf\n", x2);
    return x2;
}

int main() {
    double x0 = -2.0; // Primeiro valor inicial
    double x1 = 3.0; // Segundo valor inicial
    double tol = 0.000001; // Tolerância
    
    printf("Método da Secante \n");
    printf("Valores iniciais: x0 = %.2lf, x1 = %.2lf\n", x0, x1);
    printf("Tolerância: %.6lf\n", tol);
    
    metodoSecante(x0, x1, tol);
    
    return 0;
}