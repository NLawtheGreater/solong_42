#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "libft.h"
#include "ft_printf.h"


/*int	main()
{
	void *ptr;
	int	b;
	char *ptrs[20];
	int	i;

	b = 23;
	ptr = "\0";
	ptr = &b;
	i = 0;
	while (ptr + i)
	{
		*(ptrs + i)  = (ptr + i);
		i++;
	}
	puts (*ptrs);
}*/
//0x5645a5e5c004

/*int	main()
{
	int *ptr;
	int	b;

	b = 1;
	ptr = &b;
	printf("%p\n", ptr);
}*/
//23 = 0x7fffa61879bc
//1 = 0x7ffe3931ceec

/*int main()
{
	int *ptr;
	int	b;
	//int i;

	b = 23;
	ptr = &b;
	//i = 0;
	//while (ptr + i)
	//{
	//puts (ptr);
	//	i++;
	//}	
}*/
//1 = 0x1
//23 = 0x17
int main()
{
	ft_printf("ft: %k \n");
	printf("original: %k \n");
/*	
	printf("u: %u", 999999999999999999999999);
	printf("d+: %d", 999999999999999999999999);
	printf("d-: %d", -999999999999999999999999);
	printf("i+: %i", 999999999999999999999999);
	printf("i-: %i", -999999999999999999999999);
	ft_printf("u: %u", 999999999999999999999999);
	ft_printf("d+: %d", 999999999999999999999999);
	ft_printf("d-: %d", -999999999999999999999999);
	ft_printf("i+: %i", 999999999999999999999999);
	ft_printf("i-: %i", -999999999999999999999999);

	printf("%s", "abc");
	printf("111%s333", "222");
	printf("%s333", "222");
	printf("111%s", "222");
	printf("{%s}", 0);
	printf("{%s}", "");
 //abc111222333222333111222{(null)}{}
	ft_printf("%s", "abc");
	ft_printf("111%s333", "222");
	ft_printf("%s333", "222");
	ft_printf("111%s", "222");
	ft_printf("{%s}", 0);
	ft_printf("{%s}", "");
//abc111222333222333111222{(null)}{}

	printf("111%s333%s555", "222", "444");
	printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
//111222333444555111222333444555666aaabbbccc12345
	ft_printf("111%s333%s555", "222", "444");
	ft_printf("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb");
	ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");


	printf("%d", 42);
	printf("%d", -42);
	printf("before %d after", 42);
	printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	printf("a%db%dc%dd", 1, -2, 3);
	printf("%d", INT_MAX);
	printf("%d", INT_MIN);
	ft_putstr_fd("\n", 1);
//42-42before 42 after1-23-45a1b-2c3d2147483647-2147483648	
	ft_printf("%d", 42);
	ft_printf("%d", -42);
	ft_printf("before %d after", 42);
	ft_printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	ft_printf("a%db%dc%dd", 1, -2, 3);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	//42-42before 42 after1-23-45a1b-2c3d2147483647-2147483648
	ft_putstr_fd("\n", 1);	
*/
/*	int i;
	unsigned long l;
	char *str;

	printf("%p", &i);
	printf("%p", &l);
	printf("%p", &str);
	printf("%p", &strlen);
	printf("%p", 0);
	//0x7ffd022664640x7ffd022664680x7ffd022664700x7f90dee126d00x0
	ft_printf("%p", &i);
	ft_printf("%p", &l);
	ft_printf("%p", &str);
	ft_printf("%p", &strlen);
	ft_printf("%p", 0);
	//0x7ffd022664640x7ffd022664680x7ffd022664700x7f90dee126d0(nil)

	printf("%%");
	printf("aa%%bb");
	printf("%%%%%%%%%%");
	printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("%");
//%aa%bb%%%%%.%.%.%.%.%.%.%.%.	
	ft_printf("%%");
	ft_printf("aa%%bb");
	ft_printf("%%%%%%%%%%");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	ft_printf("%");
	write(1, "\n", 1);
 //%aa%bb%%%%%.%.%.%.%.%.%.%.%.	

	printf("s: %s, p: %p, d:%d", "a string", &main, 42);
	printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
//s: a string, p: 0x5564daba01a9, d:42
//a0x7f3928f476d0120x7f3928f470e0b0x7f3928f476d00x7f3928f470e0c	
	ft_printf("s: %s, p: %p, d:%d", "a string", &main, 42);
	ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
//s: a string, p: 0x5564daba01a9, d:42
//a0x7f3928f476d0120x7f3928f470e0b0x7f3928f476d00x7f3928f470e0c

	printf("%i", 42);
	printf("%i", -42);
	printf("before %i after", 42);
	printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	printf("a%ib%ic%id", 1, -2, 3);
	42-42before 42 after1-23-45a1b-2c3d
	ft_printf("%i", 42);
	ft_printf("%i", -42);
	ft_printf("before %i after", 42);
	ft_printf("%i%i%i%i%i", 1, -2, 3, -4, 5);
	ft_printf("a%ib%ic%id", 1, -2, 3);
	42-42before 42 after1-23-45a1b-2c3d

	printf("%u", 42);
	printf("before %u after", 42);
	printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	printf("a%ub%uc%ud", 0, 55555, 100000);
	printf("%u", UINT_MAX);
//42before 42 after110099942999988888a0b55555c100000d4294967295
	ft_printf("%u", 42);
	ft_printf("before %u after", 42);
	ft_printf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	ft_printf("a%ub%uc%ud", 0, 55555, 100000);
	ft_printf("%u", UINT_MAX);
//42before 42 after110099942999988888a0b55555c100000d4294967295

	printf("%x", 42);
	printf("before %x after", 42);
	printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	printf("a%xb%xc%xd", 0, 55555, 100000);
	printf("%x, %x", 0, UINT_MAX);
//2abefore 2a after1643e72a3b9a9e98a0bd903c186a0d0, ffffffff
	ft_printf("%x", 42);
	ft_printf("before %x after", 42);
	ft_printf("%x%x%x%x%x", 1, 100, 999, 42, 999988888);
	ft_printf("a%xb%xc%xd", 0, 55555, 100000);
	ft_printf("%x, %x", 0, UINT_MAX);
//2abefore 2a after1643e72a3b9a9e98a0bd903c186a0d0, ffffffff

	printf("%X", 42);
	printf("before %X after", 42);
	printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	printf("%X, %X", 0, UINT_MAX);
//2Abefore 2A after1643E72A3B9A9E98a0bD903c186A0d0, FFFFFFFF
	ft_printf("%X", 42);
	ft_printf("before %X after", 42);
	ft_printf("%X%X%X%X%X", 1, 100, 999, 42, 999988888);
	ft_printf("a%Xb%Xc%Xd", 0, 55555, 100000);
	ft_printf("%X, %X", 0, UINT_MAX);
//2Abefore 2A after1643E72A3B9A9E98a0bD903c186A0d0, FFFFFFFF

	printf("%c", 'c');
	printf("%c%c", '4', '2');
	 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\ 
	 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\ 
	 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
	 	   	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', 
	 	   	'/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', 
	 	   	'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
	 	   	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
	 	   	']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	printf("%c", 0);
//c42 !"#$%&'()*+,-./0123                 456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ                 [\]^_`abcdefghijklmnopqrstuvwxyz{|
	write(1, "\n", 1);	
	ft_printf("%c", 'c');
	ft_printf("%c%c", '4', '2');
	 ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
	 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
	 	   	%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
	 	   	' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', 
	 	   	'/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', 
	 	   	'>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
	 	   	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
	 	   	']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');
	ft_printf("%c", 0);
//c42 !"#$%&'()*+,-./0123                 456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ                 [\]^_`abcdefghijklmnopqrstuvwxyz{|
	write(1, "\n", 1);	

	printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
//bonjour  42 0x7fa0d5de46d0 % 2a	
	ft_printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
//bonjour  42 0x7fa0d5de46d0 % 2a	
*/
	return (0);
}