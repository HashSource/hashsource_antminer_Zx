void sub_4962C()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(v3, "check_every_chain_asic_pll");
    sub_38730(5, v3, 0);
  }
  v0 = 644283;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      sub_481EC(i, 0, 12, 1);
      sub_2A92C();
    }
  }
}
