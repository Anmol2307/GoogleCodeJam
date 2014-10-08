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
typedef pair<string, string> pss;
map<string, vector<string> > m;
map<string,int> color;

int main () {
  int t, k = 1;
  inp(t);

  while (t--) {
    int n; inp(n);
    m.clear();
    color.clear();
    string str1, str2;

    for (int i = 0; i < n; i++) {
      cin >> str1 >> str2;
      if (m.find(str1) != m.end()) m[str1].push_back(str2);
      else {
        vector<string> vec;
        vec.push_back(str2);
        m[str1] = vec;
      }

      if (m.find(str2) != m.end()) m[str2].push_back(str1);
      else {
        vector<string> vec;
        vec.push_back(str1);
        m[str2] = vec;
      }
    }
    map<string, vector<string> >::iterator it;

    // for (it = m.begin(); it != m.end(); it++) {
    //   printf("Node %s\n",it->first.c_str());
    //   vector <string> v = it->second;
    //   for (int i = 0; i < v.size(); i++) {
    //     printf("%s\n",v[i].c_str());
    //   }
    // }
    // exit(0);

    color[m.begin()->first] = 0;
    queue<string> Q;
    Q.push(m.begin()->first);
    bool flag = false;
    while (!Q.empty()) {
      string str = Q.front();
      Q.pop();
      vector <string> neigh = m[str];
      int sz = neigh.size();
      int c = color[str];
      for (int i = 0; i < sz; i++) {
        string s = neigh[i];
        if (color.find(s) == color.end()) {
          color[s] = 1 - c;
          Q.push(s);
        }
        else if (color[str] == color[s]) {
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
    if (flag) printf("Case #%d: No\n",k++);
    else  printf("Case #%d: Yes\n",k++);
  }
}