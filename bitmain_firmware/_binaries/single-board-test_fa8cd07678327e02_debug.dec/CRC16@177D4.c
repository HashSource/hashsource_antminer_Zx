uint16_t __cdecl CRC16(const uint8_t *p_data, uint16_t w_len)
{
  const uint8_t *v2; // r3
  uint16_t wIndex; // [sp+Ch] [bp+Ch]
  uint8_t chCRCLo; // [sp+Eh] [bp+Eh]
  uint8_t chCRCHi; // [sp+Fh] [bp+Fh]

  chCRCHi = -1;
  chCRCLo = -1;
  while ( w_len-- )
  {
    v2 = p_data++;
    wIndex = (unsigned __int8)(chCRCLo ^ *v2);
    chCRCLo = chCRCHi ^ chCRCHTalbe[chCRCLo ^ *v2];
    chCRCHi = chCRCLTalbe[wIndex];
  }
  return chCRCLo | (chCRCHi << 8);
}
