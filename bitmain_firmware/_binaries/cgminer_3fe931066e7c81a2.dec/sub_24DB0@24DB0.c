void __fastcall sub_24DB0(int a1)
{
  int v1; // r1
  int v2; // r11
  int v3; // r5
  int v4; // r12
  int v5; // r2
  int v6; // r9
  int v7; // r7
  int v8; // r3
  int v9; // r12
  int v10; // r0
  double v11; // d8
  double *v12; // r4
  double v13; // d9
  double *v14; // r5
  int v15; // r3
  _DWORD *v16; // r5
  __int64 v17; // kr00_8
  __suseconds_t tv_usec; // r4
  __time_t tv_sec; // r3
  int v20; // r2
  int v21; // r1
  bool v22; // nf
  int v23; // r4
  int v24; // r4
  int v25; // r3
  double v26; // r0
  double v27; // d16
  bool v28; // zf
  double v29; // d8
  int v30; // r1
  unsigned int v31; // r0
  int v32; // r1
  __time_t v33; // [sp+Ch] [bp-1090h]
  __time_t v34; // [sp+Ch] [bp-1090h]
  unsigned int v35; // [sp+10h] [bp-108Ch]
  int v36; // [sp+14h] [bp-1088h]
  int v37; // [sp+14h] [bp-1088h]
  int v38; // [sp+14h] [bp-1088h]
  int v39; // [sp+14h] [bp-1088h]
  __int64 v40; // [sp+28h] [bp-1074h]
  int v41; // [sp+34h] [bp-1068h]
  int v42; // [sp+48h] [bp-1054h]
  _DWORD *v43; // [sp+4Ch] [bp-1050h]
  _DWORD *v44; // [sp+50h] [bp-104Ch]
  struct timeval *v45; // [sp+54h] [bp-1048h]
  int *v47; // [sp+5Ch] [bp-1040h]
  int v48; // [sp+60h] [bp-103Ch]
  unsigned int v49; // [sp+64h] [bp-1038h]
  int v50; // [sp+68h] [bp-1034h]
  int remaining; // [sp+70h] [bp-102Ch]
  int v52; // [sp+74h] [bp-1028h]
  struct timeval v53; // [sp+78h] [bp-1024h] BYREF
  struct timeval v54; // [sp+80h] [bp-101Ch] BYREF
  struct timeval v55; // [sp+88h] [bp-1014h] BYREF
  struct timeval v56; // [sp+90h] [bp-100Ch] BYREF
  struct timespec s[509]; // [sp+98h] [bp-1004h] BYREF

  v1 = *(_DWORD *)(a1 + 4);
  v2 = *(_DWORD *)(a1 + 36);
  v3 = *(_DWORD *)a1;
  v4 = 1717986919 * dword_75DCC;
  v50 = *(_DWORD *)a1;
  v42 = *(_DWORD *)(v2 + 4);
  v5 = dword_75DCC / 5;
  if ( !(dword_75DCC / 5) )
    v5 = 1;
  if ( v1 )
    v3 = a1;
  else
    v4 = 1;
  v48 = v5;
  if ( v1 )
    remaining = *(unsigned __int8 *)(v3 + 8);
  else
    remaining = v4;
  v49 = (*(int (**)(void))(*(_DWORD *)(v2 + 4) + 48))();
  sub_2A84C(&v53);
  sub_2A84C(&v56);
  if ( !*(_BYTE *)(v2 + 364) )
  {
    v40 = 0;
    v6 = *(unsigned __int8 *)(v2 + 364);
    v7 = v6;
    v8 = 1000000 * v48 + 1023;
    if ( 1000000 * v48 >= 0 )
      v8 = 1000000 * v48;
    v52 = v8 >> 10;
    while ( 1 )
    {
      v10 = sub_247D4(a1, v50);
      *(_BYTE *)(a1 + 62) = 0;
      *(_BYTE *)(v2 + 172) = 1;
      v41 = v10;
      sub_2A84C(&v55);
      *(_DWORD *)(v41 + 1736) = 0;
      *(_QWORD *)(v2 + 160) = 0;
      if ( !(*(int (__fastcall **)(int, int))(v42 + 56))(a1, v41) )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf((char *)s, 0x1000u, "work prepare failed, exiting mining thread %d", v50);
          sub_38730(3, (const char *)s, 0);
        }
        goto LABEL_82;
      }
      v11 = *(double *)(v42 + 104);
      v12 = (double *)(v41 + 1864);
      v13 = *(double *)(v41 + 1864);
      v14 = (double *)(v41 + 1712);
      v15 = (unsigned __int8)byte_7B859;
      if ( v11 > v13 )
        v11 = *(double *)(v41 + 1864);
      *v14 = v11;
      if ( v11 < *(double *)(v42 + 120) )
        v11 = *(double *)(v42 + 120);
      *v14 = v11;
      if ( !v15 )
      {
        v47 = (int *)(v2 + 296);
        v43 = (_DWORD *)(v2 + 304);
        v45 = (struct timeval *)(v41 + 1912);
        v44 = (_DWORD *)(v2 + 312);
        goto LABEL_30;
      }
      LODWORD(v26) = sub_5CB64(*(__int64 *)&dword_7B100);
      if ( v26 / dbl_755F8 * 60.0 <= 30.0 )
        break;
      v27 = *(double *)(v42 + 112);
      if ( v27 >= *(double *)(v42 + 104) || v13 <= v27 )
        goto LABEL_75;
      v28 = byte_78E09 == 0;
      v29 = v27 + 1.0;
      *(double *)(v42 + 112) = v27 + 1.0;
      if ( !v28 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf((char *)s, 0x1000u, "Driver %s working diff changed to %.0f", *(const char **)(v42 + 4), v27 + 1.0);
        sub_38730(7, (const char *)s, 0);
        v29 = *(double *)(v42 + 112);
      }
      if ( *v12 < v29 )
        v29 = *v12;
      *v14 = v29;
LABEL_73:
      sub_16244(v41 + 1929);
      v45 = (struct timeval *)(v41 + 1912);
      v47 = (int *)(v2 + 296);
      v43 = (_DWORD *)(v2 + 304);
      v44 = (_DWORD *)(v2 + 312);
      while ( 1 )
      {
LABEL_30:
        sub_2A84C(&v54);
        sub_2A448(&v54, &v53.tv_sec);
        sub_2A47C(&v53, v47);
        if ( sub_2A4C8(&v53, v43) )
          sub_2A530(v43, &v53);
        if ( sub_2A4FC(&v53, v44) )
          sub_2A530(v44, &v53);
        ++*(_DWORD *)(v2 + 292);
        v16 = *(_DWORD **)(v41 + 1748);
        sub_2A47C(&v53, v16 + 103);
        if ( sub_2A4C8(&v53, v16 + 105) )
          sub_2A530(v16 + 105, &v53);
        if ( sub_2A4FC(&v53, v16 + 107) )
          sub_2A530(v16 + 107, &v53);
        ++v16[102];
        sub_2A84C(v45);
        pthread_setcancelstate(1, 0);
        sub_FC24(a1);
        v17 = ((__int64 (__fastcall *)(int, int, unsigned int, _DWORD))*(_DWORD *)(v42 + 64))(
                a1,
                v41,
                v49 + *(_DWORD *)(v41 + 1736),
                0);
        sub_FC58(a1);
        pthread_setcancelstate(0, 0);
        pthread_testcancel();
        sub_2A84C(&v53);
        if ( v17 == -1 )
          break;
        v40 += v17;
        tv_usec = v53.tv_usec;
        if ( *(_QWORD *)(v2 + 160) < v17 )
          *(_QWORD *)(v2 + 160) = v17;
        tv_sec = v53.tv_sec;
        v20 = tv_usec - v54.tv_usec + (tv_usec - v54.tv_usec < 0 ? 0xF4000 : 0);
        if ( tv_usec - v54.tv_usec < 0 )
          v20 += 576;
        v7 += v20;
        v21 = v53.tv_sec - v54.tv_sec;
        if ( tv_usec - v54.tv_usec < 0 )
          --v21;
        v6 += v21;
        if ( v7 > 1000000 )
        {
          ++v6;
          v7 -= 1000000;
        }
        v9 = v53.tv_sec - v55.tv_sec;
        if ( tv_usec - v55.tv_usec < 0 )
          --v9;
        if ( v48 > v6 )
        {
          if ( v49 == -1 )
            goto LABEL_20;
          v30 = v7 + 1024;
          v33 = v53.tv_sec;
          if ( v7 + 1024 < 0 )
            v30 = v7 + 2047;
          v38 = v9;
          v35 = (sub_5C710(1000000, v30 >> 10) + 16) * v48;
          tv_sec = v33;
          v9 = v38;
          if ( v49 <= 0xFFFFFC00 / v35 )
            v49 = (v49 * v35) >> 10;
          else
            v49 = -1;
        }
        else if ( v48 < v6 )
        {
          v49 = v48 * v49 / v6;
        }
        else if ( v7 > 100000 )
        {
          v34 = v53.tv_sec;
          v39 = v9;
          v31 = sub_5C710(1000000 * v48 + v7, v52);
          tv_sec = v34;
          v9 = v39;
          v49 = (v49 << 10) / v31;
        }
        v23 = tv_usec - v56.tv_usec;
        v22 = v23 < 0;
        v24 = v23 + (v23 < 0 ? 0xF4000 : 0);
        v25 = tv_sec - v56.tv_sec;
        if ( v22 )
        {
          --v25;
          v24 += 576;
        }
        if ( v40 && (v25 > 0 || v24 > (int)&loc_30D40) || dword_75DCC <= v25 )
        {
          v36 = v9;
          sub_1BBA4(v50, v40);
          sub_2A530(&v56, &v53);
          v9 = v36;
          v40 = 0;
        }
        if ( *(_BYTE *)(a1 + 62) )
        {
          if ( !remaining )
          {
            v32 = *(_DWORD *)(a1 + 4);
            s[0].tv_sec = 0;
            s[0].tv_nsec = 250000000 * v32;
            nanosleep(s, 0);
          }
          goto LABEL_22;
        }
        if ( *(_BYTE *)(a1 + 60) || (v6 = *(_DWORD *)(v2 + 32)) != 0 )
        {
          v6 = 0;
          v37 = v9;
          v7 = 0;
          sub_11C8C(a1, v50, v42);
          v9 = v37;
        }
        else
        {
          v7 = 0;
        }
LABEL_20:
        if ( v9 > dword_75DF0 || *(_QWORD *)(v2 + 160) > 0xFFFFFFFD || sub_22B44(v41, 0) )
          goto LABEL_22;
      }
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
      {
        snprintf((char *)s, 0x1000u, "%s %d failure, disabling!", *(const char **)(v42 + 8), *(_DWORD *)(v2 + 8));
        sub_38730(3, (const char *)s, 0);
      }
      *(_DWORD *)(v2 + 32) = 1;
      sub_2ED88((_DWORD *)v2, 1);
      *(_BYTE *)(v2 + 364) = 1;
LABEL_22:
      sub_15780((void **)v41);
      if ( *(_BYTE *)(v2 + 364) )
        goto LABEL_82;
    }
    v27 = *(double *)(v42 + 112);
LABEL_75:
    if ( v13 < v27 )
      *(double *)(v42 + 112) = v13;
    goto LABEL_73;
  }
LABEL_82:
  *(_DWORD *)(v2 + 32) = 1;
}
