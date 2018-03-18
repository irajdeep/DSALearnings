http://codeforces.com/contest/939/problem/D
https://www.geeksforgeeks.org/union-find/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <string>

const long long MAXN = 1e7;
using namespace std;
const int N = 30;
int par[N] ;
int r[N];

int findSet(int i){
	if (par[i] == i) return i;
	return par[i] = findSet(par[i]);
}

void unionSet(int x , int y){
	int xp = findSet(x) , yp = findSet(y);
	if( r[xp] < r[yp] )
		par[ xp ] = yp; 
	else if(r[xp] > r[yp])
		par[ yp ] = xp;
	else {	
			par[yp] = xp;
			r[xp]++;
	}
}

int main() {
	ios_base::sync_with_stdiao(false);
	cin.tie(NULL);
 

 	for(int i = 0 ; i < N ; i++) par[i] = i , r[i] = 0;
 	int n;
 	cin >> n ;
 	string a , b;
 	cin >> a ;
 	cin >> b ;
 	vector < pair < char , char > > v;
 	for(int i = 0 ; i < n ; i++){
 		if (findSet(a[i] - 'a') != findSet(b[i] - 'a')){
 			v.push_back(make_pair(a[i] , b[i]));
 			unionSet(a[i] - 'a' , b[i] - 'a');
 		}
 	}
 	cout << (int)v.size() << "\n";
 	for(auto &e : v){
 		cout << e.first << " " << e.second << "\n";
 	}
    return 0;
}