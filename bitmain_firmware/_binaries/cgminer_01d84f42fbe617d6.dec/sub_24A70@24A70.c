void __fastcall sub_24A70(int a1)
{
  int v2; // r1
  int v3; // r9
  int v4; // r2
  bool v5; // zf
  int v6; // r8
  int v7; // r11
  int v8; // r3
  int v9; // r12
  int v10; // r0
  int v11; // r5
  double v12; // d9
  double v13; // d8
  int v14; // r3
  _DWORD *v15; // r7
  __int64 v16; // kr00_8
  __suseconds_t tv_usec; // r4
  __time_t tv_sec; // r12
  __time_t v19; // r3
  int v20; // r2
  int v21; // r1
  int v22; // r3
  int v23; // r4
  double v24; // r0
  double v25; // d16
  double v26; // d8
  int v27; // r1
  unsigned int v28; // r0
  int v29; // r2
  __time_t v30; // [sp+Ch] [bp-880h]
  __time_t v31; // [sp+Ch] [bp-880h]
  unsigned int v32; // [sp+10h] [bp-87Ch]
  int v33; // [sp+14h] [bp-878h]
  int v34; // [sp+14h] [bp-878h]
  int v35; // [sp+14h] [bp-878h]
  int v36; // [sp+14h] [bp-878h]
  __int64 v37; // [sp+28h] [bp-864h]
  int v38; // [sp+3Ch] [bp-850h]
  _DWORD *v39; // [sp+40h] [bp-84Ch]
  _DWORD *v40; // [sp+44h] [bp-848h]
  struct timeval *v41; // [sp+48h] [bp-844h]
  int *v42; // [sp+4Ch] [bp-840h]
  int v43; // [sp+50h] [bp-83Ch]
  unsigned int v44; // [sp+54h] [bp-838h]
  int v45; // [sp+58h] [bp-834h]
  int remaining; // [sp+60h] [bp-82Ch]
  unsigned int v47; // [sp+64h] [bp-828h]
  struct timeval v48; // [sp+68h] [bp-824h] BYREF
  struct timeval v49; // [sp+70h] [bp-81Ch] BYREF
  struct timeval v50; // [sp+78h] [bp-814h] BYREF
  struct timeval v51; // [sp+80h] [bp-80Ch] BYREF
  struct timespec s[256]; // [sp+88h] [bp-804h] BYREF

  v2 = *(_DWORD *)(a1 + 4);
  v3 = *(_DWORD *)(a1 + 36);
  v45 = *(_DWORD *)a1;
  v38 = *(_DWORD *)(v3 + 4);
  v4 = dword_6006C / 5;
  if ( (int)((unsigned __int64)(1717986919LL * dword_6006C) >> 32) >> 1 == dword_6006C >> 31 )
    v4 = 1;
  v5 = v2 == 0;
  if ( v2 )
    v2 = *(unsigned __int8 *)(a1 + 8);
  v43 = v4;
  if ( v5 )
    remaining = 1;
  else
    remaining = v2;
  v44 = (*(int (__fastcall **)(int, int))(v38 + 48))(a1, v2);
  sub_2B13C(&v48);
  sub_2B13C(&v51);
  if ( !*(_BYTE *)(v3 + 364) )
  {
    v6 = *(unsigned __int8 *)(v3 + 364);
    v37 = 0;
    v7 = v6;
    v8 = 1000000 * v43 + 1023;
    if ( 1000000 * v43 >= 0 )
      v8 = 1000000 * v43;
    v47 = v8 >> 10;
    while ( 1 )
    {
      v10 = sub_244C4(a1, v45);
      *(_BYTE *)(a1 + 62) = 0;
      *(_BYTE *)(v3 + 172) = 1;
      v11 = v10;
      sub_2B13C(&v50);
      *(_DWORD *)(v11 + 248) = 0;
      *(_QWORD *)(v3 + 160) = 0;
      if ( !(*(int (__fastcall **)(int, int))(v38 + 56))(a1, v11) )
      {
        if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
        {
          snprintf((char *)s, 0x800u, "work prepare failed, exiting mining thread %d", v45);
          sub_38438(3, (const char *)s, 0);
        }
        goto LABEL_81;
      }
      v12 = *(double *)(v11 + 376);
      v13 = *(double *)(v38 + 104);
      if ( v13 > v12 )
        v13 = *(double *)(v11 + 376);
      *(double *)(v11 + 224) = v13;
      v14 = (unsigned __int8)byte_63DF9;
      if ( v13 < *(double *)(v38 + 120) )
        v13 = *(double *)(v38 + 120);
      *(double *)(v11 + 224) = v13;
      if ( !v14 )
      {
        v42 = (int *)(v3 + 296);
        v39 = (_DWORD *)(v3 + 304);
        v40 = (_DWORD *)(v3 + 312);
        v41 = (struct timeval *)(v11 + 424);
        goto LABEL_29;
      }
      LODWORD(v24) = sub_493DC(*(__int64 *)&dword_636A8);
      if ( v24 / dbl_5F898 * 60.0 <= 30.0 )
        break;
      v25 = *(double *)(v38 + 112);
      if ( v25 >= *(double *)(v38 + 104) || v12 <= v25 )
        goto LABEL_74;
      v5 = byte_630C1 == 0;
      v26 = v25 + 1.0;
      *(double *)(v38 + 112) = v25 + 1.0;
      if ( !v5 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        snprintf((char *)s, 0x800u, "Driver %s working diff changed to %.0f", *(const char **)(v38 + 4), v25 + 1.0);
        sub_38438(7, (const char *)s, 0);
        v26 = *(double *)(v38 + 112);
      }
      if ( *(double *)(v11 + 376) < v26 )
        v26 = *(double *)(v11 + 376);
      *(double *)(v11 + 224) = v26;
LABEL_72:
      sub_15D7C(v11 + 441);
      v42 = (int *)(v3 + 296);
      v39 = (_DWORD *)(v3 + 304);
      v40 = (_DWORD *)(v3 + 312);
      v41 = (struct timeval *)(v11 + 424);
      while ( 1 )
      {
LABEL_29:
        sub_2B13C(&v49);
        sub_2AD38(&v49, &v48.tv_sec);
        sub_2AD6C(&v48, v42);
        if ( sub_2ADB8(&v48, v39) )
          sub_2AE20(v39, &v48);
        if ( sub_2ADEC(&v48, v40) )
          sub_2AE20(v40, &v48);
        ++*(_DWORD *)(v3 + 292);
        v15 = *(_DWORD **)(v11 + 260);
        sub_2AD6C(&v48, v15 + 95);
        if ( sub_2ADB8(&v48, v15 + 97) )
          sub_2AE20(v15 + 97, &v48);
        if ( sub_2ADEC(&v48, v15 + 99) )
          sub_2AE20(v15 + 99, &v48);
        ++v15[94];
        sub_2B13C(v41);
        pthread_setcancelstate(1, 0);
        sub_F7D4(a1);
        v16 = ((__int64 (__fastcall *)(int, int, unsigned int, _DWORD))*(_DWORD *)(v38 + 64))(
                a1,
                v11,
                v44 + *(_DWORD *)(v11 + 248),
                0);
        sub_F808(a1);
        pthread_setcancelstate(0, 0);
        pthread_testcancel();
        sub_2B13C(&v48);
        if ( v16 == -1 )
          break;
        tv_usec = v48.tv_usec;
        tv_sec = v50.tv_sec;
        v37 += v16;
        if ( *(_QWORD *)(v3 + 160) < v16 )
          *(_QWORD *)(v3 + 160) = v16;
        v19 = v48.tv_sec;
        v20 = tv_usec - v49.tv_usec + (tv_usec - v49.tv_usec < 0 ? 0xF4000 : 0);
        v9 = v48.tv_sec - tv_sec;
        if ( tv_usec - v49.tv_usec < 0 )
          v20 += 576;
        v21 = v48.tv_sec - v49.tv_sec;
        v6 += v20;
        if ( tv_usec - v49.tv_usec < 0 )
          --v21;
        v7 += v21;
        if ( v6 > 1000000 )
        {
          ++v7;
          v6 -= 1000000;
        }
        if ( tv_usec - v50.tv_usec < 0 )
          --v9;
        if ( v43 > v7 )
        {
          if ( v44 == -1 )
            goto LABEL_19;
          v27 = v6 + 1024;
          v30 = v48.tv_sec;
          if ( v6 + 1024 < 0 )
            v27 = v6 + 2047;
          v35 = v9;
          v32 = (sub_48F88(1000000, v27 >> 10) + 16) * v43;
          v19 = v30;
          v9 = v35;
          if ( v44 <= 0xFFFFFC00 / v32 )
            v44 = (v44 * v32) >> 10;
          else
            v44 = -1;
        }
        else if ( v43 < v7 )
        {
          v19 = v48.tv_sec;
          v44 = v43 * v44 / v7;
        }
        else if ( v6 > (int)&loc_186A0 )
        {
          v31 = v48.tv_sec;
          v36 = v9;
          v28 = sub_48F88(1000000 * v43 + v6, v47);
          v19 = v31;
          v9 = v36;
          v44 = (v44 << 10) / v28;
        }
        v22 = v19 - v51.tv_sec;
        v23 = tv_usec - v51.tv_usec;
        if ( v23 < 0 )
        {
          --v22;
          v23 += 1000000;
        }
        if ( v37 && (v22 > 0 || v23 > (int)&loc_30D40) || dword_6006C <= v22 )
        {
          v33 = v9;
          sub_1C834(v45, v37);
          sub_2AE20(&v51, &v48);
          v9 = v33;
          v37 = 0;
        }
        if ( *(_BYTE *)(a1 + 62) )
        {
          if ( !remaining )
          {
            v29 = *(_DWORD *)(a1 + 4);
            s[0].tv_sec = 0;
            s[0].tv_nsec = 250000000 * v29;
            nanosleep(s, 0);
          }
          goto LABEL_21;
        }
        if ( *(_BYTE *)(a1 + 60) || (v7 = *(_DWORD *)(v3 + 32)) != 0 )
        {
          v7 = 0;
          v34 = v9;
          v6 = 0;
          sub_118C4(a1, v45, v38);
          v9 = v34;
        }
        else
        {
          v6 = 0;
        }
LABEL_19:
        if ( v9 > dword_60090 || *(_QWORD *)(v3 + 160) > 0xFFFFFFFD || sub_2282C(v11, 0) )
          goto LABEL_21;
      }
      if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
      {
        snprintf((char *)s, 0x800u, "%s %d failure, disabling!", *(const char **)(v38 + 8), *(_DWORD *)(v3 + 8));
        sub_38438(3, (const char *)s, 0);
      }
      *(_DWORD *)(v3 + 32) = 1;
      sub_2ED00((_DWORD *)v3, 1);
      *(_BYTE *)(v3 + 364) = 1;
LABEL_21:
      sub_152B8((void **)v11);
      if ( *(_BYTE *)(v3 + 364) )
        goto LABEL_81;
    }
    v25 = *(double *)(v38 + 112);
LABEL_74:
    if ( v12 < v25 )
      *(double *)(v38 + 112) = v12;
    goto LABEL_72;
  }
LABEL_81:
  *(_DWORD *)(v3 + 32) = 1;
}
