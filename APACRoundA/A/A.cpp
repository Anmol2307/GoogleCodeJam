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

map<string, int> m;

void create () {
  m["1111011"] = 9;
  m["1111111"] = 8;
  m["1110000"] = 7;
  m["1011111"] = 6;
  m["1011011"] = 5;
  m["0110011"] = 4;
  m["1111001"] = 3;
  m["1101101"] = 2; 
  m["0110000"] = 1;
  m["1111110"] = 0;
}


int main () {
  int t, k = 1;
  create();
  inp(t);
  while (t--) {
    int n;
    inp(n);
    string arr[n];
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      arr[i] = str;
    }

    bitset<7> val(arr[0]);

    for (int i = 1; i < n; i++) {
      bitset<7> b(arr[i]);
      val |= b;
    }
    
    vector <int> damaged;
    for (int i = 0; i < 7; i++) {
      if (val[i] == 0) {
        damaged.push_back(i);
      }
    }

    vector <vector <int> > vec(10);
    for (int i = 0; i < min(n,10); i++) {
        bitset<7> tmp(arr[i]);

        if (m.find(arr[i]) != m.end()) {
          vec[i].push_back(m.find(arr[i])->second); 
        }
        for (int j = 0; j < damaged.size(); j++) {
          tmp.set(damaged[j]);
          if (m.find(tmp.to_string()) != m.end()) {
            vec[i].push_back(m.find(tmp.to_string())->second); 
          }
          tmp.set(damaged[j],0);
        }
    }
    
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < vec[i].size(); j++) {
        printf("%d ",vec[i][j]);
      }
      printf("\n");
    }
  }
}