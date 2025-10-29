void sub_152E0()
{
  int v0; // r7
  unsigned int v1; // r4
  int v2; // r8
  int *v3; // r6
  int *v4; // r3
  int v5; // t1
  unsigned int v6; // r2
  int v7; // t1
  unsigned int v8; // r5
  int v9; // r8
  int v10; // r6
  int v11; // r10
  _DWORD *v12; // t1
  char v13[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = dword_7B198;
  if ( dword_7B198 <= 0 )
  {
    v1 = 1;
  }
  else
  {
    v1 = -1;
    v2 = dword_7B438 + 4 * dword_7B198;
    v3 = (int *)dword_7B438;
    v4 = (int *)dword_7B438;
    do
    {
      v5 = *v4++;
      v6 = *(_DWORD *)(v5 + 56);
      if ( v6 && v1 >= v6 )
        v1 = v6;
    }
    while ( v4 != (int *)v2 );
    if ( v1 == -1 )
    {
      v1 = 1;
    }
    else
    {
      do
      {
        while ( 1 )
        {
          v7 = *v3++;
          v8 = *(_DWORD *)(v7 + 56);
          if ( v8 )
            break;
          if ( v3 == (int *)v2 )
            goto LABEL_13;
        }
        while ( v8 % v1 )
          --v1;
      }
      while ( v3 != (int *)v2 );
    }
LABEL_13:
    v9 = dword_7B438 - 4;
    v10 = 0;
    v11 = dword_755F0[0];
    do
    {
      v12 = *(_DWORD **)(v9 + 4);
      v9 += 4;
      ++v10;
      v12[16] = v12[16] * v11 / v1;
      v12[15] = v12[14] / v1;
    }
    while ( v10 < v0 );
  }
  dword_755F0[0] = v1;
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(v13, 0x1000u, "Global quota greatest common denominator set to %lu", v1);
    sub_38730(7, v13, 0);
  }
}
