int __fastcall sub_42F7C(int a1)
{
  unsigned __int8 v1; // r5
  int v2; // r4
  unsigned __int8 v3; // r1
  int result; // r0
  char s[4096]; // [sp+10h] [bp-1000h] BYREF

  v1 = a1;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(
      s,
      0x1000u,
      "%s chainID%d asics %d addrInterval %d",
      "software_set_address_chain",
      a1,
      *((unsigned __int8 *)&unk_9D4B4 + a1 + 529),
      (unsigned __int8)byte_9D6F3);
    sub_38730(5, s, 0);
  }
  v2 = 0;
  sub_42F04(v1);
  sub_2A92C();
  do
  {
    v3 = v2++ * byte_9D6F3;
    sub_42F40(v1, v3);
    result = sub_2A92C();
  }
  while ( v2 != 3 );
  return result;
}
