/*
* POJ 2386 Count the ponds
* http://acm.hust.edu.cn/vjudge/problem/visitOriginUrl.action?id=14167
*/
#include<stdio.h>

const int MAX_ROW = 102;
const int MAX_COL = 102;
const int NUM_OF_DIRECTIONS = 8;

int row,col;
int map[MAX_ROW][MAX_COL];

bool marked[MAX_ROW][MAX_COL];

int dirc[NUM_OF_DIRECTIONS][2]={
	{-1,-1},{-1,0},{-1,+1},
	{0,-1},{0,+1},
	{+1,-1},{+1,0},{+1,+1}
};

int numberOfPonds;

void init();
void getNumberOfPonds();
void dfs(int x,int y);

int main(){
	//freopen("55.txt","r",stdin);

	init();
	getNumberOfPonds();
	printf("%d\n",numberOfPonds);

	return 0;
}

void init(){
	scanf("%d %d\n",&row,&col);

	numberOfPonds = 0;
	for(int r = 1; r <= row; ++r){
		for(int c = 1; c <= col; ++c){
			char ch;
			scanf("%c",&ch);
			if(ch == 'W'){
				map[r][c] = 1;
			}else if(ch == '.'){
				map[r][c] = 0;
			}

			marked[r][c] = false;
		}
		scanf("\n");
	}
}


void getNumberOfPonds(){
	for(int r = 1; r <= row; ++r){
		for(int c = 1; c <= col; ++c){
			if(!marked[r][c] && map[r][c]){
				dfs(r,c);
				++numberOfPonds;
			}
		}
	}
}

void dfs(int x, int y){
	marked[x][y] = true;

	for(int i = 0; i < NUM_OF_DIRECTIONS; ++i){
		int xx = x + dirc[i][0];
		int yy = y + dirc[i][1];
		bool inBound = xx > 0 && xx <= row && yy > 0 && yy <= col;
		if(inBound && !marked[xx][yy] && map[xx][yy]){
			dfs(xx,yy);
		}
	}
}
