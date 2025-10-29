void sub_56A90()
{
  int v0; // r0
  pthread_t v1; // [sp+0h] [bp-102Ch] BYREF
  pthread_attr_t attr; // [sp+4h] [bp-1028h] BYREF
  char s[4100]; // [sp+28h] [bp-1004h] BYREF

  pthread_attr_init(&attr);
  pthread_attr_setstacksize(&attr, 0x200000u);
  v0 = pthread_create(&v1, &attr, sub_5664C, 0);
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    snprintf(s, 0x1000u, "httpListenThread start ret=%d", v0);
    sub_38730(5, s, 0);
  }
}
