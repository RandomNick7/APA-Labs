#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

int main(){
	fstream out("results.txt");
	int min_bound = 10000;
	int max_bound = 25000;
	out << min_bound << " " << max_bound << "\n";
	for (int x=min_bound;x<max_bound;x+=100){
		int n = x;
		string res;
		auto start = chrono::steady_clock::now();
		
		//A long double has roughly 18 decimal digits of precision (according to gcc)
		const long double phi = (1+sqrtl(5))/2;
		res = to_string(round(pow(phi,n)/sqrtl(5)));

		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}