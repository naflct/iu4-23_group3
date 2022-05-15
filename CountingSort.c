#include <stdio.h>
#include <stdlib.h>

void CountingSort(int array[], int size) { //������ ��� ����� ������� ���������� ���������
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    int* count = (int*)malloc(max + 1 * sizeof(int)); 

    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[array[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int* out = (int*)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        out[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = out[i];
    free(out);
    //free(count); //� ������ ��� ��� ��������, �� �� ����� � ������� �� ������...
}

void printArray(int *m, int size) { //������� ���������� �������
    for (int i = 0; i < size; ++i)
        printf("%d ", m[i]);
}

void ScanArray(int *m, int n) { //������� ����� �������
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
    getch();
   }