/**
*  POJ 3278 Catch the Cow 
*  http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=15204
*/

#include<stdio.h>

#define forward(x) ((x) + 1)
#define backward(x) ((x) - 1)
#define skip(x) ((x)*2)

#define NUM_OPERATIONS 3
#define MAX_QUE_SZ 200000
#define UP_BOUND 100001
#define LOW_BOUND 0

#define enque(n) (que[(++head)%MAX_QUE_SZ] = n)
#define deque() (que[(++rear)%MAX_QUE_SZ])

typedef struct COW_STATE{
    int pos;
    int time;
}STATE;


STATE que[MAX_QUE_SZ];
int head = -1,rear = -1;

bool visited[UP_BOUND] = {0,0};

void bfs(int s, int t);

int main()
{
    int start,target;
    scanf("%d%d",&start,&target);
    
    head = rear = -1;
    bfs(start,target);

    return 0;
}

void bfs(int s,int t){
    if(s >= t){
      printf("%d\n",s-t);
      return;
    }
    
    
    int pos,nextPos;
    
    STATE state;
    state.pos = s;
    state.time = 0;
    // enqueue the t pos
    enque(state);
    
    while(head > rear){
        // dequeue
        state = deque();
        int pos = state.pos;
        // target is found
        if(pos == t){
            printf("%d\n",state.time);
            return;
        }
        // marekd as visited
        visited[pos] = 1;
    
        for(int i = 0; i < NUM_OPERATIONS; ++i){
            if(i == 0)
                nextPos = forward(pos);
            else if(i == 1)
                nextPos = backward(pos);
            else
                nextPos = skip(pos);
    
            bool inBound = nextPos >= LOW_BOUND && nextPos <= UP_BOUND;
            if(inBound && !visited[nextPos]){
                STATE temp;
                temp.pos = nextPos;
                temp.time = state.time + 1;
                enque(temp);
            }
        }
  }
}
