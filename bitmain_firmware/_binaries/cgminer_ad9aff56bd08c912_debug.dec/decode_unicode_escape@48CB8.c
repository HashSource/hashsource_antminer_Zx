int32_t __fastcall decode_unicode_escape(const char *str)
{
  const char *v1; // r3
  int32_t result; // r0
  const char *v3; // r5
  int v4; // r2
  int v5; // t1
  int v6; // r0
  int v7; // r1
  const char *v8; // r3
  const char *v9; // r1
  const char *v10; // r0
  const char *v11; // r3
  const char *v12; // r1
  const char *v13; // r0

  if ( *str != 117 )
  {
    LOWORD(v8) = -20136;
    LOWORD(v9) = -19996;
    LOWORD(v10) = -19988;
    HIWORD(v8) = (unsigned int)&primes[17] >> 16;
    HIWORD(v9) = (unsigned int)"scan_number" >> 16;
    HIWORD(v10) = (unsigned int)"ber" >> 16;
    _assert_fail(v10, v9, 0x120u, v8);
  }
  v1 = str;
  result = 0;
  v3 = v1 + 4;
  do
  {
    v5 = *(unsigned __int8 *)++v1;
    v4 = v5;
    v6 = 16 * result;
    v7 = v5 - 48;
    if ( (unsigned __int8)(v5 - 48) > 9u )
    {
      if ( (unsigned int)(v4 - 97) > 0x19 )
      {
        if ( (unsigned int)(v4 - 65) > 0x19 )
        {
          LOWORD(v11) = -20136;
          LOWORD(v12) = -19996;
          LOWORD(v13) = 12944;
          HIWORD(v11) = (unsigned int)&primes[17] >> 16;
          HIWORD(v12) = (unsigned int)"scan_number" >> 16;
          HIWORD(v13) = (unsigned int)"extra wide display without toggling" >> 16;
          _assert_fail(v13, v12, 0x12Cu, v11);
        }
        result = v6 + v4 - 55;
      }
      else
      {
        result = v6 + v4 - 87;
      }
    }
    else
    {
      result = v6 + v7;
    }
  }
  while ( v1 != v3 );
  return result;
}
