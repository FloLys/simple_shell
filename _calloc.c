#include <stdlib.h>
#include <string.h>
#include "main.h"

void *_calloc(size_t nmemb, size_t size)
{
  unsigned int		s = 0;
  char			*ptr = 0;

  s = nmemb * size;
  if ((ptr = malloc(s)) == NULL)
    return (NULL);
  memset(ptr, 0, s);
  return (ptr);
}
