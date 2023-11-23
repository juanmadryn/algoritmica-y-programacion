#include <stdio.h>

int restoDivision(int dividendo, int divisor){
	if (dividendo >= divisor){
		dividendo = dividendo - divisor;
	} else {
		return dividendo;
	}
	return restoDivision(dividendo, divisor);
}

int main(){
	int resto = restoDivision(29, 5);
	printf("Resto: %d\n", resto);
}