#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  getusage(1);
  getpriority();
  setpriority(atoi(argv[1]));
  getpriority();
  setpriority(atoi(argv[2]));
  getpriority();
  setpriority(atoi(argv[3]));
  getpriority();

  getusage(1);
  exit();
}
