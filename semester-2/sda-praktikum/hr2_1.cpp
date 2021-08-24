#include <iostream>
#include <set>
#include <iterator>
using namespace std;


int main( void ) {
    
    set <int> s;
    set <int>::iterator itr;
    //set <int>::iterator z;
    int query, op, x, size; 
    cin >> query;
    
    for( int i = 1; i<=query; i++){
    	size = s.size();
		cin >> op;
    	if( op==1 ){
    		cin >> x;
    		s.insert(x);
    		if(size < s.size() ){
			
    			if( s.size()==1 )
    				itr = s.begin();
						
    			if( s.size()%2==1 && s.size()!= 1 && x > *itr ){
    				advance(itr, 1);	
				}
				else if( s.size()%2== 0 && x < *itr ){
					advance(itr, -1);
				}
			}
		}
		else if( op==2 ){
			if( s.size()%2 == 1 ){
				auto med1 = *itr;
				cout << med1 << endl;
			}
			else if( s.size()%2 == 0 ){
				int a = *itr;
				auto b = next(itr, 1);
				auto med2 = (float) (a+(*b))/2;
				cout << med2 << endl;	
			}
			/*
			z = s.begin();
			cout<<"set: ";
			for( int i = 0; i<s.size(); i++ ){
				cout << "["<<i+1<<"]"<<*z << " ";
				advance(z, 1);
			}
			cout << endl;
			*/
		}
		//cout << "iterator: " << *itr << endl;			
	}
}




    


