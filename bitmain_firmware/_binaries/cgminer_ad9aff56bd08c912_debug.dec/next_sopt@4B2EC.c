const char *__fastcall next_sopt(const char *p, unsigned int *i)
{
  const char *result; // r0
  unsigned int len; // [sp+4h] [bp-8h] BYREF

  len = 1;
  result = next_opt(p, i, &len);
  if ( !result )
    return 0;
  while ( *result == 45 )
  {
    result = next_opt(result, i, &len);
    if ( !result )
      return 0;
  }
  return result;
}
