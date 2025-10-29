void __fastcall sub_1FFD0(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r11
  pthread_t v15; // r0
  fd_set *v16; // r3
  int v17; // r3
  int v18; // r0
  int *v19; // r4
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int *v23; // r0
  _DWORD *v24; // r0
  void **v25; // r5
  int v26; // r6
  unsigned int v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r0
  _DWORD *v30; // r7
  int v31; // r1
  unsigned int v32; // r2
  unsigned int v33; // r3
  int v34; // r1
  unsigned int v35; // r1
  int v36; // r3
  int v37; // r12
  int v38; // r12
  int v39; // r7
  time_t v40; // r0
  int v41; // r3
  double *v42; // r9
  double v43; // d0
  unsigned int v44; // r6
  int v45; // r1
  __int64 v46; // d8
  const char *v47; // r2
  unsigned int v48; // r3
  _DWORD *v49; // r6
  double v50; // d18
  double v51; // d16
  double v52; // d16
  double v53; // d17
  size_t v54; // r0
  size_t v55; // r3
  _BYTE *v56; // r9
  int v57; // r9
  double v58; // r0
  int v59; // r5
  int v60; // r3
  int v61; // r2
  _DWORD *v62; // r1
  bool v63; // zf
  int v64; // r3
  int v65; // r2
  int v66; // r2
  int v67; // r3
  int v68; // r3
  _DWORD *v69; // r0
  int v70; // r5
  int v71; // r3
  int v72; // r2
  int v73; // r4
  char *v74; // r6
  int v75; // r3
  int v76; // r3
  int v77; // r3
  double v78; // d8
  double v79; // d16
  double v80; // d17
  double v81; // d18
  double v82; // d16
  double v83; // d16
  int v84; // r3
  time_t v85; // r0
  int v86; // r1
  _DWORD *v87; // r0
  const char *v88; // r0
  double v89; // d16
  double v90; // d17
  size_t n; // [sp+1Ch] [bp-1268h]
  int *v92; // [sp+38h] [bp-124Ch]
  int v93; // [sp+40h] [bp-1244h]
  _DWORD *src; // [sp+44h] [bp-1240h]
  const char *srca; // [sp+44h] [bp-1240h]
  _DWORD *v96; // [sp+48h] [bp-123Ch]
  int s2; // [sp+50h] [bp-1234h] BYREF
  struct timeval timeout; // [sp+54h] [bp-1230h] BYREF
  char s[16]; // [sp+5Ch] [bp-1228h] BYREF
  char v100[20]; // [sp+6Ch] [bp-1218h] BYREF
  char v101[2]; // [sp+80h] [bp-1204h] BYREF
  char dest[30]; // [sp+82h] [bp-1202h] BYREF
  char v103[36]; // [sp+A0h] [bp-11E4h] BYREF
  char v104[60]; // [sp+C4h] [bp-11C0h] BYREF
  char v105; // [sp+100h] [bp-1184h] BYREF
  fd_set readfds; // [sp+104h] [bp-1180h] BYREF
  int v107[23]; // [sp+184h] [bp-1100h] BYREF
  char v108[160]; // [sp+1E0h] [bp-10A4h] BYREF
  _DWORD v109[1024]; // [sp+280h] [bp-1004h] BYREF
  _BYTE v110[4]; // [sp+1280h] [bp-4h] BYREF

  v15 = pthread_self();
  pthread_detach(v15);
  snprintf(s, 0x10u, "%d/RStratum", *a1);
  sub_2EF24(s);
  while ( !*((_BYTE *)a1 + 137) )
  {
    if ( !sub_2AD68((int)a1) && !sub_1FF34((int)a1) )
    {
      sub_2AE38((int)a1);
      sub_17F28((int)a1);
      sub_1922C(a1);
      while ( !sub_1FF34((int)a1) && (!a1[33] || a1 != (_DWORD *)sub_1D9A0() && dword_73D34 != 3 && dword_73D34 != 4) )
      {
        if ( pthread_mutex_lock(&stru_73EA0) )
          sub_B35C("wait_lpcurrent", 9235);
        pthread_cond_wait(&stru_73EB8, &stru_73EA0);
        if ( pthread_mutex_unlock(&stru_73EA0) )
          sub_B50C("wait_lpcurrent", 9237);
        off_72D18();
      }
      while ( !sub_2CE20((int)a1) )
      {
        v22 = *((unsigned __int8 *)a1 + 137);
        if ( *((_BYTE *)a1 + 137) )
          goto LABEL_27;
        sub_2A884();
      }
    }
    v16 = (fd_set *)&v105;
    do
    {
      v16->__fds_bits[1] = 0;
      v16 = (fd_set *)((char *)v16 + 4);
    }
    while ( v16 != (fd_set *)&readfds.__fds_bits[31] );
    v17 = a1[153];
    timeout.tv_usec = 0;
    timeout.tv_sec = 90;
    readfds.__fds_bits[v17 / 32] |= 1 << (v17 % 32);
    if ( sub_2AD68((int)a1) || (v18 = select(a1[153] + 1, &readfds, 0, 0, &timeout), v18 > 0) )
    {
      v19 = (int *)sub_2AF98((int)a1);
      if ( !v19 )
      {
        v71 = (unsigned __int8)byte_75C49;
        goto LABEL_121;
      }
      sub_1FCAC(a1);
      if ( sub_2CE98(a1, v19) )
        goto LABEL_10;
      v23 = sub_565E8(v19, 0, (char *)v107);
      v92 = v23;
      if ( v23 )
      {
        src = (_DWORD *)sub_571D8(v23, "result");
        v96 = (_DWORD *)sub_571D8(v92, "error");
        v24 = (_DWORD *)sub_571D8(v92, "id");
        if ( !v24 || *v24 == 7 )
        {
          if ( v96 )
          {
            v74 = (char *)sub_54C0C(v96, 3);
          }
          else
          {
            v74 = (char *)malloc(0x11u);
            if ( v74 )
              strcpy(v74, "(unknown reason)");
          }
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf((char *)v109, 0x1000u, "JSON-RPC non method decode failed: %s", v74);
            sub_385C8(7, (const char *)v109, 0);
          }
          v59 = 0;
          free(v74);
        }
        else
        {
          s2 = sub_57600((int)v24);
          if ( pthread_mutex_lock(&mutex) )
            sub_B35C("parse_stratum_response", 6921);
          v25 = (void **)dword_73E68;
          if ( dword_73E68 )
          {
            v26 = *(_DWORD *)dword_73E68;
            v27 = ((unsigned __int8)s2 + 17973517 + (HIBYTE(s2) << 24) + (BYTE2(s2) << 16) + (BYTE1(s2) << 8))
                ^ (unsigned int)&unk_7F76D;
            v28 = (-1622558010 - v27) ^ (v27 << 8);
            v29 = (-17973517 - v27 - v28) ^ (v28 >> 13);
            v30 = **(_DWORD ***)dword_73E68;
            v31 = (v27 - v28 - v29) ^ (v29 >> 12);
            v32 = (v28 - v29 - v31) ^ (v31 << 16);
            v33 = (v29 - v31 - v32) ^ (v32 >> 5);
            v34 = (v31 - v32 - v33) ^ (v33 >> 3);
            v35 = (v33 - v34 - ((v32 - v33 - v34) ^ (v34 << 10))) ^ (((v32 - v33 - v34) ^ (v34 << 10)) >> 15);
            v36 = 3 * (v35 & (*(_DWORD *)(*(_DWORD *)dword_73E68 + 4) - 1));
            v37 = v30[3 * (v35 & (*(_DWORD *)(*(_DWORD *)dword_73E68 + 4) - 1))];
            if ( v37 )
              v36 = *(_DWORD *)(v26 + 20);
            else
              v13 = 0;
            if ( v37 )
              v13 = v37 - v36;
            while ( v13 )
            {
              if ( *(_DWORD *)(v13 + 24) == 4 && !memcmp(*(const void **)(v13 + 20), &s2, 4u) )
              {
                v60 = *(_DWORD *)(v13 + 4);
                if ( v60 || *(_DWORD *)(v13 + 8) )
                {
                  v61 = *(_DWORD *)(v26 + 20);
                  v62 = (_DWORD *)(*(_DWORD *)(v26 + 16) - v61);
                  if ( (_DWORD *)v13 == v62 )
                  {
                    *(_DWORD *)(v26 + 16) = v60 + v61;
                    v60 = *(_DWORD *)(v13 + 4);
                  }
                  v63 = v60 == 0;
                  if ( v60 )
                  {
                    v62 = *v25;
                    v61 = *(_DWORD *)(v13 + 8);
                  }
                  else
                  {
                    v60 = *(_DWORD *)(v13 + 8);
                  }
                  if ( v63 )
                  {
                    v25 = (void **)v60;
                    dword_73E68 = v60;
                  }
                  else
                  {
                    v60 += v62[5];
                  }
                  if ( !v63 )
                  {
                    *(_DWORD *)(v60 + 8) = v61;
                    v60 = *(_DWORD *)(v13 + 8);
                  }
                  if ( v60 )
                    *(_DWORD *)(v60 + *((_DWORD *)*v25 + 5) + 4) = *(_DWORD *)(v13 + 4);
                  v64 = 3 * ((*((_DWORD *)*v25 + 1) - 1) & *(_DWORD *)(v13 + 28));
                  v65 = *(_DWORD *)*v25 + 12 * ((*((_DWORD *)*v25 + 1) - 1) & *(_DWORD *)(v13 + 28));
                  --*(_DWORD *)(v65 + 4);
                  v66 = *(_DWORD *)*v25;
                  if ( v13 == *(_DWORD *)(v66 + 4 * v64) )
                    *(_DWORD *)(v66 + 4 * v64) = *(_DWORD *)(v13 + 16);
                  v67 = *(_DWORD *)(v13 + 12);
                  if ( v67 )
                    *(_DWORD *)(v67 + 16) = *(_DWORD *)(v13 + 16);
                  v68 = *(_DWORD *)(v13 + 16);
                  if ( v68 )
                    *(_DWORD *)(v68 + 12) = *(_DWORD *)(v13 + 12);
                  --*((_DWORD *)*v25 + 3);
                }
                else
                {
                  free(v30);
                  free(*v25);
                  dword_73E68 = 0;
                }
                --a1[189];
                break;
              }
              v38 = *(_DWORD *)(v13 + 16);
              if ( !v38 )
              {
                v13 = 0;
                break;
              }
              v13 = v38 - *(_DWORD *)(v26 + 20);
            }
          }
          else
          {
            v13 = 0;
          }
          if ( pthread_mutex_unlock(&mutex) )
            sub_B50C("parse_stratum_response", 6928);
          off_72D18();
          if ( v13 )
          {
            v39 = *(_DWORD *)(v13 + 36);
            v40 = time(0);
            if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
            {
              snprintf(
                (char *)v109,
                0x1000u,
                "Pool %d stratum share result lag time %d seconds",
                **(_DWORD **)(v39 + 1748),
                v40 - *(_DWORD *)(v13 + 48));
              sub_385C8(7, (const char *)v109, 0);
            }
            v41 = 0;
            v109[0] = bswap32(*(_DWORD *)(v39 + 220));
            v109[1] = bswap32(*(_DWORD *)(v39 + 216));
            v109[2] = bswap32(*(_DWORD *)(v39 + 212));
            v109[3] = bswap32(*(_DWORD *)(v39 + 208));
            v109[4] = bswap32(*(_DWORD *)(v39 + 204));
            v109[5] = bswap32(*(_DWORD *)(v39 + 200));
            v109[6] = bswap32(*(_DWORD *)(v39 + 196));
            v109[7] = bswap32(*(_DWORD *)(v39 + 192));
            do
            {
              if ( *((_BYTE *)v109 + v41) )
                break;
              ++v41;
            }
            while ( v41 != 29 );
            v42 = (double *)(v39 + 1864);
            v43 = *(double *)(v39 + 1864);
            v44 = *(_DWORD *)((char *)v109 + v41);
            round(v110);
            LODWORD(v46) = sub_5A000(v43);
            HIDWORD(v46) = v45;
            sub_114B8(*(_QWORD *)(v39 + 1720), v103, 0x10u, 0);
            v47 = "";
            v48 = bswap32(v44);
            if ( *(_BYTE *)(v39 + 1771) )
              v47 = " BLOCK!";
            snprintf(v104, 0x40u, "%08lx Diff %s/%llu%s", v48, v103, v46, v47);
            v49 = *(_DWORD **)(v39 + 1748);
            v93 = *(_DWORD *)(sub_1AA90(*(_DWORD *)(v39 + 1744)) + 36);
            if ( src && (*src == 5 || *(_BYTE *)(v39 + 1812) && *src == 7) )
            {
              if ( pthread_mutex_lock(&stru_77B74) )
                sub_B35C("share_result", 3481);
              v81 = dbl_78410;
              ++*(_DWORD *)(v93 + 36);
              ++*((_QWORD *)v49 + 1);
              v82 = *(double *)(v93 + 200) + *v42;
              ++qword_78248;
              *(double *)(v93 + 200) = v82;
              v83 = *v42 + v81;
              *((double *)v49 + 13) = *((double *)v49 + 13) + *v42;
              dbl_78410 = v83;
              if ( pthread_mutex_unlock(&stru_77B74) )
                sub_B50C("share_result", 3488);
              off_72D18();
              v84 = *v49;
              v49[6] = 0;
              *(_DWORD *)(v93 + 216) = v84;
              v85 = time(0);
              v86 = (unsigned __int8)byte_75C49;
              *(_DWORD *)(v93 + 220) = v85;
              *(double *)(v93 + 224) = *v42;
              v49[96] = v85;
              *((double *)v49 + 49) = *v42;
              if ( v86 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                strcpy((char *)v109, "PROOF OF WORK RESULT: true (yay!!!)");
                sub_385C8(7, (const char *)v109, 0);
              }
              if ( !byte_78AA0 && !byte_78940 )
              {
                if ( dword_77FC0 <= 1 )
                {
                  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
                  {
                    snprintf(
                      (char *)v109,
                      0x1000u,
                      "Accepted %s %s %d %s%s",
                      v104,
                      *(const char **)(*(_DWORD *)(v93 + 4) + 8),
                      *(_DWORD *)(v93 + 8),
                      "",
                      "");
                    sub_385C8(7, (const char *)v109, 0);
                  }
                }
                else if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
                {
                  snprintf(
                    (char *)v109,
                    0x1000u,
                    "Accepted %s %s %d pool %d %s%s",
                    v104,
                    *(const char **)(*(_DWORD *)(v93 + 4) + 8),
                    *(_DWORD *)(v93 + 8),
                    **(_DWORD **)(v39 + 1748),
                    "",
                    "");
                  sub_385C8(7, (const char *)v109, 0);
                }
              }
              sub_1AF6C("accept", (_DWORD *)v39);
              if ( dword_740C0 && (double)dword_740C0 <= dbl_78410 )
              {
                if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                {
                  snprintf(
                    (char *)v109,
                    0x1000u,
                    "Successfully mined %d accepted shares as requested and exiting.",
                    dword_740C0);
                  sub_385C8(4, (const char *)v109, 0);
                }
                sub_17830();
              }
              if ( v49[33] == 2 )
              {
                if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 3
                  || (snprintf((char *)v109, 0x1000u, "Rejecting pool %d now accepting shares, re-enabling!", *v49),
                      sub_385C8(4, (const char *)v109, 0),
                      v49[33] != 1) )
                {
                  v49[33] = 1;
                  ++dword_7840C;
                }
                sub_1A600(0);
              }
              if ( *(_BYTE *)(v39 + 1771) )
                sub_17148();
            }
            else
            {
              if ( pthread_mutex_lock(&stru_77B74) )
                sub_B35C("share_result", 3531);
              v50 = dbl_78498;
              ++*(_DWORD *)(v93 + 40);
              ++*((_QWORD *)v49 + 2);
              v51 = *(double *)(v93 + 208) + *v42;
              ++qword_78520;
              *(double *)(v93 + 208) = v51;
              v52 = *v42;
              v53 = *((double *)v49 + 14) + *v42;
              ++v49[6];
              *((double *)v49 + 14) = v53;
              dbl_78498 = v52 + v50;
              if ( pthread_mutex_unlock(&stru_77B74) )
                sub_B50C("share_result", 3539);
              off_72D18();
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                strcpy((char *)v109, "PROOF OF WORK RESULT: false (booooo)");
                sub_385C8(7, (const char *)v109, 0);
              }
              if ( !byte_78AA0 && !byte_78940 )
              {
                strcpy(v103, "reject");
                memset(&v103[7], (unsigned __int8)byte_78940, 0x1Du);
                v101[0] = byte_78940;
                if ( dword_77FC0 <= 1 )
                  v100[0] = byte_78940;
                else
                  snprintf(v100, 0x14u, "pool %d", **(_DWORD **)(v39 + 1748));
                if ( !*(_BYTE *)(v39 + 1812) )
                  src = (_DWORD *)sub_571D8(v92, "reject-reason");
                if ( src )
                {
                  srca = (const char *)sub_57530(src);
                  v54 = strlen(srca);
                  qmemcpy(v101, " (", sizeof(v101));
                  if ( v54 >= 0x1C )
                    v55 = 28;
                  else
                    v55 = v54;
                  v56 = &v110[v55];
                  n = v55;
                  memcpy(dest, srca, v55);
                  *((_WORD *)v56 - 2303) = 41;
                  memcpy(&v103[7], srca, n);
                  v103[6] = 58;
                  *(v56 - 4569) = 0;
                }
                else if ( *(_BYTE *)(v39 + 1772) && v96 )
                {
                  if ( *v96 == 1 )
                  {
                    v87 = sub_573C0(v96, 1u);
                    if ( !v87 || *v87 != 2 )
                      goto LABEL_76;
                  }
                  else
                  {
                    if ( *v96 != 2 )
                      goto LABEL_76;
                    v87 = v96;
                  }
                  v88 = (const char *)sub_57530(v87);
                  snprintf(v101, 0x1Fu, " (%s)", v88);
                }
LABEL_76:
                if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
                {
                  snprintf(
                    (char *)v109,
                    0x1000u,
                    "Rejected %s %s %d %s%s %s%s",
                    v104,
                    *(const char **)(*(_DWORD *)(v93 + 4) + 8),
                    *(_DWORD *)(v93 + 8),
                    v100,
                    v101,
                    "",
                    "");
                  sub_385C8(7, (const char *)v109, 0);
                }
                sub_1AF6C(v103, (_DWORD *)v39);
              }
              v57 = v49[6];
              if ( v57 > 10 && !*(_BYTE *)(v39 + 1769) )
              {
                if ( byte_78078 )
                {
                  if ( dword_7840C > 1 )
                  {
                    LODWORD(v58) = sub_59F1C(qword_78248);
                    if ( (double)v57 > v58 / dbl_72438 * 60.0 * 3.0 )
                    {
                      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                      {
                        snprintf((char *)v109, 0x1000u, "Pool %d rejected %d sequential shares, disabling!", *v49, v57);
                        sub_385C8(4, (const char *)v109, 0);
                      }
                      if ( v49[33] == 1 )
                        --dword_7840C;
                      v49[33] = 2;
                      if ( v49 == (_DWORD *)sub_1D9A0() )
                        sub_1A600(0);
                      v49[6] = 0;
                    }
                  }
                }
              }
            }
            v59 = 1;
            sub_156B8(*(void ***)(v13 + 36));
            *(_DWORD *)(v13 + 36) = 0;
            free((void *)v13);
          }
          else if ( src )
          {
            if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
              sub_B35C("parse_stratum_response", 6938);
            if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 67)) )
              sub_B5E4("parse_stratum_response", 6938);
            if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
              sub_B50C("parse_stratum_response", 6938);
            v78 = *((double *)a1 + 230);
            if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
              sub_B578("parse_stratum_response", 6940);
            off_72D18();
            if ( *src == 5 )
            {
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                snprintf((char *)v109, 0x1000u, "Accepted untracked stratum share from pool %d", *a1);
                sub_385C8(7, (const char *)v109, 0);
              }
              if ( pthread_mutex_lock(&stru_77B74) )
                sub_B35C("parse_stratum_response", 6948);
              v89 = *((double *)a1 + 13) + v78;
              v90 = dbl_78410;
              ++*((_QWORD *)a1 + 1);
              ++qword_78248;
              *((double *)a1 + 13) = v89;
              dbl_78410 = v78 + v90;
              if ( pthread_mutex_unlock(&stru_77B74) )
                sub_B50C("parse_stratum_response", 6953);
            }
            else
            {
              if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
              {
                snprintf((char *)v109, 0x1000u, "Rejected untracked stratum share from pool %d", *a1);
                sub_385C8(7, (const char *)v109, 0);
              }
              if ( pthread_mutex_lock(&stru_77B74) )
                sub_B35C("parse_stratum_response", 6959);
              v79 = *((double *)a1 + 14) + v78;
              v80 = dbl_78498;
              ++*((_QWORD *)a1 + 2);
              ++qword_78520;
              *((double *)a1 + 14) = v79;
              dbl_78498 = v78 + v80;
              if ( pthread_mutex_unlock(&stru_77B74) )
                sub_B50C("parse_stratum_response", 6964);
            }
            v59 = 0;
            off_72D18();
          }
          else
          {
            v59 = 0;
          }
        }
        v75 = v92[1];
        if ( v75 != -1 )
        {
          v76 = v75 - 1;
          v92[1] = v76;
          if ( !v76 )
            sub_5779C((void **)v92);
        }
        if ( v59 )
        {
LABEL_10:
          if ( *((_BYTE *)a1 + 696) )
          {
            v69 = sub_1A520();
            *((_BYTE *)a1 + 696) = 0;
            v70 = (int)v69;
            sub_1D5F0((int)a1, (int)v69);
            *(_BYTE *)(v70 + 1768) = 1;
            sub_1DA54(v70);
            sub_156B8((void **)v70);
          }
          goto LABEL_12;
        }
        v77 = (unsigned __int8)byte_75C49;
        goto LABEL_156;
      }
      if ( !byte_75C49 )
        goto LABEL_12;
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
        goto LABEL_157;
      snprintf((char *)v109, 0x1000u, "JSON decode failed(%d): %s", v107[0], v108);
      sub_385C8(7, (const char *)v109, 0);
      v77 = (unsigned __int8)byte_75C49;
LABEL_156:
      if ( !v77 )
        goto LABEL_12;
LABEL_157:
      if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
      {
        snprintf((char *)v109, 0x1000u, "Unknown stratum msg: %s", (const char *)v19);
        sub_385C8(7, (const char *)v109, 0);
      }
LABEL_12:
      free(v19);
    }
    else
    {
      if ( !byte_75C49 )
        goto LABEL_126;
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
      {
LABEL_122:
        if ( byte_77B70 || byte_75C48 || dword_73504 > 6 )
        {
          snprintf((char *)v109, 0x1000u, "Stratum connection to pool %d interrupted", *a1);
          sub_385C8(7, (const char *)v109, 0);
        }
        goto LABEL_126;
      }
      snprintf((char *)v109, 0x1000u, "Stratum select failed on pool %d with value %d", *a1, v18);
      sub_385C8(7, (const char *)v109, 0);
      v71 = (unsigned __int8)byte_75C49;
LABEL_121:
      if ( v71 )
        goto LABEL_122;
LABEL_126:
      v72 = dword_78264;
      ++a1[40];
      dword_78264 = v72 + 1;
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 61)) )
        sub_B35C("supports_resume", 7101);
      if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B5E4("supports_resume", 7101);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 61)) )
        sub_B50C("supports_resume", 7101);
      v73 = a1[165];
      if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 67)) )
        sub_B578("supports_resume", 7103);
      off_72D18();
      if ( !v73 || byte_7846C )
        sub_17F28((int)a1);
      sub_1922C(a1);
      if ( a1 == (_DWORD *)sub_1D9A0() )
        sub_17148();
      while ( !sub_2CE20((int)a1) )
      {
        v22 = *((unsigned __int8 *)a1 + 137);
        if ( *((_BYTE *)a1 + 137) )
          goto LABEL_27;
        sub_2A884();
      }
    }
  }
  sub_2AE38((int)a1);
LABEL_27:
  sub_201FC(0, v20, v21, v22, a5, a6, a7, a8, a9, a10, a11, a12, a13);
}
