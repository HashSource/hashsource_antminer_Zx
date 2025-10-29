int sub_1ABE0()
{
  int *v0; // r12
  int *v1; // r2
  int v2; // r0
  int v3; // t1
  int result; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r6

  sub_2B13C((struct timeval *)&dword_61370);
  sub_2AE20(dword_61378, &dword_61370);
  dbl_64238 = 0.0;
  v0 = (int *)dbl_61380;
  dbl_640B0 = 0.0;
  dbl_638A0 = 0.0;
  dbl_64228 = 0.0;
  dbl_63268 = 0.0;
  do
  {
    *(_QWORD *)v0 = 0;
    v0 += 2;
  }
  while ( v0 != &dword_613E0 );
  dword_63E48 = 0;
  dword_640C0 = 0;
  dbl_5F898 = 1.0;
  dbl_60088 = 1.0;
  dword_613E0 = 0;
  qword_639C8 = 0;
  *(_QWORD *)&dword_636A8 = 0;
  dword_63E44 = 0;
  dbl_63B88 = 0.0;
  dword_63A70 = 0;
  dbl_63C10 = 0.0;
  dword_639E4 = 0;
  dbl_639D0 = 0.0;
  dword_63410 = 0;
  dword_63E58 = 0;
  *(_QWORD *)&dword_63BE8 = 0;
  qword_63C98 = 0;
  *(_QWORD *)&dword_64220 = 0;
  *(_QWORD *)&dword_63D68 = 0;
  if ( dword_63740 > 0 )
  {
    v1 = (int *)dword_639E0;
    v2 = dword_639E0 + 4 * dword_63740;
    do
    {
      v3 = *v1++;
      *(_QWORD *)(v3 + 72) = 0;
      *(_QWORD *)(v3 + 80) = 0;
      *(_QWORD *)(v3 + 88) = 0;
      *(_QWORD *)(v3 + 360) = 0;
      *(_DWORD *)(v3 + 116) = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      *(_DWORD *)(v3 + 20) = 0;
      *(_DWORD *)(v3 + 120) = 0;
      *(_DWORD *)(v3 + 124) = 0;
      *(_DWORD *)(v3 + 128) = 0;
      *(_DWORD *)(v3 + 132) = 0;
      *(_DWORD *)(v3 + 352) = 0;
      *(_DWORD *)(v3 + 40) = 0;
      *(_DWORD *)(v3 + 44) = 0;
    }
    while ( v1 != (int *)v2 );
  }
  result = sub_15BEC();
  if ( dword_63CC0 > 0 )
  {
    v5 = 0;
    do
    {
      v6 = v5++;
      v7 = sub_1AB68(v6);
      sub_2AE20((_DWORD *)(v7 + 368), &dword_61370);
      if ( pthread_mutex_lock(&stru_6392C) )
        sub_B4E4("zero_stats", 5852);
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
      if ( pthread_mutex_unlock(&stru_6392C) )
        sub_B694("zero_stats", 5863);
      off_60178();
      result = (*(int (__fastcall **)(int))(*(_DWORD *)(v7 + 4) + 96))(v7);
    }
    while ( dword_63CC0 > v5 );
  }
  return result;
}
