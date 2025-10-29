void __fastcall sub_47F54(int a1)
{
  int v2; // r6
  _BYTE *v3; // r7
  __int16 *v4; // r5
  int v5; // r8
  __int16 v6; // r2
  __int16 v7; // r3
  int v8; // r11
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%d %s", a1, "calibration_sensor_offset_chain");
    sub_385C8(5, s, 0);
  }
  v2 = 0;
  v3 = (char *)&unk_76A14 + 4 * a1;
  v4 = (__int16 *)((char *)&unk_9A2A8 + 16 * a1 + 128);
  do
  {
    LOBYTE(v5) = 11;
    do
    {
      sub_475A0(a1, v2, 76, 1u);
      sub_475A0(a1, v2, 76, 0);
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "chain:%d local:%d remote:%d", a1, *v4, v4[1]);
        sub_385C8(5, s, 0);
      }
      v6 = *v4;
      v7 = v4[1];
      v8 = *v4 - v7;
      if ( v8 < 0 )
        v8 = v7 - v6;
      *v3 = v6 + *v3 - v7;
      if ( v8 <= 2 )
        break;
      sub_47DA0(a1, v2);
      v5 = (unsigned __int8)(v5 - 1);
    }
    while ( v5 );
    ++v3;
    v4 += 4;
    v2 = (unsigned __int8)(v2 + 1);
  }
  while ( v2 != 2 );
}
