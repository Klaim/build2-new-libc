#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include <somelibc/version.h>
#include <somelibc/somelibc.h>

int main ()
{
  char b[256];

  // Basics.
  //
  {
    assert (say_hello (b, "World") > 0);
    assert (strcmp (b, "Hello, World!\n") == 0);
  }

  // Empty name.
  //
  {
    assert (say_hello (b, "") < 0 && errno == EINVAL);
  }

  return 0;
}
