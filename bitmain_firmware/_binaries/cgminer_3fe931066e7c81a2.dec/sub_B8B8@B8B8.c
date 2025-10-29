void __fastcall __noreturn sub_B8B8(int a1)
{
  int *v2; // r0
  char s[4096]; // [sp+10h] [bp-1000h] BYREF

  v2 = _errno_location();
  snprintf(
    s,
    0x1000u,
    "Failed to pthread_mutex_init errno=%d in %s %s():%d",
    *v2,
    "driver-btm-zcash.c",
    "bitmain_ZCASH_prepare",
    a1);
  sub_38730(3, s, 1);
  sub_16CA8(1);
}
