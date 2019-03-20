#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  getusage(1);
  getpriority();
  setpriority(7);

  getpriority();
  setpriority(1);

  getpriority();
  setpriority(2);

  getusage(1);
  exit();
}
