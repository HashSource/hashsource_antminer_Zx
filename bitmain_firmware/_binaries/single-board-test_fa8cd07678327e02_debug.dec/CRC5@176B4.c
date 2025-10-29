unsigned __int8 __cdecl CRC5(unsigned __int8 *ptr, unsigned __int8 len)
{
  unsigned __int8 crcout[8]; // [sp+Ch] [bp+Ch]
  int crcin; // [sp+14h] [bp+14h]
  char crcin_4; // [sp+18h] [bp+18h]
  unsigned __int8 din; // [sp+1Bh] [bp+1Bh]
  unsigned __int8 crc; // [sp+1Ch] [bp+1Ch]
  unsigned __int8 k; // [sp+1Dh] [bp+1Dh]
  unsigned __int8 j; // [sp+1Eh] [bp+1Eh]
  unsigned __int8 i; // [sp+1Fh] [bp+1Fh]

  crcin = 16843009;
  crcin_4 = 1;
  j = 0x80;
  k = 0;
  for ( i = 0; i < (unsigned int)len; ++i )
  {
    din = (j & *ptr) != 0;
    crcout[0] = din ^ crcin_4;
    crcout[1] = crcin;
    crcout[2] = din ^ crcin_4 ^ BYTE1(crcin);
    *(_WORD *)&crcout[3] = HIWORD(crcin);
    j >>= 1;
    if ( ++k == 8 )
    {
      j = 0x80;
      k = 0;
      ++ptr;
    }
    crcin = *(_DWORD *)crcout;
    crcin_4 = crcout[4];
  }
  crc = 0;
  if ( crcin_4 )
    crc = 16;
  if ( HIBYTE(crcin) )
    crc |= 8u;
  if ( BYTE2(crcin) )
    crc |= 4u;
  if ( BYTE1(crcin) )
    crc |= 2u;
  if ( (_BYTE)crcin )
    crc |= 1u;
  return crc;
}
