
#include <omp.h>
#define N 1000
#define N_THREADS 4
main () 
{
int tid, i, chunk;
double a[N], b[N], c[N];
  
omp_set_num_threads(N_THREADS);   
chunk = N/N_THREADS;
#pragma omp parallel private(tid,i) shared(a,b,c)
  {
  tid = omp_get_thread_num();
  for (i = tid * chunk; i < (tid+1) * chunk; i++)
    {
    c[i] = a[i] + b[i];
    }
  }  /* end of parallel section */   
}
