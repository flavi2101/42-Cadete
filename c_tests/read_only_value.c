#include <stdio.h>
void	modify(char	*copy_point)
{
	copy_point[0]= 'S';
}
int	main(void)
{
//declare a string of text like a pointer in this format mark it's a reda only data, so try modify get a segmentation error fault
	char	*phrase = "some random text";
//but provide a declaration using array the data is not set as read only, line showing in line 11.
	char	phrase2[]= "second rarndom test";
	modify(phrase);
	modify(phrase2);
	printf("%s", phrase);
// a curiosity is that a char *p="casa" can be interpreted as const char *p ="world", both will be store in the section .rodata

/* another important concept about this is that argv even been load in the stack( since main is also a function), this pointer of pointer is store in a read write memory\
so we don't have to worry about the sintax of **argv or *argv[] '*/
}
