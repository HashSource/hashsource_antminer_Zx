void sub_1C028()
{
  char v0[2052]; // [sp+0h] [bp-804h] BYREF

  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    snprintf(v0, 0x800u, "Attempting to restart %s", byte_60EA4);
    sub_38438(4, v0, 0);
  }
  sub_2F38C((int)sub_1C708, 0, 5000);
  sub_2B13C((struct timeval *)&dword_613E4);
  sub_19060();
  if ( dword_61418 > 0 )
  {
    kill(dword_61418, 15);
    dword_61418 = 0;
  }
  execv(*(const char **)dword_6141C, (char *const *)dword_6141C);
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    strcpy(v0, "Failed to restart application");
    sub_38438(4, v0, 0);
  }
}
