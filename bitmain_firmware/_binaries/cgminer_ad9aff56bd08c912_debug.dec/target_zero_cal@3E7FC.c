int __fastcall target_zero_cal(uint8_t *target)
{
  unsigned __int8 *v2; // r6
  uint8_t *v3; // r0
  uint8_t *v4; // r3
  uint8_t v5; // t1
  int v6; // r5
  int v7; // r4
  int v8; // r1
  char v10; // [sp+0h] [bp-25h] BYREF
  uint8_t tmphash[32]; // [sp+1h] [bp-24h] BYREF
  char v12; // [sp+21h] [bp-4h] BYREF

  memset(tmphash, 0, sizeof(tmphash));
  v2 = tmphash;
  v3 = target + 32;
  v4 = (uint8_t *)&v10;
  do
  {
    v5 = *--v3;
    *++v4 = v5;
  }
  while ( v4 != &tmphash[31] );
  v6 = 0;
LABEL_4:
  v7 = 7;
  while ( 1 )
  {
    v8 = v7--;
    if ( bit_read(v2, v8) )
      return v6;
    ++v6;
    if ( v7 == -1 )
    {
      if ( ++v2 != (unsigned __int8 *)&v12 )
        goto LABEL_4;
      return v6;
    }
  }
}
