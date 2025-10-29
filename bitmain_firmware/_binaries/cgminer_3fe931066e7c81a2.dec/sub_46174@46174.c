void __fastcall sub_46174(int a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r4
  char v5; // t1
  _DWORD v6[2]; // [sp+Ch] [bp-1010h] BYREF
  __int16 v7; // [sp+14h] [bp-1008h]
  char v8; // [sp+16h] [bp-1006h]
  char s[4072]; // [sp+18h] [bp-1004h] BYREF

  v6[1] = 0;
  v7 = 0;
  v6[0] = 0;
  v3 = a2 & 0xFFFFFFF8;
  v8 = 0;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s: analog_mux_reg_value = %08x", "select_core_to_check_temperature_chain", a2);
    sub_38730(5, s, 0);
  }
  if ( *((_BYTE *)&unk_9D4B4 + a1 + 8) == 1 )
  {
    v4 = 495919;
    do
    {
      v5 = *(_BYTE *)++v4;
      sub_3CDCC((int)v6, 0, v5, 64, v3);
      sub_3C150((unsigned __int8)a1, v6, 0xBu);
      sub_2A92C();
    }
    while ( v4 != 495922 );
  }
}
