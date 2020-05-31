#include <stdio.h>
#include <stdlib.h>

#define N 9

int search(int array[], int startAt, int finishAt, int valueToFind)
{
    int position = (startAt + finishAt) / 2;

    // printf("position index: %d\n", position);
    // printf("position value: %d\n", array[position]);  
    
    if(startAt > finishAt)
        return -1;

    if (valueToFind < array[position])
        return search(array, startAt, position-1, valueToFind);
    else if (valueToFind > array[position])
        return search(array, position+1, finishAt, valueToFind);    
    else
        return position;
}

void main()
{
    int array[N];

    for (int i = 0; i < N; i++)
    {
        array[i] = i + 1;
    }    

    for (int i = 0; i < N; i++)
    {
        int position = search(array, 0, N-1, i+1);
        printf("position: %d\n", position);
    }  

    int position = search(array, 0, N-1, 20);

    printf("position: %d\n", position);
}