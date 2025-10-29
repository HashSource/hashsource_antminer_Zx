void __fastcall sub_1B514(int a1, __int64 a2)
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

  sub_2A7A4((struct timeval *)&dword_73F80);
  sub_2A97C();
  v6 = dword_73F80;
  if ( dword_73F80 - dword_73F88 < dword_72C0C )
  {
    if ( a1 < 0 )
      return;
    sub_2A488(dword_73F10, &dword_73F80);
    v7 = 0;
  }
  else
  {
    dword_73F88 = dword_73F80;
    byte_73F8C ^= byte_73F8D;
    sub_2A488(dword_73F10, &dword_73F80);
    if ( a1 < 0 )
    {
      if ( pthread_mutex_lock(&stru_781AC) )
        sub_B35C("hashmeter", 6763);
      if ( dword_78994 > 0 )
      {
        v15 = 0;
        do
        {
          v16 = v15++;
          v17 = *(_DWORD *)(sub_1AA90(v16) + 36);
          sub_2A97C();
          sub_2A488((_DWORD *)(v17 + 140), &dword_73F80);
          HIDWORD(v18) = dword_72C0C;
          LODWORD(v18) = v17 + 48;
          sub_156D0(v18);
          LODWORD(v19) = v17 + 56;
          sub_156D0(v19);
          LODWORD(v20) = v17 + 64;
          sub_156D0(v20);
          LODWORD(v21) = v17 + 72;
          v3 = 0.0;
          sub_156D0(v21);
        }
        while ( dword_78994 > v15 );
      }
      if ( pthread_mutex_unlock(&stru_781AC) )
        sub_B50C("hashmeter", 6776);
      v7 = 1;
      off_72D18();
      goto LABEL_24;
    }
    v7 = 1;
  }
  v8 = sub_1AA90(a1);
  v9 = *(_DWORD *)(v8 + 36);
  sub_2A488((_DWORD *)(v8 + 44), &dword_73F80);
  *(_DWORD *)(v9 + 240) = v6;
  sub_2A97C();
  sub_2A488((_DWORD *)(v9 + 140), &dword_73F80);
  if ( pthread_mutex_lock(&stru_781AC) )
    sub_B35C("hashmeter", 6737);
  LODWORD(v10) = sub_59F08(a2);
  v11 = v10;
  HIDWORD(v10) = dword_72C0C;
  LODWORD(v10) = v9 + 48;
  *(double *)(v9 + 80) = *(double *)(v9 + 80) + v11;
  sub_156D0(v10);
  LODWORD(v12) = v9 + 56;
  sub_156D0(v12);
  LODWORD(v13) = v9 + 64;
  sub_156D0(v13);
  LODWORD(v14) = v9 + 72;
  v3 = v11;
  sub_156D0(v14);
  if ( pthread_mutex_unlock(&stru_781AC) )
    sub_B50C("hashmeter", 6743);
  off_72D18();
  sub_1767C(v48, 0x100u, v9);
  if ( byte_73E80 )
  {
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "%s", v48);
      sub_385C8(7, s, 0);
    }
  }
  else
  {
    printf("%s          \r", v48);
    fflush((FILE *)stdout);
  }
LABEL_24:
  if ( pthread_mutex_lock(&stru_781AC) )
    sub_B35C("hashmeter", 6779);
  LODWORD(v22) = sub_59F08(a2);
  v23 = v22;
  dbl_77AE8 = v22 + dbl_77AE8;
  if ( v7 )
  {
    v26 = dword_73F78 + 1;
    v27 = 0;
    v28 = 0;
    v29 = (int *)dbl_73F18;
    if ( dword_73F78 + 1 > 11 )
      v26 = 0;
    dword_73F78 = v26;
    do
    {
      v30 = *(double *)v29;
      v29 += 2;
      if ( v30 >= 0.0 )
      {
        LODWORD(v31) = sub_59F08(v27);
        ++v28;
        LODWORD(v27) = sub_5A000(v30 + v31);
        HIDWORD(v27) = v32;
      }
    }
    while ( v29 != &dword_73F78 );
    if ( v28 )
    {
      LODWORD(a2) = sub_59F7C(v27, v28);
      HIDWORD(a2) = v33;
    }
    sub_59F08(a2);
    LODWORD(v34) = &dbl_78938;
    sub_156D0(v34);
    LODWORD(v35) = &dbl_78AC0;
    sub_156D0(v35);
    LODWORD(v36) = &dbl_78AB0;
    sub_156D0(v36);
    LODWORD(v37) = &dbl_78120;
    v38 = sub_156D0(v37);
    v3 = dbl_78938;
    v39 = llround(v38);
    v25 = 0.0;
    v24 = dword_73F78;
    dbl_73F18[dword_73F78] = 0.0;
    *(_QWORD *)&dword_788F8 = 1000000 * v39;
  }
  else
  {
    v24 = dword_73F78;
    v25 = dbl_73F18[dword_73F78];
  }
  dbl_73F18[v24] = v25 + v23;
  sub_2A97C();
  dbl_72438 = v3;
  if ( v3 - dbl_72C28 > 86400.0 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
    {
      snprintf(s, 0x1000u, "cgminer time error total_secs = %f last_total_secs = %f", v3, dbl_72C28);
      sub_385C8(3, s, 0);
    }
    if ( pthread_mutex_unlock(&stru_781AC) )
      sub_B50C("hashmeter", 6819);
    off_72D18();
    sub_1B220();
    if ( pthread_mutex_lock(&stru_781AC) )
      sub_B35C("hashmeter", 6821);
  }
  else
  {
    dbl_72C28 = v3;
  }
  if ( v7 )
  {
    LODWORD(v40) = sub_5A000(dbl_77AE8 / dbl_72438 * 1000000.0);
    sub_114B8(v40, v45, 0x10u, 4);
    dbl_73F90 = dbl_78938 / 1000.0;
    LODWORD(v41) = sub_5A000(dbl_78938 * 1000000.0);
    sub_114B8(v41, v46, 0x10u, 4);
    LODWORD(v42) = sub_5A000(dbl_78AC0 * 1000000.0);
    sub_114B8(v42, v47, 0x10u, 4);
    LODWORD(v43) = sub_5A000(dbl_78AB0 * 1000000.0);
    sub_114B8(v43, v48, 0x10u, 4);
    LODWORD(v44) = sub_5A000(dbl_78120 * 1000000.0);
    sub_114B8(v44, s, 0x10u, 4);
    snprintf(byte_73F98, 0x100u, "(%ds):%s (1m):%s (5m):%s (15m):%s (avg):%sh/s", dword_72C0C, v46, v47, v48, s, v45);
  }
  if ( pthread_mutex_unlock(&stru_781AC) )
    sub_B50C("hashmeter", 6850);
  off_72D18();
  if ( v7 )
  {
    if ( byte_73E80 )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(s, 0x1000u, "%s", byte_73F98);
        sub_385C8(7, s, 0);
      }
    }
    else
    {
      printf("%s          \r", byte_73F98);
      fflush((FILE *)stdout);
    }
  }
}
