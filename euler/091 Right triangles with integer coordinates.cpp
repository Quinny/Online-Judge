#include <iostream>
#define MAX 50
using Point = std::pair<int, int>;

int dist_squared(Point, Point);
bool right_angle(Point, Point, Point);

int main(){
	Point o(0, 0);
	int ans = 0;
	for(int i = 0; i <= MAX; i++){
		for(int j = 0; j <= MAX; j++){
			for(int k = 0; k <= MAX; k++){
				for(int m = 0; m <= MAX; m++){
					if(right_angle(Point(i, j), Point(k, m), o)) ans++;
				}
			}
		}
	}
	std::cout << ans / 2 << std::endl;
	return 0;
}

bool right_angle(Point x, Point y, Point o){
	int d1 = dist_squared(o, x);
	int d2 = dist_squared(o, y);
	int d3 = dist_squared(x, y);
	if(d1 == 0 || d2 == 0 || d3 == 0) return false;
	int longest = std::max({d1, d2, d3});
	if(longest == d1)
		return d2 + d3 == d1;
	if(longest == d2)
		return d1 + d3 == d2;
	return d1 + d2 == d3;
}

int dist_squared(Point x, Point y){
	int dx = y.first - x.first;
	int dy = y.second - x.second;
	return (dx * dx) + (dy * dy);
}