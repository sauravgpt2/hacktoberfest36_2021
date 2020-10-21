#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    if(p1.second<p2.second){
        return true;
    }
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,count=1;
        cin>>n;
        int a[n],b[n];
        pair<int,int>p[n];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            p[i] = make_pair(a[i], b[i]); 
        }
        sort(p,p+n,compare);
        int i=0;
        for(int j=1;j<n;j++){
            if(p[j].first>=p[i].second){
                count++;
                i=j;
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}
