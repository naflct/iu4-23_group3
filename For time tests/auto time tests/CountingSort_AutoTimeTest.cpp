#include <stdio.h>
#include <stdlib.h>
#include<iostream> //�++
#include<chrono> //�++

void CountingSort(int* m, int n) { //������� ���������� (������� 2)
    int max = m[0];
    for (int i = 1; i < n; i++)
        if (m[i] > max)
            max = m[i];
    int* c = (int*)malloc((max + 1) * sizeof(*m));
    memset(c, 0, sizeof(*m) * (max + 1));

    for (int i = 0; i < n; ++i) {
        ++c[m[i]];
    }

    int b = 0;
    for (int i = 0; i < max + 1; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            m[b++] = i;
        }
    }

    free(c);
}

void printArray(int* m, int size) { //������� ���������� �������
    for (int i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

void ScanArray(int* m, int n) { //������� ����� �������
    for (int i = 0; i < n; ++i)
        scanf_s("%d", &m[i]);
}

void RandArray(int* m, int n) { //������� ����� ��������� ����� �������
    int min, max, fl1 = 0, fl2 = 0, ch = 0;
    min = 1;
    max = 10000000;
    srand(time(0));
    m[0] = rand() % (max - min + 1) + min;
    for (int i = 1; i < n; i++)
    {
        fl2 = 0;
        while (fl2 == 0)
        {
            ch = rand() % (max - min + 1) + min;
            for (int j = 0; j < i; j++)
                if (m[j] == ch)
                    fl1++;
            if (fl1 == 0)
            {
                m[i] = ch;
                fl2 = 1;
            }
            fl1 = 0;
        };
    };
}

int main() {
    int n, r, x = 100;
    while (x <= 100000)
    {
        n = x;
        std::cout << x << " ";
        r = 1;
        int* m = (int*)malloc(n * sizeof(int)); //�������� ������
        if (r == 0) {
            printf("Input the elements\n");
        }
        else RandArray(m, n); //�� ��� ������ ������

        auto begin = std::chrono::steady_clock::now(); //������ �������� ������� ���������� ����� (�++)
        CountingSort(m, n); //���������
        auto end = std::chrono::steady_clock::now(); //�++
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //�++
        std::cout << elapsed_ms.count() << "\n"; //����� ��������
        free(m);
        x += 100;
        //getch();
    }
}