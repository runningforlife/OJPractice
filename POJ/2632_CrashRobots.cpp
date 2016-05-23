#include<cstdio>

#define MAX_SIZE 102
#define WALL_CRASH "Robot %d crashes into the wall\n"
#define ROBOT_CRASH "Robot %d crashes into robot %d\n"

typedef enum{
    NODIRECT = 0,EAST,NORTH,WEST,SOUTH
}DIRECTION;

typedef struct{
    int x;
    int y;
    DIRECTION dir;
}STATE;

typedef struct{
    int robot;
    int action;
    int times;
}CMD;

STATE rob[MAX_SIZE];
int hasRobot[MAX_SIZE][MAX_SIZE];
CMD instruct[MAX_SIZE];

int A,B,N,M;

void Init(){
    for(int i = 1; i <= B; ++i){
        for(int j = 1; j <= A; ++j){
            hasRobot[i][j] = 0;
        }
    }

    for(int i = 1; i <= N; ++i){
        rob[i].x = 0;
        rob[i].y = 0;
        rob[i].dir = NODIRECT;
    }

    for(int i = 0; i < M; ++i){
        instruct[i].robot = 0;
        instruct[i].action = 0;
        instruct[i].times = 0;
    }

    return;
}

void GetInput(){

    for(int i = 1; i <= N; ++i){
        int x,y;
        char ch;
        scanf("%d %d ",&y,&x);
        scanf("%c",&ch);
        rob[i].x = x, rob[i].y = y;
        hasRobot[x][y] = i;
        if(ch == 'E')
            rob[i].dir = EAST;
        else if(ch == 'W')
            rob[i].dir = WEST;
        else if(ch == 'S')
            rob[i].dir = SOUTH;
        else if(ch == 'N')
            rob[i].dir = NORTH;
    }

    for(int i = 0; i < M; ++i){
        int robot,times;
        char action;
        scanf("%d ",&robot);
        scanf("%c",&action);
        scanf("%d",&times);
        instruct[i].robot = robot;
        instruct[i].times = times;
        if(action == 'L')
            instruct[i].action = 1;
        else if(action == 'R')
            instruct[i].action = 2;
        else if(action == 'F')
            instruct[i].action = 3;
    }

    return;
}

bool DoMove(int cmdCount){
    int robot = instruct[cmdCount].robot;
    int times = instruct[cmdCount].times;
    int action = instruct[cmdCount].action;

    int antiCwDirc[4][4] = {{1,4,3,2},{2,1,4,3},{3,2,1,4},{4,3,2,1}};
    int cwDirc[4][4] = {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};// clock-wise

    STATE next = rob[robot];
    int dir = (int)rob[robot].dir;
    if(action == 3){
        int x = rob[robot].x, y = rob[robot].y;
        int xx = x,yy = y;

        for(int i = 1; i <= times; ++i){
            if(dir == 1)
                ++yy;
            else if(dir == 2)
                ++xx;
            else if(dir == 3)
                --yy;
            else if(dir == 4)
                --xx;
            bool isOk = xx > 0 && xx <= B && yy > 0 && yy <= A;
            if(!isOk){
                printf(WALL_CRASH,robot);
                return false;
            }else if(hasRobot[xx][yy]){
                printf(ROBOT_CRASH,robot,hasRobot[xx][yy]);
                return false;
            }
        }
        next.x = xx;
        next.y = yy;
        hasRobot[x][y] = 0;
        hasRobot[xx][yy] = robot;
    }else if(action == 1){
        times %= 4;
        next.dir = (DIRECTION)cwDirc[dir-1][times];
    }else if(action == 2){
        times %= 4;
        next.dir = (DIRECTION)antiCwDirc[dir-1][times];
    }
    // save the next state
    rob[robot] = next;

    return true;
}

void ProcessInstruct(){

    int cmdCount = 0;
    while(cmdCount < M){
        if(!DoMove(cmdCount))
           return;

        ++cmdCount;
    }
    printf("OK\n");

    return;
}


int main()
{
    //freopen("InputData/2326.txt","r",stdin);
    int numberOfCases;
    scanf("%d",&numberOfCases);
    while(numberOfCases-- > 0){
        scanf("%d %d %d %d",&A,&B,&N,&M);
        Init();
        GetInput();
        ProcessInstruct();
    }

    return 0;
}
