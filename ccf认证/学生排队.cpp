#include<iostream>
#include<cmath>

using namespace std;

void operate(int num, int adjust, int queue[]) {
    int k = 0;
    while (queue[k] != num) k++;//�ҵ�Ҫ����������λ��k
    if (adjust < 0)//��ǰ����
    {
        for (int i = k; i > k + adjust; i--) {
            queuw[i] = queue[i - 1];
        }
        queue[k + adjust] = num;
    } else//������
    {

    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int queue[1005];
    int adjust[2];

    for (int i = 1; i < n + 1; i++) {
        queue[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> adjust[0] >> adjust[1];
        operate(adjust[0], adjust[1], queue);
    }

    for (int i = 1; i < n + 1; i++)
        cout << queue[i] << " ";

    return 0;
} 
