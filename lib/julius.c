#include "julius.h"

#include <stdio.h>

void parse_json (char *text) {
	char ch;
	char quote;
	char quoted_text[100];
	int quoted_text_index = 0;
	int inside_quote = 0;

	int index = 0;
	while (text[index] != '\0') {
		ch = text[index];
		if (inside_quote) {
			if (ch == quote) {
				quoted_text[quoted_text_index] = '\0';
				inside_quote = 0;
				printf("Quoted text: '%s'\n", quoted_text);
			} else {
				quoted_text[quoted_text_index++] = ch;
			}
		} else if (ch == '"' || ch == '\'') {
			inside_quote = 1;
			quoted_text[0] = '\0';
			quoted_text_index = 0;
			quote = ch;
		}

		//printf("%c", ch);
		index++;
	}
	printf("\n");
}


