void sub_1D7C8()
{
  char v0[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(v0, 0x1000u, "Attempting to restart %s", byte_76BF4);
    sub_38730(4, v0, 0);
  }
  sub_2F438((int)sub_1B4C0, 0, 5000);
  sub_2A84C((struct timeval *)&dword_77148);
  sub_19ADC();
  if ( dword_7728C > 0 )
  {
    kill(dword_7728C, 15);
    dword_7728C = 0;
  }
  execv(*(const char **)dword_77290, (char *const *)dword_77290);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    strcpy(v0, "Failed to restart application");
    sub_38730(4, v0, 0);
  }
}
