#include <stdio.h>

int main(int argc, char **argv)
{
	printf("demo remove:\n");

	int intRe = rename("12345678.txt", "87654321.txt");
	int intRm = remove("1234567890.txt");

	return 0;
}
