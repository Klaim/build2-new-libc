#pragma once

#include <stdio.h>

#include <somelibc/export.h>

// Print a greeting for the specified name into the specified
// stream. On success, return the number of character printed.
// On failure, set errno and return a negative value.
//
SOMELIBC_SYMEXPORT int
say_hello (char * output, const char *name);
