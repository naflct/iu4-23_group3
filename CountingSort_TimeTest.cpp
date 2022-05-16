#include <stdio.h>
#include <stdlib.h>
#include<iostream> //�++
#include<chrono> //�++
/*void CountingSort(int array[], int size) { //������ ��� ����� ������� ���������� ���������
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
} */

//m � ��������� �� ������ �������
 //n � ������ �������
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

/*void RandArray(int* m, int n) { //������� ����� ��������� ��������������� ����� �������
    int min, max, fl1 = 0, fl2 = 0, ch = 0;
    puts("Input min number");
    scanf_s("%d", &min);
    puts("Input max number");
    scanf_s("%d", &max);
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
} */

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
    auto begin = std::chrono::steady_clock::now(); //������ �������� ������� ���������� ����� (�++)
    CountingSort(m, n); //���������
    auto end = std::chrono::steady_clock::now(); //�++
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); //�++
    std::cout << "Time: " << elapsed_ms.count() << " nanoseconds\n"; //����� ��������
    printf("Sorted array\n");
    printArray(m, n); //����� �������������� �������
    free(m);
    //getch();
   }