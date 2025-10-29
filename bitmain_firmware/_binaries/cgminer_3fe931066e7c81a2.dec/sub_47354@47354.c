void __noreturn sub_47354()
{
  int *v0; // r1
  int j; // r3
  int v2; // t1
  int v3; // r5
  int v4; // r11
  int v5; // t1
  int *v6; // r5
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
  int *v41; // r12
  int v42; // r0
  int *v43; // r2
  int i; // [sp+24h] [bp-1008h]
  char s[4100]; // [sp+28h] [bp-1004h] BYREF

  sub_43E4C(800);
  for ( i = 815; ; i = 825 )
  {
    v0 = dword_7C130;
    for ( j = 644283; j != 644287; ++j )
    {
      v2 = *(unsigned __int8 *)(j + 1);
      if ( v2 == 1 )
      {
        v42 = 0;
        do
        {
          v43 = &v0[v42++];
          v43[1] = 0;
          v43[25] = 0;
          v43[61] = 800;
          v43[49] = i;
          v43[37] = 775;
          v43[73] = 0;
        }
        while ( v42 != 3 );
      }
      v0 += 3;
    }
    do
    {
      do
      {
LABEL_5:
        sleep(1u);
        pthread_mutex_lock(&stru_79100);
        pthread_cond_wait(&stru_7C078, &stru_79100);
        pthread_mutex_unlock(&stru_79100);
        v3 = (unsigned __int8)byte_78E3C;
      }
      while ( byte_78E3C );
      v4 = 644283;
      do
      {
        v5 = *(unsigned __int8 *)++v4;
        if ( v5 != 1 )
          goto LABEL_8;
        v15 = 0;
        v17 = &dword_7C130[3 * v3 + 25];
        v16 = *v17;
        if ( *v17 )
          goto LABEL_48;
        while ( 2 )
        {
          v18 = *(v17 - 24);
          if ( (unsigned int)v18 <= 0xF )
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
              for ( k = 1; k != 115; ++k )
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
            for ( m = 1; m != 115; ++m )
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
          for ( n = 1; n != 115; ++n )
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
          for ( k = 1; k != 115; ++k )
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
          v17[24] = *((_DWORD *)v39 + 555);
LABEL_37:
          v26 = (unsigned __int8)byte_78E09;
          v27 = *(_DWORD *)&aResetAllHashBo[16 * k + 2220];
          v17[36] = v27;
          if ( v26 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
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
              *(v17 - 24),
              v16);
            sub_38730(7, s, 0);
            v27 = v17[36];
          }
          sub_43734((unsigned __int8)v3, (unsigned __int8)v15, v27);
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
      v6 = dword_7C130;
      v7 = 0;
      v8 = 644283;
      v9 = 0;
      for ( ii = 0; ii != 4; ++ii )
      {
        v11 = *(unsigned __int8 *)++v8;
        if ( v11 == 1 )
        {
          v41 = &dword_7C130[3 * ii];
          v7 += v41[61] + v6[62] + v6[63];
          v9 += v41[73] + v6[74] + v6[75];
          if ( byte_78E09 )
          {
            if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
            {
              snprintf(s, 0x1000u, "chain%d %d %d %d\n", ii, v6[61], v6[62], v6[63]);
              sub_38730(7, s, 0);
            }
          }
        }
        v6 += 3;
      }
    }
    while ( v9 != 3 * (unsigned __int8)byte_9D6CB );
    v12 = sub_5C710(v7, v9);
    v13 = i == 825;
    if ( v12 > 800 )
      v13 = 1;
    v14 = v12;
    if ( v13 )
    {
      sub_470A8();
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "scan freq done, avg freq %d max %d, reboot cgminer\n", v14, i);
        sub_38730(5, s, 0);
      }
      system("/etc/init.d/cgminer.sh restart > /dev/null 2>&1 &");
      goto LABEL_5;
    }
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "scan freq again, avg freq %d max %d\n", v12, 825);
      sub_38730(5, s, 0);
    }
  }
}
