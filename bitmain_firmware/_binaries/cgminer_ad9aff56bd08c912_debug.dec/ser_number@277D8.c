int __fastcall ser_number(unsigned __int8 *s, int32_t val)
{
  unsigned __int8 v3; // r2
  int result; // r0

  if ( val > 127 )
  {
    if ( val >= 16512 )
    {
      if ( val <= 2113663 )
        result = 4;
      else
        result = 5;
      if ( val <= 2113663 )
        v3 = 3;
      else
        v3 = 4;
    }
    else
    {
      result = 3;
      v3 = 2;
    }
  }
  else
  {
    v3 = 1;
    result = 2;
  }
  *(_DWORD *)(s + 1) = val;
  *s = v3;
  return result;
}
