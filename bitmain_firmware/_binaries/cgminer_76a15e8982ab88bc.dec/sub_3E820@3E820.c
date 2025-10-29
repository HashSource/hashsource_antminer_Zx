int __fastcall sub_3E820(int a1)
{
  __int16 *v1; // r6
  int i; // r4
  unsigned int v4; // r5
  unsigned int v5; // t1
  int v6; // lr
  int result; // r0
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  v1 = &word_75EF8[3 * a1 - 1];
  for ( i = 0; i != 3; ++i )
  {
    v5 = (unsigned __int16)v1[1];
    ++v1;
    v4 = v5;
    v6 = sub_3E3A0(byte_73988[i], v5);
    if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
    {
      snprintf(
        s,
        0x1000u,
        "chain%d asic%d addr %02x, %s set vol %d, get vol %d",
        a1,
        i,
        (unsigned __int8)byte_73988[i],
        "every_asic_set_isl_voltage",
        v4,
        v6);
      sub_385C8(5, s, 0);
    }
    result = sub_2A884();
  }
  return result;
}
