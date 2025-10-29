void *__fastcall sub_20088(_DWORD *a1)
{
  int v1; // r11
  pthread_t v3; // r0
  fd_set *v4; // r3
  int v5; // r3
  int v6; // r0
  int *v7; // r4
  int *v9; // r0
  _DWORD *v10; // r0
  void **v11; // r5
  int v12; // r6
  unsigned int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r0
  _DWORD *v16; // r7
  int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r3
  int v20; // r1
  unsigned int v21; // r1
  int v22; // r3
  int v23; // r12
  int v24; // r12
  int v25; // r7
  time_t v26; // r0
  int v27; // r3
  double *v28; // r9
  double v29; // d0
  unsigned int v30; // r6
  int v31; // r1
  __int64 v32; // d8
  const char *v33; // r2
  unsigned int v34; // r3
  _DWORD *v35; // r6
  double v36; // d18
  double v37; // d16
  double v38; // d16
  double v39; // d17
  size_t v40; // r0
  size_t v41; // r3
  _BYTE *v42; // r9
  int v43; // r9
  double v44; // r0
  int v45; // r5
  int v46; // r3
  int v47; // r2
  _DWORD *v48; // r1
  bool v49; // zf
  int v50; // r3
  int v51; // r2
  int v52; // r2
  int v53; // r3
  int v54; // r3
  _DWORD *v55; // r0
  int v56; // r5
  int v57; // r3
  int v58; // r2
  int v59; // r4
  char *v60; // r6
  int v61; // r3
  int v62; // r3
  int v63; // r3
  double v64; // d8
  double v65; // d16
  double v66; // d17
  double v67; // d18
  double v68; // d16
  double v69; // d16
  int v70; // r3
  time_t v71; // r0
  int v72; // r1
  _DWORD *v73; // r0
  const char *v74; // r0
  double v75; // d16
  double v76; // d17
  size_t n; // [sp+1Ch] [bp-1268h]
  int *v78; // [sp+38h] [bp-124Ch]
  int v79; // [sp+40h] [bp-1244h]
  _DWORD *src; // [sp+44h] [bp-1240h]
  const char *srca; // [sp+44h] [bp-1240h]
  _DWORD *v82; // [sp+48h] [bp-123Ch]
  int s2; // [sp+50h] [bp-1234h] BYREF
  struct timeval timeout; // [sp+54h] [bp-1230h] BYREF
  char s[16]; // [sp+5Ch] [bp-1228h] BYREF
  char v86[20]; // [sp+6Ch] [bp-1218h] BYREF
  char v87[2]; // [sp+80h] [bp-1204h] BYREF
  char dest[30]; // [sp+82h] [bp-1202h] BYREF
  char v89[36]; // [sp+A0h] [bp-11E4h] BYREF
  char v90[60]; // [sp+C4h] [bp-11C0h] BYREF
  char v91; // [sp+100h] [bp-1184h] BYREF
  fd_set readfds; // [sp+104h] [bp-1180h] BYREF
  int v93[23]; // [sp+184h] [bp-1100h] BYREF
  char v94[160]; // [sp+1E0h] [bp-10A4h] BYREF
  _DWORD v95[1024]; // [sp+280h] [bp-1004h] BYREF
  _BYTE v96[4]; // [sp+1280h] [bp-4h] BYREF

  v3 = pthread_self();
  pthread_detach(v3);
  snprintf(s, 0x10u, "%d/RStratum", *a1);
  sub_2F0B4(s);
  while ( !*((_BYTE *)a1 + 137) )
  {
    if ( !sub_2AE10((int)a1) && !sub_1FFEC((int)a1) )
    {
      sub_2AEE0((int)a1);
      sub_182F4((int)a1);
      sub_185C8(a1);
      while ( !sub_1FFEC((int)a1) && (!a1[33] || a1 != (_DWORD *)sub_1DA58() && dword_76EFC != 3 && dword_76EFC != 4) )
      {
        if ( pthread_mutex_lock(&stru_77060) )
          sub_B414("wait_lpcurrent", 9248);
        pthread_cond_wait(&stru_77078, &stru_77060);
        if ( pthread_mutex_unlock(&stru_77060) )
          sub_B5C4("wait_lpcurrent", 9250);
        off_75ED8();
      }
      while ( !sub_2CEC8((int)a1) )
      {
        if ( *((_BYTE *)a1 + 137) )
          return 0;
        sub_2A92C();
      }
    }
    v4 = (fd_set *)&v91;
    do
    {
      v4->__fds_bits[1] = 0;
      v4 = (fd_set *)((char *)v4 + 4);
    }
    while ( v4 != (fd_set *)&readfds.__fds_bits[31] );
    v5 = a1[153];
    timeout.tv_usec = 0;
    timeout.tv_sec = 90;
    readfds.__fds_bits[v5 / 32] |= 1 << (v5 % 32);
    if ( sub_2AE10((int)a1) || (v6 = select(a1[153] + 1, &readfds, 0, 0, &timeout), v6 > 0) )
    {
      v7 = (int *)sub_2B040((int)a1);
      if ( !v7 )
      {
        v57 = (unsigned __int8)byte_78E09;
        goto LABEL_121;
      }
      sub_1FD64(a1);
      if ( sub_2CF40(a1, v7) )
        goto LABEL_10;
      v9 = sub_59230(v7, 0, (char *)v93);
      v78 = v9;
      if ( v9 )
      {
        src = (_DWORD *)sub_59E20(v9, "result");
        v82 = (_DWORD *)sub_59E20(v78, "error");
        v10 = (_DWORD *)sub_59E20(v78, "id");
        if ( !v10 || *v10 == 7 )
        {
          if ( v82 )
          {
            v60 = (char *)sub_57854(v82, 3);
          }
          else
          {
            v60 = (char *)malloc(0x11u);
            if ( v60 )
              strcpy(v60, "(unknown reason)");
          }
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            snprintf((char *)v95, 0x1000u, "JSON-RPC non method decode failed: %s", v60);
            sub_38730(7, (const char *)v95, 0);
          }
          v45 = 0;
          free(v60);
        }
        else
        {
          s2 = sub_5A248((int)v10);
          if ( pthread_mutex_lock(&stru_77030) )
            sub_B414("parse_stratum_response", 6921);
          v11 = (void **)dword_77048;
          if ( dword_77048 )
          {
            v12 = *(_DWORD *)dword_77048;
            v13 = ((unsigned __int8)s2 + 17973517 + (HIBYTE(s2) << 24) + (BYTE2(s2) << 16) + (BYTE1(s2) << 8))
                ^ (unsigned int)&unk_7F76D;
            v14 = (-1622558010 - v13) ^ (v13 << 8);
            v15 = (-17973517 - v13 - v14) ^ (v14 >> 13);
            v16 = **(_DWORD ***)dword_77048;
            v17 = (v13 - v14 - v15) ^ (v15 >> 12);
            v18 = (v14 - v15 - v17) ^ (v17 << 16);
            v19 = (v15 - v17 - v18) ^ (v18 >> 5);
            v20 = (v17 - v18 - v19) ^ (v19 >> 3);
            v21 = (v19 - v20 - ((v18 - v19 - v20) ^ (v20 << 10))) ^ (((v18 - v19 - v20) ^ (v20 << 10)) >> 15);
            v22 = 3 * (v21 & (*(_DWORD *)(*(_DWORD *)dword_77048 + 4) - 1));
            v23 = v16[3 * (v21 & (*(_DWORD *)(*(_DWORD *)dword_77048 + 4) - 1))];
            if ( v23 )
              v22 = *(_DWORD *)(v12 + 20);
            else
              v1 = 0;
            if ( v23 )
              v1 = v23 - v22;
            while ( v1 )
            {
              if ( *(_DWORD *)(v1 + 24) == 4 && !memcmp(*(const void **)(v1 + 20), &s2, 4u) )
              {
                v46 = *(_DWORD *)(v1 + 4);
                if ( v46 || *(_DWORD *)(v1 + 8) )
                {
                  v47 = *(_DWORD *)(v12 + 20);
                  v48 = (_DWORD *)(*(_DWORD *)(v12 + 16) - v47);
                  if ( (_DWORD *)v1 == v48 )
                  {
                    *(_DWORD *)(v12 + 16) = v46 + v47;
                    v46 = *(_DWORD *)(v1 + 4);
                  }
                  v49 = v46 == 0;
                  if ( v46 )
                  {
                    v48 = *v11;
                    v47 = *(_DWORD *)(v1 + 8);
                  }
                  else
                  {
                    v46 = *(_DWORD *)(v1 + 8);
                  }
                  if ( v49 )
                  {
                    v11 = (void **)v46;
                    dword_77048 = v46;
                  }
                  else
                  {
                    v46 += v48[5];
                  }
                  if ( !v49 )
                  {
                    *(_DWORD *)(v46 + 8) = v47;
                    v46 = *(_DWORD *)(v1 + 8);
                  }
                  if ( v46 )
                    *(_DWORD *)(v46 + *((_DWORD *)*v11 + 5) + 4) = *(_DWORD *)(v1 + 4);
                  v50 = 3 * ((*((_DWORD *)*v11 + 1) - 1) & *(_DWORD *)(v1 + 28));
                  v51 = *(_DWORD *)*v11 + 12 * ((*((_DWORD *)*v11 + 1) - 1) & *(_DWORD *)(v1 + 28));
                  --*(_DWORD *)(v51 + 4);
                  v52 = *(_DWORD *)*v11;
                  if ( v1 == *(_DWORD *)(v52 + 4 * v50) )
                    *(_DWORD *)(v52 + 4 * v50) = *(_DWORD *)(v1 + 16);
                  v53 = *(_DWORD *)(v1 + 12);
                  if ( v53 )
                    *(_DWORD *)(v53 + 16) = *(_DWORD *)(v1 + 16);
                  v54 = *(_DWORD *)(v1 + 16);
                  if ( v54 )
                    *(_DWORD *)(v54 + 12) = *(_DWORD *)(v1 + 12);
                  --*((_DWORD *)*v11 + 3);
                }
                else
                {
                  free(v16);
                  free(*v11);
                  dword_77048 = 0;
                }
                --a1[189];
                break;
              }
              v24 = *(_DWORD *)(v1 + 16);
              if ( !v24 )
              {
                v1 = 0;
                break;
              }
              v1 = v24 - *(_DWORD *)(v12 + 20);
            }
          }
          else
          {
            v1 = 0;
          }
          if ( pthread_mutex_unlock(&stru_77030) )
            sub_B5C4("parse_stratum_response", 6928);
          off_75ED8();
          if ( v1 )
          {
            v25 = *(_DWORD *)(v1 + 36);
            v26 = time(0);
            if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
            {
              snprintf(
                (char *)v95,
                0x1000u,
                "Pool %d stratum share result lag time %d seconds",
                **(_DWORD **)(v25 + 1748),
                v26 - *(_DWORD *)(v1 + 48));
              sub_38730(7, (const char *)v95, 0);
            }
            v27 = 0;
            v95[0] = bswap32(*(_DWORD *)(v25 + 220));
            v95[1] = bswap32(*(_DWORD *)(v25 + 216));
            v95[2] = bswap32(*(_DWORD *)(v25 + 212));
            v95[3] = bswap32(*(_DWORD *)(v25 + 208));
            v95[4] = bswap32(*(_DWORD *)(v25 + 204));
            v95[5] = bswap32(*(_DWORD *)(v25 + 200));
            v95[6] = bswap32(*(_DWORD *)(v25 + 196));
            v95[7] = bswap32(*(_DWORD *)(v25 + 192));
            do
            {
              if ( *((_BYTE *)v95 + v27) )
                break;
              ++v27;
            }
            while ( v27 != 29 );
            v28 = (double *)(v25 + 1864);
            v29 = *(double *)(v25 + 1864);
            v30 = *(_DWORD *)((char *)v95 + v27);
            round(v96);
            LODWORD(v32) = sub_5CC48(v29);
            HIDWORD(v32) = v31;
            sub_11580(*(_QWORD *)(v25 + 1720), v89, 0x10u, 0);
            v33 = "";
            v34 = bswap32(v30);
            if ( *(_BYTE *)(v25 + 1771) )
              v33 = " BLOCK!";
            snprintf(v90, 0x40u, "%08lx Diff %s/%llu%s", v34, v89, v32, v33);
            v35 = *(_DWORD **)(v25 + 1748);
            v79 = *(_DWORD *)(sub_1B124(*(_DWORD *)(v25 + 1744)) + 36);
            if ( src && (*src == 5 || *(_BYTE *)(v25 + 1812) && *src == 7) )
            {
              if ( pthread_mutex_lock(&stru_7AD4C) )
                sub_B414("share_result", 3481);
              v67 = dbl_7B5E8;
              ++*(_DWORD *)(v79 + 36);
              ++*((_QWORD *)v35 + 1);
              v68 = *(double *)(v79 + 200) + *v28;
              ++qword_7B420;
              *(double *)(v79 + 200) = v68;
              v69 = *v28 + v67;
              *((double *)v35 + 13) = *((double *)v35 + 13) + *v28;
              dbl_7B5E8 = v69;
              if ( pthread_mutex_unlock(&stru_7AD4C) )
                sub_B5C4("share_result", 3488);
              off_75ED8();
              v70 = *v35;
              v35[6] = 0;
              *(_DWORD *)(v79 + 216) = v70;
              v71 = time(0);
              v72 = (unsigned __int8)byte_78E09;
              *(_DWORD *)(v79 + 220) = v71;
              *(double *)(v79 + 224) = *v28;
              v35[96] = v71;
              *((double *)v35 + 49) = *v28;
              if ( v72 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
              {
                strcpy((char *)v95, "PROOF OF WORK RESULT: true (yay!!!)");
                sub_38730(7, (const char *)v95, 0);
              }
              if ( !byte_7BC78 && !byte_7BB18 )
              {
                if ( dword_7B198 <= 1 )
                {
                  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
                  {
                    snprintf(
                      (char *)v95,
                      0x1000u,
                      "Accepted %s %s %d %s%s",
                      v90,
                      *(const char **)(*(_DWORD *)(v79 + 4) + 8),
                      *(_DWORD *)(v79 + 8),
                      "",
                      "");
                    sub_38730(7, (const char *)v95, 0);
                  }
                }
                else if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
                {
                  snprintf(
                    (char *)v95,
                    0x1000u,
                    "Accepted %s %s %d pool %d %s%s",
                    v90,
                    *(const char **)(*(_DWORD *)(v79 + 4) + 8),
                    *(_DWORD *)(v79 + 8),
                    **(_DWORD **)(v25 + 1748),
                    "",
                    "");
                  sub_38730(7, (const char *)v95, 0);
                }
              }
              sub_1B600("accept", (_DWORD *)v25);
              if ( dword_77288 && (double)dword_77288 <= dbl_7B5E8 )
              {
                if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
                {
                  snprintf(
                    (char *)v95,
                    0x1000u,
                    "Successfully mined %d accepted shares as requested and exiting.",
                    dword_77288);
                  sub_38730(4, (const char *)v95, 0);
                }
                sub_178F8();
              }
              if ( v35[33] == 2 )
              {
                if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3
                  || (snprintf((char *)v95, 0x1000u, "Rejecting pool %d now accepting shares, re-enabling!", *v35),
                      sub_38730(4, (const char *)v95, 0),
                      v35[33] != 1) )
                {
                  v35[33] = 1;
                  ++dword_7B5E4;
                }
                sub_19BF8(0);
              }
              if ( *(_BYTE *)(v25 + 1771) )
                sub_17210();
            }
            else
            {
              if ( pthread_mutex_lock(&stru_7AD4C) )
                sub_B414("share_result", 3531);
              v36 = dbl_7B670;
              ++*(_DWORD *)(v79 + 40);
              ++*((_QWORD *)v35 + 2);
              v37 = *(double *)(v79 + 208) + *v28;
              ++qword_7B6F8;
              *(double *)(v79 + 208) = v37;
              v38 = *v28;
              v39 = *((double *)v35 + 14) + *v28;
              ++v35[6];
              *((double *)v35 + 14) = v39;
              dbl_7B670 = v38 + v36;
              if ( pthread_mutex_unlock(&stru_7AD4C) )
                sub_B5C4("share_result", 3539);
              off_75ED8();
              if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
              {
                strcpy((char *)v95, "PROOF OF WORK RESULT: false (booooo)");
                sub_38730(7, (const char *)v95, 0);
              }
              if ( !byte_7BC78 && !byte_7BB18 )
              {
                strcpy(v89, "reject");
                memset(&v89[7], (unsigned __int8)byte_7BB18, 0x1Du);
                v87[0] = byte_7BB18;
                if ( dword_7B198 <= 1 )
                  v86[0] = byte_7BB18;
                else
                  snprintf(v86, 0x14u, "pool %d", **(_DWORD **)(v25 + 1748));
                if ( !*(_BYTE *)(v25 + 1812) )
                  src = (_DWORD *)sub_59E20(v78, "reject-reason");
                if ( src )
                {
                  srca = (const char *)sub_5A178(src);
                  v40 = strlen(srca);
                  qmemcpy(v87, " (", sizeof(v87));
                  if ( v40 >= 0x1C )
                    v41 = 28;
                  else
                    v41 = v40;
                  v42 = &v96[v41];
                  n = v41;
                  memcpy(dest, srca, v41);
                  *((_WORD *)v42 - 2303) = 41;
                  memcpy(&v89[7], srca, n);
                  v89[6] = 58;
                  *(v42 - 4569) = 0;
                }
                else if ( *(_BYTE *)(v25 + 1772) && v82 )
                {
                  if ( *v82 == 1 )
                  {
                    v73 = sub_5A008(v82, 1u);
                    if ( !v73 || *v73 != 2 )
                      goto LABEL_76;
                  }
                  else
                  {
                    if ( *v82 != 2 )
                      goto LABEL_76;
                    v73 = v82;
                  }
                  v74 = (const char *)sub_5A178(v73);
                  snprintf(v87, 0x1Fu, " (%s)", v74);
                }
LABEL_76:
                if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
                {
                  snprintf(
                    (char *)v95,
                    0x1000u,
                    "Rejected %s %s %d %s%s %s%s",
                    v90,
                    *(const char **)(*(_DWORD *)(v79 + 4) + 8),
                    *(_DWORD *)(v79 + 8),
                    v86,
                    v87,
                    "",
                    "");
                  sub_38730(7, (const char *)v95, 0);
                }
                sub_1B600(v89, (_DWORD *)v25);
              }
              v43 = v35[6];
              if ( v43 > 10 && !*(_BYTE *)(v25 + 1769) )
              {
                if ( byte_7B250 )
                {
                  if ( dword_7B5E4 > 1 )
                  {
                    LODWORD(v44) = sub_5CB64(qword_7B420);
                    if ( (double)v43 > v44 / dbl_755F8 * 60.0 * 3.0 )
                    {
                      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
                      {
                        snprintf((char *)v95, 0x1000u, "Pool %d rejected %d sequential shares, disabling!", *v35, v43);
                        sub_38730(4, (const char *)v95, 0);
                      }
                      if ( v35[33] == 1 )
                        --dword_7B5E4;
                      v35[33] = 2;
                      if ( v35 == (_DWORD *)sub_1DA58() )
                        sub_19BF8(0);
                      v35[6] = 0;
                    }
                  }
                }
              }
            }
            v45 = 1;
            sub_15780(*(void ***)(v1 + 36));
            *(_DWORD *)(v1 + 36) = 0;
            free((void *)v1);
          }
          else if ( src )
          {
            if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
              sub_B414("parse_stratum_response", 6938);
            if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 67)) )
              sub_B69C("parse_stratum_response", 6938);
            if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
              sub_B5C4("parse_stratum_response", 6938);
            v64 = *((double *)a1 + 230);
            if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
              sub_B630("parse_stratum_response", 6940);
            off_75ED8();
            if ( *src == 5 )
            {
              if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
              {
                snprintf((char *)v95, 0x1000u, "Accepted untracked stratum share from pool %d", *a1);
                sub_38730(7, (const char *)v95, 0);
              }
              if ( pthread_mutex_lock(&stru_7AD4C) )
                sub_B414("parse_stratum_response", 6948);
              v75 = *((double *)a1 + 13) + v64;
              v76 = dbl_7B5E8;
              ++*((_QWORD *)a1 + 1);
              ++qword_7B420;
              *((double *)a1 + 13) = v75;
              dbl_7B5E8 = v64 + v76;
              if ( pthread_mutex_unlock(&stru_7AD4C) )
                sub_B5C4("parse_stratum_response", 6953);
            }
            else
            {
              if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
              {
                snprintf((char *)v95, 0x1000u, "Rejected untracked stratum share from pool %d", *a1);
                sub_38730(7, (const char *)v95, 0);
              }
              if ( pthread_mutex_lock(&stru_7AD4C) )
                sub_B414("parse_stratum_response", 6959);
              v65 = *((double *)a1 + 14) + v64;
              v66 = dbl_7B670;
              ++*((_QWORD *)a1 + 2);
              ++qword_7B6F8;
              *((double *)a1 + 14) = v65;
              dbl_7B670 = v64 + v66;
              if ( pthread_mutex_unlock(&stru_7AD4C) )
                sub_B5C4("parse_stratum_response", 6964);
            }
            v45 = 0;
            off_75ED8();
          }
          else
          {
            v45 = 0;
          }
        }
        v61 = v78[1];
        if ( v61 != -1 )
        {
          v62 = v61 - 1;
          v78[1] = v62;
          if ( !v62 )
            sub_5A3E4((void **)v78);
        }
        if ( v45 )
        {
LABEL_10:
          if ( *((_BYTE *)a1 + 696) )
          {
            v55 = sub_1A3D4();
            *((_BYTE *)a1 + 696) = 0;
            v56 = (int)v55;
            sub_1ACC4((int)a1, (int)v55);
            *(_BYTE *)(v56 + 1768) = 1;
            sub_1DB0C(v56);
            sub_15780((void **)v56);
          }
          goto LABEL_12;
        }
        v63 = (unsigned __int8)byte_78E09;
        goto LABEL_156;
      }
      if ( !byte_78E09 )
        goto LABEL_12;
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        goto LABEL_157;
      snprintf((char *)v95, 0x1000u, "JSON decode failed(%d): %s", v93[0], v94);
      sub_38730(7, (const char *)v95, 0);
      v63 = (unsigned __int8)byte_78E09;
LABEL_156:
      if ( !v63 )
        goto LABEL_12;
LABEL_157:
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
      {
        snprintf((char *)v95, 0x1000u, "Unknown stratum msg: %s", (const char *)v7);
        sub_38730(7, (const char *)v95, 0);
      }
LABEL_12:
      free(v7);
    }
    else
    {
      if ( !byte_78E09 )
        goto LABEL_126;
      if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
      {
LABEL_122:
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 6 )
        {
          snprintf((char *)v95, 0x1000u, "Stratum connection to pool %d interrupted", *a1);
          sub_38730(7, (const char *)v95, 0);
        }
        goto LABEL_126;
      }
      snprintf((char *)v95, 0x1000u, "Stratum select failed on pool %d with value %d", *a1, v6);
      sub_38730(7, (const char *)v95, 0);
      v57 = (unsigned __int8)byte_78E09;
LABEL_121:
      if ( v57 )
        goto LABEL_122;
LABEL_126:
      v58 = dword_7B43C;
      ++a1[40];
      dword_7B43C = v58 + 1;
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
        sub_B414("supports_resume", 7101);
      if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B69C("supports_resume", 7101);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
        sub_B5C4("supports_resume", 7101);
      v59 = a1[165];
      if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B630("supports_resume", 7103);
      off_75ED8();
      if ( !v59 || byte_7B644 )
        sub_182F4((int)a1);
      sub_185C8(a1);
      if ( a1 == (_DWORD *)sub_1DA58() )
        sub_17210();
      while ( !sub_2CEC8((int)a1) )
      {
        if ( *((_BYTE *)a1 + 137) )
          return 0;
        sub_2A92C();
      }
    }
  }
  sub_2AEE0((int)a1);
  return 0;
}
