void __fastcall opt_show_bool(char *buf, const bool *b)
{
  const char *v2; // r3
  int v3; // r4
  const char *v4; // r1

  LOWORD(v2) = 25936;
  v3 = *(unsigned __int8 *)b;
  v4 = "true";
  if ( !v3 )
  {
    HIWORD(v2) = (unsigned int)"data[3] = 0x%x, \t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n" >> 16;
    v4 = v2;
  }
  j_strncpy(buf, v4, 0x50u);
}
