#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

const long long MAXN = 1e7;

using namespace std;
/**

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
**/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  		int len = (int) s.length();

  		unordered_map< char , int > visited;
  		if( !len ) return 0;

  		int l = 0 , r = 0 ;
  		int ans = 1;
  		
  		while((l <= r) && (r < len)){
  			
  			if ( !visited[ s[r] ] ){
  				visited [ s[r] ] = 1;
  				ans = max (ans , r - l + 1);
  				r += 1;
  			}
  			else{
  				while ( visited[ s[r] ] ){
  					visited[ s[l] ] --;
  					l += 1;
  				}
  			}
  		}

  		return ans;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "aab";
	Solution * sol = new Solution;

	cout << sol->lengthOfLongestSubstring(s) << "\n";
    return 0;
}
