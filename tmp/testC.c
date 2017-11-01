#include <stdio.h>

int main(int argc, char **argv)
{
	for(int i = 0; i < 25; i++){
		printf("Hello world!\n");
	}
	system("clear");

	for(int i = 0; i < 25; i++){
		printf("Clear world!\n");
	}

	system("clear");
	printf("Success!\n");

	return 0;
}
