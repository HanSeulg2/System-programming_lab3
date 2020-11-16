/* forkprocess.c */ 
/* fork example */ 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	pid_t pid; /* 부모에서 프로세스 식별번호 저장 */
	printf("Calling fork \n"); 
	pid = fork(); /* 새로운 프로세스 생성 */ 
	if (pid == 0) 
		printf("I'm the child process\n"); 
	else if (pid > 0) 
		printf("I'm the parent process\n"); 
	else 
	printf("fork failed\n"); 
} 
