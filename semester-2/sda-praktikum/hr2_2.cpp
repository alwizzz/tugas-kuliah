#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

int main ( void ){
	
	map<string, string> m;
	map<string, string>::iterator itr;
	int query, op;
	string key, name;
	
	cin >> query;
	for( int i=0; i<query; i++ ){
		cin >> op;
		
		if( op==1 ){
			cin >> key;
			cin >> name;
			if( m.count(key)==0 ){
				m.insert( pair<string, string>(key, name) );
				cout << "kursi berhasil dipesan" <<endl;
			}
			else{
				itr = m.find(key);
				cout << "kursi sudah dipesan " << itr->second << endl;
			}
		}
		else if( op==2 ){
			cin >> key;
			if( m.count(key)==0 ){
				cout << "kursi masih kosong" <<endl;
			}
			else{
				itr = m.find(key);
				cout << "kursi sudah dipesan " << itr->second << endl;
			}		
		}
	}
}
