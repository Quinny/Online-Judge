#include <iostream>

struct Point{
	int x, y;
	Point(int a, int b): x(a), y(b) {};
};

struct Triangle{
	Point a, b, c;
	Triangle(Point x, Point y, Point z): a(x), b(y), c(z) {};
	int area(){
		return std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	}
	bool contains(Point p){
		Triangle t1(a, b, p);
		Triangle t2(b, c, p);
		Triangle t3(a, c, p);
		return area() == t1.area() + t2.area() + t3.area();
	}
};

int main(){
	Point o(0,0);
	int ans = 0;
	for(int i = 0; i < 1000; i++){
		int x, y;
		std::cin >> x >> y;
		Point a(x, y);
		std::cin >> x >> y;
		Point b(x, y);
		std::cin >> x >> y;
		Point c(x, y);
		if(Triangle(a, b, c).contains(o)) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}