#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[], char ** envp) {
	
	
	
	
	int retval;
	char ascii_value=0;
	char digit=0;
	char offset = 0x30;
	int number=0;
	int error = 1;
	
	
    retval = read(0, &ascii_value, 1);
    while (retval == 1 && ascii_value !='\n') {
		
		if(ascii_value == offset || ascii_value == 0x31) {
			digit = ascii_value - offset;
			number = (number << 1) + digit;  
			retval = read(0, &ascii_value, 1);
			}
		else {
			printf("%u\n", error);
			return 1;
			}
	}

    printf("%u\n", number);
	return 0;
	}
