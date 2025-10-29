void __fastcall Sha256_Update(CSha256 *p, const uint8_t *data, size_t size)
{
  unsigned int count_high; // r5
  unsigned int count; // r0
  const uint8_t *v6; // r6
  int v7; // r3
  const uint8_t *v8; // r8
  char v9; // t1
  char *v10; // r1

  count_high = HIDWORD(p->count);
  count = p->count;
  if ( size )
  {
    v6 = data;
    v7 = count & 0x3F;
    v8 = &data[size];
    while ( 1 )
    {
      v9 = *v6++;
      v10 = (char *)p + v7++;
      v10[40] = v9;
      p->count = __PAIR64__(count_high, count) + 1;
      if ( v7 == 64 )
      {
        Sha256_WriteByteBlock(p);
        v7 = 0;
        if ( v6 == v8 )
          return;
      }
      else if ( v6 == v8 )
      {
        return;
      }
      count_high = HIDWORD(p->count);
      count = p->count;
    }
  }
}
