#include <bits/stdc++.h>
using namespace std;
struct dataset
{
    float x[10],y;
}m[20];

int main ()
{
    int n,ob,y; float w[20],s[20],a;
    cout<<"How many attribute : "; cin>>n; cout<<"\nAlpha : "; cin>>a; cout<<"\nHow many object in data set : "; cin>>ob;
    for(int i=0;i<=n;i++) {
        cout<<"\nInput w"<<i<<" : "; cin>>w[i];
    }

    for(int i=0;i<ob;i++){
        cout<<"\nm"<<i<<": \n";
        for(int j=0;j<=n;j++){
            if(j==0){
                m[i].x[j]=1;
            }
            else{
                cout<<"x"<<j<<"- "; cin>>m[i].x[j];
            }
        }
        cout<<"y- "; cin>>m[i].y;
    }
    for(int i=0;i<ob;i++){ cout<<"\nm"<<i+1<<":  ";
        for(int j=1;j<=n;j++){ cout<<"\tx"<<j<<": "<<m[i].x[j]<<"  "; } cout<<"\ty: "<<m[i].y; }

    int maxIter=100,iter=0;
    float y_bar,e=1;
    while (iter <= maxIter)
    {
        for(int j=0;j<=n;j++){
            s[j]=0;
        }
        for(int i=0;i<ob;i++)
        {
            y_bar=0;
            for(int j=0;j<=n;j++){
                y_bar = y_bar + (w[j]*m[i].x[j]);
            }
            e = y_bar - m[i].y;
            for(int j=0;j<=n;j++){
                s[j]=s[j]+(e*m[i].x[j]);
            }
        }
        for(int j=0;j<=n;j++){
            w[j] = w[j] - ( a*s[j] );
        }
        iter++;
    } cout<<"\n\n";
    for(int i=0;i<=n;i++){
        cout<<"\nNew w"<<i<<": "<<w[i];
    }

}
