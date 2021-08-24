#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	FILE* source = fopen("data.dat", "r");
	FILE* target = fopen("databin.dat", "wb");
	
	char temp[15];
	while (fscanf(source, "%s", temp) == 1 ){
		fprintf(target, "%s", temp);
	}
	puts("end of program");
}
