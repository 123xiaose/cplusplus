#include<iostream>
#include<list>
#include<cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    int left = n;
    int arr[1000];
    for (int j = 0; j <= 1000; j++)
        arr[j] = -1;
    int i = 0;
    while (left > 1) {
        i = i % n;
        while (arr[i] == 0)//�ҵ�Ӧ�ñ�����С����
        {
            i++;
            i = i % n;
        }
        cnt++;//����

        //cout<<"С����"<<i+1<<" ����"<<cnt<<endl;

        if (cnt >= k && cnt % k == 0 || cnt % 10 == k)//�ж��Ƿ����
        {
            arr[i] = 0;
            left--;
            //cout<<"С����"<<i+1<<"����"<<endl;
        }
        i++;//�ֵ���һ��С����
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
} 
