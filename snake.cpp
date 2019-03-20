#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1005
#define M 25
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[N][N];
int n,m,L,K;
struct node{
	int x,y,s;
}a[M],b[M],path[M];
queue<node> Q;

int work1(){
	while (!Q.empty()) Q.pop();
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=K;i++) vis[b[i].x][b[i].y]=1;
	Q.push(a[1]);
	vis[a[1].x][a[1].y]=1;
	while (!Q.empty()){
		node tmp=Q.front();
		Q.pop();
		if (tmp.x==1 && tmp.y==1) return tmp.s;
		for (int i=0;i<4;i++){
			int tx=tmp.x+dx[i],ty=tmp.y+dy[i];
			if (tx<1 || tx>n || ty<1 || ty>m || vis[tx][ty]) continue;
			vis[tx][ty]=1;
			Q.push((node){tx,ty,tmp.s+1});
		}
	}
	return 0;
}

int work2(){
	while (!Q.empty()) Q.pop();
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=L;i++){
	  vis[a[i].x][a[i].y]=1;
		path[i]=a[i];
	}
	Q.push(a[1]);
	for (int i=1;i<=K;i++) vis[b[i].x][b[i].y]=1;
	while (!Q.empty()){
		node tmp=Q.front();
		Q.pop();
		if (tmp.x==1 && tmp.y==1) return tmp.s;
		for (int i=0;i<4;i++){
			int tx=tmp.x+dx[i],ty=tmp.y+dy[i];
			if (tx<1 || tx>n || ty<1 || ty>m || vis[tx][ty]) continue;
			vis[tx][ty]=1;
			vis[path[L].x][path[L].y]=0;
			for (int i=L;i>1;i--) path[i]=path[i-1];
			path[1]=(node){tx,ty,tmp.s+1};
			Q.push(path[1]);
		}
	}
	return 0;
}
int main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	int Case;
	scanf("%d",&Case);
	while (Case--){
		scanf("%d%d%d",&n,&m,&L);
		for (int i=1;i<=L;i++) scanf("%d%d",&a[i].x,&a[i].y);
		scanf("%d",&K);
		for (int i=1;i<=K;i++) scanf("%d%d",&b[i].x,&b[i].y);
		if (L==1){
			int ans=work1();
			printf("%d\n",ans>0?ans:-1);
		}
		else{
			int ans=work2();
			printf("%d\n",ans>0?ans:-1);
		}
	}
}
