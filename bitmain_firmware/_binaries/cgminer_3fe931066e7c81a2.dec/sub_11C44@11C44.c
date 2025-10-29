void __noreturn sub_11C44(const char *a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+Ch] BYREF

  va_start(varg_r1, a1);
  vsnprintf(byte_76CF8, 0x200u, a1, varg_r1);
  sub_38730(3, byte_76CF8, 1);
  exit(1);
}
