// До рефакторинґу: незрозумілі імена, «магічні числа», без дужок
int chk(int t) { return t > 85 ? 2 : t > 70; }

int f(int*a,int n){int s=0,i;
for(i=0;i<n;i++)if(a[i]>0)s+=a[i];return s;}
