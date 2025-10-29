int sub_1B220()
{
  int *v0; // r12
  int *v1; // r2
  int v2; // r4
  int v3; // t1
  int result; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r6

  sub_2A7A4((struct timeval *)&dword_73F08);
  sub_2A488(dword_73F10, &dword_73F08);
  dbl_78AC0 = 0.0;
  v0 = (int *)dbl_73F18;
  dbl_78938 = 0.0;
  dbl_78120 = 0.0;
  dbl_78AB0 = 0.0;
  dbl_77AE8 = 0.0;
  do
  {
    *(_QWORD *)v0 = 0;
    v0 += 2;
  }
  while ( v0 != &dword_73F78 );
  byte_73F7C = 1;
  dword_786D0 = 0;
  dword_78948 = 0;
  dbl_72C28 = 1.0;
  dbl_72438 = 1.0;
  dword_73F78 = 0;
  dword_77C90 = 0;
  *(_QWORD *)&dword_78470 = 0;
  dword_786CC = 0;
  dbl_78410 = 0.0;
  dword_782F4 = 0;
  dbl_78498 = 0.0;
  dword_78264 = 0;
  dbl_78250 = 0.0;
  dword_786E0 = 0;
  qword_78248 = 0;
  qword_78520 = 0;
  *(_QWORD *)&dword_78AA8 = 0;
  *(_QWORD *)&dword_785F0 = 0;
  *(_QWORD *)&dword_77F28 = 0;
  if ( dword_77FC0 > 0 )
  {
    v1 = (int *)dword_78260;
    v2 = dword_78260 + 4 * dword_77FC0;
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
  result = sub_15FEC();
  if ( dword_78548 > 0 )
  {
    v5 = 0;
    do
    {
      v6 = v5++;
      v7 = sub_1B1A8(v6);
      sub_2A488((_DWORD *)(v7 + 368), &dword_73F08);
      if ( pthread_mutex_lock(&stru_781AC) )
        sub_B35C("zero_stats", 5874);
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
      if ( pthread_mutex_unlock(&stru_781AC) )
        sub_B50C("zero_stats", 5885);
      off_72D18();
      result = (*(int (__fastcall **)(int))(*(_DWORD *)(v7 + 4) + 96))(v7);
    }
    while ( dword_78548 > v5 );
  }
  return result;
}
