#include<bits/stdc++.h>
using namespace std;
void wait(int &x){
	if(x>0) x--;
}
void signal(int &x){
	x++;
}
int main(){
	int n;
	cout<<"Enter Buffer size\n";
	cin>>n;
	int a[n];
	int full=0,empty=n;
	int mutex=1;
	while(1){
	int c;
	cout<<"Enter 1. Producer 2.consumer\n";
	cin>>c;
	if(c==1){
		if(empty!=0 && mutex==1){
			wait(empty);
			wait(mutex);
			cout<<"Enter data to be produced\n";
			cin>>a[full];
			signal(mutex);
			signal(full);
		}
		else{
			cout<<"Buffer is full\n";
		}
	}
	else if(c==2){
		if(full!=0 && mutex==1){
			wait(full);
			wait(mutex);
			cout<<"Item consumed is : "<<a[full]<<'\n';
			signal(mutex);
			signal(empty);
		}
		else{
			cout<<"Buffer is empty\n";
		}
	}
	else{
		cout<<"Exited!!\n";
		break;
	}
	}
}
