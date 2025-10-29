void __fastcall sub_3F0A4(int a1)
{
  int v2; // r6
  int i; // r4
  int v4; // t1
  char v5[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(v5, 0x1000u, "set voltage to %d\n", a1);
    sub_38730(5, v5, 0);
  }
  v2 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    v4 = *(unsigned __int8 *)++v2;
    if ( v4 == 1 )
    {
      sub_3F010(i, 0, a1);
      sub_3F010(i, 1, a1);
      sub_3F010(i, 2, a1);
    }
  }
}
