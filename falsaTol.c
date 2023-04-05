#include <stdio.h>
#include <math.h>

double funcao(double x) {
     // Função cuja raiz queremos encontrar
    return exp(x)*-x;  // f(x) = e^x * -x.
}
double metodoFalsaPosicao(double a, double b, double tol) {
    double aAnterior = -a;
    double bAnterior = -b;
    double c;
    int iteracao = 0;
    

    if (funcao(a) * funcao(b) >= 0) {
        printf("Erro: A raiz não está entre as entradas A e B.\n");
        return 0;
    }
    
    printf("Iteração\ta\t\tb\t\tc\t\tf(c)\n");
    
    do {
        if(a - aAnterior < tol && b - bAnterior < tol){ //Parar caso a variação de A e a variação de B forem abaixo da tolerância.
            break;
            
        }
        aAnterior = a;
        bAnterior = b;
    
        c = (a * funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a)); // Aproximação da falsa posição
        
        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", iteracao + 1, a, b, c, funcao(c));
        
        if (funcao(c) == 0) {
            printf("Raiz encontrada: %.6lf\n", c);
            return c;
        } else if (funcao(c) * funcao(a) < 0) {
            b = c; // A raiz está no intervalo [a, c]
        } else {
            a = c; // A raiz está no intervalo [c, b]
        }
        
        iteracao++;
       
    }while (fabs(b - a) > tol);
    
    printf("Raiz encontrada: %.6lf\n", c);
    return c;
}

int main() {
    double a = -2; // Limite inferior do intervalo
    double b = 3.0; // Limite superior do intervalo
    double tol = 0.01; // Tolerância
    
    printf("Método da Falsa Posição");
    printf("Intervalo inicial: [%.2lf, %.2lf]\n", a, b);
    printf("Tolerância: %.6lf\n", tol);
    
    metodoFalsaPosicao(a, b, tol);
    
    return 0;
}