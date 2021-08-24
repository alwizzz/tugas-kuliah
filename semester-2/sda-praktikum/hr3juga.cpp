#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int value = 0;
    Node *left = nullptr;
    Node *right = nullptr;
} Node;

typedef struct BST {
    Node *root = nullptr;

    void insert( int x ){
        if( root == nullptr ){
        	root = new Node;
        	root->value = x;
		}
		else{
			Node* ptr = root;
    	    while( ptr != nullptr ){
	            if( x > ptr->value )
    		        ptr = ptr->right;
    	        else if( x < ptr->value )
    	            ptr = ptr->left;
    	    }
    	    ptr = new Node;
   		    ptr->value = x;
        }
    }

    Node* search( int x ){
        Node* ptr = root;
        while( ptr != nullptr ){
            if( ptr->value == x ){
                break;
            }
            else{
                if( x > ptr->value )
                    ptr = ptr->right;
                else if( x < ptr->value )
                    ptr = ptr->left;
            }
        }
        return ptr;
    }
    
    int depth( int x ){
        Node* ptr;
        ptr = root;
        int counter = 1;
        while( ptr != nullptr ){
            if( x == ptr->value ){
                break;
            }
            else{
                if( x > ptr->value ){
                    counter++;
                    ptr = ptr->right;
                }
                else if( x < ptr->value ){
                    counter++;
                    ptr = ptr->left;
                }
            }
        }
        if( ptr == nullptr ){
            return -1;
        }
        else{
            return counter;
        }
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
