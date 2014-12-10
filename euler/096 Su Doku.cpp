#include <iostream>
#define SIZE 9

// shout out to this guy http://en.wikipedia.org/wiki/Sudoku_solving_algorithms
using Point = std::pair<int, int>;
Point find_empty(int board[][SIZE]); // finds next empty point
bool valid_spot(int board[][SIZE], Point p, int v); // checks if we can put the number there
void solve(int board[][SIZE]); // solves the board
void read_board(int board[][SIZE]); // reads the board into the array

int main(){
	std::string tmp;
	int ans = 0;
	for(int i = 0; i < 50; i++){
		std::cin >> tmp;
		std::cin >> tmp;
		int board[SIZE][SIZE];
		read_board(board);
		solve(board);
		ans += (board[0][0] * 100) + (board[0][1] * 10) + board[0][2];
	}
	std::cout << ans << std::endl;
	return 0;
}

void read_board(int board[][SIZE]){
	char v;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			std::cin >> v;
			board[i][j] = v - '0';
		}
	}
}

Point find_empty(int board[][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(board[i][j] == 0) return Point(i,j);
		}
	}
	return Point(-1, -1);
}

bool valid_spot(int board[][SIZE], Point p, int v){
	for(int i = 0; i < SIZE; i++){ // check same row and col
		if(board[p.first][i] == v) return false;
		if(board[i][p.second] == v) return false;
	}
	int x = p.first - (p.first % 3); // find the top left of the box
	int y = p.second - (p.second % 3);
	for(int i = x; i < x + 3; i++){ // check the same square
		for(int j = y; j < y + 3; j++){
			if(board[i][j] == v) return false;
		}
	}
	return true;
}

void solve(int board[][SIZE]){
	Point p(0,0);
	p = find_empty(board);
	if(p.first == -1 && p.second == -1) return;
	for(int i = 1; i <= 9; i++){
		if(valid_spot(board, p, i)){
			board[p.first][p.second] = i;
			solve(board);
			Point check = find_empty(board);
			if(check.first == -1 && check.second == -1) return;
		}
	}
	board[p.first][p.second] = 0; // we didnt find a solution, start over
}