#include<cstdio>

const int SUDOKU_SIZE = 9;
const int TOTAL = SUDOKU_SIZE*SUDOKU_SIZE;

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

bool done = false;

void init();
void dfs(int i);
void printResult();


int main(){
	//freopen("2676.txt","r",stdin);
	int testCases;
	scanf("%d\n",&testCases);
	while(--testCases >= 0){
		init();
		dfs(0);
		printResult();
	}

	return 0;
}

void init(){
	done = false;

	char ch;
	for(int i = 0; i < SUDOKU_SIZE; ++i){
		for(int j = 0; j < SUDOKU_SIZE; ++j){
			scanf("%c",&ch);
			sudoku[i][j] = ch - '0';
		}
		scanf("\n");
	}
}

void dfs(int i){
	if(i > (TOTAL - 1)){
		done = true;
		return;
	}
	
	int x = i/SUDOKU_SIZE;
	int y = i%SUDOKU_SIZE;
	if(sudoku[x][y]){
		dfs(i+1);
	}else{
		int tempX = x - x%3;
		int tempY = y - y%3;
		for(int j = 1; j <= SUDOKU_SIZE; ++j){

			bool isOk = true;
			
			for( int c = 0; c < SUDOKU_SIZE; ++c){
				int xx = tempX + c/3;
				int yy = tempY + c%3;
				// checking
				if(sudoku[x][c] == j || sudoku[c][y] == j || sudoku[xx][yy] == j){
					isOk = false;
					break;
				}
			}
			
			if(isOk){
				sudoku[x][y] = j;
				dfs(i+1);
				if(done) return;
				sudoku[x][y] = 0;
			}
		}
	}
}

void printResult(){
	for(int i = 0; i < SUDOKU_SIZE; ++i){
		for(int j = 0; j < SUDOKU_SIZE; ++j){
			printf("%d",sudoku[i][j]);
		}
		printf("\n");
	}

}