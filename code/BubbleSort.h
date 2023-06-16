#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

template<typename T>
void sort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                T temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}
#endif