bool __fastcall extract_sockaddr(char *url, char **sockaddr_url, char **sockaddr_port)
{
  char *v4; // r4
  char *v6; // r0
  char *v7; // r6
  char *v8; // r0
  char v9; // r5
  int v10; // r5
  char *v11; // r6
  size_t v12; // r0
  int v13; // r3
  int v14; // r7
  char *v16; // r0
  char port[8]; // [sp+8h] [bp-10Ch] BYREF
  char url_address[260]; // [sp+10h] [bp-104h] BYREF

  v4 = url;
  *sockaddr_url = url;
  v6 = strstr(url, "//");
  if ( v6 )
    v4 = v6 + 2;
  v7 = strchr(v4, 91);
  v8 = strchr(v4, 93);
  v9 = (char)v8;
  if ( v8 )
    v9 = 1;
  if ( !v7 )
    v9 = 0;
  if ( v7 < v8 )
    v10 = v9 & 1;
  else
    v10 = 0;
  if ( !v10 )
    v8 = v4;
  v11 = strchr(v8, 58);
  v12 = strlen(v4);
  if ( v11 )
  {
    v13 = v11 - v4;
    v14 = ~(v11 - v4) + v12;
    if ( v14 <= 0 )
      return 0;
    ++v11;
  }
  else
  {
    v13 = v12;
    v14 = 0;
  }
  if ( v13 <= 0 )
    return 0;
  if ( v10 )
  {
    v13 -= 2;
    ++v4;
  }
  snprintf(url_address, 0xFEu, "%.*s", v13, v4);
  if ( v14 )
  {
    snprintf(port, 6u, "%.*s", v14, v11);
    v16 = strchr(port, 47);
    if ( v16 )
      *v16 = 0;
  }
  else
  {
    strcpy(port, "80");
  }
  *sockaddr_port = _strdup(port);
  *sockaddr_url = _strdup(url_address);
  return 1;
}
