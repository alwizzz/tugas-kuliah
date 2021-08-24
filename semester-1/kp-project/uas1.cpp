#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 5;
	
	if( i==2 ){
		tambah:
		printf("%d", i);
		i+=2;
		if( i<= 10){
		
			goto tambah	;
		}else if( i<= 13){
			goto kurang;
		} else{
			puts("bye");		
			exit(0);
		}
	} else{
		kurang:
		i--;
		goto tambah;
	}
}
	
