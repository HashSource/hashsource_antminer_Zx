int __fastcall add_var_int(uint8_t *msg, uint64_t var_int)
{
  bool v3; // cf
  uint8_t v4; // r3
  int v6; // r4
  size_t v7; // r2
  uint64_t v8; // [sp+0h] [bp-Ch] BYREF

  v8 = var_int;
  if ( var_int >= 0xFD )
  {
    if ( var_int >= 0x10000 )
    {
      v3 = HIDWORD(var_int) != 0;
      if ( HIDWORD(var_int) == 1 )
        v3 = 1;
      if ( v3 )
      {
        v6 = 9;
        v7 = 8;
      }
      else
      {
        v6 = 5;
        v7 = 4;
      }
      if ( v3 )
        v4 = -1;
      else
        v4 = -2;
      *msg = v4;
    }
    else
    {
      v6 = 3;
      *msg = -3;
      v7 = 2;
    }
  }
  else
  {
    *msg = var_int;
    v6 = 1;
    v7 = 0;
  }
  memcpy(msg + 1, &v8, v7);
  return v6;
}
