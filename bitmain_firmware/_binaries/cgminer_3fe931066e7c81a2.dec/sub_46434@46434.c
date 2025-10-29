int __fastcall sub_46434(int a1, int a2)
{
  char *v4; // r3
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(s, 0x1000u, "%s chainid %d", "reset_chain", a2);
    sub_38730(4, s, 0);
  }
  pthread_mutex_lock(&stru_790D0);
  dword_7909C = a2;
  sub_3FC24();
  pthread_mutex_unlock(&stru_790D0);
  v4 = (char *)dword_78E10 + a2;
  v4[732] = 0;
  v4[776] = 0;
  v4[748] = 1;
  sub_2A3DC(a1 + (a2 << 6) + 634);
  sub_2A3DC(a1 + (a2 << 6) + 890);
  byte_76B4B = 0;
  pthread_mutex_lock(&stru_790D0);
  dword_7909C = a2;
  sub_3DF78();
  sub_2A92C();
  sub_3DDD0();
  sub_2A92C();
  pthread_mutex_unlock(&stru_790D0);
  byte_76B4B = 1;
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_hash_board_low", a2);
    sub_38730(5, s, 0);
  }
  *(_DWORD *)(dword_78E10[0] + 52) = 1 << a2;
  sub_2A92C();
  pthread_mutex_lock(&stru_790D0);
  dword_7909C = a2;
  sub_3FA7C();
  pthread_mutex_unlock(&stru_790D0);
  sleep(1u);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_hash_board_high", a2);
    sub_38730(5, s, 0);
  }
  *(_DWORD *)(dword_78E10[0] + 52) = 0;
  *((_BYTE *)&dword_78E10[187] + a2) = 0;
  sub_445E8(a2, a1);
  sub_3BB44(26);
  sub_2A92C();
  sub_43E98(a2, 0);
  sub_2A92C();
  sub_3BB44(0);
  return sub_2A92C();
}
