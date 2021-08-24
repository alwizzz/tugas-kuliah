#include <iostream>
#include <array>
using namespace std;

typedef struct node{
	int data;
	node* Lptr;
	node* Rptr;
} Node;

void insert( Node** ptr, int value );
void inOrder_print( Node* ptr );

int main( void ){
	
	Node* root = NULL;
	
	array <int, 12> data = {57, 32, 78, 24, 48, 85, 39, 81, 96, 35, 43, 90};
	for( int i=0; i<12; i++ )
		insert( &root, data.at(i) );
	
	cout << "Data\t: ";
	for( int i=0; i<12; i++)
		cout << data.at(i) << " ";
	cout << endl;		
	
	cout << "InOrder\t: ";
	inOrder_print( root );
}

void insert( Node** ptr, int value ){
	if( (*ptr)==NULL ){
		(*ptr) = new Node;
		(*ptr)->data = value;
		(*ptr)->Lptr = NULL;
		(*ptr)->Rptr = NULL;
	}
	else{
		if( value > (*ptr)->data ){
			insert( &( (*ptr)->Rptr ), value);
		}
		else if( value < (*ptr)->data ){
			insert( &( (*ptr)->Lptr ), value );
		}		
	}
}

void inOrder_print( Node* ptr ){
	if( ptr!=NULL ){
		inOrder_print( ptr->Lptr );
		cout << ptr->data << " ";
		inOrder_print( ptr->Rptr );
	}

}
