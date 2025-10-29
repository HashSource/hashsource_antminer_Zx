int __fastcall callapi(const char *a1, char *name, unsigned int a3)
{
  struct hostent *v6; // r0
  struct hostent *v7; // r6
  int v8; // r0
  int v9; // r8
  int v10; // r4
  char **h_addr_list; // r3
  int v12; // r3
  size_t v13; // r0
  char *v14; // r7
  int v15; // r6
  char *v16; // r5
  ssize_t v17; // r0
  int v18; // r5
  size_t v19; // r1
  int *v21; // r0
  int v22; // r4
  char *v23; // r0
  int *v24; // r0
  char *v25; // r0
  int *v26; // r0
  char *v27; // r0
  int *v28; // r0
  char *v29; // r0
  struct sockaddr v30; // [sp+0h] [bp-14h] BYREF

  v6 = gethostbyname(name);
  if ( !v6 )
  {
    printf("Couldn't get hostname: '%s'\n", name);
    return 1;
  }
  v7 = v6;
  v8 = socket(2, 1, 0);
  v9 = v8;
  if ( v8 == -1 )
  {
    v26 = _errno_location();
    v27 = strerror(*v26);
    printf("Socket initialisation failed: %s\n", v27);
    return 1;
  }
  v10 = 0;
  memset(&v30.sa_data[2], 0, 12);
  h_addr_list = v7->h_addr_list;
  *(_DWORD *)&v30.sa_family = 2;
  v12 = *(_DWORD *)*h_addr_list;
  *(_WORD *)v30.sa_data = __rev16(a3);
  *(_DWORD *)&v30.sa_data[2] = v12;
  if ( connect(v8, &v30, 0x10u) < 0 )
  {
    v28 = _errno_location();
    v29 = strerror(*v28);
    printf("Socket connect failed: %s\n", v29);
    return 1;
  }
  v13 = strlen(a1);
  if ( send(v9, a1, v13, 0) < 0 )
  {
    v21 = _errno_location();
    v22 = 1;
    v23 = strerror(*v21);
    printf("Send failed: %s\n", v23);
  }
  else
  {
    v14 = (char *)malloc(0x10000u);
    if ( !v14 )
    {
      printf("Err: OOM (%d)\n", 0x10000);
      return 1;
    }
    v15 = 0xFFFF;
    while ( 1 )
    {
      v16 = &v14[v10];
      v17 = recv(v9, &v14[v10], v15 - v10, 0);
      v10 += v17;
      if ( v17 < 0 )
      {
        v24 = _errno_location();
        v22 = 1;
        v25 = strerror(*v24);
        printf("Recv failed: %s\n", v25);
        goto LABEL_16;
      }
      if ( !v17 )
        break;
      if ( v15 == v10 )
      {
        v18 = v15 + 0x10000;
        v19 = v15 + 0x10000;
        v15 += 0xFFFF;
        v14 = (char *)realloc(v14, v19);
        if ( !v14 )
        {
          printf("Err: OOM (%d)\n", v18);
          return 1;
        }
      }
    }
    v22 = 0;
LABEL_16:
    *v16 = 0;
    if ( dword_211B0 )
    {
      puts(v14);
    }
    else
    {
      printf("Reply was '%s'\n", v14);
      display(v14);
    }
  }
  close(v9);
  return v22;
}
