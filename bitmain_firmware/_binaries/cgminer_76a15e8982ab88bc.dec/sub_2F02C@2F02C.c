int __fastcall sub_2F02C(sem_t *a1, const char *a2, const char *a3, int a4)
{
  int result; // r0
  int *v9; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  result = sem_post(a1);
  if ( result )
  {
    v9 = _errno_location();
    snprintf(s, 0x1000u, "Failed to sem_post errno=%d cgsem=0x%p in %s %s():%d", *v9, a1, a2, a3, a4);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  return result;
}
