#include "libftprintf.h"

int main()
{
    int i = 0;
    i = ft_printf("my printf : %x","aymane");
    printf("\n[[[%d]]]\n", i);
    int j = printf("th printf : %x","aymane");
    printf("\n[[[%d]]]\n", j);
    // int j = printf("th printf : %d ",15);
    // ft_printf("%d",16);
}
