int __fastcall sub_45310(int a1)
{
  int result; // r0
  unsigned int v3; // r4
  _DWORD v4[2]; // [sp+Ch] [bp-100Ch] BYREF
  __int16 v5; // [sp+14h] [bp-1004h]
  char v6; // [sp+16h] [bp-1002h]
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  result = *((unsigned __int8 *)&unk_9A2A8 + a1 + 8);
  v4[1] = 0;
  v5 = 0;
  v6 = 0;
  v3 = dword_73998 | 0x4060;
  dword_73998 |= 0x4060u;
  v4[0] = 0;
  if ( result == 1 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(s, 0x1000u, "%s: reg_value=0x%08x chainid %u", "enable_read_temperature_from_asic_chain", v3, a1);
      sub_385C8(5, s, 0);
    }
    sub_3CA8C((int)v4, 0, byte_75F70[0], 28, v3);
    sub_3BFB4((unsigned __int8)a1, v4, 0xBu);
    sub_2A884();
    sub_3CA8C((int)v4, 0, byte_75F71, 28, v3);
    sub_3BFB4((unsigned __int8)a1, v4, 0xBu);
    return sub_2A884();
  }
  return result;
}
