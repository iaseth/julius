#include <stdio.h>

#include "julius.h"

int main (int argc, char const *argv[]) {
	if (argc < 2) {
		printf("Too few args!\n");
	} else if (argc > 2) {
		printf("Too many args!\n");
	} else {
		printf("Exactly two args.\n");
	}
}
