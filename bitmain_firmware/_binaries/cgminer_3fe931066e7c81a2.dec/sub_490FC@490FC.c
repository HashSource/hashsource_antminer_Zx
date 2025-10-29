void __fastcall sub_490FC(int a1, int a2)
{
  char *v4; // r6
  int v5; // r3
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(s, 0x1000u, "Chain %d %s", a1, "set_temperature_offset_value_chain_sensor");
    sub_38730(4, s, 0);
  }
  v4 = (char *)&dword_78E10[a1] + a2;
  sub_4633C(a1, a2, 76, 0x11u, v4[3540]);
  sub_2A92C();
  sub_4886C(a1, a2, 76, 0x11u);
  v5 = v4[3460];
  if ( v5 == v4[3540] )
  {
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "%s: Chain%d Sensor%d temp offset : %02d, ",
        "set_temperature_offset_value_chain_sensor",
        a1,
        a2,
        v4[3460]);
      sub_38730(5, s, 0);
    }
  }
  else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s: Chain%d Sensor%d temp offset value set error. It should be %02d, but read back is %02d\n",
      "set_temperature_offset_value_chain_sensor",
      a1,
      a2,
      v4[3540],
      v5);
    sub_38730(3, s, 0);
  }
}
