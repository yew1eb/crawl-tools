#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
struct node{
	string name;
	string place;
	int num;
}fruit[200];
bool cmp(node a,node b){
	if(a.place<b.place)
		return true;
	else if(a.place==b.place){
		if(a.name<b.name)
			return true;
	}
	return false;
}
int main(){
	int t,t1,n,i,j,flag;
	scanf("%d",&t);
	t1=t;
	while(t--){
		if(t!=t1-1)
			printf("\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			cin>>fruit[i].name>>fruit[i].place>>fruit[i].num;
		sort(fruit,fruit+n,cmp);
	flag=0;
	for(i=0;i<n;i++){		
		for(j=0;j<i;j++){
			if(fruit[i].name==fruit[j].name&&fruit[i].place==fruit[j].place){
				fruit[j].num+=fruit[i].num;
				flag++;break;
			}
		}
	}
	cout<<fruit[0].place<<endl;
	cout<<"   |----"<<fruit[0].name<<"("<<fruit[0].num<<")"<<endl;
	for(i=1;i<n;i++){
		if(fruit[i].name==fruit[i-1].name&&fruit[i].place==fruit[i-1].place)
			continue;
		if(fruit[i].place==fruit[i-1].place){
			cout<<"   |----"<<fruit[i].name<<"("<<fruit[i].num<<")"<<endl;
		}
		else{
			cout<<fruit[i].place<<endl;
			cout<<"   |----"<<fruit[i].name<<"("<<fruit[i].num<<")"<<endl;
		}
	}
	}
	return 0;
}