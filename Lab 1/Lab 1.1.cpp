
#include <iostream>

int processArray(double arr[], int l, double NewArr[], double min_rnd, double max_rnd)
{
    double interval = max_rnd - min_rnd;
    for (int i = 0; i < l; i++)
    {
        arr[i] = min_rnd + (double)(rand() % (int)(max_rnd - min_rnd));
        printf("%g ", arr[i]);
    }

    double min_elem = 0.0;

    for (int i = 0; i < l; i++)
    {
        if (min_elem == 0.0 || min_elem > arr[i])
        {
            min_elem = arr[i];
        }
    }
    printf("\nmin Item = %d\n", (int)min_elem);

    for (int i = 0; i < l; i++)
    {
        NewArr[i] = arr[i] - min_elem;
        printf("%g ", NewArr[i]);
    }
    printf("\n");


    bool Min = false;
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == min_elem)
        {
            Min = true;
        }
        if (Min)
        {
            arr[i] = min_elem;
        }
        printf("%g ", arr[i]);
    }


    return min_elem;
}

int main()
{
    double arr[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    double NewArr[15];
    processArray(arr, sizeof(arr) / sizeof(double), NewArr, 20.0, 100.0);
    return 0;
}


