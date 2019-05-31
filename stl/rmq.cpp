#include<bits/stdc++.h>

using namespace std;
typedef long long LL;


#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)

void err() { cerr << "\033[39;0m" << endl; }

template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v: a) cerr << v << ' ';
    err(x...);
}

template<typename T, typename... A>
void err(T a, A... x) {
    cerr << a << ' ';
    err(x...);
}

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}

const int M = 10;

struct RMQ {
    int f[22][M];

    inline int highbit(int x) { return 31 - __builtin_clz(x); }

    void init(int *v, int n) {
        FOR (i, 0, n) f[0][i] = v[i];
        FOR (x, 1, highbit(n) + 1)FOR (i, 0, n - (1 << x) + 1)f[x][i] = min(f[x - 1][i], f[x - 1][i + (1 << (x - 1))]);
    }

    int get_min(int l, int r) {
        assert(l <= r);
        int t = highbit(r - l + 1);
        return min(f[t][l], f[t][r - (1 << t) + 1]);
    }
} rmq;

int main() {
    int a[10];
    FOR(i, 0, 10)a[i] = rand() % 10;
    FOR(i, 0, 10)cout << a[i] << " ";
    cout << endl;
    rmq.init(a, 10);
    while (1) {
        int l(read<int>()), r(read<int>());
        if (cin.fail())break;
        cout << rmq.get_min(l, r) << endl;
    }
    return 0;
}
/**
 * RMQ����
?RMQ��Range Minimum/Maximum Query������������ֵ��ѯ�����ڳ���Ϊn������arr���ش�����ѯ��Q(i,j)����������arr���±���i,j֮������/Сֵ�����ֻ��һ��ѯ�ʣ���һ��for�Ϳ��Ը㶨����������ж��ѯ�ʾ��޷��ںܿ��ʱ�䴦�������

ST�㷨
?ST�㷨��һ�������㷨����������O(nlogn)ʱ���ڽ���Ԥ����Ȼ����O(1)��ʱ���ڻش�ÿ����ѯ���������ڵ�����Ϊarr[] = {1,3,6,7,4,2,5,9}���㷨�������£�

һ��Ԥ�����Դ���������СֵΪ����
?dpi��ʾ�ӵ�iλ��ʼ����2^j^������Ҳ���ǵ�i+2^j^-1���е���Сֵ������dp2��ʾ�ӵ�2������ʼ������2��������Сֵ����3,6֮�����Сֵ����dp2=3����dp����ĺ������Ǿ�֪����dpi=arr[i]���±���Ǵ�1��ʼ������ֵ���ˣ�ʣ�µľ���״̬ת�Ʒ��̡����Ȱ�dpiƽ���ֳ����Σ���Ϊһ����ż�������֣�����i��i+2^j-1^-1Ϊһ�Σ�i+2^j-1^��i+2^j^-1Ϊһ�Σ�ÿ�γ��ȶ�Ϊ2^j-1^��������i=1,j=3ʱ����1,3,6,7��4,2,5,9�����Ρ�dpi�������������ֵ�����ֵ�����ǵõ���״̬ת�Ʒ���ʽdpi = max(dpi,dpi+2^j-1^)

for(int i = 1;i <= n;i++)
    dp[i][0] = arr[i];
for(int j = 1;(1 << j) <= n;j++)
    for(int i = 1;i + (1 << j) - 1 <= n;i++)
        dp[i][j] = Math.min(dp[i][j-1],dp[i + (1<<(j - 1))][j-1]);
������ѯ
?����������Ҫ��ѯ����[L,R]�е���Сֵ����k=log~2~(R-L+1)��������[L,R]����Сֵres=min(dpL,dpR-(1<<k)+1)��Ϊʲô�����Ϳ��Ա�֤������ֵ��dpLά������[L,L+2^k^-1]��dpL[k]ά������[R-2^k^+1,R]�����ֻҪ֤��R-2^k^+1 �� l+2^k^-1���ɣ�����֤��ʡ��

int k = (int) (Math.log(r - l + 1) / Math.log(2));
int min = Math.min(dp_min[l][k],dp_min[r - (1 << k) + 1][k]);
�ٸ�����
?L=4,R=6����ʱk=log~2~(R-L+1)=log~2~3=1������RMQ(4,6)=min(dp4,dp5)=min(4,2)=2�������׿�����������ȷ��
 */
