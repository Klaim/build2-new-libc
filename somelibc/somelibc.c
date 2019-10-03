#include <somelibc/somelibc.h>

#include <errno.h>

int say_hello (char *f, const char* n)
{
  if (f == NULL || n == NULL || *n == '\0')
  {
    errno = EINVAL;
    return -1;
  }

  return sprintf (f, "Hello, %s!\n", n);
}
