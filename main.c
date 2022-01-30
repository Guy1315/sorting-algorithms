#include <stdio.h>
#include <conio.h>
#include <math.h>


void search(int *a, int size, int key)
{
    for(int i =0;i<size;i++)
        if(*a+i==key)
        {
            printf("the index which the key is in is %d",i);
            goto end;
        }
        printf("key was not found:<");
        end:;
}

int binarySearch(int *a, int size, int key)
{
    int mid;
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        mid = low +(high-low)/2;
        if (*(a+mid) == key)
            return mid;
        if (*(a+mid) < key)
            low = mid + 1;
        else
            high = mid -1;
    }
    return -1;
}

int RbinarySearch(int* a,int x, int left, int right)
 {
   if(left>right)
     return -1;
   int middle = (left+right)/2;
   if(a[middle]==x)
     return middle;

   if(x<a[middle])
     return RbinarySearch(a,x,left,middle-1);

   return RbinarySearch(a,x,middle+1,right);
 }

void bubblesort(int *a, int size)
{
    int temp;
    for (int i = 0; i < size-1; i++)
        for (int j = 0; j < size-i-1; j++)
            if (*(a+j) > *(a+j+1))
            {
                 temp=*(a+j+1);
                 *(a+j+1)=*(a+j);
                 *(a+j)=temp;
            }
}

void selectionSort(int *a, int size)
{
    int min,temp;
    for (int i = 0; i < size-1; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
          if (a[j] < a[min])
            min = j;
        temp=*(a+min);
        *(a+i)=*(a+min);
        *(a+i)=temp;
    }
}

void insertionSort(int a[], int n)
{
    int num,j;
    for (int i = 1; i < n; i++) {
        num = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > num) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = num;
    }
}

void mergeArrays(int *a, int *b, int *c)
{
    int i=0,j=0,k=0;
    while(i<(sizeof(a) / sizeof(int))&&j<(sizeof(b) / sizeof(int)))
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        if(a[i]>b[j])
        {
            c[k]=b[j];
            j++;
            k++;
        }
        if(a[i]==b[j])
        {
            c[k]=b[j];
            j++;
            i++;
            k++;
        }
    }
    if(i<(sizeof(a) / sizeof(int)))
    {
        while(i<(sizeof(a) / sizeof(int)))
        {
            c[k]=a[i];
            i++;
            k++;
        }
    }
    else
    {
        if((j<sizeof(b) / sizeof(int)))
        {
            while(j<(sizeof(b) / sizeof(int)))
            {
                c[k]=b[j];
                j++;
                k++;
            }
        }
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
  int a[] = {3, 4, 5, 6, 7};
  int result = RbinarySearch(a,3,0,5);
  if (result == -1)
    printf(" the key was not found");
  else
    printf("key was found in index %d", result);
  return 0;
}
