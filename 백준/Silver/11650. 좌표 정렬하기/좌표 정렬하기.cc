#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PUSH(l, r) { top->lo = (l); top->hi = (r); ++top; }
#define POP(l, r) {l_prev = (l); r_prev = (r); --top; (l) = top->lo; (r) = top->hi;}
#define SWAP(x, y) {point _tmp; _tmp = *(x); *(x) = *(y); *(y) = _tmp;}
#define MAX_THRESH 4
typedef struct
{
    int x;
    int y;
} point;
typedef struct
{
    point *lo;
    point *hi;
} node;


point arr[100000];

void merge_sort(point* left, point* right);
int comp(const void* a, const void* b);


int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
    {
        scanf("%d %d", &((arr+i)->x), &((arr+i)->y));
    }

    merge_sort(arr, arr+N);

    for(int i = 0; i < N; ++i)
        printf("%d %d\n", (arr+i)->x, (arr+i)->y);
    
    return 0;
}

void merge_sort(point* left, point* right)
{
    point* tmp = (point*)malloc(sizeof(point) * (right-left));
    node stack[128]; // upper bound of 2 * log(tot_elements) is 2 * 64, since CHAR_BITS * sizeof(size_t) = 64.
    node* top = stack;
    point* l = left;
    point* r = right;
    point* mid;
    point* l_prev = l-1;
    point* r_prev = r;

    PUSH(NULL, NULL);

    while(top > stack)
    {
        if(r-l <= MAX_THRESH)
        {
            for(point* head = l; head < r; ++head)
            {
                point cmp = *head;
                point* ptr = head;
                for(point* cur = head + 1; cur < r; ++cur)
                {
                    if(comp(cur, &cmp) < 0)
                    {
                        cmp = *cur;
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
        point* ptr_l = l;
        point* ptr_r = mid;
        for(int i = 0; ptr_l < mid || ptr_r < r; ++i)
        {
            if((ptr_l < mid && comp(ptr_l, ptr_r) < 0) || ptr_r == r)
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
        memcpy(l, tmp, sizeof(point) * (r-l));


        POP(l, r);
    }
    free(tmp);
}

int comp(const void* a, const void* b)
{
    int x = ((point*)a)->x - ((point*)b)->x;
    int y = ((point*)a)->y - ((point*)b)->y;
    if(x)
        return x;
    return y;
}