#include <stdio.h>
int main(){
    int N; scanf("%d", &N);
    int t;
    for (int i=1; i<=N; i++){
        scanf("%d", &t);
        if ((t+i) % 2){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}