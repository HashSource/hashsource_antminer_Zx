char *__fastcall sub_583CC(char *result, char *s)
{
  if ( result )
  {
    result[92] = 0;
    *((_DWORD *)result + 2) = 0;
    *(_DWORD *)result = -1;
    *((_DWORD *)result + 1) = -1;
    if ( s )
      return sub_58368(result, s);
    else
      result[12] = 0;
  }
  return result;
}
