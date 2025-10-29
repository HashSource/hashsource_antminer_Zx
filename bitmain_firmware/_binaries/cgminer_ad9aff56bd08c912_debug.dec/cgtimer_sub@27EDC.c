void __fastcall cgtimer_sub(cgtimer_t *a, cgtimer_t *b, cgtimer_t *res)
{
  __time_t v3; // r3
  __syscall_slong_t tv_nsec; // r1
  __syscall_slong_t v5; // r0

  v3 = a->tv_sec - b->tv_sec;
  res->tv_sec = v3;
  tv_nsec = b->tv_nsec;
  v5 = a->tv_nsec - tv_nsec;
  if ( v5 >= 0 )
  {
    res->tv_nsec = v5;
  }
  else
  {
    tv_nsec = 1000000000;
    --v3;
  }
  if ( v5 < 0 )
  {
    res->tv_sec = v3;
    res->tv_nsec = tv_nsec + v5;
  }
}
