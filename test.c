#include "libftprintf.h"

int main()
{
    int i = 0;
    char *str;

    i = ft_printf("|G`k+RS%% ,j%sX],x+;%u%xb)J|D(\%uW'o%x6d`Tq%u;%c)H*D <", "R6Z=pfPgf&\"Q3hn\rDvB\v\\V8&2[V8+T&xO@~yM5]7tHxnJ6rt", -1243829183, 1786622777,
-658210621, 1197034953, 225467647, 1599022758);



    // i = ft_printf("my printf : %p", (void *)-14523);
    printf("\n[[[%d]]]\n", i);
    // int j = printf("th printf : %p", (void *)-14523);
    int j = printf("|G`k+RS%% ,j%sX],x+;%u%xb)J|D(\%uW'o%x6d`Tq%u;%c)H*D <", "R6Z=pfPgf&\"Q3hn\rDvB\v\\V8&2[V8+T&xO@~yM5]7tHxnJ6rt", -1243829183, 1786622777,
-658210621, 1197034953, 225467647, 1599022758);
    printf("\n[[[%d]]]\n", j);
    // int j = printf("th printf : %d ",15);
    // ft_printf("%d",16);
}
