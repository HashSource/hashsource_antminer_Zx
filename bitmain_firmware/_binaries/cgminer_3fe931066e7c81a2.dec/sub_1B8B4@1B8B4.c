int sub_1B8B4()
{
  int *v0; // r12
  int *v1; // r2
  int v2; // r4
  int v3; // t1
  int result; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r6

  sub_2A84C((struct timeval *)&dword_770D0);
  sub_2A530(dword_770D8, &dword_770D0);
  dbl_7BC98 = 0.0;
  v0 = (int *)dbl_770E0;
  dbl_7BB10 = 0.0;
  dbl_7B2F8 = 0.0;
  dbl_7BC88 = 0.0;
  dbl_7ACC0 = 0.0;
  do
  {
    *(_QWORD *)v0 = 0;
    v0 += 2;
  }
  while ( v0 != &dword_77140 );
  byte_77144 = 1;
  dword_7B8A8 = 0;
  dword_7BB20 = 0;
  dbl_75DE8 = 1.0;
  dbl_755F8 = 1.0;
  dword_77140 = 0;
  dword_7AE68 = 0;
  *(_QWORD *)&dword_7B648 = 0;
  dword_7B8A4 = 0;
  dbl_7B5E8 = 0.0;
  dword_7B4CC[0] = 0;
  dbl_7B670 = 0.0;
  dword_7B43C = 0;
  dbl_7B428 = 0.0;
  dword_7B8B8 = 0;
  qword_7B420 = 0;
  qword_7B6F8 = 0;
  *(_QWORD *)&dword_7BC80 = 0;
  *(_QWORD *)&dword_7B7C8 = 0;
  *(_QWORD *)&dword_7B100 = 0;
  if ( dword_7B198 > 0 )
  {
    v1 = (int *)dword_7B438;
    v2 = dword_7B438 + 4 * dword_7B198;
    do
    {
      v3 = *v1++;
      *(_QWORD *)(v3 + 104) = 0;
      *(_QWORD *)(v3 + 112) = 0;
      *(_QWORD *)(v3 + 120) = 0;
      *(_QWORD *)(v3 + 392) = 0;
      *(_DWORD *)(v3 + 148) = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      *(_DWORD *)(v3 + 20) = 0;
      *(_DWORD *)(v3 + 152) = 0;
      *(_DWORD *)(v3 + 156) = 0;
      *(_DWORD *)(v3 + 160) = 0;
      *(_DWORD *)(v3 + 164) = 0;
      *(_DWORD *)(v3 + 384) = 0;
      *(_DWORD *)(v3 + 40) = 0;
      *(_DWORD *)(v3 + 44) = 0;
    }
    while ( v1 != (int *)v2 );
  }
  result = sub_160B4();
  if ( dword_7B720 > 0 )
  {
    v5 = 0;
    do
    {
      v6 = v5++;
      v7 = sub_1B83C(v6);
      sub_2A530((_DWORD *)(v7 + 368), &dword_770D0);
      if ( pthread_mutex_lock(&stru_7B384) )
        sub_B414("zero_stats", 5874);
      *(_QWORD *)(v7 + 80) = 0;
      *(_DWORD *)(v7 + 36) = 0;
      *(_QWORD *)(v7 + 192) = 0;
      *(_QWORD *)(v7 + 88) = 0;
      *(_DWORD *)(v7 + 40) = 0;
      *(_QWORD *)(v7 + 200) = 0;
      *(_DWORD *)(v7 + 44) = 0;
      *(_QWORD *)(v7 + 208) = 0;
      *(_DWORD *)(v7 + 220) = 0;
      *(_QWORD *)(v7 + 224) = 0;
      if ( pthread_mutex_unlock(&stru_7B384) )
        sub_B5C4("zero_stats", 5885);
      off_75ED8();
      result = (*(int (__fastcall **)(int))(*(_DWORD *)(v7 + 4) + 96))(v7);
    }
    while ( dword_7B720 > v5 );
  }
  return result;
}
