#include "header.h"

void failederror(char *errlog){
    perror(errlog);
    exit(1);
}
