//Operations for adding and multiplying reeally long numbers represented as strings

#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b){
    if(a.size() < b.size())
        swap(a, b);
 
    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');
 
    for(int i=a.size()-1; i>0; i--){
        if(a[i] > '9'){
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
	}
	
    if(a[0] > '9'){
        string t;
        t+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        t[0] = ((t[0]-'0')/10)+'0';
        a = t+a;
    }
    return a;
}

//I am NOT implementing multiplication using FFT on strings in under 1 week.
string mul(string a, string b){
	if (a=="0" || b=="0"){
		return "0";
	}
    
	int m = a.size() - 1, n = b.size() - 1, c = 0;
    string res;
    for (int i=0; i<=m+n || c; ++i) {
        for (int j=max(0, i-n); j<=min(i, m);j++)
            c += (a[m-j] - '0') * (b[n-i+j] - '0');
        res += c % 10 + '0';
        c /= 10;
    }
    reverse(res.begin(), res.end());
	return res;
}