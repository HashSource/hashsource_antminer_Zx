void __fastcall set_led(bool stop)
{
  const char *v1; // r1
  const char *v2; // r1
  const char *v3; // r1
  char cmd[100]; // [sp+4h] [bp-64h] BYREF

  LOWORD(v1) = -25968;
  blink_15605 ^= 1u;
  HIWORD(v1) = (unsigned int)"r chain %d failed" >> 16;
  if ( stop )
  {
    sprintf(cmd, v1, 0, 942);
    system(cmd);
    LOWORD(v3) = -25968;
    HIWORD(v3) = (unsigned int)"r chain %d failed" >> 16;
    sprintf(cmd, v3, (unsigned __int8)blink_15605, 941);
  }
  else
  {
    sprintf(cmd, v1, 0, 941);
    system(cmd);
    LOWORD(v2) = -25968;
    HIWORD(v2) = (unsigned int)"r chain %d failed" >> 16;
    sprintf(cmd, v2, (unsigned __int8)blink_15605, 942);
  }
  system(cmd);
}
