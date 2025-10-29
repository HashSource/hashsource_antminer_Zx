bool __fastcall extract_sockaddr(char *url, char **sockaddr_url, char **sockaddr_port)
{
  const char *v4; // r1
  char *v5; // r4
  char *v7; // r0
  char *v8; // r6
  char *v9; // r0
  char v10; // r5
  int v11; // r5
  char *v12; // r6
  size_t v13; // r0
  int v14; // r3
  int v15; // r7
  const char *v16; // r2
  int *v17; // r3
  int v18; // r3
  const char *v20; // r2
  char *v21; // r0
  char port[8]; // [sp+8h] [bp-10Ch] BYREF
  char url_address[260]; // [sp+10h] [bp-104h] BYREF

  LOWORD(v4) = -2572;
  HIWORD(v4) = (unsigned int)"ominator set to %lu" >> 16;
  v5 = url;
  *sockaddr_url = url;
  v7 = strstr(url, v4);
  if ( v7 )
    v5 = v7 + 2;
  v8 = strchr(v5, 91);
  v9 = strchr(v5, 93);
  v10 = (char)v9;
  if ( v9 )
    v10 = 1;
  if ( !v8 )
    v10 = 0;
  if ( v8 < v9 )
    v11 = v10 & 1;
  else
    v11 = 0;
  if ( !v11 )
    v9 = v5;
  v12 = strchr(v9, 58);
  v13 = strlen(v5);
  if ( v12 )
  {
    v14 = v12 - v5;
    v15 = ~(v12 - v5) + v13;
    if ( v15 <= 0 )
      return 0;
    ++v12;
  }
  else
  {
    v14 = v13;
    v15 = 0;
  }
  if ( v14 <= 0 )
    return 0;
  LOWORD(v16) = 16348;
  HIWORD(v16) = (unsigned int)"get)" >> 16;
  snprintf(url_address, 0xFEu, v16);
  if ( v15 )
  {
    LOWORD(v20) = 16348;
    HIWORD(v20) = (unsigned int)"get)" >> 16;
    snprintf(port, 6u, v20, v15, v12);
    v21 = strchr(port, 47);
    if ( v21 )
      *v21 = 0;
  }
  else
  {
    LOWORD(v17) = 16356;
    HIWORD(v17) = (unsigned int)"no (false positive; hash > target)" >> 16;
    v18 = *v17;
    *(_WORD *)port = v18;
    port[2] = BYTE2(v18);
  }
  *sockaddr_port = _strdup(port);
  *sockaddr_url = _strdup(url_address);
  return 1;
}
