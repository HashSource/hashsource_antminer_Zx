void *__fastcall sub_1FC10(_DWORD *a1)
{
  pthread_t v2; // r0
  fd_set *v3; // r3
  int v4; // r3
  int v5; // r2
  int v6; // r0
  int *v7; // r5
  int *v9; // r0
  _DWORD *v10; // r0
  void **v11; // r6
  int v12; // r4
  unsigned int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r0
  int v16; // r7
  int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r3
  int v20; // r1
  _DWORD *v21; // r8
  int v22; // r7
  time_t v23; // r0
  int v24; // r3
  double v25; // d0
  unsigned int v26; // r8
  int v27; // r1
  __int64 v28; // d8
  const char *v29; // r2
  unsigned int v30; // r3
  _DWORD *v31; // r8
  double v32; // d18
  double v33; // d16
  double v34; // d16
  double v35; // d17
  _DWORD *v36; // r12
  size_t v37; // r0
  size_t v38; // r12
  int v39; // r12
  double v40; // d8
  double v41; // r0
  int v42; // r6
  int v43; // r3
  int v44; // r2
  _DWORD *v45; // r1
  bool v46; // zf
  int v47; // r3
  int v48; // r2
  int v49; // r2
  int v50; // r3
  int v51; // r3
  _DWORD *v52; // r0
  int v53; // r4
  int v54; // r3
  int v55; // r2
  int v56; // r4
  char *v57; // r4
  int v58; // r3
  int v59; // r3
  int v60; // r3
  double v61; // d8
  double v62; // d16
  double v63; // d18
  __int64 v64; // r6
  double v65; // d18
  double v66; // d16
  double v67; // d16
  int v68; // r3
  time_t v69; // r0
  int v70; // r1
  _DWORD *v71; // r0
  const char *v72; // r0
  double v73; // d16
  double v74; // d17
  __int64 v75; // r6
  char *v76; // [sp+18h] [bp-A6Ch]
  size_t na; // [sp+1Ch] [bp-A68h]
  size_t n; // [sp+1Ch] [bp-A68h]
  int *v79; // [sp+3Ch] [bp-A48h]
  int v80; // [sp+44h] [bp-A40h]
  _DWORD *src; // [sp+48h] [bp-A3Ch]
  const char *srca; // [sp+48h] [bp-A3Ch]
  _DWORD *v83; // [sp+4Ch] [bp-A38h]
  int s2; // [sp+50h] [bp-A34h] BYREF
  struct timeval timeout; // [sp+54h] [bp-A30h] BYREF
  char s[16]; // [sp+5Ch] [bp-A28h] BYREF
  char v87[20]; // [sp+6Ch] [bp-A18h] BYREF
  char v88[2]; // [sp+80h] [bp-A04h] BYREF
  char dest[30]; // [sp+82h] [bp-A02h] BYREF
  char v90[36]; // [sp+A0h] [bp-9E4h] BYREF
  char v91[60]; // [sp+C4h] [bp-9C0h] BYREF
  char v92; // [sp+100h] [bp-984h] BYREF
  fd_set readfds; // [sp+104h] [bp-980h] BYREF
  int v94[23]; // [sp+184h] [bp-900h] BYREF
  char v95[160]; // [sp+1E0h] [bp-8A4h] BYREF
  _DWORD v96[513]; // [sp+280h] [bp-804h] BYREF

  v2 = pthread_self();
  pthread_detach(v2);
  snprintf(s, 0x10u, "%d/RStratum", *a1);
  sub_2F02C(s);
  while ( !*((_BYTE *)a1 + 105) )
  {
    if ( !sub_2B6F8((int)a1) && !sub_1FB7C((int)a1) )
    {
      sub_2B7C0((pthread_mutex_t *)a1);
      sub_18D90((int)a1);
      sub_17FC4(a1);
      while ( !sub_1FB7C((int)a1) && (!a1[25] || a1 != (_DWORD *)sub_1D644() && dword_611AC != 3 && dword_611AC != 4) )
      {
        if ( pthread_mutex_lock(&stru_61314) )
          sub_B4E4("wait_lpcurrent", 9252);
        pthread_cond_wait(&stru_61330, &stru_61314);
        if ( pthread_mutex_unlock(&stru_61314) )
          sub_B694("wait_lpcurrent", 9254);
        off_60178();
      }
      while ( !sub_2DC00((pthread_mutex_t *)a1) )
      {
        if ( *((_BYTE *)a1 + 105) )
          return 0;
        sub_2B21C();
      }
    }
    v3 = (fd_set *)&v92;
    do
    {
      v3->__fds_bits[1] = 0;
      v3 = (fd_set *)((char *)v3 + 4);
    }
    while ( v3 != (fd_set *)&readfds.__fds_bits[31] );
    v4 = a1[145];
    timeout.tv_usec = 0;
    v5 = v4 + 31;
    timeout.tv_sec = 90;
    if ( v4 >= 0 )
      v5 = v4;
    readfds.__fds_bits[v5 >> 5] |= 1 << (v4 % 32);
    if ( sub_2B6F8((int)a1) || (v6 = select(a1[145] + 1, &readfds, 0, 0, &timeout), v6 > 0) )
    {
      v7 = (int *)sub_2B920((int)a1);
      if ( !v7 )
      {
        v54 = (unsigned __int8)byte_630C1;
        goto LABEL_118;
      }
      sub_1F8F4(a1);
      if ( sub_2DC70((pthread_mutex_t *)a1, v7) )
        goto LABEL_12;
      v9 = sub_45AA8(v7, 0, (char *)v94);
      v79 = v9;
      if ( v9 )
      {
        src = (_DWORD *)sub_46698(v9, "result");
        v83 = (_DWORD *)sub_46698(v79, (char *)"error");
        v10 = (_DWORD *)sub_46698(v79, "id");
        if ( !v10 || *v10 == 7 )
        {
          if ( v83 )
          {
            v57 = (char *)sub_440CC(v83, 3);
          }
          else
          {
            v57 = (char *)malloc(0x11u);
            if ( v57 )
              strcpy(v57, "(unknown reason)");
          }
          if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
          {
            snprintf((char *)v96, 0x800u, "JSON-RPC non method decode failed: %s", v57);
            sub_38438(7, (const char *)v96, 0);
          }
          v42 = 0;
          free(v57);
        }
        else
        {
          s2 = sub_46AC0((int)v10);
          if ( pthread_mutex_lock(&stru_612DC) )
            sub_B4E4("parse_stratum_response", 6899);
          v11 = (void **)dword_612F4;
          if ( dword_612F4 )
          {
            v13 = ((unsigned __int8)s2 + 17973517 + (HIBYTE(s2) << 24) + (BYTE2(s2) << 16) + (BYTE1(s2) << 8))
                ^ (unsigned int)&unk_7F76D;
            v14 = (-1622558010 - v13) ^ (v13 << 8);
            v15 = (-17973517 - v13 - v14) ^ (v14 >> 13);
            v16 = *(_DWORD *)dword_612F4;
            v17 = (v13 - v14 - v15) ^ (v15 >> 12);
            v18 = (v14 - v15 - v17) ^ (v17 << 16);
            v19 = (v15 - v17 - v18) ^ (v18 >> 5);
            v20 = (v17 - v18 - v19) ^ (v19 >> 3);
            v21 = **(_DWORD ***)dword_612F4;
            v12 = v21[3
                    * (((v19 - v20 - ((v18 - v19 - v20) ^ (v20 << 10)))
                      ^ (((v18 - v19 - v20) ^ (v20 << 10)) >> 15))
                     & (*(_DWORD *)(*(_DWORD *)dword_612F4 + 4) - 1))];
            if ( !v12 )
              goto LABEL_38;
            while ( 1 )
            {
              v12 -= *(_DWORD *)(v16 + 20);
LABEL_38:
              if ( !v12 )
                goto LABEL_41;
              if ( *(_DWORD *)(v12 + 24) == 4 && !memcmp(*(const void **)(v12 + 20), &s2, 4u) )
                break;
              v12 = *(_DWORD *)(v12 + 16);
              if ( !v12 )
                goto LABEL_41;
            }
            v43 = *(_DWORD *)(v12 + 4);
            if ( v43 || *(_DWORD *)(v12 + 8) )
            {
              v44 = *(_DWORD *)(v16 + 20);
              v45 = (_DWORD *)(*(_DWORD *)(v16 + 16) - v44);
              if ( (_DWORD *)v12 == v45 )
              {
                *(_DWORD *)(v16 + 16) = v43 + v44;
                v43 = *(_DWORD *)(v12 + 4);
              }
              v46 = v43 == 0;
              if ( v43 )
              {
                v45 = *v11;
                v44 = *(_DWORD *)(v12 + 8);
              }
              else
              {
                v43 = *(_DWORD *)(v12 + 8);
              }
              if ( v46 )
              {
                v11 = (void **)v43;
                dword_612F4 = v43;
              }
              else
              {
                v43 += v45[5];
              }
              if ( !v46 )
              {
                *(_DWORD *)(v43 + 8) = v44;
                v43 = *(_DWORD *)(v12 + 8);
              }
              if ( v43 )
                *(_DWORD *)(v43 + *((_DWORD *)*v11 + 5) + 4) = *(_DWORD *)(v12 + 4);
              v47 = 3 * ((*((_DWORD *)*v11 + 1) - 1) & *(_DWORD *)(v12 + 28));
              v48 = *(_DWORD *)*v11 + 12 * ((*((_DWORD *)*v11 + 1) - 1) & *(_DWORD *)(v12 + 28));
              --*(_DWORD *)(v48 + 4);
              v49 = *(_DWORD *)*v11;
              if ( v12 == *(_DWORD *)(v49 + 4 * v47) )
                *(_DWORD *)(v49 + 4 * v47) = *(_DWORD *)(v12 + 16);
              v50 = *(_DWORD *)(v12 + 12);
              if ( v50 )
                *(_DWORD *)(v50 + 16) = *(_DWORD *)(v12 + 16);
              v51 = *(_DWORD *)(v12 + 16);
              if ( v51 )
                *(_DWORD *)(v51 + 12) = *(_DWORD *)(v12 + 12);
              --*((_DWORD *)*v11 + 3);
            }
            else
            {
              free(v21);
              free(*v11);
              dword_612F4 = 0;
            }
            --a1[175];
          }
          else
          {
            v12 = 0;
          }
LABEL_41:
          if ( pthread_mutex_unlock(&stru_612DC) )
            sub_B694("parse_stratum_response", 6906);
          off_60178();
          if ( v12 )
          {
            v22 = *(_DWORD *)(v12 + 36);
            v23 = time(0);
            if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
            {
              snprintf(
                (char *)v96,
                0x800u,
                "Pool %d stratum share result lag time %d seconds",
                **(_DWORD **)(v22 + 260),
                v23 - *(_DWORD *)(v12 + 48));
              sub_38438(7, (const char *)v96, 0);
            }
            v24 = 0;
            v96[0] = bswap32(*(_DWORD *)(v22 + 220));
            v96[1] = bswap32(*(_DWORD *)(v22 + 216));
            v96[2] = bswap32(*(_DWORD *)(v22 + 212));
            v96[3] = bswap32(*(_DWORD *)(v22 + 208));
            v96[4] = bswap32(*(_DWORD *)(v22 + 204));
            v96[5] = bswap32(*(_DWORD *)(v22 + 200));
            v96[6] = bswap32(*(_DWORD *)(v22 + 196));
            v96[7] = bswap32(*(_DWORD *)(v22 + 192));
            do
            {
              if ( *((_BYTE *)v96 + v24) )
                break;
              ++v24;
            }
            while ( v24 != 29 );
            v25 = *(double *)(v22 + 376);
            v26 = *(_DWORD *)((char *)v96 + v24);
            round();
            LODWORD(v28) = sub_494C0(v25);
            HIDWORD(v28) = v27;
            sub_11130(*(_QWORD *)(v22 + 232), v90, 0x10u, 0);
            v29 = "";
            v30 = bswap32(v26);
            if ( *(_BYTE *)(v22 + 283) )
              v29 = " BLOCK!";
            snprintf(v91, 0x40u, "%08lx Diff %s/%llu%s", v30, v90, v28, v29);
            v31 = *(_DWORD **)(v22 + 260);
            v80 = *(_DWORD *)(sub_1C36C(*(_DWORD *)(v22 + 256)) + 36);
            if ( src && (*src == 5 || *(_BYTE *)(v22 + 324) && *src == 7) )
            {
              if ( pthread_mutex_lock(&mutex) )
                sub_B4E4("share_result", 3478);
              v65 = dbl_63B88;
              ++*(_DWORD *)(v80 + 36);
              ++*((_QWORD *)v31 + 1);
              v66 = *(double *)(v80 + 200) + *(double *)(v22 + 376);
              ++qword_639C8;
              *(double *)(v80 + 200) = v66;
              v67 = *(double *)(v22 + 376);
              *((double *)v31 + 9) = *((double *)v31 + 9) + v67;
              dbl_63B88 = v67 + v65;
              if ( pthread_mutex_unlock(&mutex) )
                sub_B694("share_result", 3485);
              off_60178();
              v68 = *v31;
              v31[6] = 0;
              *(_DWORD *)(v80 + 216) = v68;
              v69 = time(0);
              v70 = (unsigned __int8)byte_630C1;
              *(_DWORD *)(v80 + 220) = v69;
              *(_QWORD *)(v80 + 224) = *(_QWORD *)(v22 + 376);
              v31[88] = v69;
              *((_QWORD *)v31 + 45) = *(_QWORD *)(v22 + 376);
              if ( v70 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
              {
                strcpy((char *)v96, "PROOF OF WORK RESULT: true (yay!!!)");
                sub_38438(7, (const char *)v96, 0);
              }
              if ( !byte_64218 && !byte_640B8 )
              {
                if ( dword_63740 <= 1 )
                {
                  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
                  {
                    snprintf(
                      (char *)v96,
                      0x800u,
                      "Accepted %s %s %d %s%s",
                      v91,
                      *(const char **)(*(_DWORD *)(v80 + 4) + 8),
                      *(_DWORD *)(v80 + 8),
                      "",
                      "");
                    sub_38438(7, (const char *)v96, 0);
                  }
                }
                else if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
                {
                  snprintf(
                    (char *)v96,
                    0x800u,
                    "Accepted %s %s %d pool %d %s%s",
                    v91,
                    *(const char **)(*(_DWORD *)(v80 + 4) + 8),
                    *(_DWORD *)(v80 + 8),
                    **(_DWORD **)(v22 + 260),
                    "",
                    "");
                  sub_38438(7, (const char *)v96, 0);
                }
              }
              sub_1D408("accept", (_DWORD *)v22);
              if ( dword_61414 && (double)dword_61414 <= dbl_63B88 )
              {
                if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
                {
                  snprintf(
                    (char *)v96,
                    0x800u,
                    "Successfully mined %d accepted shares as requested and exiting.",
                    dword_61414);
                  sub_38438(4, (const char *)v96, 0);
                }
                sub_17328();
              }
              if ( v31[25] == 2 )
              {
                if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 3
                  || (snprintf((char *)v96, 0x800u, "Rejecting pool %d now accepting shares, re-enabling!", *v31),
                      sub_38438(4, (const char *)v96, 0),
                      v31[25] != 1) )
                {
                  v31[25] = 1;
                  ++dword_63B84;
                }
                sub_195D4(0);
              }
              if ( *(_BYTE *)(v22 + 283) )
                sub_16C8C();
            }
            else
            {
              if ( pthread_mutex_lock(&mutex) )
                sub_B4E4("share_result", 3528);
              v32 = dbl_63C10;
              ++*(_DWORD *)(v80 + 40);
              ++*((_QWORD *)v31 + 2);
              v33 = *(double *)(v80 + 208) + *(double *)(v22 + 376);
              ++qword_63C98;
              *(double *)(v80 + 208) = v33;
              v34 = *(double *)(v22 + 376);
              v35 = *((double *)v31 + 10) + v34;
              ++v31[6];
              *((double *)v31 + 10) = v35;
              dbl_63C10 = v34 + v32;
              if ( pthread_mutex_unlock(&mutex) )
                sub_B694("share_result", 3536);
              off_60178();
              if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
              {
                strcpy((char *)v96, "PROOF OF WORK RESULT: false (booooo)");
                sub_38438(7, (const char *)v96, 0);
              }
              if ( !byte_64218 && !byte_640B8 )
              {
                strcpy(v90, "reject");
                memset(&v90[7], (unsigned __int8)byte_640B8, 0x1Du);
                v88[0] = byte_640B8;
                if ( dword_63740 > 1 )
                  snprintf(v87, 0x14u, "pool %d", **(_DWORD **)(v22 + 260));
                else
                  v87[0] = byte_640B8;
                if ( *(_BYTE *)(v22 + 324) )
                {
                  v36 = src;
                  if ( src )
                    goto LABEL_70;
LABEL_210:
                  if ( *(_BYTE *)(v22 + 284) && v83 )
                  {
                    if ( *v83 == 1 )
                    {
                      v71 = sub_46880(v83, 1u);
                      if ( v71 && *v71 == 2 )
                      {
LABEL_215:
                        v72 = (const char *)sub_469F0(v71);
                        snprintf(v88, 0x1Fu, " (%s)", v72);
                      }
                    }
                    else if ( *v83 == 2 )
                    {
                      v71 = v83;
                      goto LABEL_215;
                    }
                  }
                }
                else
                {
                  v36 = (_DWORD *)sub_46698(v79, "reject-reason");
                  if ( !v36 )
                    goto LABEL_210;
LABEL_70:
                  srca = (const char *)sub_469F0(v36);
                  v37 = strlen(srca);
                  qmemcpy(v88, " (", sizeof(v88));
                  if ( v37 >= 0x1C )
                    v38 = 28;
                  else
                    v38 = v37;
                  na = v38;
                  v76 = (char *)&v96[512] + v38;
                  memcpy(dest, srca, v38);
                  *((_WORD *)v76 - 1279) = 41;
                  memcpy(&v90[7], srca, na);
                  v90[6] = 58;
                  *(v76 - 2521) = 0;
                }
                if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
                {
                  snprintf(
                    (char *)v96,
                    0x800u,
                    "Rejected %s %s %d %s%s %s%s",
                    v91,
                    *(const char **)(*(_DWORD *)(v80 + 4) + 8),
                    *(_DWORD *)(v80 + 8),
                    v87,
                    v88,
                    "",
                    "");
                  sub_38438(7, (const char *)v96, 0);
                }
                sub_1D408(v90, (_DWORD *)v22);
              }
              v39 = v31[6];
              if ( v39 > 10 && !*(_BYTE *)(v22 + 281) )
              {
                if ( byte_637F8 )
                {
                  if ( dword_63B84 > 1 )
                  {
                    v40 = (double)v39;
                    n = v31[6];
                    LODWORD(v41) = sub_493DC(qword_639C8);
                    if ( v40 > v41 / dbl_5F898 * 60.0 * 3.0 )
                    {
                      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
                      {
                        snprintf((char *)v96, 0x800u, "Pool %d rejected %d sequential shares, disabling!", *v31, n);
                        sub_38438(4, (const char *)v96, 0);
                      }
                      if ( v31[25] == 1 )
                        --dword_63B84;
                      v31[25] = 2;
                      if ( v31 == (_DWORD *)sub_1D644() )
                        sub_195D4(0);
                      v31[6] = 0;
                    }
                  }
                }
              }
            }
            v42 = 1;
            sub_152B8(*(void ***)(v12 + 36));
            *(_DWORD *)(v12 + 36) = 0;
            free((void *)v12);
          }
          else if ( src )
          {
            if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 53)) )
              sub_B4E4("parse_stratum_response", 6916);
            if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 59)) )
              sub_B76C("parse_stratum_response", 6916);
            if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 53)) )
              sub_B694("parse_stratum_response", 6916);
            v61 = *((double *)a1 + 223);
            if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 59)) )
              sub_B700("parse_stratum_response", 6918);
            off_60178();
            if ( *src == 5 )
            {
              if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
              {
                snprintf((char *)v96, 0x800u, "Accepted untracked stratum share from pool %d", *a1);
                sub_38438(7, (const char *)v96, 0);
              }
              if ( pthread_mutex_lock(&mutex) )
                sub_B4E4("parse_stratum_response", 6926);
              v73 = *((double *)a1 + 9) + v61;
              v74 = dbl_63B88;
              v75 = qword_639C8;
              ++*((_QWORD *)a1 + 1);
              qword_639C8 = v75 + 1;
              *((double *)a1 + 9) = v73;
              dbl_63B88 = v61 + v74;
              if ( pthread_mutex_unlock(&mutex) )
                sub_B694("parse_stratum_response", 6931);
            }
            else
            {
              if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
              {
                snprintf((char *)v96, 0x800u, "Rejected untracked stratum share from pool %d", *a1);
                sub_38438(7, (const char *)v96, 0);
              }
              if ( pthread_mutex_lock(&mutex) )
                sub_B4E4("parse_stratum_response", 6937);
              v62 = *((double *)a1 + 10) + v61;
              v63 = dbl_63C10;
              v64 = qword_63C98;
              ++*((_QWORD *)a1 + 2);
              qword_63C98 = v64 + 1;
              *((double *)a1 + 10) = v62;
              dbl_63C10 = v61 + v63;
              if ( pthread_mutex_unlock(&mutex) )
                sub_B694("parse_stratum_response", 6942);
            }
            v42 = 0;
            off_60178();
          }
          else
          {
            v42 = 0;
          }
        }
        v58 = v79[1];
        if ( v58 != -1 )
        {
          v59 = v58 - 1;
          v79[1] = v59;
          if ( !v59 )
            sub_46C5C((void **)v79);
        }
        if ( v42 )
        {
LABEL_12:
          if ( *((_BYTE *)a1 + 648) )
          {
            v52 = sub_19DA0();
            *((_BYTE *)a1 + 648) = 0;
            v53 = (int)v52;
            sub_1A514((int)a1, (int)v52);
            *(_BYTE *)(v53 + 280) = 1;
            sub_1D6F8(v53);
            sub_152B8((void **)v53);
          }
          goto LABEL_14;
        }
        v60 = (unsigned __int8)byte_630C1;
        goto LABEL_153;
      }
      if ( !byte_630C1 )
        goto LABEL_14;
      if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
        goto LABEL_154;
      snprintf((char *)v96, 0x800u, "JSON decode failed(%d): %s", v94[0], v95);
      sub_38438(7, (const char *)v96, 0);
      v60 = (unsigned __int8)byte_630C1;
LABEL_153:
      if ( !v60 )
        goto LABEL_14;
LABEL_154:
      if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
      {
        snprintf((char *)v96, 0x800u, "Unknown stratum msg: %s", (const char *)v7);
        sub_38438(7, (const char *)v96, 0);
      }
LABEL_14:
      free(v7);
    }
    else
    {
      if ( !byte_630C1 )
        goto LABEL_123;
      if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
      {
LABEL_119:
        if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
        {
          snprintf((char *)v96, 0x800u, "Stratum connection to pool %d interrupted", *a1);
          sub_38438(7, (const char *)v96, 0);
        }
        goto LABEL_123;
      }
      snprintf((char *)v96, 0x800u, "Stratum select failed on pool %d with value %d", *a1, v6);
      sub_38438(7, (const char *)v96, 0);
      v54 = (unsigned __int8)byte_630C1;
LABEL_118:
      if ( v54 )
        goto LABEL_119;
LABEL_123:
      v55 = dword_639E4;
      ++a1[32];
      dword_639E4 = v55 + 1;
      if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 53)) )
        sub_B4E4("supports_resume", 7079);
      if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(a1 + 59)) )
        sub_B76C("supports_resume", 7079);
      if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 53)) )
        sub_B694("supports_resume", 7079);
      v56 = a1[157];
      if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 59)) )
        sub_B700("supports_resume", 7081);
      off_60178();
      if ( !v56 || byte_63BE4 )
        sub_18D90((int)a1);
      sub_17FC4(a1);
      if ( a1 == (_DWORD *)sub_1D644() )
        sub_16C8C();
      while ( !sub_2DC00((pthread_mutex_t *)a1) )
      {
        if ( *((_BYTE *)a1 + 105) )
          return 0;
        sub_2B21C();
      }
    }
  }
  sub_2B7C0((pthread_mutex_t *)a1);
  return 0;
}
