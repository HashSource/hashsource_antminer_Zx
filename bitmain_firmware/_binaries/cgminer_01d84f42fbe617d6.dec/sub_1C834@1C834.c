void __fastcall sub_1C834(int a1, __int64 a2)
{
  double v3; // d0
  int v6; // r7
  int v7; // r0
  int v8; // r5
  __int64 v9; // r0
  double v10; // r0
  double v11; // d8
  double v12; // r0
  double v13; // r0
  double v14; // r0
  double v15; // r0
  int v16; // r6
  int v17; // r0
  int v18; // r5
  double v19; // r0
  double v20; // r0
  double v21; // r0
  double v22; // r0
  double v23; // r0
  double v24; // d9
  int v25; // r3
  double v26; // d16
  int v27; // r3
  __int64 v28; // d16
  int v29; // r5
  int *v30; // r11
  double v31; // d8
  double v32; // r0
  int v33; // r1
  __int64 v34; // r0
  double v35; // r0
  double v36; // r0
  double v37; // r0
  double v38; // r0
  int v39; // r0
  __int64 v40; // r0
  unsigned __int64 v41; // r0
  unsigned __int64 v42; // r0
  unsigned __int64 v43; // r0
  unsigned __int64 v44; // r0
  unsigned __int64 v45; // r0
  int v46; // [sp+1Ch] [bp-940h]
  __int64 v47; // [sp+20h] [bp-93Ch]
  char v48[16]; // [sp+28h] [bp-934h] BYREF
  char v49[16]; // [sp+38h] [bp-924h] BYREF
  char v50[16]; // [sp+48h] [bp-914h] BYREF
  char v51[256]; // [sp+58h] [bp-904h] BYREF
  char s[2052]; // [sp+158h] [bp-804h] BYREF

  sub_2B13C((struct timeval *)&dword_613E4);
  sub_2B314();
  v6 = dword_613E4;
  if ( dword_613E4 - dword_61428 < dword_6006C )
  {
    if ( a1 < 0 )
      return;
    v46 = 0;
    sub_2AE20(dword_61378, &dword_613E4);
  }
  else
  {
    dword_61428 = dword_613E4;
    byte_6142C ^= byte_6142D;
    sub_2AE20(dword_61378, &dword_613E4);
    if ( a1 < 0 )
    {
      if ( pthread_mutex_lock(&stru_6392C) )
        sub_B4E4("hashmeter", 6741);
      if ( dword_6410C > 0 )
      {
        v16 = 0;
        do
        {
          v17 = v16++;
          v18 = *(_DWORD *)(sub_1C36C(v17) + 36);
          sub_2B314();
          sub_2AE20((_DWORD *)(v18 + 140), &dword_613E4);
          LODWORD(v19) = v18 + 48;
          sub_152D0(v19);
          LODWORD(v20) = v18 + 56;
          sub_152D0(v20);
          LODWORD(v21) = v18 + 64;
          sub_152D0(v21);
          LODWORD(v22) = v18 + 72;
          v3 = 0.0;
          sub_152D0(v22);
        }
        while ( dword_6410C > v16 );
      }
      if ( pthread_mutex_unlock(&stru_6392C) )
        sub_B694("hashmeter", 6754);
      v46 = 1;
      v47 = a2;
      off_60178();
      goto LABEL_28;
    }
    v46 = 1;
  }
  v7 = sub_1C36C(a1);
  v8 = *(_DWORD *)(v7 + 36);
  sub_2AE20((_DWORD *)(v7 + 44), &dword_613E4);
  *(_DWORD *)(v8 + 240) = v6;
  sub_2B314();
  sub_2AE20((_DWORD *)(v8 + 140), &dword_613E4);
  LODWORD(v9) = sub_4943C(a2, 1000000);
  v47 = v9;
  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    LODWORD(v15) = sub_493C8(a2);
    snprintf(s, 0x800u, "[thread %d: %llu hashes, %.1f mhash/sec]", a1, v47, v15 / v3 / 1000000.0);
    sub_38438(7, s, 0);
  }
  if ( pthread_mutex_lock(&stru_6392C) )
    sub_B4E4("hashmeter", 6715);
  LODWORD(v10) = sub_493C8(v47);
  v11 = v10;
  LODWORD(v10) = v8 + 48;
  *(double *)(v8 + 80) = *(double *)(v8 + 80) + v11;
  sub_152D0(v10);
  LODWORD(v12) = v8 + 56;
  sub_152D0(v12);
  LODWORD(v13) = v8 + 64;
  sub_152D0(v13);
  LODWORD(v14) = v8 + 72;
  v3 = v11;
  sub_152D0(v14);
  if ( pthread_mutex_unlock(&stru_6392C) )
    sub_B694("hashmeter", 6721);
  off_60178();
  sub_1715C(v51, 0x100u, v8);
  if ( byte_612F8 )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(s, 0x800u, "%s", v51);
      sub_38438(7, s, 0);
    }
  }
  else
  {
    printf("%s          \r", v51);
    fflush((FILE *)stdout);
  }
LABEL_28:
  if ( pthread_mutex_lock(&stru_6392C) )
    sub_B4E4("hashmeter", 6757);
  LODWORD(v23) = sub_493C8(v47);
  v24 = v23;
  dbl_63268 = v23 + dbl_63268;
  if ( v46 )
  {
    v27 = dword_613E0 + 1;
    v28 = 0;
    v29 = 0;
    v30 = (int *)dbl_61380;
    if ( dword_613E0 + 1 > 11 )
      v27 = 0;
    dword_613E0 = v27;
    do
    {
      v31 = *(double *)v30;
      v30 += 2;
      if ( v31 >= 0.0 )
      {
        LODWORD(v32) = sub_493C8(v28);
        ++v29;
        LODWORD(v28) = sub_494C0(v31 + v32);
        HIDWORD(v28) = v33;
      }
    }
    while ( v30 != &dword_613E0 );
    if ( v29 )
    {
      LODWORD(v34) = sub_4943C(v28, v29);
      v47 = v34;
    }
    sub_493C8(v47);
    LODWORD(v35) = &dbl_640B0;
    sub_152D0(v35);
    LODWORD(v36) = &dbl_64238;
    sub_152D0(v36);
    LODWORD(v37) = &dbl_64228;
    sub_152D0(v37);
    LODWORD(v38) = &dbl_638A0;
    v39 = sub_152D0(v38);
    v3 = dbl_640B0;
    v40 = llround(v39);
    v26 = 0.0;
    v25 = dword_613E0;
    dbl_61380[dword_613E0] = 0.0;
    *(_QWORD *)&dword_64070 = 1000000 * v40;
  }
  else
  {
    v25 = dword_613E0;
    v26 = dbl_61380[dword_613E0];
  }
  dbl_61380[v25] = v26 + v24;
  sub_2B314();
  dbl_5F898 = v3;
  if ( v3 - dbl_60088 > 86400.0 )
  {
    if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
    {
      snprintf(s, 0x800u, "cgminer time error total_secs = %f last_total_secs = %f", v3, dbl_60088);
      sub_38438(3, s, 0);
    }
    if ( pthread_mutex_unlock(&stru_6392C) )
      sub_B694("hashmeter", 6797);
    off_60178();
    sub_1ABE0();
    if ( pthread_mutex_lock(&stru_6392C) )
      sub_B4E4("hashmeter", 6799);
  }
  else
  {
    dbl_60088 = v3;
  }
  if ( v46 )
  {
    LODWORD(v41) = sub_494C0(dbl_63268 / dbl_5F898 * 1000000.0);
    sub_11130(v41, v48, 0x10u, 4);
    dbl_61430 = dbl_640B0 / 1000.0;
    LODWORD(v42) = sub_494C0(dbl_640B0 * 1000000.0);
    sub_11130(v42, v49, 0x10u, 4);
    LODWORD(v43) = sub_494C0(dbl_64238 * 1000000.0);
    sub_11130(v43, v50, 0x10u, 4);
    LODWORD(v44) = sub_494C0(dbl_64228 * 1000000.0);
    sub_11130(v44, v51, 0x10u, 4);
    LODWORD(v45) = sub_494C0(dbl_638A0 * 1000000.0);
    sub_11130(v45, s, 0x10u, 4);
    snprintf(byte_61438, 0x100u, "(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s", dword_6006C, v49, v50, v51, s, v48);
  }
  if ( pthread_mutex_unlock(&stru_6392C) )
    sub_B694("hashmeter", 6828);
  off_60178();
  if ( v46 )
  {
    if ( byte_612F8 )
    {
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        snprintf(s, 0x800u, "%s", byte_61438);
        sub_38438(7, s, 0);
      }
    }
    else
    {
      printf("%s          \r", byte_61438);
      fflush((FILE *)stdout);
    }
  }
}
