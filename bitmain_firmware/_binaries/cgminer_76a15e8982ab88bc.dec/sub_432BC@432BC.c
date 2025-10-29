int __fastcall sub_432BC(int a1)
{
  int v1; // r6
  char v2; // r7
  int v3; // r5
  int i; // r4
  int v5; // t1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  v1 = (unsigned __int8)a1;
  v2 = a1;
  byte_9A4C9 = a1;
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "%s: bt8d = %d", "set_baud", a1);
    sub_385C8(7, s, 0);
  }
  v3 = 631471;
  for ( i = 0; i != 4; i = (unsigned __int8)(i + 1) )
  {
    v5 = *(unsigned __int8 *)++v3;
    if ( v5 == 1 )
      sub_43250(i, v2);
  }
  sleep(1u);
  sub_3B998(v1);
  return sub_2A884();
}
