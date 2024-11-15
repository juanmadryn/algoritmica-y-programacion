#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para calcular el dígito verificador usando Módulo 11
int calcularDigitoVerificadorModulo11(const char *num) {
    int longitud = strlen(num);
    int suma = 0;
    int peso = 2; // Peso inicial
    
    // Iteramos sobre cada dígito del número, de derecha a izquierda
    for (int i = longitud - 1; i >= 0; i--) {
        if (!isdigit(num[i])) {
            printf("Error: el número contiene caracteres no numéricos.\n");
            return -1;
        }

        int digito = num[i] - '0';
        suma += digito * peso;
        
        peso++;
        if (peso > 7) { // En el caso de CUIT/CUIL, los pesos se reinician en 2 después de 7
            peso = 2;
        }
    }

    int resto = suma % 11;
    int digitoVerificador = 11 - resto;

    // Ajuste según el estándar de CUIT/CUIL
    if (digitoVerificador == 10) return 9;
    if (digitoVerificador == 11) return 0;
    
    return digitoVerificador;
}

// Función para verificar un número completo con dígito verificador
int verificarConModulo11(const char *numCompleto) {
    int longitud = strlen(numCompleto);
    if (longitud < 2) {
        printf("Error: el número debe tener al menos un dígito y el dígito verificador.\n");
        return 0;
    }

    // Separar el número base del dígito verificador
    char numeroBase[20];
    strncpy(numeroBase, numCompleto, longitud - 1);
    numeroBase[longitud - 1] = '\0';
    
    int digitoVerificadorReal = numCompleto[longitud - 1] - '0';
    int digitoVerificadorCalculado = calcularDigitoVerificadorModulo11(numeroBase);

    return digitoVerificadorReal == digitoVerificadorCalculado;
}

int main() {
    char num[20];

    printf("Ingresa el número (sin el dígito verificador): ");
    scanf("%19s", num);
    
    int digitoVerificador = calcularDigitoVerificadorModulo11(num);

    if (digitoVerificador != -1) {
        printf("El dígito verificador calculado es: %d\n", digitoVerificador);
    }

    printf("Ingresa el número completo (incluyendo el dígito verificador): ");
    scanf("%19s", num);

    if (verificarConModulo11(num)) {
        printf("El número es válido según el Módulo 11.\n");
    } else {
        printf("El número no es válido según el Módulo 11.\n");
    }

    return 0;
}
