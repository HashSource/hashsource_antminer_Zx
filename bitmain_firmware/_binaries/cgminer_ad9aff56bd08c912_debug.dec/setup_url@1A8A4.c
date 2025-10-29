void __fastcall setup_url(pool *pool, char *arg)
{
  char *proxy; // r5
  const char *v4; // r1
  const char *v5; // r1
  char *v6; // r0
  char *v7; // r7
  int *v8; // r3
  char *v9; // r6
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int *v14; // r5
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  char tmp42[4096]; // [sp+0h] [bp-1004h] BYREF

  proxy = get_proxy(arg, pool);
  if ( !detect_stratum(pool, proxy) )
  {
    opt_set_charp(proxy, &pool->rpc_url);
    LOWORD(v4) = -1996;
    HIWORD(v4) = (unsigned int)"d target %s" >> 16;
    if ( strncmp(proxy, v4, 7u) )
    {
      LOWORD(v5) = -1988;
      HIWORD(v5) = (unsigned int)" %s" >> 16;
      if ( strncmp(proxy, v5, 8u) )
      {
        v6 = (char *)malloc(0x100u);
        v7 = v6;
        if ( !v6 )
        {
          LOWORD(v14) = -1976;
          HIWORD(v14) = (unsigned int)" signal received." >> 16;
          v15 = *v14;
          v16 = v14[1];
          v17 = v14[2];
          v18 = v14[3];
          v14 += 4;
          *(_DWORD *)tmp42 = v15;
          *(_DWORD *)&tmp42[4] = v16;
          *(_DWORD *)&tmp42[8] = v17;
          *(_DWORD *)&tmp42[12] = v18;
          v19 = v14[1];
          v20 = v14[2];
          *(_DWORD *)&tmp42[16] = *v14;
          *(_DWORD *)&tmp42[20] = v19;
          *(_WORD *)&tmp42[24] = v20;
          tmp42[26] = BYTE2(v20);
          applog(3, tmp42, 1);
          _quit(1, 1);
        }
        LOWORD(v8) = -2584;
        v9 = v6;
        HIWORD(v8) = (unsigned int)"t common denominator set to %lu" >> 16;
        v10 = *v8;
        v11 = v8[1];
        v12 = v8[2];
        v13 = v8[3];
        *(_DWORD *)v9 = v10;
        *((_DWORD *)v9 + 1) = v11;
        *((_DWORD *)v9 + 2) = v12;
        v9 += 12;
        *(_WORD *)v9 = v13;
        v9[2] = BYTE2(v13);
        strncat(v7, proxy, 0xF2u);
        detect_stratum(pool, v7);
      }
    }
  }
}
