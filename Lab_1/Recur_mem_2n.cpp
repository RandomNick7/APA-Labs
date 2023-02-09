#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

string fibo(int n, string* m){
	if (m[n].length()>0)
		return m[n];

	int k = (n+n%2)/2;
	string fib1 = fibo(k-1,m);
	string fib2 = fibo(k,m);
	
	if(n%2){
		m[n] = add(mul(fib1,fib1), mul(fib2,fib2));	//f1^2 + f2^2
	}else{
		m[n] = mul(add(mul("2",fib1),fib2),fib2);	//(2*f1+f2)*f2
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
		
		//Space can be HEAVILY optimized... [O(n)->O(logn)]
		//...but playing with indices in the new array is a headache and a half
		string* m = new string[n+1];
		m[0] = "0";
		m[1] = "1";
		res = fibo(n,m);
	
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}
