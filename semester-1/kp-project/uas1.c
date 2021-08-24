#include <stdio.h>

void main()
{
	#undef NULL
	
	char* sapa = "Selamat Ujian!";
	#define NULL 0
	while(*sapa != NULL)
	{
		printf("%c", *sapa++);
	}
}
