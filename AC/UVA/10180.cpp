#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

int arr[MAXN];

int pointers[MAXN];

int N;

bool cmp(int a, int b){
	return arr[a-1]<arr[b-1];
}

long tree[MAXN];

void update(int index,int delta){
	while(index<=N){
		tree[index-1]+=delta;
		index+=index&(-index);
	}
}

int sum(int index){
	int ret = 0;
	while(index>0){
		ret+=tree[index-1];
		index-=index&(-index);
	}
	return ret;
}


int main(){


	while(1){
		cin>>N;

		if(N<1)
			break;

		for(int i=0;i<N;i++){
			pointers[i]=i+1;
			tree[i]=0;
			cin>>arr[i];
		}

		sort(pointers,pointers+N,cmp);

		long ret = 0;

		for(int i=0;i<N;i++){
			ret+=sum(N)-sum(pointers[i]);
//			cout<<" "<<ret<<endl;
			update(pointers[i],1);
		}

		cout<<ret<<endl;

	}
	return 0;
}
