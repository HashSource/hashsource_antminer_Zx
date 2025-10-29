void __noreturn sub_46090()
{
  char *v0; // r1
  int j; // r2
  int v2; // t1
  int v3; // r5
  int v4; // r11
  int v5; // t1
  _DWORD *v6; // r5
  int v7; // r10
  int v8; // r6
  int v9; // r9
  int ii; // r4
  int v11; // t1
  int v12; // r0
  _BOOL4 v13; // r3
  int v14; // r4
  int v15; // r6
  int v16; // r0
  int *v17; // r4
  int v18; // r3
  int v19; // lr
  int v20; // r12
  int k; // r2
  int v22; // r1
  int m; // r1
  int v24; // lr
  unsigned int v25; // r1
  int v26; // r12
  int v27; // r2
  const char *v28; // r3
  int v29; // t1
  int v30; // r1
  int v31; // lr
  const char *v32; // r3
  int n; // r2
  int v34; // r12
  int v35; // lr
  const char *v36; // r3
  int v37; // r12
  int v38; // r3
  char *v39; // lr
  bool v40; // zf
  char *v41; // r12
  int v42; // r12
  char *v43; // r3
  int i; // [sp+24h] [bp-1008h]
  char s[4100]; // [sp+28h] [bp-1004h] BYREF

  for ( i = 731; ; i = 750 )
  {
    v0 = (char *)&unk_78F58;
    for ( j = 631471; j != 631475; ++j )
    {
      v2 = *(unsigned __int8 *)(j + 1);
      if ( v2 == 1 )
      {
        v42 = 0;
        do
        {
          *(_DWORD *)&v0[v42] = 0;
          v43 = &v0[v42];
          v42 += 4;
          *((_DWORD *)v43 + 12) = 0;
          *((_DWORD *)v43 + 48) = 681;
          *((_DWORD *)v43 + 36) = i;
          *((_DWORD *)v43 + 24) = 650;
          *((_DWORD *)v43 + 60) = 0;
        }
        while ( v42 != 12 );
      }
      v0 += 12;
    }
    do
    {
      do
      {
LABEL_5:
        sleep(1u);
        pthread_mutex_lock(&stru_75F40);
        pthread_cond_wait(&stru_78EA0, &stru_75F40);
        pthread_mutex_unlock(&stru_75F40);
        v3 = (unsigned __int8)byte_75C7C;
      }
      while ( byte_75C7C );
      v4 = 631471;
      do
      {
        v5 = *(unsigned __int8 *)++v4;
        if ( v5 != 1 )
          goto LABEL_8;
        v15 = 0;
        v17 = (int *)((char *)&unk_78F58 + 12 * v3 + 48);
        v16 = *v17;
        if ( *v17 )
          goto LABEL_48;
        while ( 2 )
        {
          v18 = *(v17 - 12);
          if ( (unsigned int)v18 <= 5 )
          {
            v19 = v17[36];
            v20 = v17[24];
            if ( v20 == v19 )
            {
LABEL_76:
              v17[48] = 1;
              goto LABEL_46;
            }
            v17[12] = v19;
            if ( v19 == 100 )
            {
              k = v16;
LABEL_28:
              if ( v20 == 100 )
                goto LABEL_70;
            }
            else
            {
              v18 = (int)"d";
              for ( k = 1; k != 100; ++k )
              {
                v22 = *(_DWORD *)(v18 + 16);
                v18 += 16;
                if ( v19 == v22 )
                  goto LABEL_28;
              }
              k = -1;
              if ( v20 == 100 )
              {
LABEL_70:
                m = 0;
                goto LABEL_32;
              }
            }
            v18 = (int)"d";
            for ( m = 1; m != 100; ++m )
            {
              v24 = *(_DWORD *)(v18 + 16);
              v18 += 16;
              if ( v20 == v24 )
                goto LABEL_32;
            }
            m = -1;
LABEL_32:
            v25 = m - k;
            if ( v25 == 1 )
              ++k;
            else
              v18 = v25 + (v25 >> 31);
            if ( v25 != 1 )
            {
              v25 = 1;
              k += v18 >> 1;
            }
            goto LABEL_37;
          }
LABEL_48:
          v30 = v17[12];
          v31 = v17[36];
          if ( v30 == v31 )
            goto LABEL_76;
          if ( v31 == 100 )
          {
            v35 = -1;
LABEL_54:
            if ( v30 == 100 )
              goto LABEL_74;
            goto LABEL_55;
          }
          v32 = "d";
          for ( n = 1; n != 100; ++n )
          {
            v34 = *((_DWORD *)v32 + 4);
            v32 += 16;
            if ( v31 == v34 )
            {
              v35 = n - 1;
              goto LABEL_54;
            }
          }
          v35 = -2;
          if ( v30 == 100 )
          {
LABEL_74:
            k = 0;
            goto LABEL_58;
          }
LABEL_55:
          v36 = "d";
          for ( k = 1; k != 100; ++k )
          {
            v37 = *((_DWORD *)v36 + 4);
            v36 += 16;
            if ( v30 == v37 )
              goto LABEL_58;
          }
          k = -1;
LABEL_58:
          v38 = v35 - k;
          v39 = &aResetAllHashBo[16 * v35];
          v40 = v38 == 1;
          v25 = -1;
          if ( v38 == 1 )
            ++k;
          else
            v38 += (unsigned int)v38 >> 31;
          if ( !v40 )
            k += v38 >> 1;
          v17[24] = *((_DWORD *)v39 + 530);
LABEL_37:
          v26 = (unsigned __int8)byte_75C49;
          v27 = *(_DWORD *)&aResetAllHashBo[16 * k + 2120];
          v17[36] = v27;
          if ( v26 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            if ( v25 == 1 )
              v28 = "up";
            else
              v28 = "down";
            snprintf(
              s,
              0x1000u,
              "%s freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
              v28,
              v3,
              v15,
              v27,
              v17[12],
              v17[24],
              *(v17 - 12),
              v16);
            sub_385C8(7, s, 0);
            v27 = v17[36];
          }
          sub_4273C((unsigned __int8)v3, (unsigned __int8)v15, v27);
LABEL_46:
          if ( ++v15 != 3 )
          {
            v29 = v17[1];
            ++v17;
            v16 = v29;
            if ( !v29 )
              continue;
            goto LABEL_48;
          }
          break;
        }
LABEL_8:
        ++v3;
      }
      while ( v3 != 4 );
      v6 = &unk_78F58;
      v7 = 0;
      v8 = 631471;
      v9 = 0;
      for ( ii = 0; ii != 4; ++ii )
      {
        v11 = *(unsigned __int8 *)++v8;
        if ( v11 == 1 )
        {
          v41 = (char *)&unk_78F58 + 12 * ii;
          v7 += *((_DWORD *)v41 + 48) + v6[49] + v6[50];
          v9 += *((_DWORD *)v41 + 60) + v6[61] + v6[62];
          if ( byte_75C49 )
          {
            if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
            {
              snprintf(s, 0x1000u, "chain%d %d %d %d\n", ii, v6[48], v6[49], v6[50]);
              sub_385C8(7, s, 0);
            }
          }
        }
        v6 += 3;
      }
    }
    while ( v9 != 3 * (unsigned __int8)byte_9A49F );
    v12 = sub_59AC8(v7, v9);
    v13 = i == 750;
    if ( v12 > 718 )
      v13 = 1;
    v14 = v12;
    if ( v13 )
    {
      sub_45F7C();
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "scan freq done, avg freq %d max %d, reboot cgminer\n", v14, i);
        sub_385C8(5, s, 0);
      }
      system("/etc/init.d/cgminer.sh restart > /dev/null 2>&1 &");
      goto LABEL_5;
    }
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "scan freq again, avg freq %d max %d\n", v12, 750);
      sub_385C8(5, s, 0);
    }
  }
}
