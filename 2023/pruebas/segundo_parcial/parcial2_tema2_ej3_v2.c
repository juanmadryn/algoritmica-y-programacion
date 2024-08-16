#include <stdio.h>

int restoDivision(int dividendo, int divisor){
	if (dividendo < divisor){
		return dividendo;
	}
	return restoDivision(dividendo - divisor, divisor);
}

int main(){
	int resto = restoDivision(29, 5);
	printf("Resto: %d\n", resto);
}