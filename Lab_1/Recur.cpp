#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

string fibo(int n){
    if(n>1){
        return add(fibo(n-2),fibo(n-1));
    }else{
        return to_string(n);
    }
}

int main(){
	fstream out("results.txt");
	int min_bound = 15;
	int max_bound = 35;
	out << min_bound << " " << max_bound << "\n";
	for (int x=min_bound;x<max_bound;x++){
		int n = x;
		auto start = chrono::steady_clock::now();
		
		fibo(n);
	
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
    return 0;
}