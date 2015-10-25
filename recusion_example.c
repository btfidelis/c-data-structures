#include<stdio.h>
#include<stdlib.h>

sum_vector(int vec[], int n)
{
    if (n < 0) {
        return 0;
    } else {
        return vec[n] + sum_vector(vec, n - 1);
    }
}


int main()
{
    int vec[] = {2, 4, 5, 5};

    printf("Sum = %d", sum_vector(vec, 3));

}
