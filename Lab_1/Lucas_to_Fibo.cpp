#include <iostream>
#include <fstream>
#include <chrono>
#include "ops.hpp"

//Using fibonacci numbers themselves is overrated!

string lucas(int n, string* m){
	if(m[n].length() == 0){
		m[n] = add(lucas(n-1,m),lucas(n-2,m));
	}
	return m[n];
}

string decr(string a){
	int i = a.size()-1;
	if(i==0 && a[0]=='1'){
		a = "0";
	}else{
		while(a[i]=='0'){
			a[i]='9';
			i--;
		}
		a[i]--;
		if(a[0] == '0'){
			a.erase(0,1);
		}
	}
	return a;
}

string fibo(int n, string* m){
	if(n==2){
		return "1";
	}
	if(n%2){
		n--;
		n/=2;
		if(n%2){
			return add(mul(m[n],fibo(n+1,m)),"1");
		}else{
			return decr(mul(m[n],fibo(n+1,m)));
		}
	}else{
		n/=2;
		return mul(m[n],fibo(n,m));
	}
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
			int l=(n-n%2)/2;
			string* m = new string[l+1];
			m[0] = "2";
			m[1] = "1";
			lucas(l,m);
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