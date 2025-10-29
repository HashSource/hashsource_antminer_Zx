void __fastcall sub_47DA0(int a1, int a2)
{
  char *v4; // r6
  int v5; // r3
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "Chain %d %s", a1, "set_temperature_offset_value_chain_sensor");
    sub_385C8(4, s, 0);
  }
  v4 = (char *)&dword_75C50[a1] + a2;
  sub_45674(a1, a2, 76, 0x11u, v4[3524]);
  sub_2A884();
  sub_475A0(a1, a2, 76, 0x11u);
  v5 = v4[3460];
  if ( v5 == v4[3524] )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "%s: Chain%d Sensor%d temp offset : %02d, ",
        "set_temperature_offset_value_chain_sensor",
        a1,
        a2,
        v4[3460]);
      sub_385C8(5, s, 0);
    }
  }
  else if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
  {
    snprintf(
      s,
      0x1000u,
      "%s: Chain%d Sensor%d temp offset value set error. It should be %02d, but read back is %02d\n",
      "set_temperature_offset_value_chain_sensor",
      a1,
      a2,
      v4[3524],
      v5);
    sub_385C8(3, s, 0);
  }
}
