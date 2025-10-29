void *__fastcall sub_5664C(void *a1)
{
  int v1; // r0
  int v2; // r3
  int v3; // r0
  int v4; // r12
  int v6; // [sp+Ch] [bp-1030h]
  socklen_t v7; // [sp+10h] [bp-102Ch] BYREF
  int optval; // [sp+14h] [bp-1028h] BYREF
  struct sockaddr addr; // [sp+18h] [bp-1024h] BYREF
  struct sockaddr v10; // [sp+28h] [bp-1014h] BYREF
  char s[4040]; // [sp+38h] [bp-1004h] BYREF

  sleep(0x1Eu);
  do
  {
    v1 = socket(2, 1, 6);
    dword_76B9C = v1;
    if ( v1 < 0 )
    {
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
      {
        strcpy(s, "socket creating failed, try again after 10s...");
        sub_38730(5, s, 0);
      }
      sleep(0xAu);
    }
    else
    {
      optval = 1;
      if ( setsockopt(v1, 1, 2, &optval, 4u) < 0 && (byte_7AD48 || byte_78E08 || dword_766C4 > 3) )
      {
        strcpy(s, "*******************setsockopt(SO_REUSEADDR) failed");
        sub_38730(4, s, 0);
      }
      addr.sa_family = 2;
      *(_WORD *)addr.sa_data = -21481;
      memset(&addr.sa_data[2], 0, 12);
      if ( bind(dword_76B9C, &addr, 0x10u) < 0 )
      {
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          strcpy(s, "http port bind failed! try again after 10s...");
          sub_38730(5, s, 0);
        }
      }
      else
      {
        if ( listen(dword_76B9C, 100) >= 0 )
          break;
        if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
        {
          strcpy(s, "http listen failed! try again after 10s...");
          sub_38730(5, s, 0);
        }
      }
      close(dword_76B9C);
      dword_76B9C = -1;
      sleep(0xAu);
    }
  }
  while ( !byte_7ACB8 );
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 4 )
  {
    strcpy(s, "start listen on 6060 ...");
    sub_38730(5, s, 0);
  }
  if ( !byte_7ACB8 )
  {
LABEL_10:
    v2 = 0;
    while ( !v2 )
    {
      usleep(0x2710u);
      v7 = 16;
      v3 = accept(dword_76B9C, &v10, &v7);
      v2 = (unsigned __int8)byte_7ACB8;
      v4 = v3;
      if ( v3 != -1 )
      {
        if ( byte_7ACB8 )
        {
          close(v3);
          break;
        }
        if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          v6 = v3;
          snprintf(s, 0x1000u, "one client connected sock=%d", v3);
          sub_38730(7, s, 0);
          v4 = v6;
        }
        sub_559D0(v4);
        if ( !byte_7ACB8 )
          goto LABEL_10;
        break;
      }
    }
  }
  close(dword_76B9C);
  dword_76B9C = -1;
  return 0;
}
