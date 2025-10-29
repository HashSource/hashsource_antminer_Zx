int __fastcall sub_356A8(int a1, int a2, int a3, int a4)
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
  _DWORD *v51; // [sp+Ch] [bp-40h]
  double v52; // [sp+10h] [bp-3Ch] BYREF
  double v53; // [sp+18h] [bp-34h] BYREF
  double v54; // [sp+20h] [bp-2Ch] BYREF
  double v55; // [sp+28h] [bp-24h] BYREF
  double v56; // [sp+30h] [bp-1Ch] BYREF
  double v57; // [sp+38h] [bp-14h] BYREF
  double v58; // [sp+40h] [bp-Ch] BYREF

  sub_32F3C((unsigned int *)a1, 11, 0, 0, a4);
  v5 = "SUMMARY,";
  if ( a4 )
    v5 = ",\"SUMMARY\":[";
  v6 = sub_30708((unsigned int *)a1, v5);
  if ( pthread_mutex_lock(&stru_6392C) )
    sub_B844("summary", 2788);
  LODWORD(v7) = sub_49488(dbl_63B88 + dbl_63C10 + dbl_639D0);
  *(_QWORD *)&dword_636A8 = v7;
  v8 = v7;
  LODWORD(v9) = sub_493DC(qword_639C8);
  v10 = dbl_5F898;
  v53 = dbl_63268 / dbl_5F898;
  if ( dbl_5F898 == 0.0 )
  {
    v52 = v9 * 60.0;
    v10 = 1.0;
  }
  else
  {
    v52 = v9 / dbl_5F898 * 60.0;
  }
  LODWORD(v12) = sub_493DC(v8);
  HIDWORD(v12) = v11;
  v54 = v12 / v10 * 60.0;
  v13 = sub_32EAC(0, "Elapsed", (const char *)&dbl_5F898, 1);
  v14 = sub_32CFC(v13, "GHS 5s", byte_62E38, 0);
  v15 = sub_34D90(v14, "GHS av", (const char *)&v53, 0);
  v16 = sub_32DD4(v15, "Found Blocks", (const char *)&dword_63E58, 1);
  v17 = sub_32E64(v16, "Getworks", (const char *)&dword_63BE8, 1);
  v18 = sub_32E64(v17, "Accepted", (const char *)&qword_639C8, 1);
  v19 = sub_32E64(v18, "Rejected", (const char *)&qword_63C98, 1);
  v20 = sub_32DB0(v19, "Hardware Errors", (const char *)&dword_63E44, 1);
  v21 = sub_35448(v20, "Utility", (const char *)&v52, 0);
  v22 = sub_32E64(v21, "Discarded", (const char *)&dword_63D68, 1);
  v23 = sub_32E64(v22, "Stale", (const char *)&dword_64220, 1);
  v24 = sub_32DD4(v23, "Get Failures", (const char *)&dword_639E4, 1);
  v25 = sub_32DD4(v24, "Local Work", (const char *)&dword_63A70, 1);
  v26 = sub_32DD4(v25, "Remote Failures", (const char *)&dword_63410, 1);
  v27 = sub_32DD4(v26, "Network Blocks", (const char *)&dword_640BC, 1);
  v28 = sub_35400(v27, "Total MH", (const char *)&dbl_63268, 1);
  v29 = sub_35448(v28, "Work Utility", (const char *)&v54, 0);
  v30 = sub_354D8(v29, "Difficulty Accepted", (const char *)&dbl_63B88, 1);
  v31 = sub_354D8(v30, "Difficulty Rejected", (const char *)&dbl_63C10, 1);
  v32 = sub_354D8(v31, "Difficulty Stale", (const char *)&dbl_639D0, 1);
  v33 = sub_32E40(v32, "Best Share", (const char *)&qword_611C8, 1);
  v34 = *(_QWORD *)&dword_636A8 + dword_63E44;
  if ( v34 )
  {
    v51 = v33;
    v35 = (double)dword_63E44;
    LODWORD(v36) = sub_493DC(v34);
    v33 = v51;
    v37 = v35 / v36;
  }
  else
  {
    v37 = 0.0;
  }
  v55 = v37;
  v38 = sub_35684(v33, "Device Hardware%", (const char *)&v55, 0);
  if ( *(_QWORD *)&dword_636A8 )
  {
    LODWORD(v39) = sub_493DC(*(__int64 *)&dword_636A8);
    v40 = dbl_63C10 / v39;
  }
  else
  {
    v40 = 0.0;
  }
  v56 = v40;
  v41 = sub_35684(v38, "Device Rejected%", (const char *)&v56, 0);
  v42 = dbl_63C10 + dbl_63B88 + dbl_639D0;
  if ( v42 == 0.0 )
    v43 = 0.0;
  else
    v43 = dbl_63C10 / v42;
  v57 = v43;
  v44 = sub_35684(v41, "Pool Rejected%", (const char *)&v57, 0);
  v45 = dbl_63B88 + dbl_63C10 + dbl_639D0;
  if ( v45 == 0.0 )
    v46 = 0.0;
  else
    v46 = dbl_639D0 / v45;
  v58 = v46;
  v47 = sub_35684(v44, "Pool Stale%", (const char *)&v58, 0);
  v48 = sub_32F18(v47, "Last getwork", (const char *)&dword_63EE8, 0);
  if ( pthread_mutex_unlock(&stru_6392C) )
    sub_B91C("summary", 2842);
  off_60178();
  result = sub_32418((unsigned int *)a1, (int)v48, a4, 0);
  if ( (v6 & a4) != 0 )
    *(_BYTE *)(a1 + 13) = 1;
  return result;
}
