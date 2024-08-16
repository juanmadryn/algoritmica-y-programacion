#include <stdio.h>

int restoDivision(int dividendo, int divisor){
	int resultado = dividendo - divisor;
	if (resultado < divisor)
		return resultado;
	return restoDivision(dividendo - divisor, divisor);
}

int main(){
	int resto = restoDivision(39, 6);
	printf("Resto: %d\n", resto);
}