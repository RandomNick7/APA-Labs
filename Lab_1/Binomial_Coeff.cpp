#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>
#include "ops.hpp"

//Division between strings is a no-no, mul() is for integers only
//We're gonna work around this at the cost of some efficiency

int get_primes(int n, int* p){
	int k = 0;
	for(int i=2;i<=n;i++){
		int flag = 1, l = round(sqrt(i));
		for(int j=2;j<=l;j++){
			if(i%j==0){
				flag = 0;
				break;
			}
		}
		if(flag){
			p[k]=i;
			k++;
		}
	}
	return k;
}

string binom_coeff(int n, int k, int s, int* prime){
	string res = "1";
	if(k==0){
		return res;
	}
	int n_term[s]={0}, k_term[s]={0};
	while(k>0){
		// decompose n;
		int nt = n;
		while(nt>1){
			for(int i=0;i<s;i++){
				if(nt%prime[i]==0){
					nt/=prime[i];
					n_term[i]++;
					break;
				}
			}
		}
		// decompose k;
		int kt = k;
		while(kt>1){
			for(int i=0;i<s;i++){
				if(kt%prime[i]==0){
					kt/=prime[i];
					k_term[i]++;
					break;
				}
			}
		}
		k--;
		n--;
	}
	//Put everything together in a string
	for(int i=0;i<s;i++){
		int c=n_term[i]-k_term[i];
		uint64_t t = 1;
		for(int j=0;j<c;j++){
			t*=prime[i];
		}
		res = mul(res,to_string(t));
	}
	return res;
}



int main(){
	fstream out("results.txt");
	int min_bound = 100;
	int max_bound = 1500;
	out << min_bound << " " << max_bound << "\n";
	for (int x=min_bound;x<max_bound;x+=10){
		int n = x;
		string res;
		auto start = chrono::steady_clock::now();
		
		string fib = "0";
		int prime[n]={0};
		int s = get_primes(n,prime);
		for(int i=0;i<(n+n%2)/2;i++){
			string t = binom_coeff(n-i-1,i,s,prime);
			fib = add(fib,t);
		}

		auto end = chrono::steady_clock::now();
		out << chrono::duration_cast<chrono::microseconds>(end - start).count() << ",";
	}
	out.close();
	return 0;
}