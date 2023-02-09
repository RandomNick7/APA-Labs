#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

int main(){
	fstream out("results.txt");
	int min_bound = 1000;
	int max_bound = 25000;
	out << min_bound << " " << max_bound << "\n";
	for (int x=min_bound;x<max_bound;x+=100){
		int n = x;
		string fib1 = "0", fib2 = "1", temp;
		auto start = chrono::steady_clock::now();
		
		if(n==0){
			cout << fib1 << endl;
		}else if(n==1){
			cout << fib2 << endl;
		}else{
			for(int i=0;i<n-1;i++){
				temp = add(fib1,fib2);
				fib1 = fib2;
				fib2 = temp;
			}
		}
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
    return 0;
}