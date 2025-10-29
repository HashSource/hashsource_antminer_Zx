int32_t __fastcall decode_unicode_escape(const char *str)
{
  const char *v1; // r3
  int32_t result; // r0
  const char *v3; // r5
  int v4; // r2
  int v5; // t1
  int v6; // r0
  int v7; // r1

  if ( *str != 117 )
    _assert_fail("str[0] == 'u'", "load.c", 0x120u, "decode_unicode_escape");
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
          _assert_fail((const char *)&word_53210, "load.c", 0x12Cu, "decode_unicode_escape");
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
