const char *__fastcall first_sopt(unsigned int *i)
{
  const char *result; // r0
  unsigned int len; // [sp+4h] [bp-8h] BYREF

  len = 0;
  result = first_opt(i, &len);
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
