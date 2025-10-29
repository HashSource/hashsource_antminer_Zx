int __fastcall sub_43C74(int a1)
{
  int v2; // r4
  int v3; // r0
  char v5[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(v5, "tty_init");
    sub_385C8(5, v5, 0);
  }
  v2 = 0;
  do
  {
    v3 = v2;
    v2 = (unsigned __int8)(v2 + 1);
    sub_439A0(v3, a1);
  }
  while ( v2 != 4 );
  return sub_2A884();
}
