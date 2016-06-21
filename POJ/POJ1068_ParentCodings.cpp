#include<stdio.h>

#define MAX_LEN 100000

char str[MAX_LEN];
int w[MAX_LEN];

void solve();

int main(){
    //freopen("InputData/POJ1068.txt","r",stdin);
    int T;
    scanf("%d",&T);

    for(int t = 1; t <= T; ++t){
        solve();
    }

    return 0;
}

void solve(){
    int N,n,cnt;
    scanf("%d",&N);

    cnt = 0;
    int preN = 0;
    for(int i = 1; i <= N; ++i){
        scanf("%d",&n);

        for(int j = preN; j < n; ++j) str[cnt++] = '(';
        str[cnt++] = ')';
        preN = n;
    }

    int l = 0;
    for(int i = 0; i < cnt; ++i){
        if(str[i] == '(') w[++l] = 0;
        else{
            printf("%d ",w[l] + 1);
            w[l-1] += (w[l] + 1);
            // left parentheses decrease
            --l;
        }
    }

    printf("\n");
}

