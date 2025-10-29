void sub_1D138()
{
  char v0[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(v0, 0x1000u, "Attempting to restart %s", byte_73A2C);
    sub_385C8(4, v0, 0);
  }
  sub_2F2A8((int)sub_1AE2C, 0, 5000);
  sub_2A7A4((struct timeval *)&dword_73F80);
  sub_195CC();
  if ( dword_740C4 > 0 )
  {
    kill(dword_740C4, 15);
    dword_740C4 = 0;
  }
  execv(*(const char **)dword_740C8, (char *const *)dword_740C8);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    strcpy(v0, "Failed to restart application");
    sub_385C8(4, v0, 0);
  }
}
