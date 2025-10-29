unsigned __int64 __fastcall sub_19E80(int a1)
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
  char s[2052]; // [sp+8h] [bp-804h] BYREF

  v1 = 1.7668201e72;
  v3 = *(_QWORD *)(a1 + 216);
  if ( !byte_63DF9 )
    v1 = 2.69595353e67;
  LODWORD(v4) = sub_493C8(v3);
  v5 = v4 * 6.27710174e57;
  LODWORD(v6) = sub_493C8(*(_QWORD *)(a1 + 208));
  v7 = v5 + v6 * 3.40282367e38;
  LODWORD(v8) = sub_493C8(*(_QWORD *)(a1 + 200));
  v9 = v7 + v8 * 1.84467441e19;
  LODWORD(v10) = sub_493C8(*(_QWORD *)(a1 + 192));
  v11 = v9 + v10;
  if ( v9 + v10 == 0.0 )
    v11 = 0.0;
  round();
  LODWORD(v13) = sub_494C0(v1 / v11);
  HIDWORD(v13) = v12;
  if ( pthread_mutex_lock(&stru_63FB0) )
    sub_B4E4("share_diff", 4968);
  if ( pthread_rwlock_wrlock(&stru_63FC8) )
    sub_B550("share_diff", 4968);
  if ( qword_611C8 < v13 )
  {
    v14 = 1;
    qword_611C8 = v13;
    sub_11130(v13, (char *)&dword_60064, 8u, 0);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_DWORD *)(a1 + 260);
  if ( *(_QWORD *)(v15 + 368) < v13 )
    *(_QWORD *)(v15 + 368) = v13;
  if ( pthread_rwlock_unlock(&stru_63FC8) )
    sub_B700("share_diff", 4977);
  if ( pthread_mutex_unlock(&stru_63FB0) )
    sub_B694("share_diff", 4977);
  off_60178();
  if ( v14 && byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf(s, 0x800u, "New best share: %s", (const char *)&dword_60064);
    sub_38438(7, s, 0);
  }
  return v13;
}
