int __fastcall sub_3EEC8(int a1)
{
  __int16 *v1; // r6
  int i; // r4
  unsigned int v4; // r5
  unsigned int v5; // t1
  int v6; // lr
  int result; // r0
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  v1 = &word_790B8[3 * a1 - 1];
  for ( i = 0; i != 3; ++i )
  {
    v5 = (unsigned __int16)v1[1];
    ++v1;
    v4 = v5;
    v6 = sub_3EA50(byte_76B48[i], v5);
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "chain%d asic%d addr %02x, %s set vol %d, get vol %d",
        a1,
        i,
        (unsigned __int8)byte_76B48[i],
        "every_asic_set_isl_voltage",
        v4,
        v6);
      sub_38730(5, s, 0);
    }
    result = sub_2A92C();
  }
  return result;
}
