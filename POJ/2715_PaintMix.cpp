/**
 * POJ2715 Paint Mix
 * http://poj.org/problem?id=2715
 */

#include<cstdio>

const int BLACK = 0;
const int WHITE = 1;
const int GALLON_TO_CUPS = 16;
const double EPSILON = 1e-5;

#define ABS(x) ((x) < 0 ? ((-1)*(x)) : (x))

typedef struct{
	double b;
	double w;
}STATE;

int c = 0;
STATE currentState[2];

double total;
double ratio[2]; // B/W for Black paint and white paint
double finalRatio = 0.0;
int numberOfPlays = 0;

void play();
bool shouldStop();
inline void pour(int flag);

int main(){
	//freopen("0509.txt","r",stdin);

	int white = 0,black = 0;
	while(scanf("%d %d %d",&black,&white,&c), 
		black != 0 && white != 0 && c != 0){

			numberOfPlays = 0;
			finalRatio = (black*1.0)/white;

			ratio[BLACK] = 1.0;
			ratio[WHITE] = 0.0;
			total = (black + white)*GALLON_TO_CUPS;
			currentState[BLACK].b = black*GALLON_TO_CUPS,currentState[BLACK].w = 0;
			currentState[WHITE].b = 0,currentState[WHITE].w = white*GALLON_TO_CUPS;

			play();
	}
}


void play(){

	while(!shouldStop()){
		// interative calculation
		//b11/w11 = (b1*(b0 + w0) + b0*c)/(w1*(b0 + w0) + w0 * c);
		//ratio[WHITE] = (currentState[WHITE].b * (currentState[BLACK].b + currentState[BLACK].w)
		pour(BLACK);
		pour(WHITE);
		++numberOfPlays;
	}

	printf("%d\n",numberOfPlays);
}


inline void pour(int flag){
	double black = ratio[flag] * c;
	double white = c - black;

	if(flag == 0){
		currentState[BLACK].b -= black;
		currentState[BLACK].w -= white;
		currentState[WHITE].b += black;
		currentState[WHITE].w += white;
	}else{
		currentState[BLACK].b += black;
		currentState[BLACK].w += white;
		currentState[WHITE].b -= black;
		currentState[WHITE].w -= white;
	}

	double blackTotal = currentState[BLACK].b + currentState[BLACK].w;
	ratio[BLACK] = currentState[BLACK].b/blackTotal;
	ratio[WHITE] = currentState[WHITE].b/(total - blackTotal);
}

bool shouldStop(){
	double rb = currentState[BLACK].b/currentState[BLACK].w;
	double rb = currentState[BLACK].b/currentState[BLACK].w;
	double rw = currentState[WHITE].b/currentState[WHITE].w;
	if(ABS(rb - finalRatio) < EPSILON && 
		ABS(rw - finalRatio) < EPSILON){
			return true;
	}

	return false;
}