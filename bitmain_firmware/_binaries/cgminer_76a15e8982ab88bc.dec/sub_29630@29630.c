_BYTE *__fastcall sub_29630(_BYTE *result, char *a2, int a3)
{
  _BYTE *v3; // r12
  char v4; // t1

  if ( a3 <= 0 )
  {
    v3 = result;
  }
  else
  {
    v3 = &result[2 * a3];
    do
    {
      *result = aClearSock[((unsigned __int8)*a2 >> 4) + 84];
      v4 = *a2++;
      result[1] = aClearSock[(v4 & 0xF) + 84];
      result += 2;
    }
    while ( v3 != result );
  }
  *v3 = 0;
  return result;
}
