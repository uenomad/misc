#ifndef ARGS_H
#define ARGS_H

// Allowed syntax
//	-a
//	-bval
//	-b val
//	--something
//	--something=val
//	--something val
// Suffixes:
//	: required value
// Examples:
//	args_get(argc, argv, "a:", buffer);
//	args_get(argc, argv, "something", buffer);

/* Returns 1 if argument arg is found. Value is copied in buffer. */
int args_get(int argc, char *argv[], const char *arg, char *buffer);

#endif //ARGS_H