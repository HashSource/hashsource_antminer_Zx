int __fastcall sub_43F04(int a1)
{
  int v1; // r6
  char v2; // r7
  int v3; // r5
  int i; // r4
  int v5; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = (unsigned __int8)a1;
  v2 = a1;
  byte_9D6F5 = a1;
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "%s: bt8d = %d", "set_baud", a1);
    sub_38730(7, s, 0);
  }
  v3 = 644283;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v5 = *(unsigned __int8 *)++v3;
    if ( v5 == 1 )
      sub_43E98(i, v2);
  }
  sleep(1u);
  sub_3BB44(v1);
  return sub_2A92C();
}
