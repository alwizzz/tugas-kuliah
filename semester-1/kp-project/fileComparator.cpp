#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STRING 15
#define SIZE_FILENAME 21
#include "queue.h"

#define SHOW_INSTRUCTION
#define SHOW_QUEUE
#define CREATE_FILE

#define INTEGRITY_CHECK(a) \
	if( (a) == NULL ){ \
		puts("File not found/insufficient memory");	\
		puts(""); \
		exit(0); }
#define SUCCESS(x)											\
	puts("~~" #x " has been done successfully~~\n");	
#define CHOICE(x, y) \
	puts( #y "? (1 for yes, other for no)"); \
	printf("? "); \
	scanf("%d", &x); 

void instruction( void );
void compareFile( FILE* f1, FILE* f2, node** head, node** tail, int* ccount );
void giveNameFile( char* fileName, int mode );
void createFile( node** head, node** tail, char* newFileName );
void endProgram( void );

int main( void ){
	
	atexit( endProgram );
		
	#ifdef SHOW_INSTRUCTION
	instruction();
	#endif
		
	puts("Reading files...");
	int op;
	char firstFile[SIZE_FILENAME] = "key.txt";
	puts("The first default file to be read is \"key.txt\"");
	CHOICE( op, Do you want to change to another file)
	if( op == 1 )
		giveNameFile( firstFile, 0);
	FILE* f1 = fopen( firstFile, "r");
	INTEGRITY_CHECK(f1)
	
	char secondFile[SIZE_FILENAME] = "data.dat";
	puts("The second default file to be read is \"data.dat\"");
	CHOICE( op, Do you want to change to another file)
	if( op == 1 )
		giveNameFile( secondFile, 0);
	FILE* f2 = fopen( secondFile, "r");
	INTEGRITY_CHECK(f2)
	
	SUCCESS(Reading files)
	
	
	puts("Comparing files...");
	int corelationCounter = 0;
	int* ccount;
	ccount = &corelationCounter;
	node* head = NULL;	
	node* tail = NULL;
	compareFile( f1, f2, &head, &tail, ccount );
	
	SUCCESS(Comparing files)
	
	#ifdef SHOW_QUEUE
	int op1;
	if( head == NULL )
		puts("There are no corelation between files"); 
	else {
		printf("%d identical string(s) has been found\n", *ccount);
		CHOICE(op1 , Do you want to see the queue list)
		if( op1 == 1)
			ShowQueue(&head);
	}
	#endif
	
	#ifdef CREATE_FILE
	int op2;
	puts("");
	CHOICE(op2 , Do you want to print the result into a file)
	if( op2 != 1){
		clearQueue( &head, &tail );
		puts("");
		fclose(f1);
		fclose(f2);
		exit(0);
	}
	
	puts("\nCreating file...");
	int op3;
	char newFileName[SIZE_FILENAME] = "result.txt"; //default
	puts("The default name for the file is [result.txt] (without bracket)");
	CHOICE(op3 , Do you want set a custom file name)
	if( op3 == 1)
		giveNameFile( newFileName, 1 );
	createFile ( &head, &tail, newFileName );
	
	SUCCESS(Creating file)
	#endif
	
	
	clearQueue( &head, &tail );
	fclose(f1);
	fclose(f2);
	
	printf("End of program\n");
}


void instruction( void ){
	puts(	"INSTRUCTION:\n"
			"- Program will compare 2 files\n"
			"- Program will seek any identical (case sensitive) string between files and store it into a queue\n"
			"- There are 2 default files (key.txt and data.dat)\n"
			"- User can choose to use the default file(s) or use their own file(s)\n"
			#ifdef SHOW_QUEUE
			"- User can choose to see the current queue's content\n"
			#endif
			"- User can choose to create a new file containing the queue's content\n\n");		
			
}		

void compareFile( FILE* f1, FILE* f2, node** head, node** tail, int* ccount ){
	
	char fs1[SIZE_STRING], fs2[SIZE_STRING];
	
	while( fscanf( f1, "%s", fs1) == 1 ){
		while( fscanf( f2, "%s", fs2) == 1 ){
			if( !strcmp(fs1, fs2) ){
				*ccount += 1;
				EnQueue(head, tail, fs1 );
			}		
		}
		rewind( f2 );					
	} 	
}

void giveNameFile( char* fileName, int mode ){
	
	//mode 1 = checking for a substring ".txt"
	char customName[SIZE_FILENAME];
	
	printf("Insert the file name (maximum %d character)", SIZE_FILENAME - 1);
	if( mode == 1)
		puts("[including .txt]");
	else
		puts("");
	custom:
	printf("? ");
	scanf("%s", customName);
	if ( mode == 1){
		char ex[5] = ".txt";
		if( strstr(customName, ex) == NULL ){
			puts("Invalid file name (must include .txt)");
			goto custom;	
		}
	}
	strcpy(fileName, customName);

}

void createFile( node** head, node** tail, char* newFileName ){

	FILE* newf;
	newf = fopen( newFileName, "w");
	INTEGRITY_CHECK(newf)
	
	fileprintfQueue( head, tail, newf);
}

void endProgram(){
	puts("Program terminated");
}
