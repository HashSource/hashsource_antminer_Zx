void __noreturn sub_11B7C(const char *a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+Ch] BYREF

  va_start(varg_r1, a1);
  vsnprintf(byte_73B30, 0x200u, a1, varg_r1);
  sub_385C8(3, byte_73B30, 1);
  exit(1);
}
