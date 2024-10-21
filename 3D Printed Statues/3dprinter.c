// Problem name: 3D Printed Statues
// @author Kamal
// Method: Bit Manipulation and Binary Counting
// Status: Accepted
// Run-time: 0.00s

#include <stdio.h>

int bin_count(int n)
{
    int counter = 0;
    while(n--)
    {
        counter++;
        n >>= 1;
    }
    return counter;
}

int days(int n)
{
    return n < 4 ? n : n & (n - 1) ? bin_count(n<<1 + 1) : bin_count(n) + 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",days(n));
    return 0;
}