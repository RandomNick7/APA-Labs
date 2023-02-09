#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

void mat_mul(string A[2][2], string B[2][2]){
	string c1 = add(mul(A[0][0],B[0][0]), mul(A[0][1],B[1][0]));
	string c2 = add(mul(A[0][0],B[0][1]), mul(A[0][1],B[1][1]));
	string c3 = add(mul(A[1][0],B[0][0]), mul(A[1][1],B[1][0]));
	string c4 = add(mul(A[1][0],B[0][1]), mul(A[1][1],B[1][1]));
	
	A[0][0] = c1;
	A[0][1] = c2;
	A[1][0] = c3;
	A[1][1] = c4;
}

void mat_pow(int n, string M[2][2]){
	if(n<2){return;}
	
	mat_pow(n/2,M);
	mat_mul(M,M);
	
	if(n%2){
		string B[2][2] = {{"1","1"},{"1","0"}};
		mat_mul(M,B);
	}
}

string matrix_gen(int n){
	string F[2][2] = {{"1","1"},{"1","0"}};
	mat_pow(n-1,F);
	return F[0][0];
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
		
		if(n==0){
			res = "0";
		}else{
			res = matrix_gen(n);
		}
	
		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}