void __fastcall sub_4548C(int a1, int a2)
{
  unsigned int v3; // r4
  _DWORD v4[2]; // [sp+Ch] [bp-100Ch] BYREF
  __int16 v5; // [sp+14h] [bp-1004h]
  char v6; // [sp+16h] [bp-1002h]
  char s[4072]; // [sp+18h] [bp-1000h] BYREF

  v4[1] = 0;
  v5 = 0;
  v4[0] = 0;
  v3 = a2 & 0xFFFFFFF8;
  v6 = 0;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s: analog_mux_reg_value = %08x", "select_core_to_check_temperature_chain", a2);
    sub_385C8(5, s, 0);
  }
  if ( *((_BYTE *)&unk_9A2A8 + a1 + 8) == 1 )
  {
    sub_3CA8C((int)v4, 0, byte_75F70[0], 64, v3);
    sub_3BFB4((unsigned __int8)a1, v4, 0xBu);
    sub_2A884();
    sub_3CA8C((int)v4, 0, byte_75F71, 64, v3);
    sub_3BFB4((unsigned __int8)a1, v4, 0xBu);
    sub_2A884();
  }
}
