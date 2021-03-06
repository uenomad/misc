#include "args.h"

int args_get(int argc, char *argv[], const char *arg_in, char *buffer)
{
	int is_required = 0;
	int next_value  = 0;
	int curr_value  = 0;
	int has_equal   = 0;
	int is_short    = 0;
	int is_long     = 0;

	char arg[128];
	char aux[128];
	char *p;
	int i;

	if (strlen(arg_in) == 0) {
		return 0;
	}
	// Saving the argument in the stack.
	strcpy(aux, arg_in);
	// If value is mandatory
	if (aux[strlen(aux)-1] == ':') {
		aux[strlen(aux)-1] = '\0';
		is_required = 1;
	}
	// Is long or short?
	is_short = (strlen(aux) == 1);
	is_long  = (strlen(aux) >= 2);
	//
	if (is_short) sprintf(arg,  "-%s", aux);
	if (is_long)  sprintf(arg, "--%s", aux);
	//
	if (buffer != NULL) {
		buffer[0] = '\0';
	}
	//
	for (i = 0; i < argc; ++i)
	{
		if (strncmp(argv[i], arg, strlen(arg)) != 0) {
			continue;
		}
		// Is equal, check if has value
		curr_value = (strlen(argv[i]) > strlen(arg));
		// Check if next is value
		next_value = (i < (argc-1)) && (
					 (strncmp(argv[i+1], "--", 2) != 0) &&
					 (strncmp(argv[i+1],  "-", 1) != 0) );
		// Check if has equal symbol (=)
		has_equal = (strchr(argv[i], '=') != NULL);
		//
		if (is_short && curr_value && !has_equal && buffer) {
			p = &argv[i][strlen(arg)];
			strcpy(buffer, p);
			return 1;
		}
		if (is_short && next_value && buffer) {
			strcpy(buffer, argv[i+1]);
			return 1;
		}
		if (is_long && curr_value && has_equal && buffer) {
			p = &argv[i][strlen(arg)+1];
			strcpy(buffer, p);
			return 1;
		}
		if (is_long && next_value) {
			strcpy(buffer, argv[i+1]);
			return 1;
		}
		if ((is_long || is_short) && !is_required) {
			// True if value is not mandatory and both flags are completely equal
			if (strcmp(argv[i], arg) == 0) {
				return 1;
			}
		}
	}
	return 0;
}