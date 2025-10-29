int __fastcall sub_1A0F8(int a1, int a2)
{
  double v2; // d16
  double v5; // d8
  unsigned __int64 v6; // r0
  bool v7; // zf
  double v8; // r0
  double v9; // d8
  double v10; // r0
  __int64 v11; // r0
  int v12; // r6
  double v13; // r0
  __int64 v14; // r0
  int v15; // r6
  double v16; // r0
  __int64 v17; // r0
  int v18; // r4
  int v20; // r2
  int v21; // r0
  int v22; // r12
  int v23; // r0
  char v24[2052]; // [sp+0h] [bp-804h] BYREF

  v5 = dbl_60080;
  v6 = sub_19E80(a2);
  v7 = byte_63DF9 == 0;
  if ( byte_63DF9 )
    v2 = 65536.0;
  *(_QWORD *)(a2 + 232) = v6;
  if ( !v7 )
    v5 = v5 * v2;
  LODWORD(v8) = sub_493C8(v6);
  if ( v5 <= v8 )
  {
    v20 = *(_DWORD *)(a2 + 260);
    v21 = (unsigned __int8)byte_632F0;
    v22 = dword_63E58;
    *(_BYTE *)(a2 + 283) = 1;
    v7 = v21 == 0;
    v23 = *(_DWORD *)(v20 + 32);
    dword_63E58 = v22 + 1;
    *(_DWORD *)(v20 + 32) = v23 + 1;
    *(_BYTE *)(a2 + 282) = 1;
    if ( !v7 || byte_630C0 || dword_60964 > 4 )
    {
      snprintf(v24, 0x800u, "Found block for pool %d!", **(_DWORD **)(a2 + 260));
      sub_38438(5, v24, 0);
    }
  }
  if ( pthread_mutex_lock(&mutex) )
    sub_B4E4("update_work_stats", 8387);
  v9 = *(double *)(a2 + 224);
  LODWORD(v10) = sub_493DC(*(__int64 *)&dword_636A8);
  LODWORD(v11) = sub_49488(v10 + v9);
  v12 = *(_DWORD *)(a1 + 36);
  *(_QWORD *)&dword_636A8 = v11;
  LODWORD(v13) = sub_493DC(*(_QWORD *)(v12 + 192));
  LODWORD(v14) = sub_49488(v9 + v13);
  *(_QWORD *)(v12 + 192) = v14;
  v15 = *(_DWORD *)(a2 + 260);
  LODWORD(v16) = sub_493DC(*(_QWORD *)(v15 + 40));
  LODWORD(v17) = sub_49488(v16 + *(double *)(a2 + 224));
  *(_QWORD *)(v15 + 40) = v17;
  v18 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v18 + 232) = time(0);
  if ( pthread_mutex_unlock(&mutex) )
    sub_B694("update_work_stats", 8392);
  return off_60178();
}
