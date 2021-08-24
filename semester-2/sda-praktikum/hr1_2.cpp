#include <iostream>
#include <vector>

using namespace std;

unsigned long long int newfibo( unsigned long long int n );

int main (void){
    unsigned long long int n;
  	
    cin >> n;
    cout << newfibo(n);
  	
}

unsigned long long int newfibo( unsigned long long int n ){
	unsigned long long int a=0, b=1, c=1, i, z=0;
	for( i=1; i<=n; i++ ){
		z = a+b+c;
		a = b%100000007;
		b = c%100000007;
		c = z%100000007;
	}
	return a%100000007;
	
}




