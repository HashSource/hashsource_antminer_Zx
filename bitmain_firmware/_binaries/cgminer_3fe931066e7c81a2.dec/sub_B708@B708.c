void __fastcall __noreturn sub_B708(const char *a1, int a2)
{
  int *v4; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  v4 = _errno_location();
  snprintf(s, 0x1000u, "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d", *v4, "util.c", a1, a2);
  sub_38730(3, s, 1);
  sub_16CA8(1);
}
