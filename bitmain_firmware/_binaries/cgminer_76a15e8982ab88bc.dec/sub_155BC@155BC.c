char *__fastcall sub_155BC(int a1, int a2, int a3)
{
  int v4; // r7
  const char *v7; // r0
  const char *v8; // r0
  const char *v9; // r0
  char *result; // r0
  unsigned int v11[2]; // [sp+4h] [bp-8h] BYREF

  v4 = *(_DWORD *)(a1 + 1828);
  sub_15580((void **)a1);
  memcpy((void *)a1, (const void *)a2, 0x7B0u);
  *(_DWORD *)(a1 + 1828) = v4;
  v7 = *(const char **)(a2 + 1776);
  if ( v7 )
    *(_DWORD *)(a1 + 1776) = _strdup(v7);
  v8 = *(const char **)(a2 + 1808);
  if ( v8 )
    *(_DWORD *)(a1 + 1808) = _strdup(v8);
  v9 = *(const char **)(a2 + 1796);
  if ( v9 )
  {
    if ( a3 )
    {
      *(_DWORD *)(a1 + 68) = bswap32(bswap32(*(_DWORD *)(a1 + 68)) + a3);
      sub_29788(v11, *(unsigned __int8 **)(a2 + 1796), 4);
      v11[0] = bswap32(bswap32(v11[0]) + a3);
      *(_DWORD *)(a1 + 1796) = sub_29688((int)v11, 4);
    }
    else
    {
      *(_DWORD *)(a1 + 1796) = _strdup(v9);
    }
  }
  else if ( a3 )
  {
    *(_DWORD *)(a1 + 68) = bswap32(bswap32(*(_DWORD *)(a1 + 68)) + a3);
  }
  result = *(char **)(a2 + 1816);
  if ( result )
  {
    result = _strdup(result);
    *(_DWORD *)(a1 + 1816) = result;
  }
  return result;
}
