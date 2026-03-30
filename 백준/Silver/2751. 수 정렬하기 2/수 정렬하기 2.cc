#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PUSH(l, r) { top->lo = (l); top->hi = (r); ++top; }
#define POP(l, r) {l_prev = (l); r_prev = (r); --top; (l) = top->lo; (r) = top->hi;}
#define SWAP(x, y) {int _tmp; _tmp = *(x); *(x) = *(y); *(y) = _tmp;}
#define MAX_THRESH 4
typedef struct
{
    int *lo;
    int *hi;
} node;
int arr[1000000];
int tmp[1000000];

void merge_sort(int* left, int* right);


int main(void)
{
    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", arr+i);

    merge_sort(arr, arr+N);

    for(int i = 0; i < N; ++i)
        printf("%d\n", arr[i]);
    
    return 0;
}

void merge_sort(int* left, int* right)
{
    node stack[128];
    node* top = stack;
    int* l = left;
    int* r = right;
    int* mid;
    int* l_prev = l-1;
    int* r_prev = r;

    PUSH(NULL, NULL);

    while(top > stack)
    {
        if(r-l <= MAX_THRESH)
        {
            for(int* head = l; head < r; ++head)
            {
                int min = *head;
                int* ptr = head;
                for(int* cur = head + 1; cur < r; ++cur)
                {
                    if(*cur < min)
                    {
                        min = *cur;
                        ptr = cur;
                    }
                }
                SWAP(head, ptr);
            }
            POP(l, r);
            continue;
        }
        if(l_prev < l || r < r_prev)
        {
            mid = l + (r - l) / 2;
            PUSH(l, r);
            PUSH(l, mid);
            PUSH(mid, r);
            l_prev = l;
            l = mid;
            continue;
        }
        mid = r_prev;
        int* ptr_l = l;
        int* ptr_r = mid;
        for(int i = 0; ptr_l < mid || ptr_r < r; ++i)
        {
            if((ptr_l < mid && *ptr_l < *ptr_r) || ptr_r == r)
            {
                tmp[i] = *ptr_l;
                ++ptr_l;
            }
            else
            {
                tmp[i] = *ptr_r;
                ++ptr_r;
            }
        }
        memcpy(l, tmp, sizeof(int) * (r-l));


        POP(l, r);
    }
}