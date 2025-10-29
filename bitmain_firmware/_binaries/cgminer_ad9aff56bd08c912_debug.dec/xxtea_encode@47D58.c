void __fastcall xxtea_encode(uint32_t *v, int n, const uint32_t *key)
{
  uint32_t *v3; // r9
  unsigned int v4; // r4
  int v5; // r10
  unsigned int v6; // lr
  uint32_t *v7; // r6
  int v8; // r5
  unsigned int v9; // r12
  uint32_t v10; // r3
  int *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r4
  char tmp42[4096]; // [sp+8h] [bp-1004h] BYREF

  if ( n <= 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      LOWORD(v11) = -20456;
      HIWORD(v11) = (unsigned int)"cted sock=%d" >> 16;
      v12 = *v11;
      v13 = v11[1];
      v14 = v11[2];
      v15 = v11[3];
      v11 += 4;
      *(_DWORD *)tmp42 = v12;
      *(_DWORD *)&tmp42[4] = v13;
      *(_DWORD *)&tmp42[8] = v14;
      *(_DWORD *)&tmp42[12] = v15;
      v16 = *v11;
      v17 = v11[1];
      v18 = v11[2];
      v19 = v11[3];
      v20 = v11[4];
      *(_DWORD *)&tmp42[16] = v16;
      *(_DWORD *)&tmp42[20] = v17;
      *(_DWORD *)&tmp42[24] = v18;
      *(_DWORD *)&tmp42[28] = v19;
      *(_DWORD *)&tmp42[32] = v20;
      applog(3, tmp42, 0);
    }
  }
  else
  {
    v3 = &v[n - 1];
    v4 = *v3;
    v5 = n - 1;
    v6 = 0;
    do
    {
      v7 = v;
      v8 = 0;
      v6 -= 1640531527;
      v9 = v6 >> 2;
      do
      {
        v10 = key[((unsigned __int8)v9 ^ (unsigned __int8)v8++) & 3];
        v4 = *v7 + (((v10 ^ v4) + (v6 ^ v7[1])) ^ (((4 * v7[1]) ^ (v4 >> 5)) + ((16 * v4) ^ (v7[1] >> 3))));
        *v7++ = v4;
      }
      while ( v8 != v5 );
      v4 = (((v4 ^ key[((unsigned __int8)v9 ^ (unsigned __int8)v5) & 3]) + (v6 ^ *v))
          ^ (((4 * *v) ^ (v4 >> 5)) + ((16 * v4) ^ (*v >> 3))))
         + *v3;
      *v3 = v4;
    }
    while ( v6 != -1253254570 - 1640531527 * (52 / n) );
  }
}
