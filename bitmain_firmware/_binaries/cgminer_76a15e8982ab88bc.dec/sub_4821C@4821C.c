int __fastcall sub_4821C(char a1)
{
  int v2; // r4
  int result; // r0
  char v4[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(v4, "check_every_chain_asic_number");
    sub_385C8(5, v4, 0);
  }
  v2 = 0;
  do
  {
    sub_481D0(v2, a1);
    v2 = (unsigned __int8)(v2 + 1);
    result = sub_2A884();
  }
  while ( (unsigned __int8)v2 != 4 );
  return result;
}
