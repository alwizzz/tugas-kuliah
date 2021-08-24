#include <iostream>
#include <stack>
using namespace std;

void reverse( stack <int>& source, stack <int>& target);
void show( stack<int>& source);

int main (void){
    
    stack <int> main;
    stack <int> sub;
    int q, x, op, i;
    
    cin >> q;
    for( i=0; i<q; i++ ){
        cin >> op;
        
        if( op==1 ){
			
            cin >> x;
            sub.push(x);
        }
        
        else if( op==2 ){
        	if( main.empty()){
		  		reverse( sub, main );
			}
            main.pop();
        }
        
        else if( op==3 ){
        	if( main.empty()){
		  		reverse( sub, main );
			}
        	cout<< main.top() << endl;
        }
        
		/*
        cout<<"main stack: ";
        show(main);
        cout<<"sub stack: ";
        show(sub);
        */
    }
}

void reverse( stack <int>& source, stack <int>& target){
    while( !source.empty() ){
        target.push( source.top() );
        source.pop();
    }
}

void show( stack<int>& source){
	stack<int> s;
	s = source;
	if(s.empty())
		cout << "empty";
	else{
		while(!s.empty()){
			cout << s.top() << "->";
			s.pop();
		}
		
	}
	cout << endl;
}





