void __cdecl Sha256_WriteByteBlock(CSha256 *p)
{
  uint32_t data32[16]; // [sp+Ch] [bp+Ch] BYREF
  unsigned int i; // [sp+4Ch] [bp+4Ch]
  _DWORD vars0[2]; // [sp+50h] [bp+50h] BYREF

  for ( i = 0; i <= 0xF; ++i )
    vars0[i - 17] = p->buffer[4 * i + 3]
                  + (p->buffer[4 * i + 2] << 8)
                  + (p->buffer[4 * i] << 24)
                  + (p->buffer[4 * i + 1] << 16);
  Sha256_Transform(p->state, data32);
}
