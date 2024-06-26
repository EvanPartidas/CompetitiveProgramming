#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100005;
const int MAXK = 100005;
const int MAXA = 1000000005;

long long input[MAXN];

long long cost[MAXN];

long long N,K;

long long A;

int main(){
	int i;
	cin>>N>>K;

	for(i=0;i<N;i++)
		cin>>input[i];
	cin>>A;

	for(i=0;i<N;i++)
		cin>>cost[i];

	long long sum=0;

	priority_queue<long long,vector<long long>,greater<long long>> q;

	for(i=0;i<N;i++){
		q.push(cost[i]);
		while(K<input[i]){
			if(q.empty()){
				cout<<-1;
				return 0;
			}
			K+=A;
			sum+=q.top();
			q.pop();
		}
	}

	cout<<sum;
	return 0;
}
