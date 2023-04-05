#include <stdio.h>
#include <math.h>

double funcao(double x) {
    // Função cuja raiz queremos encontrar
    return exp(x)*-x;  // f(x) = e^x * -x.
}

double metodoBisseccao(double a, double b, double tol) {
    double c;
    int iteracao = 0;
    
    if (funcao(a) * funcao(b) >= 0) {
        printf("Erro: A raiz não está entre as entradas A e B.\n");
        return 0;
    }
    
    printf("Iteração\ta\t\tb\t\tc\t\tf(c)\n"); //Printar o status do cálculo (título).
    //Exibe A, B, o ponto médio entre ambos e f(c).
    
    while ((b - a) / 2 > tol) { //Fazer o método em si. Achar o valor médio, calcular f(a) e f(b), repetir.
        c = (a + b) / 2; // Ponto médio do intervalo
        
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteracao + 1, a, b, c, funcao(c));
        
        if (funcao(c) == 0) {
            printf("Raiz encontrada: %.6lf\n", c);
            return c;
        } else if (funcao(c) * funcao(a) < 0) {
            b = c; // A raiz está no intervalo [a, c]
        } else {
            a = c; // A raiz está no intervalo [c, b]
        }
        
        iteracao++; //Próxima iteração.
    }
    
    printf("Raiz encontrada: %.6lf\n", c);
    return c;
}

int main() {
    double a = -2; // Limite inferior do intervalo
    double b = 3.0; // Limite superior do intervalo
    double tol = 0.000001; // Tolerância (em número, não em porcentagem)
    
    printf("Método da Bissecção\n");
    printf("Intervalo inicial: [%.2lf, %.2lf]\n", a, b);
    printf("Tolerancia: %.6lf\n", tol);
    
    metodoBisseccao(a, b, tol);
    
    return 0;
}