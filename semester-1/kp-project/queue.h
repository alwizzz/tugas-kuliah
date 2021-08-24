#ifndef STDIO_H
	#include <stdio.h>
#endif
#ifndef STDLIB_H
	#include <stdlib.h>
#endif
#ifndef STRING_H
	#include <string.h>
#endif
#ifndef SIZE_STRING
	#define SIZE_STRING 10
#endif
struct Node{
	char data[SIZE_STRING];
	struct Node* link;
};
typedef struct Node node;

void EnQueue( node** head, node** tail, char value[SIZE_STRING]){
	node* newn;
	newn = (node*) malloc(sizeof(node));
	strcpy(newn->data, value);
	newn->link = NULL;	
	
	if( (*head) == NULL ) //if list is empty
		*head = newn;
	else
		(*tail)->link = newn;
		
	*tail = newn;

}

void DeQueue( node** head, node** tail ){
	node* hold;
	hold = *head;
	*head = (*head)->link;
	if( (*head) == NULL ) //if list become empty
		*tail = NULL;
	free( hold );
}

void ShowQueue( node** head ){
	node* currn;
	currn = *head;
	if( currn != NULL ){
		printf("List: ");
		while( currn != NULL ){
			printf("%s --> ", currn->data);
			currn = currn->link;
		}
		printf("NULL\n");
	} else
		puts("The list is empty");
}

void fileprintfQueue (node** head, node** tail, FILE* fileDest ){
	node* current;
	current = *head;
	while( current != NULL ){
		fprintf( fileDest, current->data);
		fprintf( fileDest, "\n");
		current = current->link;
	}
}

void clearQueue(node** head, node** tail){
	node* current;
	current = *head;
	while( current != NULL ){
		DeQueue( head, tail );
		current = current->link;
	}
}







