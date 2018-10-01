#include <stdio.h>

void radixSort(int A[], int n);
int maximumDigits(int A[], int n);
void countingSort(int A[], int temp1[], int temp2[], int n);

//main Function
int main()
{
    int n;
    int *integers;
    int i;

    printf("Enter n \n");
    scanf(" %d", &n);

    integers = (int *)malloc(n*sizeof(int));

    printf(" \n");

    printf("Start entering the integers \n");

    // Takes the input integers
    for(i=0;i<n;i++)
    {
        printf("integers[%d]: ",i);
        scanf(" %d", &integers[i]);
    }

    radixSort(integers,n);

    printf("\n");

    printf("Sorted Array: \n");

    //Prints the sorted array
    for(i=0;i<n;i++)
    {
        printf("integers[%d]: %d \n",i,integers[i]);
    }

    return 0;
}

//Radix Sort in C
void radixSort(int A[], int n)
{
    int maxDigits;
    int *temp1; // Stores the digits excluding the ones sorted of each integer
    int *temp2; // Stores the current least significant digit
    int i;
    int j;

    temp1 = (int *)malloc(n*sizeof(int));
    temp2 = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        temp1[i] = A[i];
    }

    //Calculation of Maximum digits among all the integers in input array
    maxDigits = maximumDigits(A,n);


    for(i=0;i<maxDigits;i++)
    {
        for(j=0;j<n;j++)
        {
            temp2[j] = temp1[j]%10;
            temp1[j] = temp1[j]/10;

        }

        //countingSort applied from least significant digits
        countingSort(A,temp1,temp2,n);
    }
}

//calculates the maximum digits from all the integers of input array
int maximumDigits(int A[], int n)
{
    int maxDigits = 0;
    int i;
    int temp;
    int digits;

    for(i=0;i<n;i++)
    {
        temp = A[i];
        digits =0;

        while(temp!=0)
        {
            digits++;
            temp = temp/10;
        }

        if(digits>maxDigits)
        {
            maxDigits = digits;
        }

    }

    return maxDigits;

}

//our linear time sorting Algorithm - Counting Sort applied in C
void countingSort(int A[], int temp1[], int temp2[], int n)
{
    int i;
    int j;
    int *B;
    int *B1;
    int C[10];

    B = (int *)malloc(n*sizeof(int));
    B1 = (int *)malloc(n*sizeof(int));

    for(j=0;j<10;j++)
    {
        C[j]=0;
    }

    for(i=0;i<n;i++)
    {
        C[temp2[i]] = C[temp2[i]]+1;
    }

    for(j=1;j<10;j++)
    {
        C[j] = C[j] + C[j-1];
    }

    for(i=n-1;i>=0;i--)
    {
        B[C[temp2[i]]-1] = A[i];
        B1[C[temp2[i]]-1] = temp1[i];
        C[temp2[i]] = C[temp2[i]] -1;
    }

    for(i=0;i<n;i++)
    {
        A[i] = B[i];
        temp1[i] = B1[i];
    }

    free(B);
    free(B1);
}
