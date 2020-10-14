#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i)
		t[i] = t[i<<1] + t[i<<1|1];
}

/*	this code of modify and query are for modifying
	values in ihe interval [l,r) and query return
	value at particular index
void modify(int l, int r, int value) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)
			t[l++] += value;
		if (r&1)
			t[--r] += value;
	}
}

int query(int p) {
	int res = 0;
	for (p += n; p > 0; p >>= 1)
		res += t[p];
	return res;
}

	If at some point after modifications we 
	need to inspect all the elements in the 
	array, we can push all the modifications
	to the leaves using the following code.
void push() {
	for (int i = 1; i < n; ++i) {
		t[i<<1] += t[i];
		t[i<<1|1] += t[i];
		t[i] = 0;
	}
}

*/

/*	this code of modify and query are for modifying
	value at particular index and query return
	sum of all values in range [l,r)
void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		`t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)
			res += t[l++];
		if (r&1)
			res += t[--r];
	}
	return res;
}*/
 
void solve()
{
	cin>>n;
	int i;
	for (i = 0; i < n; ++i)
		scanf("%d", t + n + i);
	build();
	modify(0,1,1);
	for(i=0;i<2*n;i++)
		cout<<t[i]<<" ";
	cout<<endl;
	cout<<query(3,11)<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}