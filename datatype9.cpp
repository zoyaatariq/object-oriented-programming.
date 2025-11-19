/* 8. Mean, median, mode, SD, variance without library functions */
#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    double a[n],sum=0;
    for(int i=0;i<n;i++){ cin>>a[i]; sum+=a[i]; }
    double mean=sum/n;

    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[j]<a[i]){ double t=a[i]; a[i]=a[j]; a[j]=t; }
    double median = (n%2)? a[n/2] : (a[n/2]+a[n/2-1])/2;

    int maxf=0; double mode=a[0];
    for(int i=0;i<n;i++){
        int f=1;
        for(int j=i+1;j<n;j++) if(a[j]==a[i]) f++;
        if(f>maxf){maxf=f; mode=a[i];}
    }

    double var=0;
    for(int i=0;i<n;i++) var += (a[i]-mean)*(a[i]-mean);
    var/=n;
    double sd=0, tmp=var, low=0, high=var;
    while(high-low>1e-12){
        double mid=(low+high)/2;
        if(mid*mid > var) high=mid;
        else low=mid;
    }
    sd=high;

    cout<<mean<<" "<<median<<" "<<mode<<" "<<sd<<" "<<var;
}
