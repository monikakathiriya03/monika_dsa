#include <stdio.h>
#include <stdlib.h>

void Merge(int a[], int l, int mid, int h)
{
    int b[50];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= h)
    {
        b[k++] = a[j++];
    }
    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

int Merge_sort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        Merge_sort(a, l, mid);
        Merge_sort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }
}

int main()
{
    int a[10], n = 10, i;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 99+1;
    }
    printf("UNSORTED ARRAY IS: \n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    Merge_sort(a, 0, n - 1);
    printf("\n SORTED ARRAY IS: \n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}