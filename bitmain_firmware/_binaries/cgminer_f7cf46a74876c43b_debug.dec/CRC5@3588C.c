unsigned __int8 __fastcall CRC5(unsigned __int8 *ptr, unsigned __int8 len)
{
  char v2; // r9
  unsigned __int8 v3; // r6
  int v5; // r2
  int v6; // r0
  int v7; // lr
  int v8; // r7
  int v9; // r12
  unsigned int v10; // r5
  unsigned int v11; // r3
  unsigned __int8 v12; // r3
  int v13; // r4

  if ( len )
  {
    v2 = 1;
    v3 = 0;
    LOBYTE(v5) = 0;
    v6 = 1;
    v7 = 1;
    v8 = 1;
    v9 = 1;
    v10 = 128;
    while ( 1 )
    {
      v5 = (unsigned __int8)(v5 + 1);
      ++v3;
      v11 = *ptr & v10;
      v10 >>= 1;
      if ( v11 )
        v12 = v2 ^ 1;
      else
        v12 = v2;
      if ( v5 == 8 )
      {
        ++ptr;
        LOBYTE(v5) = 0;
        v10 = 128;
      }
      v13 = (unsigned __int8)(v12 ^ v8);
      v2 = v6;
      if ( (unsigned int)v3 >= len )
        break;
      v6 = v7;
      v8 = v9;
      v7 = v13;
      v9 = v12;
    }
    if ( v6 )
      LOBYTE(v6) = 16;
    if ( v7 )
      LOBYTE(v6) = v6 | 8;
    if ( v12 != v8 )
      LOBYTE(v6) = v6 | 4;
    if ( v9 )
    {
      LOBYTE(v6) = v6 | 2;
      if ( !v12 )
        return v6;
      goto LABEL_18;
    }
    if ( v12 )
LABEL_18:
      LOBYTE(v6) = v6 | 1;
  }
  else
  {
    LOBYTE(v6) = 31;
  }
  return v6;
}
