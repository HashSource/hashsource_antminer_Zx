void __fastcall __noreturn sub_B50C(const char *a1, int a2)
{
  int *v4; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  v4 = _errno_location();
  snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v4, "cgminer.c", a1, a2);
  sub_385C8(3, s, 1);
  sub_16BE0(1);
}
