void __fastcall sub_1BBA4(int a1, __int64 a2)
{
  double v3; // d0
  int v6; // r7
  int v7; // r6
  int v8; // r0
  int v9; // r8
  double v10; // r0
  double v11; // d8
  double v12; // r0
  double v13; // r0
  double v14; // r0
  int v15; // r7
  int v16; // r0
  int v17; // r6
  double v18; // r0
  double v19; // r0
  double v20; // r0
  double v21; // r0
  double v22; // r0
  double v23; // d11
  int v24; // r3
  double v25; // d16
  int v26; // r3
  __int64 v27; // d16
  int v28; // r8
  int *v29; // r9
  double v30; // d8
  double v31; // r0
  int v32; // r1
  int v33; // r1
  double v34; // r0
  double v35; // r0
  double v36; // r0
  double v37; // r0
  int v38; // r0
  __int64 v39; // r0
  unsigned __int64 v40; // r0
  unsigned __int64 v41; // r0
  unsigned __int64 v42; // r0
  unsigned __int64 v43; // r0
  unsigned __int64 v44; // r0
  char v45[16]; // [sp+20h] [bp-1134h] BYREF
  char v46[16]; // [sp+30h] [bp-1124h] BYREF
  char v47[16]; // [sp+40h] [bp-1114h] BYREF
  char v48[256]; // [sp+50h] [bp-1104h] BYREF
  char s[4100]; // [sp+150h] [bp-1004h] BYREF

  sub_2A84C((struct timeval *)&dword_77148);
  sub_2AA24();
  v6 = dword_77148;
  if ( dword_77148 - dword_77150 < dword_75DCC )
  {
    if ( a1 < 0 )
      return;
    sub_2A530(dword_770D8, &dword_77148);
    v7 = 0;
  }
  else
  {
    dword_77150 = dword_77148;
    byte_77154 ^= byte_77155;
    sub_2A530(dword_770D8, &dword_77148);
    if ( a1 < 0 )
    {
      if ( pthread_mutex_lock(&stru_7B384) )
        sub_B414("hashmeter", 6763);
      if ( dword_7BB6C > 0 )
      {
        v15 = 0;
        do
        {
          v16 = v15++;
          v17 = *(_DWORD *)(sub_1B124(v16) + 36);
          sub_2AA24();
          sub_2A530((_DWORD *)(v17 + 140), &dword_77148);
          HIDWORD(v18) = dword_75DCC;
          LODWORD(v18) = v17 + 48;
          sub_15798(v18);
          LODWORD(v19) = v17 + 56;
          sub_15798(v19);
          LODWORD(v20) = v17 + 64;
          sub_15798(v20);
          LODWORD(v21) = v17 + 72;
          v3 = 0.0;
          sub_15798(v21);
        }
        while ( dword_7BB6C > v15 );
      }
      if ( pthread_mutex_unlock(&stru_7B384) )
        sub_B5C4("hashmeter", 6776);
      v7 = 1;
      off_75ED8();
      goto LABEL_24;
    }
    v7 = 1;
  }
  v8 = sub_1B124(a1);
  v9 = *(_DWORD *)(v8 + 36);
  sub_2A530((_DWORD *)(v8 + 44), &dword_77148);
  *(_DWORD *)(v9 + 240) = v6;
  sub_2AA24();
  sub_2A530((_DWORD *)(v9 + 140), &dword_77148);
  if ( pthread_mutex_lock(&stru_7B384) )
    sub_B414("hashmeter", 6737);
  LODWORD(v10) = sub_5CB50(a2);
  v11 = v10;
  HIDWORD(v10) = dword_75DCC;
  LODWORD(v10) = v9 + 48;
  *(double *)(v9 + 80) = *(double *)(v9 + 80) + v11;
  sub_15798(v10);
  LODWORD(v12) = v9 + 56;
  sub_15798(v12);
  LODWORD(v13) = v9 + 64;
  sub_15798(v13);
  LODWORD(v14) = v9 + 72;
  v3 = v11;
  sub_15798(v14);
  if ( pthread_mutex_unlock(&stru_7B384) )
    sub_B5C4("hashmeter", 6743);
  off_75ED8();
  sub_17744(v48, 0x100u, v9);
  if ( byte_77018 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "%s", v48);
      sub_38730(7, s, 0);
    }
  }
  else
  {
    printf("%s          \r", v48);
    fflush((FILE *)stdout);
  }
LABEL_24:
  if ( pthread_mutex_lock(&stru_7B384) )
    sub_B414("hashmeter", 6779);
  LODWORD(v22) = sub_5CB50(a2);
  v23 = v22;
  dbl_7ACC0 = v22 + dbl_7ACC0;
  if ( v7 )
  {
    v26 = dword_77140 + 1;
    v27 = 0;
    v28 = 0;
    v29 = (int *)dbl_770E0;
    if ( dword_77140 + 1 > 11 )
      v26 = 0;
    dword_77140 = v26;
    do
    {
      v30 = *(double *)v29;
      v29 += 2;
      if ( v30 >= 0.0 )
      {
        LODWORD(v31) = sub_5CB50(v27);
        ++v28;
        LODWORD(v27) = sub_5CC48(v30 + v31);
        HIDWORD(v27) = v32;
      }
    }
    while ( v29 != &dword_77140 );
    if ( v28 )
    {
      LODWORD(a2) = sub_5CBC4(v27, v28);
      HIDWORD(a2) = v33;
    }
    sub_5CB50(a2);
    LODWORD(v34) = &dbl_7BB10;
    sub_15798(v34);
    LODWORD(v35) = &dbl_7BC98;
    sub_15798(v35);
    LODWORD(v36) = &dbl_7BC88;
    sub_15798(v36);
    LODWORD(v37) = &dbl_7B2F8;
    v38 = sub_15798(v37);
    v3 = dbl_7BB10;
    v39 = llround(v38);
    v25 = 0.0;
    v24 = dword_77140;
    dbl_770E0[dword_77140] = 0.0;
    *(_QWORD *)&dword_7BAD0 = 1000000 * v39;
  }
  else
  {
    v24 = dword_77140;
    v25 = dbl_770E0[dword_77140];
  }
  dbl_770E0[v24] = v25 + v23;
  sub_2AA24();
  dbl_755F8 = v3;
  if ( v3 - dbl_75DE8 > 86400.0 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
    {
      snprintf(s, 0x1000u, "cgminer time error total_secs = %f last_total_secs = %f", v3, dbl_75DE8);
      sub_38730(3, s, 0);
    }
    if ( pthread_mutex_unlock(&stru_7B384) )
      sub_B5C4("hashmeter", 6819);
    off_75ED8();
    sub_1B8B4();
    if ( pthread_mutex_lock(&stru_7B384) )
      sub_B414("hashmeter", 6821);
  }
  else
  {
    dbl_75DE8 = v3;
  }
  if ( v7 )
  {
    LODWORD(v40) = sub_5CC48(dbl_7ACC0 / dbl_755F8 * 1000000.0);
    sub_11580(v40, v45, 0x10u, 4);
    dbl_77158 = dbl_7BB10 / 1000.0;
    LODWORD(v41) = sub_5CC48(dbl_7BB10 * 1000000.0);
    sub_11580(v41, v46, 0x10u, 4);
    LODWORD(v42) = sub_5CC48(dbl_7BC98 * 1000000.0);
    sub_11580(v42, v47, 0x10u, 4);
    LODWORD(v43) = sub_5CC48(dbl_7BC88 * 1000000.0);
    sub_11580(v43, v48, 0x10u, 4);
    LODWORD(v44) = sub_5CC48(dbl_7B2F8 * 1000000.0);
    sub_11580(v44, s, 0x10u, 4);
    snprintf(byte_77160, 0x100u, "(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s", dword_75DCC, v46, v47, v48, s, v45);
  }
  if ( pthread_mutex_unlock(&stru_7B384) )
    sub_B5C4("hashmeter", 6850);
  off_75ED8();
  if ( v7 )
  {
    if ( byte_77018 )
    {
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        snprintf(s, 0x1000u, "%s", byte_77160);
        sub_38730(7, s, 0);
      }
    }
    else
    {
      printf("%s          \r", byte_77160);
      fflush((FILE *)stdout);
    }
  }
}
