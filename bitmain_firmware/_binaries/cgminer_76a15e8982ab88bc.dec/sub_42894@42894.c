void __noreturn sub_42894()
{
  FILE *v0; // r0
  int v1; // r4
  unsigned __int8 *v2; // r11
  char *v3; // r12
  FILE *v4; // r10
  int v5; // t1
  int v6; // r5
  int *v7; // r7
  int v8; // r3
  FILE *v9; // r0
  char *v10; // r10
  int v11; // lr
  _DWORD *v12; // r0
  unsigned __int8 *v13; // r5
  _DWORD *v14; // r12
  int v15; // t1
  int v16; // r3
  int v17; // r1
  int v18; // r3
  int v19; // r1
  _DWORD *v20; // r3
  unsigned __int8 *v21; // r5
  int v22; // t1
  int v23; // r6
  char *v24; // lr
  int v25; // r5
  char *v26; // r11
  int v27; // t1
  int v28; // r6
  char *v29; // r7
  int v30; // t1
  unsigned int v31; // r12
  unsigned int v32; // r3
  const char *v33; // r2
  int j; // r3
  int v35; // r1
  int v36; // r3
  int v37; // r2
  int v38; // r5
  int v39; // r9
  int v40; // r3
  int v41; // r7
  _DWORD *v42; // r6
  int *v43; // r11
  int *v44; // r4
  int v46; // r3
  const char *v47; // r0
  int v48; // r1
  const char *v49; // r2
  int v50; // r12
  int i; // r3
  int v52; // r12
  int v53; // r3
  int v54; // r2
  int v55; // r2
  char *v56; // [sp+1Ch] [bp-1080h]
  int v57; // [sp+1Ch] [bp-1080h]
  unsigned __int8 *v58; // [sp+20h] [bp-107Ch]
  int v59; // [sp+34h] [bp-1068h] BYREF
  _DWORD v60[12]; // [sp+38h] [bp-1064h] BYREF
  _DWORD v61[12]; // [sp+68h] [bp-1034h] BYREF
  char s[4072]; // [sp+98h] [bp-1004h] BYREF

  v0 = fopen("/config/chips_freq.config", "r");
  if ( v0 )
  {
    v1 = 0;
    v2 = (unsigned __int8 *)&unk_9A2AF;
    v3 = (char *)&unk_78F58;
    v4 = v0;
    do
    {
      while ( 1 )
      {
        v5 = *++v2;
        if ( v5 == 1 )
          break;
        if ( ++v1 == 4 )
          goto LABEL_10;
      }
      v6 = 0;
      v7 = (int *)&v3[12 * v1 + 192];
      do
      {
        ++v6;
        v59 = 0;
        v56 = v3;
        fscanf(v4, "%d", &v59);
        v8 = v59;
        if ( (unsigned int)(v59 - 650) >= 0x65 )
          v8 = 681;
        *v7++ = v8;
        v3 = v56;
      }
      while ( v6 != 3 );
      ++v1;
    }
    while ( v1 != 4 );
LABEL_10:
    v9 = v4;
    v10 = v3;
    fclose(v9);
    v11 = 0;
    v12 = v61;
    memset(v60, 0, sizeof(v60));
    v13 = (unsigned __int8 *)&unk_9A2AF;
    v14 = &unk_78F58;
    memset(v61, 0, sizeof(v61));
    do
    {
      v15 = *++v13;
      if ( v15 == 1 )
      {
        v16 = v14[49];
        v17 = v14[48];
        *v12 = 681;
        LOWORD(v17) = v17 + v16;
        v18 = v14[50];
        v12[1] = 681;
        v12[2] = 681;
        *(_WORD *)((char *)&unk_9A2A8 + 2 * v11 + 561) = (__int16)(v17 + v18) / 3;
      }
      ++v11;
      v12 += 3;
      v14 += 3;
    }
    while ( v11 != 4 );
    while ( !byte_75F2C[0] )
LABEL_49:
      sub_2A884();
    while ( 1 )
    {
      v38 = 0;
      v39 = 0;
      v58 = (unsigned __int8 *)&unk_9A2AF;
      do
      {
        v40 = *++v58;
        if ( v40 == 1 )
        {
          v41 = 0;
          v42 = &v60[3 * v38];
          v43 = (int *)&v10[12 * v38 + 192];
          v44 = &v61[3 * v38];
          do
          {
            if ( *v42++ )
            {
              ++v39;
            }
            else
            {
              v46 = *v43;
              if ( (unsigned int)*v43 <= 0x2A8 )
              {
                v55 = *v43;
                *v44 = v46;
                sub_4273C((unsigned __int8)v38, (unsigned __int8)v41, v55);
                *(v42 - 1) = 1;
              }
              else if ( v46 == 681 )
              {
                *(v42 - 1) = 1;
              }
              else
              {
                v47 = "d";
                v48 = 1;
                v49 = "d";
                do
                {
                  v50 = *((_DWORD *)v49 + 4);
                  v49 += 16;
                  if ( v46 == v50 )
                    goto LABEL_59;
                  ++v48;
                }
                while ( v48 != 100 );
                v48 = -1;
LABEL_59:
                if ( *v44 == 100 )
                {
                  i = 0;
                }
                else
                {
                  for ( i = 1; i != 100; ++i )
                  {
                    v52 = *((_DWORD *)v47 + 4);
                    v47 += 16;
                    if ( *v44 == v52 )
                      goto LABEL_63;
                  }
                  i = -1;
                }
LABEL_63:
                if ( v48 - i <= 1 )
                  v53 = i + 1;
                else
                  v53 = i + 2;
                v54 = *(_DWORD *)&aResetAllHashBo[16 * v53 + 2120];
                *v44 = v54;
                v57 = v54;
                sub_4273C((unsigned __int8)v38, (unsigned __int8)v41, v54);
                if ( v57 == *v43 )
                  *(v42 - 1) = 1;
              }
            }
            ++v41;
            ++v44;
            ++v43;
          }
          while ( v41 != 3 );
        }
        ++v38;
      }
      while ( v38 != 4 );
      if ( 3 * (unsigned __int8)byte_9A49F <= v39 )
        break;
      sleep(3u);
      if ( !byte_75F2C[0] )
        goto LABEL_49;
    }
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      strcpy(s, "All asics arrive target freq\n");
      sub_385C8(5, s, 0);
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "open %s failed\n", "/config/chips_freq.config");
    sub_385C8(5, s, 0);
    v10 = (char *)&unk_78F58;
  }
  else
  {
    v10 = (char *)&unk_78F58;
  }
  v19 = 0;
  v20 = &unk_78F58;
  v21 = (unsigned __int8 *)&unk_9A2AF;
  do
  {
    while ( 1 )
    {
      v22 = *++v21;
      if ( v22 == 1 )
        break;
      ++v19;
      v20 += 3;
      if ( v19 == 4 )
        goto LABEL_22;
    }
    v23 = 3 * v19++;
    v24 = &v10[4 * v23];
    *(_DWORD *)v24 = 0;
    *((_DWORD *)v24 + 12) = 0;
    *((_DWORD *)v24 + 36) = 731;
    *((_DWORD *)v24 + 24) = 650;
    v20[1] = 0;
    v20[13] = 0;
    v20[37] = 731;
    v20[25] = 650;
    v20[2] = 0;
    v20[14] = 0;
    v20[38] = 731;
    v20[26] = 650;
    v20 += 3;
  }
  while ( v19 != 4 );
  while ( 1 )
  {
    do
    {
LABEL_22:
      sleep(1u);
      pthread_mutex_lock(&stru_75F40);
      pthread_cond_wait(&stru_78EA0, &stru_75F40);
      pthread_mutex_unlock(&stru_75F40);
      v25 = (unsigned __int8)byte_75C7C;
    }
    while ( byte_75C7C );
    v26 = &byte_9A2B0;
    if ( byte_9A2B0 == 1 )
    {
LABEL_26:
      v28 = 0;
      v29 = &v10[12 * v25 + 48];
      if ( *(_DWORD *)v29 == 1 )
      {
LABEL_29:
        v31 = *((_DWORD *)v29 + 36);
        v32 = *((_DWORD *)v29 + 12);
        if ( v31 > v32 )
        {
          if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
          {
            snprintf(
              s,
              0x1000u,
              "low freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
              v25,
              v28,
              v31,
              v32,
              *((_DWORD *)v29 + 24),
              *((_DWORD *)v29 - 12),
              1);
            sub_385C8(5, s, 0);
            v31 = *((_DWORD *)v29 + 36);
          }
          if ( v31 == 100 )
          {
            v36 = -1;
          }
          else
          {
            v33 = "d";
            for ( j = 1; j != 100; ++j )
            {
              v35 = *((_DWORD *)v33 + 4);
              v33 += 16;
              if ( v35 == v31 )
              {
                v36 = j - 1;
                goto LABEL_39;
              }
            }
            v36 = -2;
          }
LABEL_39:
          v37 = *(_DWORD *)&aResetAllHashBo[16 * v36 + 2120];
          *((_DWORD *)v29 + 36) = v37;
          sub_4273C((unsigned __int8)v25, (unsigned __int8)v28, v37);
        }
      }
      while ( ++v28 != 3 )
      {
        v30 = *((_DWORD *)v29 + 1);
        v29 += 4;
        if ( v30 == 1 )
          goto LABEL_29;
      }
    }
    while ( ++v25 != 4 )
    {
      v27 = (unsigned __int8)*++v26;
      if ( v27 == 1 )
        goto LABEL_26;
    }
  }
}
