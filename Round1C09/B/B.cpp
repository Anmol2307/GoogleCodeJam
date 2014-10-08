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
    printf("Case #%d: ",k++);
    int n;
    inp(n);

    double xc = 0, yc = 0, zc = 0, vxc = 0, vyc = 0, vzc = 0;
    for (int i = 0; i < n; i++) {
      double x1, y1, z1, vx1, vy1, vz1;  
      scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &vx1, &vy1, &vz1);
      xc += x1;
      yc += y1;
      zc += z1;

      vxc += vx1;
      vyc += vy1;
      vzc += vz1;
    }
    xc /= n; yc /= n; zc /= n;
    vxc /= n; vyc /= n; vzc /= n;

    double ti = -(xc*vxc + yc*vyc + zc*vzc);
    double denom = vxc*vxc + vyc*vyc+ vzc*vzc;
    if (denom != 0 && ti > 0) ti /= denom;
    else ti = 0.00000000;
    double dist;
    if (denom != 0 && ti >= 0) dist = sqrt((xc + vxc*ti)*(xc + vxc*ti) + (yc + vyc*ti)*(yc + vyc*ti) + (zc + vzc*ti)*(zc + vzc*ti));
    else dist = sqrt(xc*xc + yc*yc + zc*zc);
    printf("%.8lf %.8lf\n",dist,ti);
  }
}