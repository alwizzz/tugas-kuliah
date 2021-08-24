#include<iostream>
#include<time.h>
#include<chrono>
#include <array>
#include <string>
using namespace std;
using namespace chrono;

int eraseAT(string str) {
	string acc;
	bool a, b;
	int x = 0;
	if (str.length() == 0)
		return 0;
	for (int i = 0; i < str.length(); i++) {	
		if (str[i] == '[' || str[i] == ':' || str[i] == '|') {
			if (str[i] == '[') {
				acc.push_back(str[i]);
				a = true;
			} 
			else if (str[i] == ':' && a) {
				if (str[i] == ':' && acc[acc.length() - 1] == ':') {
					acc.pop_back();
					b = false;
				} 
				else {	
					acc.push_back(str[i]);
					b = true;
				}
			}
			else if (str[i] == '|' && b) {} 
			else x++;
		} 
		else if (str[i] == ']') {
			if (acc.length() == 0)
				x++;
			else {
				acc.pop_back();
				a = false;
			}
		} 
		else x++;
	}
	if (acc.length() == 0) return x;
	else return -1;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < str.length(); j++)
			for (int k = 0; k < str.length(); k++)
				str[i] = str[k];
	return 0;
}

char randchar(){
	const array <char, 31> listchar = {'[', ':', '|', ']', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
	
	return listchar[ rand()%31 + 1 ];
		
}

int main(void){
	
	cout << "\t\tTestcase" << endl;
	for( int n=100000; n<=1000000; n+=100000 ){
		string str;
	
		for( int i=0; i<n; i++ ){
			str.push_back(randchar() );				
		}
		
		auto t0 = high_resolution_clock::now();
		int a = eraseAT(str);
		auto t1 = high_resolution_clock::now();
		auto dt = t1-t0;
		long long dtms = duration_cast <microseconds> (dt).count();

		
		cout << "n=" << n << "\t" << dtms << endl;
	}
}
