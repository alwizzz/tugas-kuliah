#include<iostream>
#include<time.h>
#include<chrono>
#include <array>
using namespace std;
using namespace chrono;
void swap(int * xp, int * yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void STAY(int arr[], int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]) swap(&arr[j], &arr[j+1]);
		}
	}
}

int main(void){
	
	cout << "\tBestcase\tWorstcase\tAveragecase" << endl;
	for( int n=999; n<=10000; n+=1000 ){
		int* best = new int[n];
		int* worst = new int[n];
		int* avg = new int[n];
		
		for( int i=0; i<n; i++ ){
			best[i] = i;
			worst[i] = n-i;
			avg[i] = rand();
		}
		
		auto best_t0 = high_resolution_clock::now();
		STAY(best, n);
		auto best_t1 = high_resolution_clock::now();
		auto best_dt = best_t1-best_t0;
		long long best_dtms = duration_cast <microseconds> (best_dt).count();
		
		auto worst_t0 = high_resolution_clock::now();
		STAY(worst, n);
		auto worst_t1 = high_resolution_clock::now();
		auto worst_dt = worst_t1-worst_t0;
		long long worst_dtms = duration_cast <microseconds> (worst_dt).count();
		
		auto avg_t0 = high_resolution_clock::now();
		STAY(avg, n);
		auto avg_t1 = high_resolution_clock::now();
		auto avg_dt = avg_t1-avg_t0;
		long long avg_dtms = duration_cast <seconds> (avg_dt).count();
		
		cout << "n=" << n << "\t" << best_dtms << "\t\t" << worst_dtms << "\t\t" << avg_dtms << endl;
	}
}
