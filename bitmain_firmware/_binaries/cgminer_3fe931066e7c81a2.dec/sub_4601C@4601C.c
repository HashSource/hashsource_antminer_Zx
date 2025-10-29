int __fastcall sub_4601C(int a1)
{
  int result; // r0
  unsigned int v3; // r4
  int v4; // r5
  char v5; // t1
  _DWORD v6[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v7; // [sp+14h] [bp-1008h]
  char v8; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  result = *((unsigned __int8 *)&unk_9D4B4 + a1 + 8);
  v6[1] = 0;
  v7 = 0;
  v8 = 0;
  v3 = dword_76B5C | 0x4060;
  dword_76B5C |= 0x4060u;
  v6[0] = 0;
  if ( result == 1 )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(s, 0x1000u, "%s: reg_value=0x%08x chainid %u", "enable_read_temperature_from_asic_chain", v3, a1);
      sub_38730(5, s, 0);
    }
    v4 = 495919;
    do
    {
      v5 = *(_BYTE *)++v4;
      sub_3CDCC((int)v6, 0, v5, 28, v3);
      sub_3C150((unsigned __int8)a1, v6, 0xBu);
      result = sub_2A92C();
    }
    while ( v4 != 495922 );
  }
  return result;
}
