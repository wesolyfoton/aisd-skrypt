#include <stdio.h>

void bitonic_compare(int* A, int n, bool up)
{
    for(int i = 0; i < n/2; i++)
        if ((A[i] > A[i+n/2]) == up)
        {
            int t = A[i];
            A[i] = A[i+n/2];
            A[i+n/2] = t;
        }
}

void bitonic_merge(int* A, int n, bool up)
{
    if (n > 1)
    {
        bitonic_compare(A,     n,   up);
        bitonic_merge  (A,     n/2, up);
        bitonic_merge  (A+n/2, n/2, up);
    }
}

void bitonic_sort(int* A, int n, bool up)
{
    if (n > 1)
    {
        bitonic_sort(A,     n/2, true);
        bitonic_sort(A+n/2, n/2, false);
        bitonic_merge(A, n, up);
    }
}

int main(void)
{
    int tab[] = {2, 8, 7, 1, 4, 3, 5, 6};
    
    bitonic_sort(tab, 8, true);
    
    for (int i = 0; i < 8; i++)
        printf("%d ", tab[i]);
    printf("\n");
    
    return 0;
}
