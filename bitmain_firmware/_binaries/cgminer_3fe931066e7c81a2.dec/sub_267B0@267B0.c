void sub_267B0()
{
  int v0; // r3
  unsigned int v1; // r0
  int i; // r2
  char *v3; // r0
  char *v4; // r4
  FILE *v5; // r0
  FILE *v6; // r4
  int v7; // r0
  unsigned int v8; // r0
  char s1; // [sp+Fh] [bp-3091h] BYREF
  struct stat stat_buf; // [sp+10h] [bp-3090h] BYREF
  char filename[4052]; // [sp+6Ch] [bp-3034h] BYREF
  char v12[4052]; // [sp+106Ch] [bp-2034h] BYREF
  char v13[4116]; // [sp+206Ch] [bp-1034h] BYREF

  byte_7BAC8 = 1;
  immedok((WINDOW *)dword_7B430, 1);
  sub_18AD8();
  v0 = dword_75DDC;
  v1 = dword_75DF0;
  for ( i = dword_75DF4; ; i = dword_75DF4 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          snprintf(
            v13,
            0x1000u,
            "[Q]ueue: %d\n[S]cantime: %d\n[E]xpiry: %d\n[W]rite config file\n[C]gminer restart\n",
            v0,
            v1,
            i);
          sub_18BC0(v13);
          strcpy(v13, "Select an option or any other key to return\n");
          sub_18BC0(v13);
          sub_18B44();
          s1 = wgetch((WINDOW *)stdscr);
          if ( strncasecmp(&s1, "q", 1u) )
            break;
          v7 = sub_260D0("Extra work items to queue");
          v0 = v7;
          if ( (unsigned int)v7 > 0x270F )
            goto LABEL_18;
          dword_75DDC = v7;
          if ( v7 >= dword_75DD8 )
          {
            v1 = dword_75DF0;
            i = dword_75DF4;
          }
          else
          {
            dword_75DD8 = v7;
            i = dword_75DF4;
            v1 = dword_75DF0;
          }
        }
        if ( strncasecmp(&s1, "s", 1u) )
          break;
        v1 = sub_260D0("Set scantime in seconds");
        if ( v1 > 0x270F )
          goto LABEL_18;
        dword_75DF0 = v1;
        v0 = dword_75DDC;
        i = dword_75DF4;
      }
      if ( strncasecmp(&s1, "e", 1u) )
        break;
      v8 = sub_260D0("Set expiry time in seconds");
      i = v8;
      if ( v8 > 0x270F )
      {
LABEL_18:
        strcpy(v13, "Invalid selection\n");
        sub_18BC0(v13);
        v0 = dword_75DDC;
        v1 = dword_75DF0;
        i = dword_75DF4;
      }
      else
      {
        dword_75DF4 = v8;
        v0 = dword_75DDC;
        v1 = dword_75DF0;
      }
    }
    if ( strncasecmp(&s1, "w", 1u) )
      break;
    sub_16150(filename);
    snprintf(v13, 0x1032u, "Config filename to write (Enter for default) [%s]", filename);
    v3 = sub_25FDC(v13);
    v4 = v3;
    if ( *v3 == 45 && v3[1] == 49 && !v3[2] )
    {
      free(v3);
LABEL_10:
      v5 = fopen(filename, "w");
      v6 = v5;
      if ( v5 )
      {
        sub_15B64(v5);
        fclose(v6);
      }
      else
      {
        strcpy(v12, "Cannot open or create file\n");
        sub_18BC0(v12);
      }
      goto LABEL_12;
    }
    strcpy(filename, v3);
    free(v4);
    if ( _xstat(3, filename, &stat_buf) )
      goto LABEL_10;
    strcpy(v12, "File exists, overwrite?\n");
    sub_18BC0(v12);
    s1 = wgetch((WINDOW *)stdscr);
    if ( !strncasecmp(&s1, "y", 1u) )
      goto LABEL_10;
LABEL_12:
    v0 = dword_75DDC;
    v1 = dword_75DF0;
  }
  if ( !strncasecmp(&s1, "c", 1u)
    && (strcpy(v13, "Are you sure?\n"), sub_18BC0(v13), s1 = wgetch((WINDOW *)stdscr), !strncasecmp(&s1, "y", 1u)) )
  {
    sub_1D7C8();
  }
  else
  {
    sub_18AD8();
  }
  immedok((WINDOW *)dword_7B430, 0);
  byte_7BAC8 = 0;
}
