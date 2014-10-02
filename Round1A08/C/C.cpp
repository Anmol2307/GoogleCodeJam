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

#define rep(i,b) for(int i=0;i<b;i++)
typedef long long int lli;
typedef vector <int> vi;
typedef pair<int,int> pii;
typedef vector <pii> vpii;
typedef vector <vector <lli> > matrix;
#define MOD 1000


matrix I;


matrix multiply(matrix A, matrix B)
{
    matrix C(2,vector<lli>(2));
    C[0][0] = ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
    C[0][1] = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
    C[1][0] = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
    C[1][1] = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
    return C;
}

//find N'th power of matrix T 
matrix mpow(matrix T, lli N)
{
    if (N== 0) return I;
    if(N==1)return T;
    matrix ret=mpow(T,N/2);
    matrix ret1=multiply(ret,ret);
    // printf("N %lli \n",N);
    // for (int i = 0; i < ret1.size(); i++) {
    //   for (int j = 0; j < ret1[i].size(); j++) {
    //     printf("%lli ",ret1[i][j]);
    //   }
    //   printf("\n");
    // }
    if(N%2==0)return ret1;
    else return multiply(ret1,T);
}



int main () {
  int t, k = 1;
  inp(t);
  
  matrix A;
  vector <lli> row1;
  vector <lli> row2;

  row1.push_back(6);row1.push_back(-4); 
  row2.push_back(1);row2.push_back(0);
  
  A.push_back(row1);A.push_back(row2);

  I.resize(2);

  for (int i = 0; i < 2; i++) {
    I[i].resize(2);
    I[i][i] = 1;
  }


  while (t--) {
    lli n;
    scanf("%lli", &n);
    if (n == 0) {
      printf("1\n");
      continue;
    }

    matrix ans = mpow(A,n-1);
    lli ret = (ans[0][0]*6 + ans[0][1]*2)%MOD;
    if (ret < 0) ret += MOD;
    printf("Case #%d: ",k);
    if (ret - 1 < 10) {
      printf("00");
      printf("%lli\n",ret-1);
    }
    else if (ret - 1 < 100) {
      printf("0");
      printf("%lli\n",ret-1);
    }
    else {
      printf("%lli\n",ret-1);
    }
    k++;
  }
}