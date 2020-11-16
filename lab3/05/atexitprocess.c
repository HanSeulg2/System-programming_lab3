/* atexitprocess.c */ 
/* atexit example */
#include <stdlib.h>
void exitfunc1(void);
void exitfunc2(void);
int main()
{
	atexit(exitfunc1);
	atexit(exitfunc2);
	printf("This is main function.\n");
}
void exitfunc1(void)
{
	printf("This is exit function 1.\n");
}
void exitfunc2(void)
{
	printf("This is exit function 2.\n");
}

