#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  getpriority();
  setpriority(7);
  exit();
}
