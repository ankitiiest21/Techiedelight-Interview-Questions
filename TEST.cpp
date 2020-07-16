#include<iostream>
#include<bits/stdc++.h> 
#include<string>
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define IN insert
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define NL cout<<endl
#define ll long long int
#define ld long double
#define vl vector<ll>
#define sl set<ll>
#define ml map<ll,ll>
#define sc set<char>
#define li list<ll>
#define vp vector<pair<ll, ll> >
#define vs vector<string>
#define ss set<string>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define REPIT(it,a) for(auto it=a.begin();it!=a.end();it++)
#define DB(x) cout<<"Debug "<<x<<endl
#define N (ll)10000
#define mod (ll)1000000007
using namespace std;
ll findIndexToGetMaxLength(ll a[],ll n){
	int prev=0,curr=0,maxi=INT_MIN;
	REP(i,0,n){
	 if(a[i]==0){
	  curr=i;
	  if(max(maxi,curr-prev)==curr-prev){
	  	maxi=curr-prev;
	  	prev=i;
	  }
	 }
	}
	return prev;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n; cin>>n; ll a[n]; REP(i,0,n) cin>>a[i];
    cout<<findIndexToGetMaxLength(a,n)<<endl;
}