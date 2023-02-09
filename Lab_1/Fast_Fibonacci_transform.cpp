#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

void pair_mult(string A[2], string B[2]){
	string c1 = add(add(mul(A[0],B[0]), mul(A[0],B[1])), mul(A[1],B[0]));
	string c2 = add(mul(A[0],B[0]), mul(A[1],B[1]));
	A[0] = c1;
	A[1] = c2;
}

string fibo_pair(int n){
	int pow = 1;
	string P[2] = {"1","0"};
	string res[2] = {"0", "1"};
	while(pow<=n){
		if(n&pow){
			pair_mult(res,P);
		}
		pair_mult(P,P);
		pow<<=1;
	}
	return res[0];
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
	
		res = fibo_pair(n);
		
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}