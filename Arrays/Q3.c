#include <stdio.h>
#include <stdlib.h>

void solve(int* arr){
   int res=arr[0];
   int end=arr[0];
   for(int i=1;i<7;i++){
    if(end+arr[i]>arr[i]) end=arr[i]+end;
    else end=arr[i];
    if(res<=end)res=end;
   }
   printf("%d ",res);
}

int main(){
    int arr1[7]={2, 3, -8, 7, -1, 2, 3};
    solve(arr1);
}