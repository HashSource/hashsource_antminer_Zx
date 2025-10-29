void sub_47C4C()
{
  int v0; // r6
  int i; // r4
  int v2; // t1
  int j; // r5
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(s, "check_sensor_ID");
    sub_385C8(7, s, 0);
  }
  v0 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      for ( j = 0; j != 2; ++j )
      {
        sub_475A0((unsigned __int8)i, (unsigned __int8)j, 76, 0xFEu);
        if ( byte_77B70 || byte_75C48 || dword_73504 > 2 )
        {
          snprintf(
            s,
            0x1000u,
            "%s: Chain%d Sensor%d Manufacturer ID = 0x%02x",
            "check_sensor_ID",
            i,
            j,
            (char)byte_769E4[4 * i + j]);
          sub_385C8(3, s, 0);
        }
      }
    }
  }
}
