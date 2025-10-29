void __fastcall opt_show_charp(char *buf, char *const *p)
{
  size_t v4; // r5
  char *v5; // r0
  const char *v6; // r1
  char *v7; // r4

  v4 = strlen(*(const char **)p);
  *buf = 34;
  v5 = buf + 1;
  v6 = *p;
  if ( v4 > 0x4E )
  {
    strncpy(v5, v6, 0x4Eu);
    buf[79] = 34;
  }
  else
  {
    v7 = &buf[v4];
    strncpy(v5, v6, v4);
    v7[1] = 34;
    if ( v4 != 78 )
      v7[2] = 0;
  }
}
