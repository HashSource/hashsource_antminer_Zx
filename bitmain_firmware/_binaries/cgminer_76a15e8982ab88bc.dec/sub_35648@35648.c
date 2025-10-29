int __fastcall sub_35648(int a1, int a2, int a3, int a4)
{
  char *v5; // r1
  int v6; // r9
  __int64 v7; // r0
  __int64 v8; // d9
  double v9; // r0
  double v10; // d8
  int v11; // r1
  double v12; // d16
  _DWORD *v13; // r0
  _DWORD *v14; // r0
  _DWORD *v15; // r0
  _DWORD *v16; // r0
  _DWORD *v17; // r0
  _DWORD *v18; // r0
  _DWORD *v19; // r0
  _DWORD *v20; // r0
  _DWORD *v21; // r0
  _DWORD *v22; // r0
  _DWORD *v23; // r0
  _DWORD *v24; // r0
  _DWORD *v25; // r0
  _DWORD *v26; // r0
  _DWORD *v27; // r0
  _DWORD *v28; // r0
  _DWORD *v29; // r0
  _DWORD *v30; // r0
  _DWORD *v31; // r0
  _DWORD *v32; // r0
  _DWORD *v33; // r12
  __int64 v34; // r0
  double v35; // d8
  double v36; // r0
  double v37; // d16
  _DWORD *v38; // r11
  double v39; // r0
  double v40; // d16
  _DWORD *v41; // r0
  double v42; // d16
  double v43; // d16
  _DWORD *v44; // r0
  double v45; // d16
  double v46; // d16
  _DWORD *v47; // r0
  _DWORD *v48; // r5
  int result; // r0
  time_t v50; // r0
  int v51; // r11
  int v52; // r11
  int v53; // r10
  time_t v54; // r0
  double v55; // d16
  int v56; // r11
  _DWORD *v58; // [sp+10h] [bp-44h]
  double v59; // [sp+18h] [bp-3Ch] BYREF
  double v60; // [sp+20h] [bp-34h] BYREF
  double v61; // [sp+28h] [bp-2Ch] BYREF
  double v62; // [sp+30h] [bp-24h] BYREF
  double v63; // [sp+38h] [bp-1Ch] BYREF
  double v64; // [sp+40h] [bp-14h] BYREF
  double v65; // [sp+48h] [bp-Ch] BYREF

  sub_32ECC((unsigned int *)a1, 11, 0, 0, a4);
  v5 = "SUMMARY,";
  if ( a4 )
    v5 = ",\"SUMMARY\":[";
  v6 = sub_30638((unsigned int *)a1, v5);
  if ( pthread_mutex_lock(&stru_781AC) )
    sub_B6BC("summary", 2793);
  LODWORD(v7) = sub_59FC8(dbl_78410 + dbl_78498 + dbl_78250);
  *(_QWORD *)&dword_77F28 = v7;
  v8 = v7;
  LODWORD(v9) = sub_59F1C(qword_78248);
  v10 = dbl_72438;
  v60 = dbl_77AE8 / 1000.0 / dbl_72438;
  if ( dbl_72438 == 0.0 )
  {
    v59 = v9 * 60.0;
    v10 = 1.0;
  }
  else
  {
    v59 = v9 / dbl_72438 * 60.0;
  }
  LODWORD(v12) = sub_59F1C(v8);
  HIDWORD(v12) = v11;
  v61 = v12 / v10 * 60.0;
  if ( byte_75C68 )
  {
    v50 = time(0);
    srand(v50);
    if ( *off_739C0 == 122 && off_739C0[1] == 57 && !off_739C0[2] )
    {
      v51 = dword_75C78;
      v52 = 14 * v51 + rand() % 2;
      v53 = v52 % 5;
    }
    else if ( !strcmp(off_739C0, "z9-mini") )
    {
      v56 = dword_75C78;
      v52 = 3 * v56 + 1 + rand() % 2;
      v53 = v52 % 5;
    }
    else
    {
      v53 = 4;
      v52 = 14;
    }
    v54 = time(0);
    srand(v54);
    v55 = (double)(rand() % 99) / 100.0;
    dbl_75C70 = (double)v52 + v55;
    v60 = (double)v52 + v55;
    v59 = v55 + (double)v53;
    v61 = (double)(rand() % 4 + 100) + 0.27;
    sprintf(byte_759C0, "%f", v60 + 0.79);
  }
  v13 = sub_32E3C(0, "Elapsed", (const char *)&dbl_72438, 1);
  v14 = sub_32C8C(v13, "GHS 5s", byte_759C0, 0);
  v15 = sub_34D20(v14, "GHS av", (const char *)&v60, 0);
  v16 = sub_32D64(v15, "Found Blocks", (const char *)&dword_786E0, 1);
  v17 = sub_32DF4(v16, "Getworks", (const char *)&dword_78470, 1);
  v18 = sub_32DF4(v17, "Accepted", (const char *)&qword_78248, 1);
  v19 = sub_32DF4(v18, "Rejected", (const char *)&qword_78520, 1);
  v20 = sub_32D40(v19, "Hardware Errors", (const char *)&dword_786CC, 1);
  v21 = sub_353E8(v20, "Utility", (const char *)&v59, 0);
  v22 = sub_32DF4(v21, "Discarded", (const char *)&dword_785F0, 1);
  v23 = sub_32DF4(v22, "Stale", (const char *)&dword_78AA8, 1);
  v24 = sub_32D64(v23, "Get Failures", (const char *)&dword_78264, 1);
  v25 = sub_32D64(v24, "Local Work", (const char *)&dword_782F4, 1);
  v26 = sub_32D64(v25, "Remote Failures", (const char *)&dword_77C90, 1);
  v27 = sub_32D64(v26, "Network Blocks", (const char *)&dword_78944, 1);
  v28 = sub_353A0(v27, "Total MH", (const char *)&dbl_77AE8, 1);
  v29 = sub_353E8(v28, "Work Utility", (const char *)&v61, 0);
  v30 = sub_35478(v29, "Difficulty Accepted", (const char *)&dbl_78410, 1);
  v31 = sub_35478(v30, "Difficulty Rejected", (const char *)&dbl_78498, 1);
  v32 = sub_35478(v31, "Difficulty Stale", (const char *)&dbl_78250, 1);
  v33 = sub_32DD0(v32, "Best Share", (const char *)&qword_73D50, 1);
  v34 = *(_QWORD *)&dword_77F28 + dword_786CC;
  if ( v34 )
  {
    v58 = v33;
    v35 = (double)dword_786CC;
    LODWORD(v36) = sub_59F1C(v34);
    v33 = v58;
    v37 = v35 / v36;
  }
  else
  {
    v37 = 0.0;
  }
  v62 = v37;
  v38 = sub_35624(v33, "Device Hardware%", (const char *)&v62, 0);
  if ( *(_QWORD *)&dword_77F28 )
  {
    LODWORD(v39) = sub_59F1C(*(__int64 *)&dword_77F28);
    v40 = dbl_78498 / v39;
  }
  else
  {
    v40 = 0.0;
  }
  v63 = v40;
  v41 = sub_35624(v38, "Device Rejected%", (const char *)&v63, 0);
  v42 = dbl_78498 + dbl_78410 + dbl_78250;
  if ( v42 == 0.0 )
    v43 = 0.0;
  else
    v43 = dbl_78498 / v42;
  v64 = v43;
  v44 = sub_35624(v41, "Pool Rejected%", (const char *)&v64, 0);
  v45 = dbl_78410 + dbl_78498 + dbl_78250;
  if ( v45 == 0.0 )
    v46 = 0.0;
  else
    v46 = dbl_78250 / v45;
  v65 = v46;
  v47 = sub_35624(v44, "Pool Stale%", (const char *)&v65, 0);
  v48 = sub_32EA8(v47, "Last getwork", (const char *)&dword_78770, 0);
  if ( pthread_mutex_unlock(&stru_781AC) )
    sub_B794("summary", 2862);
  off_72D18();
  result = sub_323A4((unsigned int *)a1, (int)v48, a4, 0);
  if ( (v6 & a4) != 0 )
    *(_BYTE *)(a1 + 13) = 1;
  return result;
}
