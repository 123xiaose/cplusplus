#include<bits/stdc++.h>

using namespace std;

#define LL long long

char str[2020][2020];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", str[i]);
        int cnt = 0, flag = 1;
        //srand(time(0)); //�������͹����ˣ�orz
        while (cnt < 10000000) { //���һǧ��������
            int a = rand() % n;
            int b = rand() % n;
            int c = rand() % n;  //%nȷ�����ݷ�Χ��0��n
            cnt++;
            if (str[a][b] == 'Q' && str[b][c] == 'Q' && str[a][c] != 'Q') {
                flag = 0;
                break;
            }
            if (str[a][b] == 'P' && str[b][c] == 'P' && str[a][c] != 'P') {
                flag = 0;
                break;
            }
        }
        if (flag) printf("T\n");
        else printf("N\n");
    }
}