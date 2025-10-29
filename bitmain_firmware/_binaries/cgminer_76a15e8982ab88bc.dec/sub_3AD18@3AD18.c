int __fastcall sub_3AD18(pthread_rwlock_t *a1)
{
  int result; // r0
  int *v2; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  result = pthread_rwlock_init(a1, 0);
  if ( result )
  {
    v2 = _errno_location();
    snprintf(
      s,
      0x1000u,
      "Failed to pthread_rwlock_init errno=%d in %s %s():%d",
      *v2,
      "driver-btm-zcash.c",
      "bitmain_ZCASH_prepare",
      7042);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  return result;
}
