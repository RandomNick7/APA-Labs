#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

string fibo(int n, string* m){
	if(m[n].length() == 0){
		m[n] = add(fibo(n-1,m),fibo(n-2,m));
	}
	return m[n];
}

int main(){
	fstream out("results.txt");
	int min_bound = 1000;
	int max_bound = 15000;
	out << min_bound << " " << max_bound << "\n";
	for (int x=min_bound;x<max_bound;x+=100){
		int n = x;
		string res;
		auto start = chrono::steady_clock::now();
		
		if(n>2){
			string* m = new string[n+1];
			m[0] = "0";
			m[1] = "1";
			res = fibo(n,m);
			free(m);
		}else{
			res = to_string(n);
		}
	
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}