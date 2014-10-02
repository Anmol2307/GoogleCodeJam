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
  vector <string> vec;
  while (t--) {
    vec.clear();
    string line;
    getline(cin,line);
    stringstream S(line);
    string str;
    while (S >> str) {
      vec.push_back(str);
    }
    reverse(vec.begin(), vec.end());
    printf("Case #%d: ",k);
    for (int i = 0; i < vec.size(); i++) {
      printf("%s ",vec[i].c_str());
    }
    printf("\n");
    k++;
  }
}