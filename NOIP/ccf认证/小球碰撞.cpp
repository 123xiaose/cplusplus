#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n, L, t;
    cin >> n >> L >> t;

    int arr[105];
    int temp[105];    //���ڴ洢arr������������н��
    int index[105];    //���ڴ������������ÿ����ԭ�����±�
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    //��С��λ�ý������򣬲���¼ÿ������ԭ���������±�
    sort(temp, temp + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] == temp[i])
                index[i] = j;
        }
    }

    //����ÿ��С�򾭹�tʱ����λ��
    //С��֮������ײ�����ǽ���λ�ü�����ԭ���ķ����ƶ�
    //ÿ��С��L���͸ı䷽�� �����˶�����0λ�þ͸ı䷽�� �����˶�
    int flag = 1;//flag=1,go right,flag=0,go left
    for (int i = 0; i < n; i++) {
        flag = 1;
        for (int j = 0; j < t; j++) {
            if (flag)
                arr[i]++;
            else arr[i]--;
            if (arr[i] == L) flag = 0;
            else if (arr[i] == 0) flag = 1;
        }
    }

    //�����ս����������
    sort(arr, arr + n);

    //����ÿ��С������λ�ò���ı�
    //��ˣ����������ս����ԭ����Ӧԭ��index[]�����е��±�,����temp[]����žͺ���
    for (int i = 0; i < n; i++) {
        temp[index[i]] = arr[i];
    }

    //������
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    return 0;
} 
