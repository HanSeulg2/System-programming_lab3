/* writeshm.c */
/* shared memory example */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#define SHMSIZE 1024
#define SHMKEY (key_t)0111
int main()
{
	int shmid, len;
	void *shmaddr;
	if ((shmid = shmget(SHMKEY,SHMSIZE,IPC_CREAT|0666)) == -1) {
		perror ("shmget failed");
		exit (1);
	}
	if ((shmaddr = shmat(shmid, NULL, 0)) ==(void *)-1) {
		perror ("shmat failed");
		exit (1);
	}
	strcpy((char *)shmaddr, "Hello, world");
	if (shmdt(shmaddr) == -1) {
		perror ("shmdt failed");
		exit (1);
	}
}
