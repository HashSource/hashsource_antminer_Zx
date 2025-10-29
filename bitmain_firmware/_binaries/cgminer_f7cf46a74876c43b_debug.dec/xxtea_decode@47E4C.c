void __fastcall xxtea_decode(uint32_t *v, int n, const uint32_t *key)
{
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r10
  int v7; // r6
  unsigned int v8; // r12
  uint32_t *v9; // r7
  unsigned int v10; // t1
  uint32_t v11; // r11
  int v12; // r6
  char tmp42[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( n <= 1 )
  {
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      strcpy(tmp42, "XXTEA decode failes, N <= 1 found.\n");
      applog(3, tmp42, 0);
    }
  }
  else
  {
    v4 = -1640531527 * (52 / n + 6);
    v5 = *v;
    v6 = v4 + 1640531527 * (52 / n) + 1253254570;
    do
    {
      v7 = n - 1;
      v8 = v4 >> 2;
      v9 = &v[n - 1];
      do
      {
        v10 = *--v9;
        v11 = key[((unsigned __int8)v8 ^ (unsigned __int8)v7--) & 3];
        v5 = v9[1] - (((v10 ^ v11) + (v4 ^ v5)) ^ (((4 * v5) ^ (v10 >> 5)) + ((16 * v10) ^ (v5 >> 3))));
        v9[1] = v5;
      }
      while ( v7 );
      v12 = v5 ^ v4;
      v4 += 1640531527;
      v5 = *v - ((((16 * v[n - 1]) ^ (v5 >> 3)) + ((4 * v5) ^ (v[n - 1] >> 5))) ^ ((v[n - 1] ^ key[v8 & 3]) + v12));
      *v = v5;
    }
    while ( v4 != v6 );
  }
}
