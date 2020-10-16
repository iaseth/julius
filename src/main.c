#include <stdio.h>
#include <stdlib.h>

#include "julius.h"

int main (int argc, char const *argv[]) {
	if (argc < 2) {
		printf("Too few args!\n");
	} else if (argc > 2) {
		printf("Too many args!\n");
	} else {
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("File not found.\n");
		} else {
			long p1 = ftell(fp);
			fseek(fp, p1, SEEK_END);
			long p2 = ftell(fp);
			fseek(fp, p1, SEEK_SET);
			long size = 1 + p2 - p1;

			char *text = malloc(sizeof(char) * (size + 1));
			fread(text, sizeof(char), size, fp);
			text[size] = '\0';
			printf("%s\n", text);
			free(text);
			fclose(fp);
		}
	}
}
