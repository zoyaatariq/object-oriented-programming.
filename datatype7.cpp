/* 6. Convert 2D int array to float/double and do matrix multiplication */
#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n][n], b[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>b[i][j];

    float f[n][n]={0};
    double d[n][n]={0};

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                f[i][j]+= (float)a[i][k]*b[k][j];
                d[i][j]+= (double)a[i][k]*b[k][j];
            }

    for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<f[i][j]<<" "; cout<<endl; }
    cout<<endl;
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<d[i][j]<<" "; cout<<endl; }
}
