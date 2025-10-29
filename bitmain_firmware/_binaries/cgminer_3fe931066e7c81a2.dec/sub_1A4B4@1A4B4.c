unsigned __int64 __fastcall sub_1A4B4(int a1)
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
  if ( !byte_7B859 )
    v1 = 2.69595353e67;
  LODWORD(v4) = sub_5CB50(v3);
  v5 = v4 * 6.27710174e57;
  LODWORD(v6) = sub_5CB50(*(_QWORD *)(a1 + 208));
  v7 = v5 + v6 * 3.40282367e38;
  LODWORD(v8) = sub_5CB50(*(_QWORD *)(a1 + 200));
  v9 = v7 + v8 * 1.84467441e19;
  LODWORD(v10) = sub_5CB50(*(_QWORD *)(a1 + 192));
  v11 = v9 + v10;
  if ( v9 + v10 == 0.0 )
    v11 = 0.0;
  round(LODWORD(v10));
  LODWORD(v13) = sub_5CC48(v1 / v11);
  HIDWORD(v13) = v12;
  if ( pthread_mutex_lock(&stru_7BA10) )
    sub_B414("share_diff", 4986);
  if ( pthread_rwlock_wrlock(&stru_7BA28) )
    sub_B480("share_diff", 4986);
  if ( qword_76F18 < v13 )
  {
    v14 = 1;
    qword_76F18 = v13;
    sub_11580(v13, (char *)&dword_75DC4, 8u, 0);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_DWORD *)(a1 + 1748);
  if ( *(_QWORD *)(v15 + 400) < v13 )
    *(_QWORD *)(v15 + 400) = v13;
  if ( pthread_rwlock_unlock(&stru_7BA28) )
    sub_B630("share_diff", 4995);
  if ( pthread_mutex_unlock(&stru_7BA10) )
    sub_B5C4("share_diff", 4995);
  off_75ED8();
  if ( v14 && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "New best share: %s", (const char *)&dword_75DC4);
    sub_38730(7, s, 0);
  }
  return v13;
}
