#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;

	// print("%1s", "")
	// int j = printf("%x",NULL);
	i = ft_printf("%.15x", 15);
	printf("\n[[%d]]\n", i);
	j = printf("%.15x", 15);
	printf("\n[[%d]]\n", j);
}
- [OUTPUT] ft_printf("%5%")
- [OUTPUT] ft_printf("%-5%")
- [OUTPUT] ft_printf("%-05%")
- [OUTPUT] ft_printf("%23s", NULL)
- [OUTPUT] ft_printf("%7.5s", "yolo")
- [OUTPUT] ft_printf("%7.5s", "bombastic")
- [OUTPUT] ft_printf("%7.7s%7.7s", "hello", "world")
- [OUTPUT] ft_printf("%3.7s%7.7s", "hello", "world")
- [OUTPUT] ft_printf("%7.7s%3.7s", "hello", "world")
- [OUTPUT] ft_printf("%3.7s%3.7s", "hello", "world")
- [OUTPUT] ft_printf("%7.3s%7.7s", "hello", "world")
- [OUTPUT] ft_printf("%3.3s%7.7s", "hello", "world")
- [OUTPUT] ft_printf("%7.3s%3.7s", "hello", "world")
- [OUTPUT] ft_printf("%3.3s%3.7s", "hello", "world")
- [OUTPUT] ft_printf("%7.7s%7.3s", "hello", "world")
- [OUTPUT] ft_printf("%3.7s%7.3s", "hello", "world")
- [OUTPUT] ft_printf("%7.7s%3.3s", "hello", "world")
- [OUTPUT] ft_printf("%3.7s%3.3s", "hello", "world")
- [OUTPUT] ft_printf("%7.3s%7.3s", "hello", "world")
- [OUTPUT] ft_printf("%3.3s%7.3s", "hello", "world")
...


// int	main(void)
// {
// 	int	i;

// 	i = ft_strx(15, "0123456789abcdef");
// 	printf("\ni is :(((%d)))\n", i);
// }

// #include "libftprintf.h"

// int main()
// {
// 	int i = 0;
// 	char *str;

//
	//     i = ft_printf("|G`k+RS%% ,j%sX],x+;%u%xb)J|D(\%uW'o%x6d`Tq%u;%c)H*D <",
		// "R6Z=pfPgf&\"Q3hn\rDvB\v\\V8&2[V8+T&xO@~yM5]7tHxnJ6rt", -1243829183,
		// 1786622777,
// // -658210621, 1197034953, 225467647, 1599022758);
// 	// i = ft_printf("%-#15d",42);
// 	// printf("\n[[[%d]]]\n", i);
// 	// int j = printf("%015d",42);
// 	// int j = printf("%p", (void *)14);
// 	// printf("\n[[[%d]]]\n", j);
// 	int o = 1052;
// 	char *s;
// 	ft_printf("th %d %d %d %d %d\n", 5,8327887,23828,8682,83263);
// 	// ft_printf("my %d  %s\n", 5);
// 	// printf("\n%p\n", s);

// 	// char c = '\0';
// 	// i = ft_printf("");
// 	// int j = printf("");
// 	// i = write(1, &c, 1);
//
	//     int j = printf("|G`k+RS%% ,j%sX],x+;%u%xb)J|D(\%uW'o%x6d`Tq%u;%c)H*D <",
		// "R6Z=pfPgf&\"Q3hn\rDvB\v\\V8&2[V8+T&xO@~yM5]7tHxnJ6rt", -1243829183,
		// 1786622777,
// // -658210621, 1197034953, 225467647, 1599022758);
// 	// int j = printf("th printf : %d ",15);
// 	// ft_printf("%d",16);
// }
