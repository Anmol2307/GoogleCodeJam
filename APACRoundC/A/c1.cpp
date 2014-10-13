#include <bits/stdc++.h>
using namespace std;
#define ll long long

string a[305];
bool v[305][305];
int n;

void go(int x, int y) {
  if(x<0 || x>=n || y<0 || y>=n) return;
  if(v[x][y] || a[x][y]=='*') return;
  v[x][y] = 1;
  bool f = false;
  for(int i=-1; i<=1; i++) {
    for(int j=-1; j<=1; j++) {
      if(i==0 && j==0) continue;
      if(x+i>=0 && x+i<n && y+j>=0 && y+j<n && a[x+i][y+j]=='*') {
	f = true;
      }
    }
  }
  if(!f) {
    for(int i=-1; i<=1; i++) {
      for(int j=-1; j<=1; j++) {
	if(i==0 && j==0) continue;
	if(x+i>=0 && x+i<n && y+j>=0 && y+j<n){
	  go(x+i,y+j);
	}
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int z=1; z<=t; z++) {
    cout<<"Case #"<<z<<": ";
    cin>>n;
    assert(n<=300);
    for(int i=0; i<n; i++) {
      cin>>a[i];
    }
    int res = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	v[i][j] = 0;
      }
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	bool f= false;
	for(int k=-1; k<=1; k++) {
	  for(int l=-1; l<=1; l++) {
	    if(i+k>=0 && i+k<n && j+l>=0 && j+l<n && a[i+k][j+l]=='*') f = true;
	  }
	}
	if((!f) && (!v[i][j])) {
	  go(i,j);
	  res++;
	}
      }
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
	if((!v[i][j]) && a[i][j]!='*') res++;
      }
    }
    cout<<res<<endl;
  }
    


  return 0;
}
  
