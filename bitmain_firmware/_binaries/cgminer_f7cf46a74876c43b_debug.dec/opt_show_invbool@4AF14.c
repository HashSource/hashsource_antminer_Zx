void __fastcall opt_show_invbool(char *buf, const bool *b)
{
  int v2; // r4
  const char *v3; // r1

  v2 = *(unsigned __int8 *)b;
  v3 = "false";
  if ( !v2 )
    v3 = "true";
  j_strncpy(buf, v3, 0x50u);
}
