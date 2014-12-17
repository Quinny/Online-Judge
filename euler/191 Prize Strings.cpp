#include <iostream>

int prizes = 0;
void gen_prizes(int, int, int);

int main(){
	gen_prizes(0, 0, 0);
	std::cout << prizes << std::endl;
	return 0;
}

void gen_prizes(int days, int lates, int absent){
	if(days == 30){
		prizes++;
		return;
	}
	if(lates == 0)
		gen_prizes(days + 1, lates + 1, 0);
	if(absent != 2)
		gen_prizes(days + 1, lates, absent + 1);
	gen_prizes(days + 1, lates, 0);
}