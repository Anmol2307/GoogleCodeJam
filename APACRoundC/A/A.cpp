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
typedef unsigned long long llu;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

int dx[] = {1,-1,1,-1,1,-1,0,0};
int dy[] = {1,1,0,0,-1,-1,1,-1};

int mat[305][305];
int visited[305][305];
int n;

int recurse () {
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0 && visited[i][j] == 0) {
        // printf("F %d %d\n",i,j);
        ans++;
        visited[i][j] = 1;
        for (int k = 0; k < 8; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if (nx < n && nx >= 0 && ny < n && ny >= 0){
            if (mat[nx][ny] >= 0) {
              visited[nx][ny] = 1;
            }
          }
        }
      }
      else if (mat[i][j] == 0 && visited[i][j] == 1) {
        for (int k = 0; k < 8; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if (nx < n && nx >= 0 && ny < n && ny >= 0){
            if (mat[nx][ny] >= 0) {
              visited[nx][ny] = 1;
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] > 0 && visited[i][j] == 0) {
        ans++;
        // printf("S %d %d\n",i,j);
      }
    }
  }

  return ans;
}


int main () {
  int t, k = 1;
  inp(t);
  while (t--) {
    printf("Case #%d: ", k++);
  
    inp(n);

    vector <string> vec;
    memset(mat,-1,sizeof(mat));
    memset(visited,0,sizeof(visited));
    for (int i = 0; i < n; i++) {
      string str;
      // cin >> str;
      getline(cin,str);
      vec.push_back(str);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vec[i][j] == '.') {
          int count = 0;
          for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx < n && nx >= 0 && ny < n && ny >= 0 && vec[nx][ny] == '*') {
              count++;
            }
          }
          mat[i][j] = count;
        }
      }
    }

    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //      printf("%d ",mat[i][j]);
    //   }
    //   printf("\n");
    // }

    int ans = recurse();
    printf("%d\n",ans);
  }
}