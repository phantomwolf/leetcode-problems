#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int reverse(int x)
{
    int rev = 0;
    while(x != 0){
        if ((rev > 0 && INT_MAX/10 < rev) ||
            (rev < 0 && INT_MIN/10 > rev))
            return 0;
        rev = rev*10 + x%10;
        x /= 10;
    }
    return rev;
}


int main(int argc, char* argv[])
{
    int x = 1000000003;
    printf("%d\n", reverse(x));
    return 0;
}
