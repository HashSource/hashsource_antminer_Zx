int *__fastcall sub_182F4(int a1)
{
  _DWORD *v2; // r4
  int v3; // r6
  _DWORD *v4; // r5
  double v5; // d8
  int v6; // r2
  int **v7; // r3
  int v8; // r1
  int *v9; // r0
  bool v10; // zf
  int v11; // r2
  int v12; // r1
  int v13; // r1
  int v14; // r2
  int v15; // r2
  int v16; // r0
  int *result; // r0
  double v18; // d16
  double v19; // d17
  __int64 v20; // r2
  void **v21; // r11
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&stru_77030) )
    sub_B414("clear_stratum_shares", 6986);
  v2 = (_DWORD *)dword_77048;
  if ( dword_77048 )
  {
    v3 = 0;
    v4 = *(_DWORD **)(dword_77048 + 8);
    v5 = 0.0;
    while ( 1 )
    {
      if ( *(_DWORD *)(v2[9] + 1748) == a1 )
      {
        v6 = v2[1];
        if ( v6 || v2[2] )
        {
          v7 = (int **)dword_77048;
          v8 = *(_DWORD *)dword_77048;
          v9 = *(int **)(*(_DWORD *)dword_77048 + 20);
          if ( (_DWORD *)(*(_DWORD *)(*(_DWORD *)dword_77048 + 16) - (_DWORD)v9) == v2 )
          {
            *(_DWORD *)(v8 + 16) = (char *)v9 + v6;
            v6 = v2[1];
          }
          v10 = v6 == 0;
          if ( v6 )
          {
            v9 = *v7;
            v8 = v2[2];
          }
          else
          {
            v6 = v2[2];
          }
          if ( v10 )
          {
            v7 = (int **)v6;
            dword_77048 = v6;
          }
          else
          {
            v6 += v9[5];
          }
          if ( !v10 )
          {
            *(_DWORD *)(v6 + 8) = v8;
            v6 = v2[2];
          }
          if ( v6 )
            *(_DWORD *)(v6 + (*v7)[5] + 4) = v2[1];
          v11 = 3 * (((*v7)[1] - 1) & v2[7]);
          v12 = **v7 + 12 * (((*v7)[1] - 1) & v2[7]);
          --*(_DWORD *)(v12 + 4);
          v13 = **v7;
          if ( *(_DWORD **)(v13 + 4 * v11) == v2 )
            *(_DWORD *)(v13 + 4 * v11) = v2[4];
          v14 = v2[3];
          if ( v14 )
            *(_DWORD *)(v14 + 16) = v2[4];
          v15 = v2[4];
          if ( v15 )
            *(_DWORD *)(v15 + 12) = v2[3];
          --(*v7)[3];
        }
        else
        {
          v21 = (void **)dword_77048;
          free(**(void ***)dword_77048);
          free(*v21);
          dword_77048 = 0;
        }
        v16 = v2[9];
        ++v3;
        v5 = v5 + *(double *)(v16 + 1864);
        sub_15780((void **)v16);
        v2[9] = 0;
        --*(_DWORD *)(a1 + 756);
        free(v2);
        if ( !v4 )
          goto LABEL_28;
      }
      else if ( !v4 )
      {
        goto LABEL_28;
      }
      v2 = v4;
      v4 = (_DWORD *)v4[2];
    }
  }
  v3 = 0;
  v5 = 0.0;
LABEL_28:
  if ( pthread_mutex_unlock(&stru_77030) )
    sub_B5C4("clear_stratum_shares", 6999);
  result = (int *)off_75ED8();
  if ( v3 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
    {
      snprintf(s, 0x1000u, "Lost %d shares due to stratum disconnect on pool %d", v3, *(_DWORD *)a1);
      sub_38730(4, s, 0);
    }
    v18 = *(double *)(a1 + 120) + v5;
    v19 = dbl_7B428;
    result = &dword_7BC80;
    v20 = *(_QWORD *)&dword_7BC80;
    *(_DWORD *)(a1 + 152) += v3;
    *(_QWORD *)&dword_7BC80 = v20 + v3;
    *(double *)(a1 + 120) = v18;
    dbl_7B428 = v19 + v5;
  }
  return result;
}
