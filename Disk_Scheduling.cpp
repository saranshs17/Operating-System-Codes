#include<bits/stdc++.h>
using namespace std;

void fcfs(int n,int startCyl, int req[]){
cout<<"\n##########\tFCFS Scheduling Algorithm\t##########\n";
int cyl = startCyl;
int finishCount=0;
vector <int> order;
bool finished[n];
memset(finished, false, sizeof(finished));
for(int i=0; i<n; i++){
order.push_back(req[i]);
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

void sstf(int n,int startCyl,int req[]){
cout<<"\n##########\tSSTF Scheduling Algorithm\t##########\n";
int cyl = startCyl;
int finishCount=0;
vector <int> order;
bool finished[n];
memset(finished, false, sizeof(finished));
int nearIdx = 0;
while(finishCount<n){
nearIdx = -1;
for(int i=0; i<n; i++){
if(finished[i]) continue;
if(nearIdx==-1){
nearIdx = i;
continue;
}
if(abs(cyl - req[i]) < abs(cyl - req[nearIdx])) nearIdx = i;
}
finished[nearIdx] = true;
cyl = req[nearIdx];
order.push_back(req[nearIdx]);
finishCount++;
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

void scan(int n,int startCyl,int req[]){
cout<<"\n##########\tSCAN Scheduling Algorithm\t##########\n";
int cyl = startCyl;
int finishCount=0;
bool finished[n];
vector <int> order;
memset(finished, false, sizeof(finished));
int maxCylinder = 0;
for(int i=0; i<n; i++) maxCylinder = max(maxCylinder, req[i]);
priority_queue<int, vector<int>, greater<int>> minPQ;
priority_queue<int, vector<int>, less<int>> maxPQ;
int dir = 0;
while(finishCount<n){
for(int i=0; i<n; i++){
if(req[i]<=cyl && finished[i]==false){
finished[i] = true;
if(dir==0) maxPQ.push(req[i]);
else minPQ.push(req[i]);
}
}
if(dir==0){
while(!maxPQ.empty()){
int r = maxPQ.top();
maxPQ.pop();
finishCount++;
order.push_back(r);
}
}
else{
while(!minPQ.empty()){
int r = minPQ.top();
minPQ.pop();
finishCount++;
order.push_back(r);
}
}
cyl = maxCylinder;
dir = 1-dir;
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

void cscan(int n,int startCyl,int req[]){
cout<<"\n##########\tC-SCAN Scheduling Algorithm\t##########\n";
int cyl = startCyl;
bool finished[n];
int finishCount=0;
vector <int> order;
priority_queue<int, vector<int>, greater<int>> minPQ;
memset(finished, false, sizeof(finished));
while(finishCount<n){
for(int i=0; i<n; i++){
if(req[i]>=cyl && finished[i]==false){
finished[i] = true;
minPQ.push(req[i]);
}
}
while(!minPQ.empty()){
int r = minPQ.top();
minPQ.pop();
finishCount++;
order.push_back(r);
}
cyl = 0;
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

void look(int n,int startCyl,int req[]){
cout<<"\n##########\tLOOK Scheduling Algorithm\t##########\n";
int cyl = startCyl;
int finishCount=0;
vector <int> order;
bool finished[n];
memset(finished, false, sizeof(finished));
int dir = 0;
while(finishCount<n){
int idx = -1;
for(int i=0; i<n; i++){
if(finished[i]) continue;
if(dir==0){
if(req[i]<cyl && (idx==-1||req[i]>req[idx])) idx = i;
}
else{
if(req[i]>cyl && (idx==-1||req[i]<req[idx])) idx = i;
}
}
if(idx == -1){
dir = 1-dir;
continue;
}
finished[idx] = true;
cyl = req[idx];
order.push_back(req[idx]);
finishCount++;
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

void clook(int n,int startCyl,int req[]){
cout<<"\n##########\tC-LOOK Scheduling Algorithm\t##########\n";
int cyl = startCyl;
int finishCount=0;
vector <int> order;
bool finished[n];
memset(finished, false, sizeof(finished));
priority_queue<int, vector<int>, greater<int>> minPQ;
while(finishCount<n){
for(int i=0; i<n; i++){
if(req[i]>=cyl && finished[i]==false){
finished[i] = true;
minPQ.push(req[i]);
}
}
while(!minPQ.empty()){
int r = minPQ.top();
minPQ.pop();
finishCount++;
order.push_back(r);
}
cyl = 0;
}
cout<<"Order of servicing requests: ";
for(int i=0;i<n;i++) cout<<order[i]<<" ";
int seektime=0;
seektime+=abs(startCyl-order[0]);
for(int i=0;i<n-1;i++) seektime+=abs(order[i]-order[i+1]);
cout<<"\nSeek time = "<< seektime <<"\n";
}

int main(){
int startCyl,n;
cout<<"Enter number of disk requests:";
cin>>n;
int req[n];
cout<<"Enter disk request cylinders:";
for(int i=0;i<n;i++) cin>>req[i];
cout<<"Enter starting cylinder:";
cin>>startCyl;
fcfs(n,startCyl,req);
sstf(n,startCyl,req);
scan(n,startCyl,req);
cscan(n,startCyl,req);
look(n,startCyl,req);
clook(n,startCyl,req);
}
