#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <unordered_map>
// const long long MAXN = 1e7;


/*
https://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
*/

using namespace std;
unordered_map<string , int> mp;
string s;
int DP[1000][1000];
int dp(int i , int j){
	if(j < i) return 0;
	if(DP[i][j] != -1) return DP[i][j];
	string tmp = s.substr(i , j - i + 1);

	if(mp[tmp] == 1) return 1;
	DP[i][j] = 0;
	for(int k = i ; k < j ; k++){
		DP[i][j] |= dp(i , k) && dp(k + 1 , j);
	}
	return DP[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	string st;
 	while( t -- ){
 		mp.clear();
 		memset (DP , -1 , sizeof(DP));
 		int n;
 		cin >> n;
 		for( int i = 0 ; i < n ; i++){
 			cin >> st;
 			mp[ st ] = 1;
 		}
 		cin >> s;
 		cout << dp(0 , (int)s.length() - 1) << "\n";
 	}
    return 0;
}
