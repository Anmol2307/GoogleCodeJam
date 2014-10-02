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

int main () {
  int t, k = 1;
  inp(t);


  while (t--) {
    int n, l;
    inp(n); inp(l);

    vector <pair<int,int> > vec;

    for (int i = 0; i < l; i++) {
      int x; inp(x);
      vec.push_back(pair<int,int>(x,i));
    }

    sort(vec.begin(), vec.end());
   
    int start = 0;
    int end = l-1;

    while (start < end) {
      if (vec[start].first + vec[end].first == n) {
        if (vec[start].second > vec[end].second) swap(vec[start].second,vec[end].second);
        printf("Case #%d: %d %d\n",k,vec[start].second+1,vec[end].second+1);
        break;
      }
      else if (vec[start].first + vec[end].first < n) start++;
      else end--;
    }
    k++;
  }
}