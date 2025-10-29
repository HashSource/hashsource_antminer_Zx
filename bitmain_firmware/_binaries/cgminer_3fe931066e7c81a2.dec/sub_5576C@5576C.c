int __fastcall sub_5576C(int result, int a2, int a3)
{
  __int64 v3; // r4
  int v4; // r7
  int v5; // r3
  int v6; // r8
  int v7; // r6
  int v9; // r2

  v3 = *(_QWORD *)(result + 32);
  v4 = result;
  v5 = v3 & 0x3F;
  if ( a3 )
  {
    v6 = a2 + a3;
    v7 = a2 + 1;
    while ( 1 )
    {
      v9 = v4 + v5++;
      *(_BYTE *)(v9 + 40) = *(_BYTE *)(v7 - 1);
      *(_QWORD *)(v4 + 32) = v3 + 1;
      if ( v5 == 64 )
      {
        result = sub_55470((unsigned __int8 *)v4);
        v5 = 0;
      }
      if ( v7++ == v6 )
        break;
      v3 = *(_QWORD *)(v4 + 32);
    }
  }
  return result;
}
