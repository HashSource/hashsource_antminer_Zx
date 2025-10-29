int __fastcall sub_49824(int a1)
{
  int v1; // r0
  _DWORD *v2; // r3
  char v3; // t1
  int v4; // r8
  int v5; // r5
  int v6; // r7
  int v7; // r4
  _DWORD v10[7]; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+1Ch] [bp-4h] BYREF

  v1 = a1 + 32;
  v2 = (_DWORD *)((char *)&v10[-1] + 3);
  memset(v10, 0, sizeof(v10));
  v11 = 0;
  do
  {
    v3 = *(_BYTE *)--v1;
    *((_BYTE *)v2 + 1) = v3;
    v2 = (_DWORD *)((char *)v2 + 1);
  }
  while ( v2 != (int *)((char *)&v11 + 3) );
  v4 = 0;
  v5 = 0;
LABEL_4:
  v6 = v5 + 8;
  v7 = 7;
  while ( !sub_42958((int)v10 + v4, v7--) )
  {
    if ( ++v5 == v6 )
    {
      if ( ++v4 != 32 )
        goto LABEL_4;
      return v5;
    }
  }
  return v5;
}
