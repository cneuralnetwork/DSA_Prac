#include <stdio.h>
#include <stdlib.h>

void solve(int* arr1, int* arr2){
    int m=4;
    int n=4;
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(j>=0){
        if(i>=0 && arr1[i]>=arr2[j]){
            arr1[k]=arr1[i];
            i--;
        }
        else{
            arr1[k]=arr2[j];
            j--;
        }
        k--;
    }
    for(int i =0;i<8;i++){
        printf("%d ",arr1[i]);
    }
}

int main(){
    int arr1[8]={1,3,5,7,0,0,0,0};
    int arr2[]={2,4,6,8};
    solve(arr1,arr2);
}