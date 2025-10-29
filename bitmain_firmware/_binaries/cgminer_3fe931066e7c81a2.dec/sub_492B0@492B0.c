void __fastcall sub_492B0(int a1)
{
  int v2; // r7
  __int16 *v3; // r5
  int v4; // r10
  __int16 v5; // r2
  __int16 v6; // r3
  int v7; // r11
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%d %s", a1, "calibration_sensor_offset_chain");
    sub_38730(5, s, 0);
  }
  v2 = 0;
  v3 = (__int16 *)((char *)&unk_9D534 + 24 * a1);
  do
  {
    LOBYTE(v4) = 11;
    do
    {
      sub_4886C(a1, (unsigned __int8)v2, 76, 1u);
      sub_4886C(a1, (unsigned __int8)v2, 76, 0);
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "chain:%d local:%d remote:%d", a1, *v3, v3[1]);
        sub_38730(5, s, 0);
      }
      v5 = *v3;
      v6 = v3[1];
      v7 = *v3 - v6;
      if ( v7 < 0 )
        v7 = v6 - v5;
      byte_79BE4[4 * a1 + v2] = v5 + byte_79BE4[4 * a1 + v2] - v6;
      if ( v7 <= 2 )
        break;
      sub_490FC(a1, (unsigned __int8)v2);
      v4 = (unsigned __int8)(v4 - 1);
    }
    while ( v4 );
    ++v2;
    v3 += 4;
  }
  while ( v2 != 3 );
}
