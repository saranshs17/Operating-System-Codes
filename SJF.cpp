#include<bits/stdc++.h>
using namespace std;  
bool cmp1(tuple<int,int,int> a,tuple<int,int,int> b){
    return (get<2>(a)==get<2>(b)?get<1>(a) < get<1>(b):(get<2>(a)<get<2>(b)));
}
bool cmp2(tuple<int,int,int> a,tuple<int,int,int> b){
    return get<0>(a) < get<0>(b);
}
int main(){
    int n;
    cout<<"Enter number of processes \n";
    cin>>n;
    vector<int> wt(n+1,0),tat(n+1,0);
    vector<tuple<int,int,int>> v(n+1,tuple<int,int,int>({0,0,0}));
    cout<<"Enter Arrival time for "<<n<<" processes\n";
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        get<0>(v[i])=i;
        get<1>(v[i])=x;
    }
    cout<<"Enter Burst time for "<<n<<" processes\n";
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        get<0>(v[i])=i;
        get<2>(v[i])=x;
    }
    sort(v.begin(),v.end(),cmp1);
    vector<int> ct(n+1,0);
    map<int,vector<int>>res;
    for(int i=1;i<=n;++i){
        if(ct[i-1]<get<1>(v[i])){
            ct[i]=get<1>(v[i])-ct[i-1];
        }
        ct[i]+=ct[i-1]+get<2>(v[i]);
        tat[i]=ct[i]-get<1>(v[i]);
        wt[i]=tat[i]-get<2>(v[i]);
        res[get<0>(v[i])].push_back(ct[i]);
        res[get<0>(v[i])].push_back(tat[i]);
        res[get<0>(v[i])].push_back(wt[i]);
    }
    sort(v.begin(),v.end(),cmp2);
    cout<<"P\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\n";
    for(int i=1;i<=n;++i){
        // In non-preemptive , Response Time = Waiting Time
        int process=get<0>(v[i]);
        cout<<process<<"\t"<<get<1>(v[i])<<"\t"<<get<2>(v[i])<<"\t"<<res[process][0]<<"\t"<<res[process][1]<<"\t"<<res[process][2]<<"\t"<<res[process][2]<<"\n";
    }
}
