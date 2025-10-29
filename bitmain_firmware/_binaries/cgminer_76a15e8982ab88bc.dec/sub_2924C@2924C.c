char *__fastcall sub_2924C(_DWORD *a1, unsigned int a2)
{
  char *result; // r0

  result = (char *)sub_291EC(a1, a2);
  if ( result )
    return _strdup(result);
  return result;
}
