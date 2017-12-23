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

struct Point{
	int x ; 
	int y ;
	//Constructor Overloading
	Point(int x1 , int y1){
		x = x1;
		y = y1;
	}
	Point(){
		x = 3;
		y = 4;
	}
	Point(int y1){
		x = 5;
		y = y1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	
	Point point1(1 , 2);
 	cout << point1.x << " " << point1.y << "\n";
 	
 	Point point2;
 	cout << point2.x << " " << point2.y << "\n";

	Point point3(7);
	cout << point3.x << " " << point3.y << "\n";	
    
    return 0;
}
