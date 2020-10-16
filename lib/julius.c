#include "julius.h"

#include <stdio.h>

void parse_json (char *text) {
	char ch;
	int index = 0;
	while (text[index] != '\0') {
		ch = text[index];
		printf("%c", ch);
		index++;
	}
	printf("\n");
}


