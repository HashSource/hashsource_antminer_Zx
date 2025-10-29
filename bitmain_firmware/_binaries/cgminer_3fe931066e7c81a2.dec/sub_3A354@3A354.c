void sub_3A354()
{
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_all_hash_board_low", 4386);
    sub_38730(5, s, 0);
  }
  *(_DWORD *)(dword_78E10[0] + 52) = 0xFFFF;
}
