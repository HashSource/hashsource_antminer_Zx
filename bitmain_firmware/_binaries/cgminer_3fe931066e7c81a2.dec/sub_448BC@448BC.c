int __fastcall sub_448BC(int a1)
{
  int v2; // r4
  int v3; // r0
  char v5[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(v5, "tty_init");
    sub_38730(5, v5, 0);
  }
  v2 = 0;
  do
  {
    v3 = v2;
    v2 = (unsigned __int8)(v2 + 1);
    sub_445E8(v3, a1);
  }
  while ( v2 != 4 );
  return sub_2A92C();
}
