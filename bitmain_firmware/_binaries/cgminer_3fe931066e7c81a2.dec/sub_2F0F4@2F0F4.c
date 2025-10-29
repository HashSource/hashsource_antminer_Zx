int __fastcall sub_2F0F4(sem_t *a1, const char *a2, const char *a3, int a4)
{
  int result; // r0
  int v8; // r7
  int *v9; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  result = sem_init(a1, 0, 0);
  v8 = result;
  if ( result )
  {
    v9 = _errno_location();
    snprintf(s, 0x1000u, "Failed to sem_init ret=%d errno=%d in %s %s():%d", v8, *v9, a2, a3, a4);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  return result;
}
