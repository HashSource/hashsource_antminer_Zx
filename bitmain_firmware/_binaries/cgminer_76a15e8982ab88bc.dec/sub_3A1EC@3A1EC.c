void sub_3A1EC()
{
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_all_hash_board_low", 4070);
    sub_385C8(5, s, 0);
  }
  *(_DWORD *)(dword_75C50[0] + 52) = 0xFFFF;
}
