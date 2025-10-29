int __fastcall string_get(void *data)
{
  int v1; // r2
  int v2; // r3

  v1 = *((_DWORD *)data + 1);
  v2 = *(unsigned __int8 *)(*(_DWORD *)data + v1);
  if ( !*(_BYTE *)(*(_DWORD *)data + v1) )
    return -1;
  *((_DWORD *)data + 1) = v1 + 1;
  return v2;
}
