#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#include <cstring>
#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <span>
#include <semaphore>
#include <version>
#endif

#if __cplusplus > 202002L
#include <spanstream>
#endif
using namespace std;

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define oo 1000111000
#define ooo 1000111000111000111
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
void build_test();
template <typename T> void minimize(T &a, T b){ if(a>b) a=b;}
template <typename T> void maximize(T &a, T b){ if(a<b) a=b;}
bool bit(ll a,int i) { return a>>i&1; }
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<plp,vector<plp>,greater<plp>> pq;

random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b)
{
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

// ************ End Setting ************
struct line{
    ll m,b;
    line(ll x=0,ll y=ooo)
    {
        m=x; b=y;
    }
    ll eval(ll x)
    {
        return m*x+b;
    }
};
const int N=555;
const int M=3001;
// =========> Declaring variables <=======
ll ans,n,a[N][N],mod=998244353;
// =========> <3 Han Han <3  <=======
ll poww(ll a,ll b)
{
    if(b==1) return a;
    ll p=poww(a,b/2);
    if(b&1) return p*p%mod*a%mod;
    return p*p%mod;
}
void elimination(int k)
{
    ll p=poww(a[k][k],mod-2);
    for(int i=k+1;i<=n;i++)
    {
        ll s=a[i][k];
        ans=(ans*p)%mod;
        for(int j=k;j<=n;j++)
        {
            a[i][j]=(a[i][j]*a[k][k]%mod-a[k][j]*s%mod+mod)%mod;
        }
    }
}
void ppp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
}
int main()
{
    FPTU;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    ans=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) if(a[i][i]<a[j][i])
        {
            swap(a[i],a[j]);
            ans*=-1;
        }
    if(ans==-1) ans+=mod;
    for(int i=1;i<=n;i++)
    {
        ans=(ans*a[i][i])%mod;
        if(ans==0) break;
        elimination(i);
        //ppp(); cout<<'\n';
    }

    cout<<ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}


// Gitchee gitchee goo means that I love you
/* Idea:

*/



