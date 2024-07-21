import java.util.*;
public class Program7 {

int n;
int cost[][]=new int[10][10];
int dist[]=new int[10];
void readmatrix(int n);
int min(int a,int b);
void shortest_path(int n,int s);
public static void main(String[] args){
int i,s;
Scanner sc=new Scanner(System.in);
System.out.println("Enter the number of vertices\n");
n=sc.nextInt();
System.out.println("Enter the cost adjecency matrix(999 for infinite)\n");
readmatrix(n);
System.out.println("Enter the source vertex\n");
s=sc.nextInt();
shortest_path(n,s);
for(i=1;i<=n;i++)
System.out.println("The shortest path between vertex %d to %d is %d\n",s,i,dist[i]);
return 0;
}
int min(int a,int b)
{
return a>b?b:a;
}
void readmatrix(int n)
{
int i,j;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
Scanner sc=new Scanner(System.in);
System.out.println("(%d,%d):",i,j);
cost[i][j]=sc.nextInt();
if(cost[i][j]==0)
cost[i][j]=999;
}
}
void shortest_path(int n,int s)
{
int c,u,i,k;
int vis[]=new int [10];
for(i=1;i<=n;i++)
{
vis[i]=0;
dist[i]=cost[s][i];
}
dist[s]=0;
vis[s]=1;
for(k=1;k<=n;k++)
{
c=999;
for(i=1;i<=n;i++)
if(vis[i]==0)
{
if(dist[i]<=c)
{
c=dist[i];
u=i;
}
}
vis[u]=1;for(i=1;i<=n;i++)
dist[i]=min(dist[i],dist[u]+cost[u][i]);
}
}
}