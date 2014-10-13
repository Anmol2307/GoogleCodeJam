#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}
typedef long long int lli;
typedef pair<lli,lli> pii;

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    printf("Case #%d: ",k++);
    int b;
    inp(b);
    vector <pii> vec;
    vector<lli> dist;
    
    for (int i = 0; i < b; i++) {
      lli x1, y1, x2, y2;
      scanf("%lli %lli %lli %lli", &x1, &y1, &x2, &y2);
      lli x = (x1+x2)/2;
      lli y = (y1+y2)/2;
      vec.push_back(pii(x,y));
      lli val  = 0;
      for (lli j = x1; j <= x2; j++) {
        for (lli k = y1; k <= y2; k++) {
          val += abs(x-j) + abs(y-k);
        }
      }
      dist.push_back(val);
    }

    int sz = vec.size();
    int mind = sz + 1;
    lli minv = 1000000000000000;
    for (int i = 0; i < sz; i++) {
      for (int j = i+1; j < sz; j++) {
        dist[j] += abs(vec[j].first - vec[i].first) + abs(vec[j].second - vec[i].second);
        dist[i] += abs(vec[j].first - vec[i].first) + abs(vec[j].second - vec[i].second);
      }
      if (dist[i] < minv) {
        mind = i;
        minv = dist[i];
      }
    }

    printf("%lli %lli %lli\n",vec[mind].first,vec[mind].second,dist[mind]);
  }
}