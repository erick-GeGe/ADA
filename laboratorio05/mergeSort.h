#include <iostream>
#include <math.h> 

void intercalar(int A[], int p, int q, int r)
{
    int B[r + 1];
    int i, j;
    for (i = p; i <= q; i++)
        B[i] = A[i];
    for (j = q + 1; j <= r; j++)
        B[r + q - j + 1] = A[j];
    i = p;
    j = r;
    for (size_t k = p; k <= r; k++)
    {
        if(B[i] <= B[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = B[j];
            j--;
        }
    }
}

void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) /2);
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r );
        intercalar(A, p , q, r);
    }
}
