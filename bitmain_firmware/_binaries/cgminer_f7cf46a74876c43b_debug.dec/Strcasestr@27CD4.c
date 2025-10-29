char *__fastcall Strcasestr(char *haystack, const char *needle)
{
  bool v2; // zf
  signed int v5; // r10
  signed int v6; // r9
  _BOOL4 v7; // r4
  const __int32_t **v8; // r0
  signed int v9; // r3
  const __int32_t *v10; // r12
  char *v11; // r0
  char *v12; // r2
  int v13; // t1
  const char *v14; // r2
  char *v15; // r0
  signed int v16; // r3
  int v17; // t1
  char *v18; // r0
  char v20[32]; // [sp+0h] [bp-20h] BYREF

  v2 = needle == 0;
  if ( needle )
    v2 = haystack == 0;
  if ( v2 )
    return 0;
  v5 = strlen(haystack);
  v6 = strlen(needle);
  if ( v5 )
    v7 = v6 == 0;
  else
    v7 = 1;
  if ( v7 )
    return 0;
  v8 = _ctype_tolower_loc();
  v9 = 0;
  v10 = *v8;
  v11 = &v20[-1];
  v12 = haystack - 1;
  do
  {
    v13 = (unsigned __int8)*++v12;
    ++v9;
    *++v11 = v10[v13];
  }
  while ( v9 < v5 );
  v14 = needle - 1;
  v15 = &v20[-1];
  v16 = 0;
  do
  {
    v17 = *(unsigned __int8 *)++v14;
    ++v16;
    *++v15 = v10[v17];
  }
  while ( v16 < v6 );
  v18 = strstr(v20, v20);
  if ( !v18 )
    return 0;
  else
    return &haystack[v18 - v20];
}
