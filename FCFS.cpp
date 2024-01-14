#include<bits/stdc++.h>
using namespace std; 
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n;
    cout<<"Enter number of processes \n";
    cin>>n;
    vector<int> wt(n+1,0),tat(n+1,0);
    vector<pair<int,int>> v(n+1,pair<int,int>({0,0}));
    cout<<"Enter Arrival time for "<<n<<" processes\n";
    for(int i=1;i<=n;++i){
        cin>>v[i].first;
    }
    cout<<"Enter Burst time for "<<n<<" processes\n";
    for(int i=1;i<=n;++i){
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ct(n+1,0);
    for(int i=1;i<=n;++i){
        if(ct[i-1]<v[i].first){
            ct[i]=v[i].first-ct[i-1];
        }
        ct[i]+=ct[i-1]+v[i].second;
        tat[i]=ct[i]-v[i].first;
        wt[i]=tat[i]-v[i].second;
    }
    cout<<"P\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\n";
    for(int i=1;i<=n;++i){
        // In non-preemptive , Response Time = Waiting Time
        cout<<i<<"\t"<<v[i].first<<"\t"<<v[i].second<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<wt[i]<<"\n";
    }
}
