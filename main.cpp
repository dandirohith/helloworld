#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector < int > VI;
typedef vector < VI > VVI;
typedef pair < int , int > PII;

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define SZ(x) x.size()
#define SET(a , b) memset(a , b , sizeof(a))
#define REP(i, n) for(int i = 0 ; i < n ; i++)
#define FOR(i, a, b) for(int i = a ; i <= b ; i++)
#define FORD(i, a, b) for(int i = a ; i >= b ; i--)
#define BOOST ios_base::sync_with_stdio(0);
#define TCSOLVE() int tests; cin >> tests; REP(i, tests) solve();
# define INF 0x3f3f3f3f

const int N = 2e5 + 5, M = 2e5 + 5, mx = 1e9, LN = 20, mod = 1e9 + 7;

int n,m;
vector < PII > v[N];
void prims(){
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

    int src = 0;
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    int cost = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        int temp = pq.top().first;
        pq.pop();
        if(inMST[u] == true){
            continue;
        }

        inMST[u] = true;
        cost+=temp;
        for (auto x : v[u])
        {
            int node = x.first;
            int weight = x.second;
            if (inMST[node] == false && key[node] > weight){
                key[node] = weight;
                pq.push(make_pair(key[node], node));
                parent[node] = u;
            }
        }
    }
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", parent[i], i);
    cout<<"Cost: "<<cost<<"\n";
}

int main()
{
    cin >> n >> m;
    FOR(i,0,m-1){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].PB({y,z});
        v[y].PB({x,z});
    }
    prims();
    return 0;
}
