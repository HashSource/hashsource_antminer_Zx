void sub_40454()
{
  int v0; // r5
  int v1; // r4
  int v2; // t1
  int v3; // r9
  int v4; // [sp+Ch] [bp-1004h] BYREF
  char s[4080]; // [sp+10h] [bp-1000h] BYREF

  v0 = 644283;
  v1 = 0;
  v4 = 0;
  do
  {
    v2 = *(unsigned __int8 *)++v0;
    if ( v2 == 1 )
    {
      pthread_mutex_lock(&stru_790D0);
      dword_7909C = v1;
      v3 = sub_40128(&s[v1 - 4]);
      sub_2A92C();
      pthread_mutex_unlock(&stru_790D0);
      if ( v3 == 1 )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          snprintf(s, 0x1000u, "chain%d pic version %02x\n", v1, (unsigned __int8)s[v1 - 4]);
          sub_38730(5, s, 0);
        }
      }
      else if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        snprintf(s, 0x1000u, "chain%d pic version read failed\n", v1);
        sub_38730(5, s, 0);
      }
    }
    ++v1;
  }
  while ( v1 != 4 );
}
