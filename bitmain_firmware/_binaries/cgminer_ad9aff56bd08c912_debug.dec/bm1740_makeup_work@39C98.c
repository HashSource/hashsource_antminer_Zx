int __fastcall bm1740_makeup_work(uint8_t *str, int len)
{
  int result; // r0
  const char *v3; // r2
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( len == 146 )
    return bm1740_makeup_work_0(str, 146);
  if ( use_syslog || (result = opt_log_output) != 0 || opt_log_level > 3 )
  {
    LOWORD(v3) = -26708;
    HIWORD(v3) = (unsigned int)"real:%u mv\n" >> 16;
    snprintf(tmp42, 0x1000u, v3, "bm1740_makeup_work");
    applog(4, tmp42, 0);
    return 0;
  }
  return result;
}
