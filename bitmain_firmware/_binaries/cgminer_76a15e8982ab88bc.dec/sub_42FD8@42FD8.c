void __noreturn sub_42FD8()
{
  int v0; // r1
  char *v1; // r2
  int v2; // t1
  int v3; // r5
  char *v4; // r9
  int v5; // t1
  int v6; // r6
  unsigned int v7; // r3
  unsigned int *v8; // r4
  unsigned int v9; // t1
  unsigned int v10; // r12
  unsigned int v11; // r1
  const char *v12; // r2
  int i; // r3
  int v14; // r1
  int v15; // r3
  int v16; // r2
  int v17; // r0
  char *v18; // r3
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  v0 = 631471;
  v1 = (char *)&unk_78F58;
  do
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      v17 = 0;
      do
      {
        *(_DWORD *)&v1[v17] = 0;
        v18 = &v1[v17];
        v17 += 4;
        *((_DWORD *)v18 + 12) = 0;
        *((_DWORD *)v18 + 48) = 681;
        *((_DWORD *)v18 + 36) = 731;
        *((_DWORD *)v18 + 24) = 650;
      }
      while ( v17 != 12 );
    }
    v1 += 12;
  }
  while ( v0 != 631475 );
  while ( 1 )
  {
    do
    {
      sleep(1u);
      pthread_mutex_lock(&stru_75F40);
      pthread_cond_wait(&stru_78EA0, &stru_75F40);
      pthread_mutex_unlock(&stru_75F40);
      v3 = (unsigned __int8)byte_75C7C;
    }
    while ( byte_75C7C );
    v4 = &byte_9A2B0;
    if ( byte_9A2B0 == 1 )
      goto LABEL_8;
    while ( ++v3 != 4 )
    {
      v5 = (unsigned __int8)*++v4;
      if ( v5 == 1 )
      {
LABEL_8:
        v6 = 0;
        v8 = (unsigned int *)((char *)&unk_78F58 + 12 * v3);
        v7 = *v8;
        if ( *v8 <= 0xA )
          goto LABEL_9;
        while ( 2 )
        {
          v10 = v8[48];
          v11 = v8[24];
          if ( v10 > v11 )
          {
            if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
            {
              snprintf(
                s,
                0x1000u,
                "low freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
                v3,
                v6,
                v10,
                v11,
                v8[36],
                v7,
                v8[12]);
              sub_385C8(5, s, 0);
              v10 = v8[48];
            }
            if ( v10 == 100 )
            {
              v15 = -1;
            }
            else
            {
              v12 = "d";
              for ( i = 1; i != 100; ++i )
              {
                v14 = *((_DWORD *)v12 + 4);
                v12 += 16;
                if ( v14 == v10 )
                {
                  v15 = i - 1;
                  goto LABEL_22;
                }
              }
              v15 = -2;
            }
LABEL_22:
            v16 = *(_DWORD *)&aResetAllHashBo[16 * v15 + 2120];
            v8[48] = v16;
            sub_4273C((unsigned __int8)v3, (unsigned __int8)v6, v16);
          }
LABEL_10:
          if ( ++v6 != 3 )
          {
            v9 = v8[1];
            ++v8;
            v7 = v9;
            if ( v9 > 0xA )
              continue;
LABEL_9:
            if ( v8[12] != 1 )
              goto LABEL_10;
            continue;
          }
          break;
        }
      }
    }
  }
}
