pthread_mutex_t *sub_40F40()
{
  int v0; // r5
  int v1; // r3
  bool v2; // r3
  unsigned int v3; // r4
  _BOOL4 v4; // r3
  pthread_mutex_t *result; // r0
  int v6; // r6
  int v7; // r4
  int v8; // [sp+Ch] [bp-1008h]
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    strcpy(s, "check_whether_need_update_pic_program");
    sub_385C8(5, s, 0);
  }
  v0 = 0;
  v8 = 631471;
  do
  {
    v1 = *(unsigned __int8 *)++v8;
    if ( v1 != 1 )
      goto LABEL_6;
    pthread_mutex_lock(&stru_75F10);
    dword_75EDC = v0;
    sub_3DC38();
    sub_2A884();
    sub_3DA90();
    sub_2A884();
    v7 = sub_3F9B0(&byte_75F28[v0]);
    sub_2A884();
    pthread_mutex_unlock(&stru_75F10);
    if ( byte_75F28[v0] <= 0x80u )
      v2 = v7 == 1;
    else
LABEL_6:
      v2 = 0;
    v3 = 0;
    while ( 1 )
    {
      v4 = v3 <= 2 && v2;
      result = &stru_75F10;
      if ( !v4 )
        break;
      pthread_mutex_lock(&stru_75F10);
      dword_75EDC = v0;
      sub_40624();
      sub_2A884();
      sub_3DA90();
      sub_2A884();
      v3 = (unsigned __int8)(v3 + 1);
      v6 = sub_3F9B0(&byte_75F28[v0]);
      pthread_mutex_unlock(&stru_75F10);
      sub_2A884();
      if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
      {
        snprintf(s, 0x1000u, "%s: Chain%d pic update for %d times", "check_whether_need_update_pic_program", v0, v3);
        sub_385C8(5, s, 0);
      }
      v2 = 1;
      if ( byte_75F28[v0] == 129 )
        v2 = v6 == 0;
    }
    ++v0;
  }
  while ( v0 != 4 );
  return result;
}
