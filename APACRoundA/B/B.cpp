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

int n;
int mat[1001][1001];
int ans[1001][1001];
  
    
void print (string dir) {
  int st, en;
  if (dir == "right") {
    st = 0; en = n-1;
    for (int i = 0; i < n; i++) {
      int index = n-1;
      for (int j = n-1; j >= 0;) {
        int val = mat[i][j];
        while (j > 0 && mat[i][j-1] == 0) {
          j--;
        }
        if (val != 0) {
          if (j > 0 && mat[i][j-1] == val) {
            ans[i][index] = val*2;
            j-=2;
          }
          else {
            ans[i][index] = val;
            j--;
          }
          index--;
        }
        else j--;
        // printf("HERE %d\n",j);
      }
      for (int j = 0; j < index; j++) {
        ans[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ",ans[i][j]);
      }
      printf("\n");
    }
  }
  else if (dir == "left") {
    st = 0; en = 0;
    for (int i = 0; i < n; i++) {
      int index = 0;
      for (int j = 0; j < n;) {
        int val = mat[i][j];
        while (j < n-1 && mat[i][j+1] == 0) {
          j++;
        }
        if (val != 0) {
          if (j < n-1 && mat[i][j+1] == val) {
            ans[i][index] = val*2;
            j+=2;
          }
          else {
            ans[i][index] = val;
            j++;
          }
          index++;
        }
        else j++;
        // printf("HERE %d\n",j);
      }
      for (int j = index; j < n; j++) {
        ans[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ",ans[i][j]);
      }
      printf("\n");
    }
  }
  else if (dir == "up") {
    st = 0; en = 0;
    for (int j = 0; j < n; j++) {
      int index = 0;
      for (int i = 0; i < n;) {
        int val = mat[i][j];
        while (i < n-1 && mat[i+1][j] == 0) {
          i++;
        }
        if (val != 0) {
          if (i < n-1 && mat[i+1][j] == val) {
            ans[index][j] = val*2;
            i+=2;
          }
          else {
            ans[index][j] = val;
            i++;
          }
          index++;
        }
        else i++;
        // printf("HERE %d\n",j);
      }
      for (int i = index; i < n; i++) {
        ans[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ",ans[i][j]);
      }
      printf("\n");
    }
  }
  else if (dir == "down") {
    st = n-1; en = 0;
    for (int j = 0; j < n; j++) {
      int index = n-1;
      for (int i = n-1; i >= 0;) {
        int val = mat[i][j];
        while (i > 0 && mat[i-1][j] == 0) {
          i--;
        }
        if (val != 0) {
          if (i > 0 && mat[i-1][j] == val) {
            ans[index][j] = val*2;
            i-=2;
          }
          else {
            ans[index][j] = val;
            i--;
          }
          index--;
        }
        else i--;
        // printf("HERE %d\n",j);
      }
      for (int i = 0; i < index; i++) {
        ans[i][j] = 0;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ",ans[i][j]);
      }
      printf("\n");
    }
  }
}


int main () {
  
  int t, k = 1;
  inp(t);

  while (t--) {
    inp(n);
    string dir;
    cin >> dir;
    memset(ans,0,sizeof(ans));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        inp(mat[i][j]);
      }
    }
    printf("Case #%d:\n",k);
    print(dir);
    k++;
  }  
}

