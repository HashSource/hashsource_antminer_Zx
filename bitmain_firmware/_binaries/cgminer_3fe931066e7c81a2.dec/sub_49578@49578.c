int __fastcall sub_49578(char a1)
{
  int v2; // r4
  int result; // r0
  char v4[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(v4, "check_every_chain_asic_number");
    sub_38730(5, v4, 0);
  }
  v2 = 0;
  do
  {
    sub_4952C(v2, a1);
    v2 = (unsigned __int8)(v2 + 1);
    result = sub_2A92C();
  }
  while ( (unsigned __int8)v2 != 4 );
  return result;
}
