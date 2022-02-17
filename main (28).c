#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t;
    scanf("%d", &t);
    for (int t1 = 0; t1 < t; t1++){
        int m, n;
        scanf("%d %d", &m, &n);
        m--;
        n--;
        int i, y[m], x[n];
        for (i = 0; i < m; i++){
            scanf("%d", &y[i]);
        }
        for (i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        qsort (y, m, sizeof(*y), comp);
        qsort (x, n, sizeof(*x), comp);
        long sum = 0;
        i = n - 1;
        int j = m - 1;
        long rseg = 1, cseg = 1;
        int p = 1000000007;
        while (j >= 0 && i >= 0){
            if (y[j] <= x[i]){
                sum += (x[i--] * rseg) % p;
                cseg++;
            } else {
                sum += (y[j--] * cseg) % p;
                rseg++;
            }
        }
        while (j >= 0) sum += (y[j--] * cseg) % p;
        while (i >= 0) sum += (x[i--] * rseg) % p;
        printf("%ld\n", sum % p);
    }
    return 0;
}