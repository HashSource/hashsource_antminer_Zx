const char *__fastcall proxytype(proxytypes_t a1)
{
  unsigned int *p_nusers; // r3
  const char *v2; // r2

  if ( !a1 )
    return "http:";
  p_nusers = &_func___11739.__data.__nusers;
  v2 = "http0:";
  while ( 1 )
  {
    p_nusers += 2;
    if ( p_nusers[1] == a1 )
      break;
    v2 = (const char *)p_nusers[2];
    if ( !v2 )
      return "invalid";
  }
  return v2;
}
