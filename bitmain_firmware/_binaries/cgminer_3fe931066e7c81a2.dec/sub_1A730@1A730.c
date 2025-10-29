int __fastcall sub_1A730(int a1, int a2)
{
  double v2; // d16
  double v5; // d8
  unsigned __int64 v6; // r0
  bool v7; // zf
  double v8; // r0
  double *v9; // r6
  double v10; // d8
  double v11; // r0
  __int64 v12; // r0
  int v13; // r7
  double v14; // r0
  __int64 v15; // r0
  int v16; // r4
  double v17; // r0
  __int64 v18; // r0
  int v19; // r4
  int v21; // r2
  int v22; // r0
  int v23; // r12
  int v24; // r0
  char v25[4096]; // [sp+0h] [bp-1000h] BYREF

  v5 = dbl_75DE0;
  v6 = sub_1A4B4(a2);
  v7 = byte_7B859 == 0;
  if ( byte_7B859 )
    v2 = 65536.0;
  *(_QWORD *)(a2 + 1720) = v6;
  if ( !v7 )
    v5 = v5 * v2;
  LODWORD(v8) = sub_5CB50(v6);
  if ( v5 <= v8 )
  {
    v21 = *(_DWORD *)(a2 + 1748);
    v22 = (unsigned __int8)byte_7AD48;
    v23 = dword_7B8B8;
    *(_BYTE *)(a2 + 1771) = 1;
    v7 = v22 == 0;
    v24 = *(_DWORD *)(v21 + 32);
    dword_7B8B8 = v23 + 1;
    *(_DWORD *)(v21 + 32) = v24 + 1;
    *(_BYTE *)(a2 + 1770) = 1;
    if ( !v7 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(v25, 0x1000u, "Found block for pool %d!", **(_DWORD **)(a2 + 1748));
      sub_38730(5, v25, 0);
    }
  }
  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("update_work_stats", 8383);
  v9 = (double *)(a2 + 1712);
  v10 = *(double *)(a2 + 1712);
  LODWORD(v11) = sub_5CB64(*(__int64 *)&dword_7B100);
  LODWORD(v12) = sub_5CC10(v11 + v10);
  v13 = *(_DWORD *)(a1 + 36);
  *(_QWORD *)&dword_7B100 = v12;
  LODWORD(v14) = sub_5CB64(*(_QWORD *)(v13 + 192));
  LODWORD(v15) = sub_5CC10(v10 + v14);
  *(_QWORD *)(v13 + 192) = v15;
  v16 = *(_DWORD *)(a2 + 1748);
  LODWORD(v17) = sub_5CB64(*(_QWORD *)(v16 + 40));
  LODWORD(v18) = sub_5CC10(v17 + *v9);
  *(_QWORD *)(v16 + 40) = v18;
  v19 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v19 + 232) = time(0);
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("update_work_stats", 8388);
  return off_75ED8();
}
