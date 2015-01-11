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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef pair< int, ll > pil;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 90
#define MOD 1000000007


int main () {
  int t, cse=1;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    if (n == 0) {
      printf("Case #%d: 0 0\n",cse++);
      continue;
    }
    map<int,int> mymap;
    int tmp = n;
    int ind = 1;
    while (tmp != 0) {
      mymap[ind] = tmp%10;
      tmp /= 10;
      ind++;
    }
    ind--;
    map<int,int>::reverse_iterator i;
    map<int,int>::reverse_iterator j;
    map<int,int>::reverse_iterator k;
    
    int mia, mib, maa, mab;
    int minval,maxval;
    bool min_will_swap = false, max_will_swap = false;
    for (i = mymap.rbegin(); i != mymap.rend(); i++) {
      int val = i->second;
      minval = INT_MAX;
      mia = i->first;
      k = i;
      k++;
      for (j = k; j != mymap.rend(); j++) {
        int y = j->second;
        if (y < minval){
          minval = y;
          mib = j->first;
        }
      }
      if (minval == 0) {
        if (i == mymap.rbegin()) {
          continue;
        }
        else {
          min_will_swap = true;
          break;
        }
      }
      else if (minval < val) {
        min_will_swap = true;
        break;
      }
      else if (minval >= val) {
        continue;
      }
    }
    
    for (i = mymap.rbegin(); i != mymap.rend(); i++) {
      int val = i->second;
      maxval = INT_MIN;
      maa = i->first;
      k = i;
      k++;
      for (j = k; j != mymap.rend(); j++) {
        int y = j->second;
        if (y > maxval){
          maxval = y;
          mab = j->first;
        }
      }
      if (maxval == 0) {
        break;
      }
      else if (maxval <= val) {
        continue;
      }
      else if (maxval > val) {
        max_will_swap = true;
        break;
      }
    }

    // printf("Min %d %d %d\n",mia, mib, min_will_swap);
    // printf("Max %d %d %d\n",maa, mab, max_will_swap);
    // exit(0);

    ll minans = 0, maxans = 0;
    if (min_will_swap) {
      int x = mymap[mia];
      mymap[mia] = mymap[mib];
      mymap[mib] = x;
      for (i = mymap.rbegin(); i != mymap.rend(); i++) {
        minans += i->second;
        minans *= 10;
      }
      minans /= 10;
      x = mymap[mia];
      mymap[mia] = mymap[mib];
      mymap[mib] = x;
    }

    if (max_will_swap) {
      int x = mymap[maa];
      mymap[maa] = mymap[mab];
      mymap[mab] = x;
      for (i = mymap.rbegin(); i != mymap.rend(); i++) {
        maxans += i->second;
        maxans *= 10;
      }
      maxans /= 10;
    }

    printf("Case #%d: ",cse++);
    if (min_will_swap) printf("%lli ",minans);
    else printf("%d ",n);

    if (max_will_swap) printf("%lli\n",maxans);
    else printf("%d\n",n);
    k++;
  }
}