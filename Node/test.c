#include <stdio.h>
#include <stdlib.h>

#define SHELLSCRIPT "\
#!/bin/bash\n\`:wq
for ((i=0 ; i < 10 ; i++))\n\
do\n\
echo \"Count: $i\"\n\
done\n\
"

int main(void)
{
  puts("Will execute sh with the following script:");
  puts(SHELLSCRIPT);
  puts("Starting now:");
  system(SHELLSCRIPT);
  return 0;
}
