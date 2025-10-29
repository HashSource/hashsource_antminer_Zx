int __fastcall sub_357C8(int a1, int a2, int a3, int a4)
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

  sub_3305C((unsigned int *)a1, 11, 0, 0, a4);
  v5 = "SUMMARY,";
  if ( a4 )
    v5 = ",\"SUMMARY\":[";
  v6 = sub_307C8((unsigned int *)a1, v5);
  if ( pthread_mutex_lock(&stru_7B384) )
    sub_B774("summary", 2793);
  LODWORD(v7) = sub_5CC10(dbl_7B5E8 + dbl_7B670 + dbl_7B428);
  *(_QWORD *)&dword_7B100 = v7;
  v8 = v7;
  LODWORD(v9) = sub_5CB64(qword_7B420);
  v10 = dbl_755F8;
  v60 = dbl_7ACC0 / dbl_755F8;
  if ( dbl_755F8 == 0.0 )
  {
    v59 = v9 * 60.0;
    v10 = 1.0;
  }
  else
  {
    v59 = v9 / dbl_755F8 * 60.0;
  }
  LODWORD(v12) = sub_5CB64(v8);
  HIDWORD(v12) = v11;
  v61 = v12 / v10 * 60.0;
  if ( byte_78E28 )
  {
    v50 = time(0);
    srand(v50);
    if ( *off_76B84 == 122 && off_76B84[1] == 57 && !off_76B84[2] )
    {
      v51 = dword_78E38;
      v52 = 14 * v51 + rand() % 2;
      v53 = v52 % 5;
    }
    else if ( !strcmp(off_76B84, "z9-mini") )
    {
      v56 = dword_78E38;
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
    dbl_78E30 = (double)v52 + v55;
    v60 = (double)v52 + v55;
    v59 = v55 + (double)v53;
    v61 = (double)(rand() % 4 + 100) + 0.27;
    sprintf(byte_78B84, "%f", v60 + 0.79);
  }
  v13 = sub_32FCC(0, "Elapsed", (const char *)&dbl_755F8, 1);
  v14 = sub_32E1C(v13, "GHS 5s", byte_78B84, 0);
  v15 = sub_34EB0(v14, "GHS av", (const char *)&v60, 0);
  v16 = sub_32EF4(v15, "Found Blocks", (const char *)&dword_7B8B8, 1);
  v17 = sub_32F84(v16, "Getworks", (const char *)&dword_7B648, 1);
  v18 = sub_32F84(v17, "Accepted", (const char *)&qword_7B420, 1);
  v19 = sub_32F84(v18, "Rejected", (const char *)&qword_7B6F8, 1);
  v20 = sub_32ED0(v19, "Hardware Errors", (const char *)&dword_7B8A4, 1);
  v21 = sub_35568(v20, "Utility", (const char *)&v59, 0);
  v22 = sub_32F84(v21, "Discarded", (const char *)&dword_7B7C8, 1);
  v23 = sub_32F84(v22, "Stale", (const char *)&dword_7BC80, 1);
  v24 = sub_32EF4(v23, "Get Failures", (const char *)&dword_7B43C, 1);
  v25 = sub_32EF4(v24, "Local Work", (const char *)dword_7B4CC, 1);
  v26 = sub_32EF4(v25, "Remote Failures", (const char *)&dword_7AE68, 1);
  v27 = sub_32EF4(v26, "Network Blocks", (const char *)&dword_7BB1C, 1);
  v28 = sub_35520(v27, "Total MH", (const char *)&dbl_7ACC0, 1);
  v29 = sub_35568(v28, "Work Utility", (const char *)&v61, 0);
  v30 = sub_355F8(v29, "Difficulty Accepted", (const char *)&dbl_7B5E8, 1);
  v31 = sub_355F8(v30, "Difficulty Rejected", (const char *)&dbl_7B670, 1);
  v32 = sub_355F8(v31, "Difficulty Stale", (const char *)&dbl_7B428, 1);
  v33 = sub_32F60(v32, "Best Share", (const char *)&qword_76F18, 1);
  v34 = *(_QWORD *)&dword_7B100 + dword_7B8A4;
  if ( v34 )
  {
    v58 = v33;
    v35 = (double)dword_7B8A4;
    LODWORD(v36) = sub_5CB64(v34);
    v33 = v58;
    v37 = v35 / v36;
  }
  else
  {
    v37 = 0.0;
  }
  v62 = v37;
  v38 = sub_357A4(v33, "Device Hardware%", (const char *)&v62, 0);
  if ( *(_QWORD *)&dword_7B100 )
  {
    LODWORD(v39) = sub_5CB64(*(__int64 *)&dword_7B100);
    v40 = dbl_7B670 / v39;
  }
  else
  {
    v40 = 0.0;
  }
  v63 = v40;
  v41 = sub_357A4(v38, "Device Rejected%", (const char *)&v63, 0);
  v42 = dbl_7B670 + dbl_7B5E8 + dbl_7B428;
  if ( v42 == 0.0 )
    v43 = 0.0;
  else
    v43 = dbl_7B670 / v42;
  v64 = v43;
  v44 = sub_357A4(v41, "Pool Rejected%", (const char *)&v64, 0);
  v45 = dbl_7B5E8 + dbl_7B670 + dbl_7B428;
  if ( v45 == 0.0 )
    v46 = 0.0;
  else
    v46 = dbl_7B428 / v45;
  v65 = v46;
  v47 = sub_357A4(v44, "Pool Stale%", (const char *)&v65, 0);
  v48 = sub_33038(v47, "Last getwork", (const char *)&dword_7B948, 0);
  if ( pthread_mutex_unlock(&stru_7B384) )
    sub_B84C("summary", 2862);
  off_75ED8();
  result = sub_32534((unsigned int *)a1, (int)v48, a4, 0);
  if ( (v6 & a4) != 0 )
    *(_BYTE *)(a1 + 13) = 1;
  return result;
}
