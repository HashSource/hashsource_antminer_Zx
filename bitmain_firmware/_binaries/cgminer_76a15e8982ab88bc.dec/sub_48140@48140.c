int __fastcall sub_48140(int result)
{
  int v1; // r6
  int v2; // r7
  int v3; // r4
  int v4; // t1
  int v5; // [sp+0h] [bp-Ch] BYREF
  __int16 v6; // [sp+4h] [bp-8h]
  char v7; // [sp+6h] [bp-6h]

  v1 = 631471;
  v2 = result;
  v3 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  do
  {
    v4 = *(unsigned __int8 *)++v1;
    if ( v4 == 1 )
    {
      sub_3CBB0((int)&v5, 1, 0, v2);
      sub_3BFB4(v3, &v5, 7u);
      sub_2A884();
      result = sub_46F24(v3, 0, v2, 1);
    }
    v3 = (unsigned __int8)(v3 + 1);
  }
  while ( v3 != 4 );
  return result;
}
