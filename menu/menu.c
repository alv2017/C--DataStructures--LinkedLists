#include <stdio.h>
#include <stdlib.h>

void display_menu(const char **menu) {
	int i = 0;

    printf("\n**************** MAIN MENU ****************\n");
    printf("\n");

    while ( menu[i] != NULL ) {
    	printf("    %s\n", menu[i]);
    	i++;
    }
    printf("\n");
}

short get_menu_length(const char **menu) {
	short i = 0;
	for (i = 0; menu[i] != NULL; i++);
	return i;
}

short select_option(short minopt, short maxopt) {
	short opt = 0;
	int result;

	while (opt == 0) {
		char user_input[100] = {'\0'};
		printf("Select option: ");
		fgets(user_input, sizeof(user_input), stdin);
		result = sscanf(user_input, "%hd", &opt);

		if (result != 1) {
			opt = 0;
		}

		if (opt < minopt || opt > maxopt) {
			opt = 0;
		}

		if (opt == 0) {
			printf("Please choose one of the valid options.\n");
		}
	}
	printf("\n");
	return opt;
}

int enter_node_value() {
	int val = 0;
	char val_str[20];

	fflush(stdin);
	printf("Enter node value: ");
	fgets(val_str, sizeof(val_str), stdin);
	val = atoi(val_str);

	return val;
}




