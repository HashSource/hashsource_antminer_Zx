const char *__fastcall next_name(const char *names, unsigned int *len)
{
  int v2; // r3
  const char *v3; // r0
  bool v4; // zf
  const char *v5; // r4
  const char *v7; // r1

  v2 = (unsigned __int8)names[*len];
  v3 = &names[*len];
  v4 = (v2 & 0xDF) == 0;
  if ( (v2 & 0xDF) != 0 )
    v4 = v2 == 61;
  if ( v4 )
    return 0;
  v5 = v3 + 2;
  LOWORD(v7) = -19144;
  HIWORD(v7) = (unsigned int)"of range" >> 16;
  *len = strcspn(v3 + 2, v7);
  return v5;
}
