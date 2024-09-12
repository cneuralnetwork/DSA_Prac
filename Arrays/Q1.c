#include <stdio.h>
#include <stdlib.h>

void freearr(int* arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=-1;
    }
}

int sizearr(int* arr){
    int i=0;
    while(arr[i]!=-1){
        i++;
    }
    return i;
}


int longestsubseq(int* arr,int n){
    if(n==0) return 0;
    int* dp=(int*)malloc(sizeof(int)*n);
    int max=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        if(dp[i]>max){
            max=dp[i];
        }
    }
    return max;
}

void solve(int* arr,int n){
    printf("%d ",longestsubseq(arr,n));
}

int main(){
    int arr[10]={10, 9, 2, 5, 3, 7, 101, 18,-1,-1};
    // len = sizeof(arr)/sizeof(arr[0])
    // printf("%d",sizearr(arr));
    solve(arr,8);
}