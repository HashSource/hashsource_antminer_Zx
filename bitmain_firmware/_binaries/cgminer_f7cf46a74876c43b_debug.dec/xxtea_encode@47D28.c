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
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( n <= 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      strcpy(tmp42, "XXTEA encode failes, N <= 1 found.\n");
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
