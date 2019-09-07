
#include <stdio.h>
#include <string.h>

int main()
{
  char name[10];
  char buffer[80];

  unsigned A = 0xA6;

  printf( "A: %#08x\n", A );

  strcpy( name, "Hello" );

  sprintf( buffer, "The string '%s' contains %d characters\n",
    name, strlen( name ) );

  printf( "%s", buffer );

  return 0;
}

