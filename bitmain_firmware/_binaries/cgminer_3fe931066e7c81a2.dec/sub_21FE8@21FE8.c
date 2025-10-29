void *__fastcall sub_21FE8(_DWORD *a1)
{
  pthread_t v1; // r0
  char *v2; // r0
  const char **v3; // r5
  int **v4; // r4
  time_t v5; // r0
  _BYTE *v6; // r7
  char *v7; // r6
  int v8; // r3
  size_t v9; // r0
  int *v10; // r6
  size_t v11; // r0
  int **v12; // r5
  int *v13; // r6
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r0
  int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r3
  int v22; // r2
  int v23; // r3
  int *v24; // r1
  int v25; // r1
  int ***v26; // r0
  int v27; // r2
  int *v28; // r5
  size_t v29; // r6
  _DWORD *v30; // r0
  _DWORD *v31; // r7
  int v32; // r8
  void **v33; // r3
  void *v34; // r6
  void ***v35; // r11
  _DWORD *v36; // r5
  void *v37; // r4
  _DWORD *v38; // r9
  int v39; // r4
  char *v40; // r6
  unsigned int v41; // r2
  int v42; // r3
  int *v43; // r3
  unsigned int v44; // r1
  unsigned int v45; // r2
  bool v46; // cc
  int v47; // r2
  time_t v48; // r0
  int v49; // r3
  int *v50; // r2
  int *v52; // r0
  void *v53; // r0
  const char *v54; // r1
  _BOOL4 v55; // r7
  int v56; // r3
  unsigned int i; // [sp+1Ch] [bp-2020h]
  char s[16]; // [sp+28h] [bp-2014h] BYREF
  char v60[4096]; // [sp+38h] [bp-2004h] BYREF
  char v61[4100]; // [sp+1038h] [bp-1004h] BYREF

  v1 = pthread_self();
  pthread_detach(v1);
  snprintf(s, 0x10u, "%d/SStratum", *a1);
  sub_2F0B4(s);
  v2 = sub_2A168();
  a1[188] = v2;
  if ( !v2 )
  {
    strcpy(v61, "Failed to create stratum_q in stratum_sthread");
    sub_38730(3, v61, 1);
    sub_16CA8(1);
  }
  memset(v60, 0, sizeof(v60));
  if ( *((_BYTE *)a1 + 137) )
    goto LABEL_56;
  do
  {
    v3 = (const char **)sub_2A300(a1[188], 0);
    if ( !v3 )
    {
      strcpy(v61, "Stratum q returned empty work");
      sub_38730(3, v61, 1);
      sub_16CA8(1);
    }
    v4 = (int **)calloc(0x34u, 1u);
    if ( !v4 )
    {
      snprintf(v61, 0x1000u, "%s: calloc() failed on sshare.", "stratum_sthread");
      sub_38730(3, v61, 1);
      sub_16CA8(1);
    }
    v5 = time(0);
    v4[9] = (int *)v3;
    v4[11] = (int *)v5;
    v6 = sub_29730((int)(v3 + 83), 32);
    v7 = sub_29730((int)(v3 + 91), 1347);
    if ( pthread_mutex_lock(&stru_77030) )
      sub_B414("stratum_sthread", 7288);
    v8 = dword_7B0F8++;
    v4[10] = (int *)v8;
    if ( pthread_mutex_unlock(&stru_77030) )
      sub_B5C4("stratum_sthread", 7291);
    off_75ED8();
    v9 = strlen(v3[452]);
    snprintf(
      v60,
      0x1000u,
      "{\"id\": %d, \"method\": \"mining.submit\", \"params\": [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\"]}",
      v4[10],
      (const char *)a1[51],
      v3[444],
      v3[449],
      &v6[v9],
      v7);
    free(v6);
    free(v7);
    while ( 1 )
    {
      v10 = v4[11];
      if ( (int)v10 + 119 < time(0) )
        goto LABEL_50;
      v11 = strlen(v60);
      if ( sub_2B5C8((int)a1, v60, v11) )
      {
        if ( pthread_mutex_lock(&stru_77030) )
          sub_B414("stratum_sthread", 7306);
        v4[2] = 0;
        v4[5] = (int *)(v4 + 10);
        v12 = (int **)dword_77048;
        v4[6] = (int *)4;
        if ( v12 )
        {
          *(_DWORD *)((*v12)[4] + 8) = v4;
          v4[1] = (int *)((*v12)[4] - (*v12)[5]);
          (*v12)[4] = (int)v4;
          v13 = *v12;
        }
        else
        {
          v4[1] = 0;
          dword_77048 = (int)v4;
          v52 = (int *)malloc(0x2Cu);
          v13 = v52;
          *v4 = v52;
          if ( !v52 )
            goto LABEL_62;
          *v52 = 0;
          v52[3] = 0;
          v52[4] = 0;
          v52[5] = 0;
          v52[6] = 0;
          v52[7] = 0;
          v52[8] = 0;
          v52[9] = 0;
          v52[10] = 0;
          v52[4] = (int)v4;
          v52[5] = 0;
          v52[1] = 32;
          v52[2] = 5;
          v53 = malloc(0x180u);
          *v13 = (int)v53;
          if ( !v53 )
            goto LABEL_62;
          memset(v53, 0, 0x180u);
          v12 = v4;
          v13[10] = -1609490463;
        }
        ++v13[3];
        v14 = (*((unsigned __int8 *)v4 + 40)
             + 17973517
             + (*((unsigned __int8 *)v4 + 43) << 24)
             + (*((unsigned __int8 *)v4 + 42) << 16)
             + (*((unsigned __int8 *)v4 + 41) << 8))
            ^ (unsigned int)&unk_7F76D;
        v15 = (-1622558010 - v14) ^ (v14 << 8);
        *v4 = *v12;
        v16 = (-17973517 - v14 - v15) ^ (v15 >> 13);
        v17 = (v14 - v15 - v16) ^ (v16 >> 12);
        v18 = (v15 - v16 - v17) ^ (v17 << 16);
        v19 = (v16 - v17 - v18) ^ (v18 >> 5);
        v20 = v17 - v18 - v19;
        v21 = (v19 - (v20 ^ (v19 >> 3)) - ((v18 - v19 - (v20 ^ (v19 >> 3))) ^ ((v20 ^ (v19 >> 3)) << 10)))
            ^ (((v18 - v19 - (v20 ^ (v19 >> 3))) ^ ((v20 ^ (v19 >> 3)) << 10)) >> 15);
        v4[7] = (int *)v21;
        v22 = 3 * (v21 & ((*v12)[1] - 1));
        v23 = 12 * (v21 & ((*v12)[1] - 1));
        ++*(_DWORD *)(**v12 + v23 + 4);
        v24 = *(int **)(**v12 + 4 * v22);
        v4[3] = 0;
        v4[4] = v24;
        v25 = **v12;
        v26 = (int ***)(v25 + v23);
        v27 = *(_DWORD *)(v25 + 4 * v22);
        if ( v27 )
        {
          *(_DWORD *)(v27 + 12) = v4;
          v26 = (int ***)(**v12 + v23);
        }
        *v26 = v4;
        if ( *(_DWORD *)(**v12 + v23 + 4) < (unsigned int)(10 * (*(_DWORD *)(**v12 + v23 + 8) + 1)) )
          goto LABEL_39;
        v28 = *v4;
        if ( (*v4)[9] == 1 )
          goto LABEL_39;
        v29 = 24 * v28[1];
        v30 = malloc(v29);
        v31 = v30;
        if ( v30 )
        {
          memset(v30, 0, v29);
          v32 = 0;
          v28[6] = (((2 * v28[1] - 1) & v28[3]) != 0) + ((unsigned int)v28[3] >> (*((_BYTE *)v28 + 8) + 1));
          (*v4)[7] = 0;
          v33 = (void **)*v4;
          v34 = (void *)(*v4)[1];
          if ( v34 )
          {
            v35 = (void ***)v4;
            for ( i = 0; i < (unsigned int)v34; ++i )
            {
              v36 = *(_DWORD **)((char *)*v33 + v32);
              if ( v36 )
              {
                v37 = v34;
                while ( 1 )
                {
                  v38 = (_DWORD *)v36[4];
                  v39 = 3 * ((2 * (_DWORD)v37 - 1) & v36[7]);
                  v40 = (char *)&v31[v39];
                  v41 = *((_DWORD *)v40 + 1) + 1;
                  *((_DWORD *)v40 + 1) = v41;
                  if ( v41 > (unsigned int)v33[6] )
                  {
                    v33[7] = (char *)v33[7] + 1;
                    *((_DWORD *)v40 + 2) = *((_DWORD *)v40 + 1) / (unsigned int)(*v35)[6];
                  }
                  v36[3] = 0;
                  v36[4] = v31[v39];
                  v42 = v31[v39];
                  if ( v42 )
                    *(_DWORD *)(v42 + 12) = v36;
                  v31[v39] = v36;
                  v33 = *v35;
                  if ( !v38 )
                    break;
                  v37 = v33[1];
                  v36 = v38;
                }
                v34 = v33[1];
              }
              v32 += 12;
            }
            v4 = (int **)v35;
          }
          free(*v33);
          (*v4)[1] *= 2;
          ++(*v4)[2];
          **v4 = (int)v31;
          v43 = *v4;
          v44 = (*v4)[3];
          v45 = (*v4)[7];
          v46 = v45 > v44 >> 1;
          if ( v45 <= v44 >> 1 )
            v47 = 0;
          else
            v47 = v43[8];
          if ( v46 )
            ++v47;
          v43[8] = v47;
          if ( (unsigned int)(*v4)[8] > 1 )
            (*v4)[9] = 1;
LABEL_39:
          ++a1[189];
          if ( pthread_mutex_unlock(&stru_77030) )
            sub_B5C4("stratum_sthread", 7309);
          off_75ED8();
          if ( sub_18C2C((int)a1, (_BYTE *)a1 + 128) && (byte_7AD48 || byte_78E08 || dword_766C4 > 3) )
          {
            snprintf(v61, 0x1000u, "Pool %d communication resumed, submitting work", *a1);
            sub_38730(4, v61, 0);
          }
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            strcpy(v61, "Successfully submitted, adding to stratum_shares db");
            sub_38730(7, v61, 0);
          }
          goto LABEL_50;
        }
LABEL_62:
        exit(-1);
      }
      if ( !sub_18834((int)a1, (_BYTE *)a1 + 128) && sub_1FFEC((int)a1) )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
        {
          snprintf(v61, 0x1000u, "Pool %d stratum share submission failure", *a1);
          sub_38730(4, v61, 0);
        }
        v56 = a1[41];
        ++dword_7AE68;
        a1[41] = v56 + 1;
      }
      if ( byte_7B644 )
        break;
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
        sub_B414("stratum_sthread", 7330);
      if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B69C("stratum_sthread", 7330);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
        sub_B5C4("stratum_sthread", 7330);
      v54 = (const char *)a1[159];
      if ( v54 )
        v55 = strcmp(v3[452], v54) == 0;
      else
        v55 = 0;
      if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B630("stratum_sthread", 7332);
      off_75ED8();
      if ( !v55 )
      {
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          strcpy(v61, "No matching session id for resubmitting stratum share");
          sub_38730(7, v61, 0);
        }
        goto LABEL_50;
      }
      sleep(5u);
    }
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(v61, "Lowmem option prevents resubmitting stratum share");
      sub_38730(7, v61, 0);
    }
LABEL_50:
    v48 = time(0);
    v49 = (unsigned __int8)byte_78E09;
    v50 = v4[11];
    v4[12] = (int *)v48;
    if ( v49 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(v61, 0x1000u, "Pool %d stratum share submission lag time %d seconds", *a1, v48 - (_DWORD)v50);
      sub_38730(7, v61, 0);
    }
    memset(v60, 0, sizeof(v60));
  }
  while ( !*((_BYTE *)a1 + 137) );
LABEL_56:
  sub_2A230(a1[188]);
  return 0;
}
