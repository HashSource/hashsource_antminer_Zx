void sub_482D0()
{
  int v0; // r5
  int i; // r4
  int v2; // t1
  char v3[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(v3, "check_every_chain_asic_pll");
    sub_385C8(5, v3, 0);
  }
  v0 = 631471;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      sub_46F24(i, 0, 12, 1);
      sub_2A884();
    }
  }
}
