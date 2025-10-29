int __fastcall sub_28BEC(const char **a1, int a2, int a3)
{
  const char *v5; // r3
  const char *v6; // r12
  size_t v7; // r0
  ssize_t v8; // r0
  int v9; // r3
  unsigned __int8 *v10; // r6
  unsigned __int8 v11; // r0
  char v13; // [sp+Fh] [bp-1405h] BYREF
  char s; // [sp+10h] [bp-1404h] BYREF
  char v15; // [sp+11h] [bp-1403h]
  char v16; // [sp+12h] [bp-1402h]
  unsigned __int8 v17; // [sp+13h] [bp-1401h] BYREF
  char v18[4080]; // [sp+410h] [bp-1004h] BYREF

  v5 = a1[156];
  v6 = a1[152];
  if ( a3 )
    snprintf(&s, 0x400u, "CONNECT %s:%s HTTP/1.0\r\n\r\n", v5, v6);
  else
    snprintf(&s, 0x400u, "CONNECT %s:%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", v5, v6, v5, v6);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(v18, 0x1000u, "Sending proxy %s:%s - %s", a1[157], a1[158], &s);
    sub_38730(7, v18, 0);
  }
  v7 = strlen(&s);
  send(a2, &s, v7, 0);
  v8 = recv(a2, &s, 0xCu, 0);
  if ( v8 <= 0 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3 )
      return 0;
    snprintf(v18, 0x1000u, "Couldn't read from proxy %s:%s after sending CONNECT", a1[157], a1[158]);
LABEL_22:
    sub_38730(4, v18, 0);
    return 0;
  }
  v9 = (unsigned __int8)byte_78E09;
  *(&s + v8) = 0;
  if ( v9 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(v18, 0x1000u, "Received from proxy %s:%s - %s", a1[157], a1[158], &s);
    sub_38730(7, v18, 0);
  }
  if ( strcmp(&s, "HTTP/1.1 200") && strcmp(&s, "HTTP/1.0 200") )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 3 )
      return 0;
    snprintf(v18, 0x1000u, "HTTP Error from proxy %s:%s - %s", a1[157], a1[158], &s);
    goto LABEL_22;
  }
  v10 = (unsigned __int8 *)&v13;
  while ( 1 )
  {
    v11 = sub_28BC4(a2);
    *++v10 = v11;
    if ( v11 == 255 )
      break;
    if ( v10 == &v17 )
    {
      while ( strncmp(&s, "\r\n\r\n", 4u) )
      {
        s = v15;
        v15 = v16;
        v16 = v17;
        v17 = sub_28BC4(a2);
        if ( v17 == 255 )
          goto LABEL_18;
      }
      if ( !byte_78E09 || !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
        return 1;
      snprintf(v18, 0x1000u, "Success negotiating with %s:%s HTTP proxy", a1[157], a1[158]);
      sub_38730(7, v18, 0);
      return 1;
    }
  }
LABEL_18:
  if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
  {
    snprintf(v18, 0x1000u, "Couldn't read HTTP byte from proxy %s:%s", a1[157], a1[158]);
    goto LABEL_22;
  }
  return 0;
}
