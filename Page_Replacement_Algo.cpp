#include<bits\stdc++.h>

using namespace std;

void FIFO(int* arr, int n, int page_frame){
vector<int> queue;
int page_fault = 0;
for(int i = 0; i<n; i++){
if(queue.size()==page_frame){
bool found = false;
for(int j=0; j<page_frame; j++){
if(queue[j]==arr[i]){
found = true;
break;
}
}
if(!found){
queue.erase(queue.begin());
queue.push_back(arr[i]);
page_fault++;
}
}
else{
queue.push_back(arr[i]);
page_fault++;
}
}
cout<<"Page fault in FIFO: "<<page_fault<<endl;
}

void Optimal_Page_Replacement(int* arr, int n){
vector<pair<int, int> > record;
int page_fault = 0;
for(int i=0; i<n; i++){
if(record.size()<3){
pair<int, int> val;
val.first = arr[i];
val.second = INT_MAX;
for(int j = i+1; j<n; j++){
if(arr[j]==arr[i]){
val.second = j;
break;
}
}
record.push_back(val);
page_fault++;
}
else{
bool found = false;
for(int j=0; j<3; j++){
if(record[j].first==arr[i]){
found = true;
record[j].second = i;
break;
}
}
if(!found){
pair<int, int> val;
val.first = arr[i];
val.second = INT_MAX;
for(int j = i+1; j<n; j++){
if(arr[j]==arr[i]){
val.second = j;
break;
}
}
int max = 0;
int max_index;
for(int j = 0; j<3; j++){
if(record[j].second>max){
max = record[j].second;
max_index = j;
}
}

record.erase(record.begin()+max_index);
record.push_back(val);
page_fault++;
}
}
}

cout<<"Page fault in Optimal Page Replacement: "<<page_fault<<endl;
}

void FIFO1(char* arr, int n, int page_frame){
vector<int> queue;
int page_fault = 0;
for(int i = 0; i<n; i++){
if(queue.size()==page_frame){
bool found = false;
for(int j=0; j<page_frame; j++){
if(queue[j]==arr[i]){
found = true;
break;
}
}
if(!found){
queue.erase(queue.begin());
queue.push_back(arr[i]);
page_fault++;
}
}
else{
queue.push_back(arr[i]);
page_fault++;
}
}
cout<<"Page fault in FIFO: "<<page_fault<<endl;
}

void most_recently_used(int* arr, int n){
vector<pair<int, int> > record;
int page_fault = 0;
for(int i = 0; i<n; i++){
if(record.size()<3){
pair<int, int> val;
val.first = arr[i];
val.second = i;
record.push_back(val);
page_fault++;
}
else{
bool found = false;
for(int j=0; j<3; j++){
if(record[j].first==arr[i]){
found = true;
record[j].second = i;
break;
}
}
if(!found){
pair<int, int> val;
val.first = arr[i];
val.second = i;
int max = 0;
int max_index;
for(int j = 0; j<3; j++){
if(record[j].second>max){
max = record[j].second;
max_index = j;
}
}

record.erase(record.begin()+max_index);
record.push_back(val);
page_fault++;
}
}
}
cout<<"Page fault in Most Recently Used: "<<page_fault<<endl;
}

void Least_Recently_used(int* arr, int n){
vector<pair<int, int> > record;
int page_fault = 0;
for(int i = 0; i<n; i++){
if(record.size()<3){
pair<int, int> val;
val.first = arr[i];
val.second = i;
record.push_back(val);
page_fault++;
}
else{
bool found = false;
for(int j=0; j<3; j++){
if(record[j].first==arr[i]){
found = true;
break;
}
}
if(!found){
pair<int, int> val;
val.first = arr[i];
val.second = i;
int min = i;
int min_index;
for(int j = 0; j<3; j++){
if(record[j].second<min){
min = record[j].second;
min_index = j;
}
}

record.erase(record.begin()+min_index);
record.push_back(val);
page_fault++;
}
}
}
cout<<"Page fault in Least Recently Used: "<<page_fault<<endl;
}

int main(){
int n;
cout<<"Enter the number of pages: ";
cin>>n;
int arr[n];
cout<<"Enter the pages: ";
for(int i=0; i<n; i++){
cin>>arr[i];
}
most_recently_used(arr, n);
Optimal_Page_Replacement(arr, n);
Least_Recently_used(arr, n);
int page_frame;
cout<<"Enter Page Frame: ";
cin>>page_frame;
FIFO(arr, n, page_frame);
cout<<"Enter Page Frame: ";
cin>>page_frame;
FIFO(arr, n, page_frame);

int m;
cout<<"Enter the number of pages: ";
cin>>m;
char cons[m];
cout<<"Enter the pages: ";
for(int i=0; i<m; i++){
cin>>cons[i];
}
cout<<"Enter Page Frame: ";
cin>>page_frame;
FIFO1(cons, m, page_frame);
cout<<"Enter Page Frame: ";
cin>>page_frame;
FIFO1(cons, m, page_frame);

return 0;
}
