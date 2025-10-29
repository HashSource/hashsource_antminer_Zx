int __fastcall sub_28FC8(const char **a1, int a2, int a3)
{
  const char *v6; // r0
  __int16 v7; // kr00_2
  unsigned int v8; // r6
  int v10; // r4
  const char *v11; // r0
  const char *v12; // r10
  signed int v13; // r0
  size_t v14; // r8
  unsigned int v15; // r6
  struct addrinfo *v16; // [sp+8h] [bp-122Ch] BYREF
  int v17; // [sp+Ch] [bp-1228h] BYREF
  _BYTE buf[4]; // [sp+2Ch] [bp-1208h] BYREF
  char v19; // [sp+30h] [bp-1204h]
  char v20; // [sp+31h] [bp-1203h]
  char v21; // [sp+32h] [bp-1202h]
  char v22; // [sp+33h] [bp-1201h]
  char v23[8]; // [sp+34h] [bp-1200h] BYREF
  _BYTE v24[500]; // [sp+3Ch] [bp-11F8h] BYREF
  struct addrinfo s[126]; // [sp+230h] [bp-1004h] BYREF

  v6 = a1[152];
  buf[0] = 4;
  buf[1] = 1;
  v7 = strtol(v6, 0, 10);
  buf[2] = HIBYTE(v7);
  buf[3] = v7;
  strcpy(v23, "CGMINER");
  v8 = bswap32(inet_addr(a1[156]));
  if ( v8 != -1 )
    goto LABEL_2;
  s[0].ai_family = 2;
  s[0].ai_flags = 0;
  v11 = a1[156];
  s[0].ai_socktype = 0;
  s[0].ai_protocol = 0;
  v16 = (struct addrinfo *)&v17;
  memset(&s[0].ai_addrlen, 0, 16);
  if ( !getaddrinfo(v11, 0, s, &v16) )
  {
    v15 = *(_DWORD *)&v16->ai_addr->sa_data[2];
    freeaddrinfo(v16);
    v8 = bswap32(v15);
    if ( v8 != -1 )
    {
LABEL_2:
      v19 = HIBYTE(v8);
      v22 = v8;
      v20 = BYTE2(v8);
      v21 = BYTE1(v8);
      send(a2, buf, 0x10u, 0);
      goto LABEL_3;
    }
LABEL_22:
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3 )
      return 0;
    snprintf((char *)s, 0x1000u, "Invalid IP address specified for socks4 proxy: %s", a1[156]);
    goto LABEL_8;
  }
  if ( !a3 )
    goto LABEL_22;
  v12 = a1[156];
  v19 = 0;
  v22 = 1;
  v20 = 0;
  v21 = 0;
  v13 = strlen(v12);
  if ( v13 >= 255 )
    v14 = 255;
  else
    v14 = v13;
  memcpy(v24, v12, v14);
  v24[v14] = 0;
  send(a2, buf, v14 + 17, 0);
LABEL_3:
  if ( sub_28BC4(a2) || sub_28BC4(a2) != 90 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3 )
      return 0;
    snprintf((char *)s, 0x1000u, "Bad response from %s:%s SOCKS4 server", a1[157], a1[158]);
LABEL_8:
    sub_38730(4, (const char *)s, 0);
    return 0;
  }
  v10 = 6;
  do
  {
    sub_28BC4(a2);
    --v10;
  }
  while ( v10 );
  return 1;
}
