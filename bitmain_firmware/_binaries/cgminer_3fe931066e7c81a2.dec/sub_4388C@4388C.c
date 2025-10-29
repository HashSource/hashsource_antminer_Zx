void __noreturn sub_4388C()
{
  int v0; // lr
  _DWORD *v1; // r12
  int *v2; // r0
  unsigned __int8 *v3; // r5
  int v4; // t1
  int v5; // r3
  int v6; // r1
  int v7; // r3
  int v8; // r4
  int v9; // r3
  int v10; // r6
  int *v11; // r11
  int *v12; // r7
  int *v13; // r5
  _DWORD *v14; // r11
  int v15; // t1
  int v16; // r3
  const char *v17; // r2
  int v18; // r1
  const char *v19; // r0
  int v20; // r12
  int v21; // r12
  int i; // r3
  int v23; // r0
  int v24; // r3
  int v25; // r2
  int v27; // r2
  int *v28; // r7
  int v29; // r2
  unsigned __int8 *v30; // lr
  int v31; // t1
  int v32; // r1
  int *v33; // r1
  int v34; // r4
  char *v35; // r11
  int v36; // t1
  int v37; // r5
  int *v38; // r6
  int v39; // t1
  unsigned int v40; // r12
  unsigned int v41; // r3
  const char *v42; // r2
  int j; // r3
  int v44; // r1
  int v45; // r3
  int v46; // r2
  int v47; // [sp+18h] [bp-1074h]
  int v48; // [sp+1Ch] [bp-1070h]
  unsigned __int8 *v49; // [sp+20h] [bp-106Ch]
  _DWORD v50[12]; // [sp+28h] [bp-1064h] BYREF
  _DWORD v51[12]; // [sp+58h] [bp-1034h] BYREF
  char s[4088]; // [sp+88h] [bp-1004h] BYREF

  v0 = 0;
  v1 = v51;
  memset(v50, 0, sizeof(v50));
  v2 = dword_7C130;
  memset(v51, 0, sizeof(v51));
  v3 = (unsigned __int8 *)&unk_9D4BB;
  do
  {
    v4 = *++v3;
    if ( v4 == 1 )
    {
      v5 = v2[62];
      v6 = v2[61];
      *v1 = 775;
      LOWORD(v6) = v6 + v5;
      v7 = v2[63];
      v1[1] = 775;
      v1[2] = 775;
      *(_WORD *)((char *)&unk_9D4B4 + 2 * v0 + 593) = (__int16)(v6 + v7) / 3;
    }
    ++v0;
    v1 += 3;
    v2 += 3;
  }
  while ( v0 != 4 );
  while ( !byte_790EC[0] )
LABEL_11:
    sub_2A92C();
  while ( 1 )
  {
    v8 = 0;
    v48 = 0;
    v49 = (unsigned __int8 *)&unk_9D4BB;
    do
    {
      v9 = *++v49;
      if ( v9 == 1 )
      {
        v10 = 0;
        v11 = &v50[3 * v8];
        v12 = &dword_7C130[3 * v8 + 61];
        v13 = &v51[3 * v8];
        v15 = *v11;
        v14 = v11 + 1;
        if ( !v15 )
        {
LABEL_13:
          v16 = *v12;
          if ( (unsigned int)*v12 <= 0x306 )
          {
            v27 = *v12;
            *v13 = v16;
            sub_43734((unsigned __int8)v8, (unsigned __int8)v10, v27);
            *(v14 - 1) = 1;
            goto LABEL_27;
          }
          if ( v16 == 775 )
          {
            *v13 = 775;
            sub_43734((unsigned __int8)v8, (unsigned __int8)v10, 775);
            *(v14 - 1) = 1;
            goto LABEL_27;
          }
          v17 = "d";
          v18 = 1;
          v19 = "d";
          while ( 1 )
          {
            v20 = *((_DWORD *)v19 + 4);
            v19 += 16;
            if ( v16 == v20 )
              break;
            if ( ++v18 == 115 )
            {
              v21 = *v13;
              v18 = -1;
              if ( *v13 == 100 )
              {
LABEL_33:
                i = 0;
                goto LABEL_22;
              }
LABEL_19:
              for ( i = 1; i != 115; ++i )
              {
                v23 = *((_DWORD *)v17 + 4);
                v17 += 16;
                if ( v21 == v23 )
                  goto LABEL_22;
              }
              i = -1;
LABEL_22:
              if ( v18 - i <= 1 )
                v24 = i + 1;
              else
                v24 = i + 2;
              v25 = *(_DWORD *)&aResetAllHashBo[16 * v24 + 2220];
              *v13 = v25;
              v47 = v25;
              sub_43734((unsigned __int8)v8, (unsigned __int8)v10, v25);
              if ( v47 == *v12 )
                *(v14 - 1) = 1;
              goto LABEL_27;
            }
          }
          v21 = *v13;
          if ( *v13 == 100 )
            goto LABEL_33;
          goto LABEL_19;
        }
        while ( 1 )
        {
          ++v48;
LABEL_27:
          ++v10;
          ++v13;
          ++v12;
          if ( v10 == 3 )
            break;
          if ( !*v14++ )
            goto LABEL_13;
        }
      }
      ++v8;
    }
    while ( v8 != 4 );
    if ( 3 * (unsigned __int8)byte_9D6CB <= v48 )
      break;
    sleep(3u);
    if ( !byte_790EC[0] )
      goto LABEL_11;
  }
  v28 = dword_7C130;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(s, "All asics arrive target freq\n");
    sub_38730(5, s, 0);
  }
  v29 = 0;
  v30 = (unsigned __int8 *)&unk_9D4BB;
  do
  {
    while ( 1 )
    {
      v31 = *++v30;
      if ( v31 == 1 )
        break;
      ++v29;
      v28 += 3;
      if ( v29 == 4 )
        goto LABEL_42;
    }
    v32 = 3 * v29++;
    v33 = &dword_7C130[v32];
    v33[1] = 0;
    v33[25] = 0;
    v33[49] = 815;
    v33[37] = 775;
    v28[2] = 0;
    v28[26] = 0;
    v28[50] = 815;
    v28[38] = 775;
    v28[3] = 0;
    v28[27] = 0;
    v28[51] = 815;
    v28[39] = 775;
    v28 += 3;
  }
  while ( v29 != 4 );
  while ( 1 )
  {
    do
    {
LABEL_42:
      sleep(1u);
      pthread_mutex_lock(&stru_79100);
      pthread_cond_wait(&stru_7C078, &stru_79100);
      pthread_mutex_unlock(&stru_79100);
      v34 = (unsigned __int8)byte_78E3C;
    }
    while ( byte_78E3C );
    v35 = &byte_9D4BC;
    if ( byte_9D4BC == 1 )
    {
LABEL_46:
      v37 = 0;
      v38 = &dword_7C130[3 * v34 + 25];
      if ( *v38 == 1 )
      {
LABEL_49:
        v40 = v38[36];
        v41 = v38[12];
        if ( v40 > v41 )
        {
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
          {
            snprintf(
              s,
              0x1000u,
              "low freq[%d-%d]: cur freq %d, [%d, %d], invalid nonce %d, ox status %d\n",
              v34,
              v37,
              v40,
              v41,
              v38[24],
              *(v38 - 24),
              1);
            sub_38730(5, s, 0);
            v40 = v38[36];
          }
          if ( v40 == 100 )
          {
            v45 = -1;
          }
          else
          {
            v42 = "d";
            for ( j = 1; j != 115; ++j )
            {
              v44 = *((_DWORD *)v42 + 4);
              v42 += 16;
              if ( v44 == v40 )
              {
                v45 = j - 1;
                goto LABEL_59;
              }
            }
            v45 = -2;
          }
LABEL_59:
          v46 = *(_DWORD *)&aResetAllHashBo[16 * v45 + 2220];
          v38[36] = v46;
          sub_43734((unsigned __int8)v34, (unsigned __int8)v37, v46);
        }
      }
      while ( ++v37 != 3 )
      {
        v39 = v38[1];
        ++v38;
        if ( v39 == 1 )
          goto LABEL_49;
      }
    }
    while ( ++v34 != 4 )
    {
      v36 = (unsigned __int8)*++v35;
      if ( v36 == 1 )
        goto LABEL_46;
    }
  }
}
