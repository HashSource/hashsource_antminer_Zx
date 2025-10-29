unsigned __int64 __fastcall sub_19B40(int a1)
{
  double v1; // d9
  __int64 v3; // r0
  double v4; // r0
  double v5; // d8
  double v6; // r0
  double v7; // d8
  double v8; // r0
  double v9; // d8
  double v10; // r0
  double v11; // d0
  int v12; // r1
  unsigned __int64 v13; // r4
  int v14; // r7
  int v15; // r1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = 1.7668201e72;
  v3 = *(_QWORD *)(a1 + 216);
  if ( !byte_78681 )
    v1 = 2.69595353e67;
  LODWORD(v4) = sub_59F08(v3);
  v5 = v4 * 6.27710174e57;
  LODWORD(v6) = sub_59F08(*(_QWORD *)(a1 + 208));
  v7 = v5 + v6 * 3.40282367e38;
  LODWORD(v8) = sub_59F08(*(_QWORD *)(a1 + 200));
  v9 = v7 + v8 * 1.84467441e19;
  LODWORD(v10) = sub_59F08(*(_QWORD *)(a1 + 192));
  v11 = v9 + v10;
  if ( v9 + v10 == 0.0 )
    v11 = 0.0;
  round(LODWORD(v10));
  LODWORD(v13) = sub_5A000(v1 / v11);
  HIDWORD(v13) = v12;
  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("share_diff", 4986);
  if ( pthread_rwlock_wrlock(&stru_78850) )
    sub_B3C8("share_diff", 4986);
  if ( qword_73D50 < v13 )
  {
    v14 = 1;
    qword_73D50 = v13;
    sub_114B8(v13, (char *)&dword_72C04, 8u, 0);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_DWORD *)(a1 + 1748);
  if ( *(_QWORD *)(v15 + 400) < v13 )
    *(_QWORD *)(v15 + 400) = v13;
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("share_diff", 4995);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("share_diff", 4995);
  off_72D18();
  if ( v14 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "New best share: %s", (const char *)&dword_72C04);
    sub_385C8(7, s, 0);
  }
  return v13;
}
