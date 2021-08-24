#include <stdio.h>
#include <stdlib.h>


int main(void){
	FILE* f;
	f = fopen("key.txt", "r");
	char str[100];
	
	while( fgets( str, 100, f) != NULL ){
		printf("%s", str);
	}
		
	

	
}
