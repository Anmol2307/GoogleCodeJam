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
map<char,pair<int,int> > m;

void pre() {
  int i, j;
  for (i = 0, j = 2; i < 25; i+=3, j++) {
    m[(char)(i+97)].first = j;
    m[(char)(i+97)].second = 1;
    m[(char)(i+98)].first = j;
    m[(char)(i+98)].second = 2;
    m[(char)(i+99)].first = j;
    m[(char)(i+99)].second = 3;
    
    if (j == 7) {
      m[(char)(i+100)].first = j;
      m[(char)(i+100)].second = 4;
      i++;
    }
  }
  m[(char)(25+97)].first = 9;
  m[(char)(25+97)].second = 4;
  
  m[(char)(32)].first = 0;
  m[(char)(32)].second = 1;

  
  // map<char,pair<int,int> >::iterator it;
  // for (it = m.begin(); it != m.end(); it++) {
  //   printf("%c %d %d\n",it->first, (it->second).first, (it->second).second);
  // }
}

string decode (string str) {
  int sz = str.size();
  string ret = "";
  for (int j = 0; j < m[str[0]].second; j++){
    // printf("%c\n",(char)(m[str[0]].first + 48));
    ret += (char)(m[str[0]].first + 48);
    // printf("%s\n",ret.c_str());
  }

  for (int i = 1; i < sz; i++) {
    if (m[str[i]].first == m[str[i-1]].first) {
      ret += ' ';
      for (int j = 0; j < m[str[i]].second; j++){
        ret += ((char)(m[str[i]].first + 48));
      }
    }
    else {
      for (int j = 0; j < m[str[i]].second; j++){
        ret += ((char)(m[str[i]].first + 48));
      }
    }
  }
  return ret;
}


int main () {
  pre();
  int t, k = 1;
  inp(t);
  vector <string> vec;
  while (t--) {
    vec.clear();
    string line, str;
    getline(cin,line);
    stringstream S(line);
    while (S >> str) {
      vec.push_back(str);
    }
    string ans = "";
    ans = decode(line);
    // for (int i = 0; i < vec.size(); i++) {
    //   ans += decode(vec[i]);
    // }
    printf("Case #%d: ",k);
    printf("%s\n",ans.c_str());
    k++;
  }
}
