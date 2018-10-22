/***********************************************************
https://blog.csdn.net/starstar1992/article/details/54913261/
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int str[1000001], ptr[1000001], l, r, cnt = 0, x = -1;

void cal_next(int *str, int *next, int len2)
{
    int k = -1, q;
    next[0] = -1;

    for(q = 1; q < len2; q++)
    {
        while(k > -1 && str[k + 1] != str[q])
        {
            k = next[k];
        }

        if(str[k + 1] == str[q])
        {
            k++;
        }

        next[q] = k;
    }
}

int KMP(int *ptr, int len1, int *str, int len2)
{
    int k = -1, i;
    int *next = new int [len2];
    cal_next(str, next, len2);

    for(i = 0; i < len1; i++)
    {
        while(k > -1 && ptr[i] != str[k + 1])
        {
            k = next[k];
        }

        if(str[k + 1] == ptr[i])
        {
            k++;
        }

        if(k == len2 - 1)
        {
            cnt++;
            x = i - len2 + 1;
        }
    }

    return -2;
}

int main(void)
{
    int m, n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &str[i]);
    }
    KMP(ptr, n, str, m);
    if(x != -1 && cnt == 1)
    {
        printf("%d %d\n", x + 1, x + m);
    }

    else
    {
        printf("-1\n");
    }
    return 0;
}
