#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

int
main(void)
{
  struct uproc* table;
  int i;
  uint max = 72;
  int catch = 0;
  uint elapsed, decs, secs, secs_decs;
  table = malloc(sizeof(struct uproc) * max);
  catch = getprocs(max, table);
  if(catch == -1)
    printf(1, "\nError: Invalid max or NULL uproc table\n");
  else {
	//printf(1,"MAX = 72");
    printf(1, "\nPID\tName\tUID\tGID\tPPID\tElapsed\tCPU\tState\tSize");
    for(i = 0;i < catch;++i) {
      decs = table[i].elapsed_ticks % 1000;
      elapsed = table[i].elapsed_ticks / 1000;
      secs_decs = table[i].CPU_total_ticks % 1000;
      secs = table[i].CPU_total_ticks / 1000;
      printf(1, "\n%d\t%s\t%d\t%d\t%d\t%d.", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, elapsed);
      if(decs < 10)
        printf(1, "00");
      else if(decs < 100)
        printf(1, "0");
      printf(1, "%d\t%d.", decs, secs);
      if(secs_decs < 10)
        printf(1, "00");
      else if(secs_decs < 100)
        printf(1, "0");
      printf(1, "%d\t%s\t%d", secs_decs, table[i].state, table[i].size);
    }
    printf(1, "\n");
  }
  free(table);
  exit();
}
#endif // CS333_P2
