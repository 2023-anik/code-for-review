#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1 || n==0){
        cout<<"Not Prime"<<endl;
        return 0;
    }
    int i=2;
    while(i<n){
        if(n%i==0){
            cout<<"Not Prime"<<endl;
            return 0;
        }
        i++;
    }
    cout<<"Prime"<<endl;
    return 0;
}