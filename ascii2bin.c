#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp) {
	
	
	
	
	int retval;
	char ascii_value=0;
	char digit=0;
	char offset = 0x30;
	int number=0;
	
    retval = read(0, &ascii_value, 1);
    while (retval == 1){
		
		if(ascii_value == offset || ascii_value == offset-1) {
			digit = ascii_value - offset;
			number = (number << 1) + digit;  
			retval = read(0, &ascii_value, 1);
			}
		else {
			retval = 0;
			}
	}

    printf("%u\n", number);
	return 0;
	}
