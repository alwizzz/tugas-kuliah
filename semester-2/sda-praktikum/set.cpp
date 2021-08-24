#include<bits/stdc++.h>
#include<set> //himpunan variabel tidak sama
#include <iterator>
using namespace std;
int main(){
	set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(5);
	
	/*
	cout<<"Element set s = ";
	for(auto it :s){
		cout<<it<<" ";
	} cout<<endl;
	*/
	
	set<int>::iterator itr = s.begin();
	advance( itr, 2 );
	cout << "itr di index 3: " << *itr << endl;
	advance( itr, -1);
	cout << "itr di index 2: " << *itr << endl;
	
	return 0;
}
