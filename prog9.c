#include<stdio.h>
#include<stdlib.h>
# include<time.h>
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        int minindex=i;
        for(int j=i+1;j<n;++j){
            if (arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        int temp=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=temp;
    }
}

void generaterandomnumber(int arr[],int n){
    srand(time(0));
    for(int i=0;i<n;++i){
        arr[i]=rand()%10000;
    }
}

int main(){
    int n;
    printf("enter the number of elements to sort:");
    scanf("%d",&n);
    if(n<=5000){
        printf("please enter a value greater then 5000.\n");
        return 1;
    }
    int*arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("memory allocation failed.\n");
        return 1;
    }
    generaterandomnumber(arr,n);
    clock_t start=clock();
    selectionsort(arr,n);
    clock_t end=clock();
    double timetaken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements:%f seconds \n",n,timetaken);
    free(arr);
    return 0;
}