uint32_t __cdecl target_zero_cal(uint8_t *target)
{
  uint8_t tmphash[32]; // [sp+8h] [bp+8h] BYREF
  int j; // [sp+28h] [bp+28h]
  int i_0; // [sp+2Ch] [bp+2Ch]
  int i; // [sp+30h] [bp+30h]
  uint32_t zero_num; // [sp+34h] [bp+34h]

  zero_num = 0;
  memset(tmphash, 0, sizeof(tmphash));
  for ( i = 0; i <= 31; ++i )
    tmphash[i] = target[31 - i];
  for ( i_0 = 0; i_0 <= 31; ++i_0 )
  {
    for ( j = 7; j >= 0; --j )
    {
      if ( bit_read(&tmphash[i_0], j) )
        return zero_num;
      ++zero_num;
    }
  }
  return zero_num;
}
