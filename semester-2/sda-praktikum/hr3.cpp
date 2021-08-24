#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct Node {
	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
} Node;

typedef struct BST {
	Node *root = nullptr;

	void insert( int x ){
		Node* newnode = new Node;
		newnode->value = x;
		if( !this->root ){
			root = new Node;
			root->value = x;
		}
		else{
			Node* ptr = this->root;
			while( ptr ){
				if( x > ptr->value  ){
					if( ptr->right ){
						ptr = ptr->right;
					}
					else{
						break;
					}
					
				}
				else if( x < ptr->value ){
					if( ptr->left ){
						ptr = ptr->left;
					}
					else{
						break;
					}
				}
			}
			if( x > ptr->value ){
				ptr->right = newnode;
			}
			else{
				ptr->left = newnode;
			}
		}
	}

	Node* search( int x ){
		Node* ptr = this->root;
		while( x != ptr->value ){
			if( x > ptr->value ){
				if(ptr->right){
					ptr = ptr->right;
				}
				else
					return nullptr;
			}
			else if( x < ptr->value ){
				if(ptr->left){
					ptr = ptr->left;
				}
				else
					return nullptr;
			}
		}
		
		return ptr;
	} 	
	
	int depth( int x ){
		Node* ptr = this->root;
		int counter = 1;
		while( x != ptr->value ){
			if( x > ptr->value ){
				if( ptr->right != nullptr ){
					counter++;
					ptr = ptr->right;
				}
				else
					return -1;
			}
			else if( x < ptr->value ){
				if( ptr->left != nullptr ){
					counter++;
					ptr = ptr->left;
				}
				else
					return -1;
			}
		}
				
		return counter;
		
	}


} BST;

int main() {
	BST *bst = new BST;
	int i, n, temp;
	cin>>n;
	for(i = 0; i<n; i++){
		cin>>temp;
		if(temp == 1){
			cin>>temp;
			bst->insert(temp);
		}
		else if(temp == 2){
			cin>>temp;
			cout<<(bst->search(temp) == nullptr ? "tidak ada\n" : "ada\n");
		}
		else if(temp == 3){
			cin>>temp;
			cout<<bst->depth(temp)<<"\n";
		}
	}
}
