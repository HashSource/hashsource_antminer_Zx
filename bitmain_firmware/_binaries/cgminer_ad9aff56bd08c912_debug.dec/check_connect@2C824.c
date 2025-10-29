bool __fastcall check_connect(sockaddr_storage *cli, char **connectaddr, char *group)
{
  char *v6; // r0
  int v7; // lr
  char *v8; // r12
  in6_addr *p_client_ip; // r0
  char *v10; // r2
  char *v11; // r1
  int v12; // r3
  int v13; // t1
  int v14; // r5
  int v15; // t1
  int v16; // t1
  bool v18; // r4
  const char *v19; // r1
  const char *v20; // r1
  in6_addr client_ip; // [sp+10h] [bp-34h] BYREF
  char tmp[36]; // [sp+20h] [bp-24h] BYREF

  v6 = (char *)malloc(0x2Eu);
  *connectaddr = v6;
  getnameinfo((const struct sockaddr *)cli, 0x80u, v6, 0x2Eu, 0, 0, 1u);
  if ( cli->ss_family == 2 )
  {
    LOWORD(v19) = 20376;
    HIWORD(v19) = (unsigned int)off_54F18 >> 16;
    sprintf(tmp, v19, *connectaddr);
    inet_pton(10, tmp, &client_ip);
  }
  else
  {
    inet_pton(10, *connectaddr, &client_ip);
  }
  *group = (*_ctype_toupper_loc())[82];
  if ( opt_api_allow )
  {
    if ( ips > 0 )
    {
      v7 = 0;
      v8 = (char *)&ipaccess->ip.__u6_addr8[15];
      while ( 2 )
      {
        p_client_ip = &client_ip;
        v10 = v8 - 16;
        v11 = v8;
        while ( 1 )
        {
          v13 = p_client_ip->__u6_addr8[0];
          p_client_ip = (in6_addr *)((char *)p_client_ip + 1);
          v12 = v13;
          v15 = (unsigned __int8)*++v11;
          v14 = v15;
          v16 = (unsigned __int8)*++v10;
          if ( v16 != (v12 & v14) )
            break;
          if ( v10 == v8 )
          {
            v18 = 1;
            *group = v8[17];
            return v18;
          }
        }
        ++v7;
        v8 += 36;
        if ( v7 != ips )
          continue;
        break;
      }
    }
    return 0;
  }
  else
  {
    v18 = opt_api_network;
    if ( !opt_api_network )
    {
      LOWORD(v20) = 20388;
      HIWORD(v20) = (unsigned int)&_func___12699.__data.__count >> 16;
      if ( !strcmp(*connectaddr, v20) )
      {
        return 1;
      }
      else if ( !client_ip.__u6_addr32[0] && __PAIR64__(client_ip.__u6_addr32[1], 0) == client_ip.__u6_addr32[2] )
      {
        return client_ip.__u6_addr32[3] == 0x1000000;
      }
    }
    return v18;
  }
}
