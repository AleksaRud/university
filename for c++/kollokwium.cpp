
#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 2;
    (a, b) = 3;
    cout << a<<" "<<b<<endl;
    b = 6; int c = 4;
    a = b+c++;
    cout<<a<<endl;
    int n=2, m=3, z;
    z=(m++,m+n);
    cout<<z<<endl;
    n=2; m=3;
    z = n^n + m&n;
    cout<<z<<endl;
    int k, d=5;
    a=2; b=4;c=3;
    k=(a>b)?(b>c?10:100):(d<c?a:b);
    cout<<k<<endl;

    int count = 0;
    while (true)
    {
        count++; if(count>10)break;
    }
    cout<<"counter:"<<count<<endl;
    int c_[]={0,2,4,5,7};
    cout<<c_<<(c_+3)<<endl;
    for(int *x =c_+3; x>=c_;(--x)--)
        cout<<*x;
    cout<<endl;
    int K = 12345, M;
    M = K/10000 * 100 + K%1000 / 100 * 10 + K%10;
    cout<< K << "  " << M << endl;

    int A,R;
    cin>>A>>R;
    if (A >= 2*R) cout<<"true"<<endl;
    else cout << "false"<<endl;
    int N, p=1;
    cin>>N;
    for (int i=1; i<=N; i++)
        if ((i%3!=0)&&(i%7==0))
        p=p*i;
    cout<<p<<endl;
    int M_, X=2;
    double p1=1.0,p2,S=0.0;
    cin>>M_;
    for(float n = 1.0; n<=M_; n++)
    {
        p1=-p1*X;
        p2= n+1.0;
        S=S+p1/p2;
    }
    cout<<S;
}
