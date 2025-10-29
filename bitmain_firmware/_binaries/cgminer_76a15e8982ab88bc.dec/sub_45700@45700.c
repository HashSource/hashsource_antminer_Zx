int __fastcall sub_45700(int a1, int a2)
{
  char *v4; // r3
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "%s chainid %d", "reset_chain", a2);
    sub_385C8(4, s, 0);
  }
  pthread_mutex_lock(&stru_75F10);
  dword_75EDC = a2;
  sub_3F4AC();
  pthread_mutex_unlock(&stru_75F10);
  v4 = (char *)dword_75C50 + a2;
  v4[732] = 0;
  v4[776] = 0;
  v4[748] = 1;
  sub_2A334(a1 + (a2 << 6) + 634);
  sub_2A334(a1 + (a2 << 6) + 890);
  byte_7398B = 0;
  pthread_mutex_lock(&stru_75F10);
  dword_75EDC = a2;
  sub_3DC38();
  sub_2A884();
  sub_3DA90();
  sub_2A884();
  pthread_mutex_unlock(&stru_75F10);
  byte_7398B = 1;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_hash_board_low", a2);
    sub_385C8(5, s, 0);
  }
  *(_DWORD *)(dword_75C50[0] + 52) = 1 << a2;
  sub_2A884();
  pthread_mutex_lock(&stru_75F10);
  dword_75EDC = a2;
  sub_3F304();
  pthread_mutex_unlock(&stru_75F10);
  sleep(1u);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s %d", "reset_hash_board_high", a2);
    sub_385C8(5, s, 0);
  }
  *(_DWORD *)(dword_75C50[0] + 52) = 0;
  *((_BYTE *)&dword_75C50[187] + a2) = 0;
  sub_439A0(a2, a1);
  sub_3B998(26);
  sub_2A884();
  sub_43250(a2, 0);
  sub_2A884();
  sub_3B998(0);
  return sub_2A884();
}
