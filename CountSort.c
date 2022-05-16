#include <stdio.h>
#include <stdlib.h>

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
    int min, max;
    puts("Input min number");
    scanf_s("%d", &min);
    puts("Input max number");
    scanf_s("%d", &max);
    srand(time(0));
    for (int i = 0; i < n; i++)
        m[i] = rand() % (max - min + 1) + min;
}

int main() {
    int n, r;
    printf("Input the number of elements: ");
    scanf_s("%d", &n); //������ ���������� ���������
    puts("Your array - 0, rand array - other"); //�������� ���� ��� ������ ������
    scanf_s("%d", &r);
    int* m = (int*)malloc(n * sizeof(int)); //�������� ������
    if (r == 0) {
        printf("Input the elements\n");
        ScanArray(m, n); //������ ������
    }
    else RandArray(m, n); //�� ��� ������ ������

    puts("Unsorted Array");
    printArray(m, n); //����� ������������������ �������
    printf("\n");
    CountingSort(m, n); //���������
    printf("Sorted array\n");
    printArray(m, n); //����� �������������� �������
    free(m);
    //getch();
}