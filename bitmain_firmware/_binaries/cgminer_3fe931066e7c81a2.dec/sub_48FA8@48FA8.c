void sub_48FA8()
{
  int v0; // r6
  int i; // r4
  int v2; // t1
  int j; // r5
  char s[4100]; // [sp+18h] [bp-1004h] BYREF

  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(s, "check_sensor_ID");
    sub_38730(7, s, 0);
  }
  v0 = 644283;
  for ( i = 0; i != 4; ++i )
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      for ( j = 0; j != 3; ++j )
      {
        sub_4886C((unsigned __int8)i, (unsigned __int8)j, 76, 0xFEu);
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 2 )
        {
          snprintf(
            s,
            0x1000u,
            "%s: Chain%d Sensor%d Manufacturer ID = 0x%02x",
            "check_sensor_ID",
            i,
            j,
            (char)byte_79BA4[4 * i + j]);
          sub_38730(3, s, 0);
        }
      }
    }
  }
}
