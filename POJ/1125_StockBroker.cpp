#include<cstdio>

const int MAX_N = 110;
const int INF = 0x1FFFFFF;

int N;
int timeMap[MAX_N][MAX_N];

// Floyd Warshall Algorithm
int fwMap[MAX_N][MAX_N];
/* maximum of shortest path from i to others */
int sp[MAX_N];
struct RESULT{
    int which;
    int time;
}res;


bool marked[MAX_N];
int time[MAX_N];


void init();

void initDij();
void dijkstraSP(int src);

int findMax(int* arry,int sz);
// get minimum of sp[]
void getMin();

int main(){

    //freopen("InputData/1125.txt","r",stdin);

    while(scanf("%d",&N), N != 0){

        init();

        for(int i = 1; i <= N; ++i){
            dijkstraSP(i);
        }

        getMin();

        res.time == INF ? printf("disjoint\n") :
        printf("%d %d\n",res.which,res.time);
    }

    return 0;
}

void init(){

    res.which = 0;
    res.time = INF;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j){
            timeMap[i][j] = timeMap[j][i] = INF;
        }

        sp[i] = INF;
    }

    for(int c = 1; c <= N; ++c){
        int num, which,time;
        scanf("%d",&num);
        for(int i = 0; i < num; ++i){
            scanf("%d %d",&which,&time);
            timeMap[c][which] = time;
        }
    }

}

void initDij(){
    for(int i = 1; i <= N; ++i){
        marked[i] = false;
        time[i] = INF;
    }
}

void dijkstraSP(int src){

    initDij();

    time[src] = 0;
    int u = src;

    for(int n = 1; n < N; ++n){

        int tmp = INF;
        for(int i = 1; i <= N; ++i){
            if(!marked[i] && tmp > time[i]){
                tmp = time[i];
                u = i;
            }
        }

        marked[u] = true;

        for(int v = 1; v <= N; ++v){
            int t = time[u] + timeMap[u][v];
            if(u != v && !marked[v] && time[v] > t){
                time[v] = time[u] + timeMap[u][v];
            }
        }
    }

    // find the max value of time[]
    sp[src] = findMax(time,N);

    return;
}

int findMax(int* arry, int sz){
    int ret = -1;
    for(int i = 1; i <= sz; ++i){
        ret = arry[i] > ret ? arry[i] : ret;
    }

    return ret;
}

void getMin(){

    for(int j = 1; j <= N; ++j){
        if(res.time > sp[j]){
            res.time = sp[j];
            res.which = j;
        }
    }

    return;
}

