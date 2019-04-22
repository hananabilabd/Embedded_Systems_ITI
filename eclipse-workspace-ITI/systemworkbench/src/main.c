
#include <stdio.h>


int
main(int argc, char* argv[])
{

  uint32_t seconds = 0;

  // Infinite loop
  while (1)
    {


      ++seconds;
      // Count seconds on the trace device.
      trace_printf("Second %u\n", seconds);
    }
  // Infinite loop, never return.
}


// ----------------------------------------------------------------------------
