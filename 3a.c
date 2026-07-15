#include<stdio.h>
int min(int a,int b)
{
    return (a<b?a:b);
}
void floyd(int d[][10],int n)
{
    for (int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
    int n,cost[10][10];
    printf("enter no of vertices:");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        scanf("%d",&cost[i][j]);
      floyd(cost,n);
      printf("all pairs shortest path\n");
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
           printf("%4d",cost[i][j]);
        printf("\n");
      }
}