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

char board[10][10];

void resetBoard() {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      board[i][j] = 0;
    }
  }
}

void printBoard() {
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      printf("%c ",board[i][j]);
    }
    printf("\n");
  }
}


char str[5];
 
int main () {
  int t, k = 1;
  inp(t);
  int n, a, b;
  while (t--) {
    scanf("%d", &n);
    resetBoard();
    printf("Case #%d: ", k++);

    int count = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s",str);
      board[str[0] - 65 + 1][str[1] - 48] = str[3];
    }

    printBoard();
    exit(0);
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        if (board[i][j] == 0) continue;
        else {
          
          if (board[i][j] == 'K') {
            for (a = -1; a < 2; a++) {
              for (b = -1; b < 2; b++) {
                if (board[i + a][j + b] != 0) {
                  count++;
                }
              }
            }
            count--; // subtract king himself.
          }

          else if (board[i][j] == 'Q') {
            a = i - 1;
            while (a--) {
              if (board[a][j]) {
                count++;
                break;
              }
            } 
            a = i + 1;
            while (a < 9) {
              if (board[a][j]) {
                count++;
                break;
              }
              a++;
            } 
            b = j - 1;
            while (b--) {
              if (board[i][b]) {
                count++;
                break;
              }
            } 
            b = j + 1;
            while (b < 9) {
              if (board[i][b]) {
                count++;
                break;
              }
              b++;
            } 

            a = i - 1; b = j - 1;
            while (a-- && b--) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i - 1; b = j + 1;
            while (a-- && b++ < 9) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i + 1; b = j - 1;
            while (a++ < 9 && b--) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i + 1; b = j + 1;
            while (a++ < 9 && b++ < 9) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
          }

          else if (board[i][j] == 'R') {
            a = i - 1;
            while (a--) {
              if (board[a][j]) {
                count++;
                break;
              }
            } 
            a = i + 1;
            while (a < 9) {
              if (board[a][j]) {
                count++;
                break;
              }
              a++;
            } 
            b = j - 1;
            while (b--) {
              if (board[i][b]) {
                count++;
                break;
              }
            } 
            b = j + 1;
            while (b < 9) {
              if (board[i][b]) {
                count++;
                break;
              }
              b++;
            } 

          }

          else if (board[i][j] == 'B') {
            a = i - 1; b = j - 1;
            while (a-- && b--) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i - 1; b = j + 1;
            while (a-- && b++ < 9) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i + 1; b = j - 1;
            while (a++ < 9 && b--) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
            a = i + 1; b = j + 1;
            while (a++ < 9 && b++ < 9) {
              if (board[a][b]) {
                count++;
                break;
              }
            }
          }

          else if (board[i][j] == 'N') {
            a = i; b = j;
            if (i - 2 > 0) {
              if (board[i - 2][j + 1]) count++;
              if (board[i - 2][j - 1]) count++;
            } 
            if (i + 2 < 9) {
              if (board[i + 2][j + 1]) count++;
              if (board[i + 2][j - 1]) count++;
            } 
            if (j - 2 > 0) {
              if (board[i - 1][j - 2]) count++;
              if (board[i + 1][j - 2]) count++;
            } 
            if (j + 2 < 9) {
              if (board[i - 1][j + 2]) count++;
              if (board[i + 1][j + 2]) count++;
            } 
          }

          else if (board[i][j] == 'P') {
            if (board[i + 1][j - 1]) count++;
            if (board[i + 1][j + 1]) count++;
          }
        }
      }
    }
    printf("%d\n", count);
  }
}