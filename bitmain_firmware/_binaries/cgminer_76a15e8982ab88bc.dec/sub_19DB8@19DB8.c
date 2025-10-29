int __fastcall sub_19DB8(int a1, int a2)
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

  v5 = dbl_72C20;
  v6 = sub_19B40(a2);
  v7 = byte_78681 == 0;
  if ( byte_78681 )
    v2 = 65536.0;
  *(_QWORD *)(a2 + 1720) = v6;
  if ( !v7 )
    v5 = v5 * v2;
  LODWORD(v8) = sub_59F08(v6);
  if ( v5 <= v8 )
  {
    v21 = *(_DWORD *)(a2 + 1748);
    v22 = (unsigned __int8)byte_77B70;
    v23 = dword_786E0;
    *(_BYTE *)(a2 + 1771) = 1;
    v7 = v22 == 0;
    v24 = *(_DWORD *)(v21 + 32);
    dword_786E0 = v23 + 1;
    *(_DWORD *)(v21 + 32) = v24 + 1;
    *(_BYTE *)(a2 + 1770) = 1;
    if ( !v7 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(v25, 0x1000u, "Found block for pool %d!", **(_DWORD **)(a2 + 1748));
      sub_385C8(5, v25, 0);
    }
  }
  if ( pthread_mutex_lock(&stru_77B74) )
    sub_B35C("update_work_stats", 8370);
  v9 = (double *)(a2 + 1712);
  v10 = *(double *)(a2 + 1712);
  LODWORD(v11) = sub_59F1C(*(__int64 *)&dword_77F28);
  LODWORD(v12) = sub_59FC8(v11 + v10);
  v13 = *(_DWORD *)(a1 + 36);
  *(_QWORD *)&dword_77F28 = v12;
  LODWORD(v14) = sub_59F1C(*(_QWORD *)(v13 + 192));
  LODWORD(v15) = sub_59FC8(v10 + v14);
  *(_QWORD *)(v13 + 192) = v15;
  v16 = *(_DWORD *)(a2 + 1748);
  LODWORD(v17) = sub_59F1C(*(_QWORD *)(v16 + 40));
  LODWORD(v18) = sub_59FC8(v17 + *v9);
  *(_QWORD *)(v16 + 40) = v18;
  v19 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v19 + 232) = time(0);
  if ( pthread_mutex_unlock(&stru_77B74) )
    sub_B50C("update_work_stats", 8375);
  return off_72D18();
}
