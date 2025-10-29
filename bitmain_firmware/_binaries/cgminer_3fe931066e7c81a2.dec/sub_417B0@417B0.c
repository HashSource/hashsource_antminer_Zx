pthread_mutex_t *sub_417B0()
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

  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(s, "check_whether_need_update_pic_program");
    sub_38730(5, s, 0);
  }
  v0 = 0;
  v8 = 644283;
  do
  {
    v1 = *(unsigned __int8 *)++v8;
    if ( v1 != 1 )
      goto LABEL_6;
    pthread_mutex_lock(&stru_790D0);
    dword_7909C = v0;
    sub_3DF78();
    sub_2A92C();
    sub_3DDD0();
    sub_2A92C();
    v7 = sub_40128(&byte_790E8[v0]);
    sub_2A92C();
    pthread_mutex_unlock(&stru_790D0);
    if ( byte_790E8[v0] <= 0x80u )
      v2 = v7 == 1;
    else
LABEL_6:
      v2 = 0;
    v3 = 0;
    while ( 1 )
    {
      v4 = v3 <= 2 && v2;
      result = &stru_790D0;
      if ( !v4 )
        break;
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = v0;
      sub_40E94();
      sub_2A92C();
      sub_3DDD0();
      sub_2A92C();
      v3 = (unsigned __int8)(v3 + 1);
      v6 = sub_40128(&byte_790E8[v0]);
      pthread_mutex_unlock(&stru_790D0);
      sub_2A92C();
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "%s: Chain%d pic update for %d times", "check_whether_need_update_pic_program", v0, v3);
        sub_38730(5, s, 0);
      }
      v2 = 1;
      if ( byte_790E8[v0] == 129 )
        v2 = v6 == 0;
    }
    ++v0;
  }
  while ( v0 != 4 );
  return result;
}
