int __fastcall sub_1F938(int a1, int a2, int a3)
{
  int v6; // r1
  __int64 v7; // r2
  int v8; // r4
  int v10; // r0

  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("inc_work_stats", 8393);
  v6 = *(_DWORD *)(a1 + 36);
  v7 = *(_QWORD *)(v6 + 192) + a3;
  *(_QWORD *)&dword_7B100 += a3;
  *(_QWORD *)(v6 + 192) = v7;
  if ( a2 )
  {
    *(_QWORD *)(a2 + 40) += a3;
  }
  else
  {
    v10 = sub_1DA58();
    *(_QWORD *)(v10 + 40) += a3;
  }
  v8 = *(_DWORD *)(a1 + 36);
  *(_DWORD *)(v8 + 232) = time(0);
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("inc_work_stats", 8406);
  return off_75ED8();
}
