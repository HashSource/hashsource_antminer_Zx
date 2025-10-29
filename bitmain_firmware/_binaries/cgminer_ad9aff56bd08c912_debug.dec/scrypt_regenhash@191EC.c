void __fastcall scrypt_regenhash(work *work)
{
  unsigned __int8 *v2; // r1
  uint32_t *v3; // r2
  unsigned int v4; // t1
  unsigned int v5; // r3
  unsigned __int8 *v6; // r0
  unsigned int v7; // t1
  uint32_t *v8; // [sp+4h] [bp-20254h] BYREF
  uint32_t data[20]; // [sp+8h] [bp-20250h] BYREF
  char scratchbuf[131584]; // [sp+58h] [bp-20200h] BYREF

  *(_DWORD *)scratchbuf = 0;
  memset(&scratchbuf[4], 0, (size_t)&loc_201FC);
  v2 = &work[-1].device_target[35];
  v3 = (uint32_t *)&v8;
  do
  {
    v4 = *((_DWORD *)v2 + 1);
    v2 += 4;
    v3[1] = bswap32(v4);
    ++v3;
  }
  while ( v3 != &data[18] );
  v5 = *(_DWORD *)&work->data[76];
  v8 = data;
  data[19] = bswap32(v5);
  scrypt_1024_1_1_256_sp(data, scratchbuf, (uint32_t *)work->hash);
  v6 = &work->target[28];
  do
  {
    v7 = *((_DWORD *)v6 + 1);
    v6 += 4;
    *(_DWORD *)v6 = bswap32(v7);
  }
  while ( v6 != &work->hash[28] );
}
