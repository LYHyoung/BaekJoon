#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n, num, min = 1000001, max = -1000001;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    printf("%d %d", min, max);

    return 0;
}