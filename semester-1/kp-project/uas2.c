#include <stdio.h>


int main()
{
	int n, i, *ptr, jumlah = 0;
	
	printf("Masukan jumlah elemen: ");
	scanf("%d", &n);
	
	ptr = (int*) calloc (n, sizeof(int));
	
	if( ptr == NULL ) exit(0);
	
	printf("Masukkan %d elemen:\n", n);
	
	for( i = 0; i < n; i++ ){
		scanf("%d", ptr + i);
		jumlah += *(ptr + i);
		
	}
	printf("Jumlah: %d", jumlah);
	
	return 0;
}
