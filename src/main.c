#include <stdio.h>

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
			char ch;
			while ((ch = fgetc(fp)) != EOF) {
				printf("%c", ch);
			}
			printf("\n");
			fclose(fp);
		}
	}
}
