void __fastcall opt_show_bool(char *buf, const bool *b)
{
  const char *v2; // r3
  int v3; // r4
  const char *v4; // r1

  LOWORD(v2) = 26060;
  v3 = *(unsigned __int8 *)b;
  v4 = "true";
  if ( !v3 )
  {
    HIWORD(v2) = (unsigned int)"x, read_back_data[1] = 0x%02x" >> 16;
    v4 = v2;
  }
  j_strncpy(buf, v4, 0x50u);
}
