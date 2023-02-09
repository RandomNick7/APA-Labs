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
		string fib1,fib2,res;
		auto start = chrono::steady_clock::now();
		
		switch(n%3){
			case 0:
				fib1 = "0";
				fib2 = "2";
				break;
			case 1:
				fib1 = "1";
				fib2 = "3";
				break;
			case 2:
				fib1 = "1";
				fib2 = "5";
				break;
		}
		if(n>2){
			n/=3;
			for(int i=0;i<n-1;i++){
				string temp = add(fib1,mul("4",fib2));
				fib1 = fib2;
				fib2 = temp;
			}
			res = fib2;
		}else{
			res = fib1;
		}	
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
    return 0;
}