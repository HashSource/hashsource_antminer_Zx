int __fastcall sub_35360(int a1, const void *a2, char *s)
{
  void *v5; // r0

  snprintf(s, 0xBu, "%p", a2);
  if ( hashtable_get(a1, s) )
    return -1;
  v5 = json_null();
  return hashtable_set(a1, s, (int)v5);
}
