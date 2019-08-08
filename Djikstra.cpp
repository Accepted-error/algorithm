#include<iostream>
#include<cstring>
using namespace std;
int Choose(int *d,int *s,int n)
{
    int i,min,m;
    m = 32767;
    min = -1;
    for(i = 1;i<n;i++)
    {
        if(d[i]<m&&!s[i])
        {
            m = d[i];
            min = i;
        }
    }
    return min;
}
int Djikstra(int v,int *d,int *path,int (*a)[6],int n)
{
    int i,k,w;
    int s[6];
    //s = malloc(sizeof(int)*n);//s数组记录源点到顶点的最短路径是否已经确定
    memset(s,0,n*sizeof(int));
    if(v<0||v>n-1)
        return -1;
    for(i = 0;i<n;i++)
    {
        d[i] = a[v][i];
        if(i!=v&&d[i]<32767)
            path[i] = v;
        else
            path[i] = -1;    
    }
    s[v] = 1;//源点到源点的距离已经确定
    d[v] = 0;//源点到源点距离为0
    for(i=1;i<n-1;i++)
    {
        k = Choose(d,s,n);
        s[k] = 1;
        cout<<k<<" ";
        for(w = 0;w<n;w++)
        {
            if(!s[w]&&d[k]+a[k][w]<d[w])//更新d数组 path数组
            {
                d[w] = d[k] + a[k][w];
                path[w] = k;
            }
        }
    }
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<d[i]<<" ";
    return 1;
}
int main()
{
    int v=0,n=6;
    int d[6];//保存源点到顶点i的当前最短距离
    int path[6];//保存从源点到顶点i的当前最短路径上顶点i的直接前驱顶点的序号
    int a[6][6];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            if(i == j)
                a[i][j] = 0;
            else
                a[i][j] = 32767;
    a[0][1] = 50;
    a[0][2] = 10;
    a[0][4] = 80;
    a[1][2] = 15;
    a[1][4] = 20;
    a[2][3] = 15;
    a[3][1] = 20;
    a[3][4] = 45;
    a[4][3] = 45;
    a[5][3] = 9;
    a[5][4] = 10;
    cout<<v<<" ";
    Djikstra(v,d,path,a,6);
    return 0;
}