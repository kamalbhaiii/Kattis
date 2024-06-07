// Problem name: Alex and Barb
// Solved by: Kamal

#include <stdio.h>

int main() {
    int k,a,b;
    scanf("%d %d %d", &k, &a, &b);
    printf(k % (a+b) < a ? "Barb\n" : "Alex\n");
    return 0;
}