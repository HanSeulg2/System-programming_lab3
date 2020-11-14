#include "global.h"
#include "header.h"
#include<signal.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void init_sh(){
  sig_quit();
  sig_int();
  
  printf("20163294 한슬기 20163329 천정석 팀과제 Shell \n");
}

int getargs(char *cmd, char **argv){
  int carg = 0;

  while (*cmd){
    if(*cmd == ' ' || *cmd == '\t' || *cmd == '&') {
      *cmd++ = '\0';

      if (*cmd == '&') 
	BACKGROUND = 1;

    }
    else{
      argv[carg++] = cmd++;
      while(*cmd != '\0' && *cmd != ' ' && *cmd != '\t'){
	cmd++;

      }
    }
    
    if(strcmp("exit", argv[0]) == 0){      // exit과 일치할 경우, 프로그램 종료
      printf("\n\nShell 종료합니다.\n");
      exit(1);
    }
    
    if(strcmp("cd", argv[0]) == 0){
      change_directory(carg, argv);
    }

  }
  argv[carg] = NULL;
  return carg;
}


void run(){
  while(1){
    getcwd(pwd,BUF_SIZE);
    printf("%s$ ", pwd);
    gets(buf);
    carg = getargs(buf, argv);

    pid = fork();

    if (pid == 0){
      fileread_in(argv);
      filewrite_out(argv);
      file_append(argv);
      if(strcmp(argv[0],"cd"))
	if(!BACKGROUND){
	  if(execvp(argv[0], argv) == -1)
	    printf("%s: command not found\n",argv[0]);
	}else{
	  execvp(argv[0], argv);
	}
      exit(1);
    }
    else if(pid > 0){
      if(!BACKGROUND)
	pid = wait(&status);
    }
    else
      perror("fork failed error");
  }
}

void main(){
  init_sh();
  run();
}

