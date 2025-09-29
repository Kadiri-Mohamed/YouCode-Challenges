#include <stdio.h>
#include "headers.h"
int main()
{
    printf("\n----------------------------------------------------------------- \n");
    for (int i = 0; i < strlen(Title); i++) {
        printf("%c", Title[i]);
        fflush(stdout); 
        usleep(50000); 
    }
    printf("\n----------------------------------------------------------------- \n\n");
    
    main_menu();
    return 0;
}