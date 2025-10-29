int __fastcall object_key_compare_serials(const void *key1, const void *key2)
{
  if ( *(_DWORD *)key1 < *(_DWORD *)key2 )
    return -1;
  else
    return *(_DWORD *)key1 != *(_DWORD *)key2;
}
