#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
using namespace chrono;

void showArray(int a[], int n);
bool isSorted(int a[], int n);
void shuffle(int a[], int n);
void bogoSort(int a[], int n);

int main( void ){
	int length = 5;
	int array[length] = {3, 6, 10, 4, 2};
	
	cout << "Array before sorted:" << endl;
	showArray(array, length);
	cout << endl;
	
	bogoSort(array, length);
	cout << endl;
	
	cout << "Array after sorted with Bogosort:" << endl;
	showArray(array, length);
}

void showArray(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isSorted(int a[], int n){
	for(int i=0; i<n-1; i++){
		if(a[i] > a[i+1])
			return false;
	}
	return true;
}

void shuffle(int a[], int n){
	int temp;
	int random;
	for(int i=0; i<n; i++){
		srand(time(0));
		do{
			random = rand()%n;
		} while (random == i); 
		
		temp = a[i];
		a[i] = a[random];
		a[random] = temp;		
	}	
}

void bogoSort(int a[], int n){
	long long int counter = 0;
	auto start = high_resolution_clock::now();
	while( !isSorted(a, n) ){
		counter++;
		shuffle(a, n);
	}
	auto end = high_resolution_clock::now();
	auto difference = end - start;
	long long duration = duration_cast <milliseconds> (difference).count();
	
	cout << "Shuffle executed: " << counter << "x" << endl;
	cout << "Time elapsed\t: " << duration << " millisecond(s)" << endl;
	
}
