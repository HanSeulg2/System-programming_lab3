/* exitprocess.c */ 
/* exit example */
#include <stdlib.h>
int main()
{
	int exit_status;
	printf("enter exit status: ");
	scanf("%d", &exit_status);
	exit(exit_status);
}

