#include <time.h>
#include <stdio.h>

int x = 0;
int seconds = 0;

vuser_init()
{   
    int x = atoi(lr_eval_string("{rand}"));
    return 0;
}

int functiontime (int digit){
        
    return (time(NULL)%(24*60) + digit);
    }
