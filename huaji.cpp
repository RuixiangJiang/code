#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1005;
int n,p;
int a[5][N];
void work1(){
	int ans=0;
	for (int i=1;i<=n;i++)
	  if (a[1][i]!=0) for (int j=1;j<=n;j++)
	    if (a[2][j]!=0) for (int k=1;k<=n;k++)
	      if (a[3][k]!=0) for (int l=1;l<=n;l++)
	        if (a[4][l]!=0){
	        	LL x=a[1][i]*a[2][j] %p *a[3][k] %p *a[4][l] %p;
	        	if (x==1) ans++;
	        }
	printf("%d",ans);
}
void work2(){
	int b[5][N]={0},ans=0;
	for (int i=1;i<=4;i++)
	  for (int j=1;j<=n;j++)
	    b[i][a[i][j]]++,b[i][0]=max(b[i][0],a[i][j]);
	for (int i=1;i<=b[1][0];i++)
	  for (int j=1;j<=b[2][0];j++)
	    for (int k=1;k<=b[3][0];k++)
	      for (int l=1;l<=b[4][0];l++){
	      	LL x=i*j %p *k %p *l %p;
	        if (x==1) ans+=b[1][i]*b[2][j]*b[3][k]*b[4][l];
	      }
	printf("%d",ans);
}
int main(){
	freopen("huaji.in","r",stdin);
	freopen("huaji.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=4;i++)
	  for (int j=1;j<=n;j++)
	    scanf("%d",&a[i][j]),a[i][j]%=p;
	if (p<=70) {work2();return 0;}
	if (n<=70) {work1();return 0;}
	int t=1;
	for (int i=1;i<=4;i++)
	  for (int j=1;j<=n;j++)
	    if (a[i][j]!=1) {t=0;break;}
	if (!t) return 0; else printf("%d",n*n*n*n);
}
