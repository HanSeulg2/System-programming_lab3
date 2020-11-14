#include "header.h"

void change_directory(int carg, char *argv[]){
  if(carg > 2){
    printf("입력 인자를 초과하였습니다.\n");
  }
  if(carg == 2){
    if(chdir(argv[1]) == 0);
    else perror(NULL);
  }
}


