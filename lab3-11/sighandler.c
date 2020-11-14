#include "header.h"
#include <signal.h>
void handler_int(int signo){
    printf("\nSIGINT: Ctrl-C,  Interrupt from\n");
    pid_t ppid = getppid();  //호출의 부모 프로세스 아이디를 반환
    kill(ppid, SIGINT);
}

void handler_quit(int signo){
    printf("\nSIGQUIT: Ctrl-Z, Quit from");
    pid_t ppid = getppid(); //호출의 부모 프로세스 아이디를 반환
    kill(ppid, SIGQUIT);
}

void sig_int(){
    struct sigaction sig_int;

    // signal int
    sig_int.sa_handler = handler_int; 
    sigfillset(&(sig_int.sa_mask)); 
    sigaction(SIGINT, &sig_int, NULL);// sigInt
}

void sig_quit(){
    struct sigaction sig_quit;

    // signal quit
    sig_quit.sa_handler = handler_quit;
    sigfillset(&(sig_quit.sa_mask));
    sigaction(SIGTSTP, &sig_quit, NULL);
}

