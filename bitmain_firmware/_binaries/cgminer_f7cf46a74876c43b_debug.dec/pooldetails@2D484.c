bool __fastcall pooldetails(char *param, char **url, char **user, char **pass)
{
  size_t v7; // r0
  char *v8; // r0
  char **v9; // r2
  char *v10; // r4
  char **v11; // r2
  char **v12; // r2
  unsigned __int8 *v14[2]; // [sp+4h] [bp-100Ch] BYREF
  char *buf; // [sp+Ch] [bp-1004h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v14[0] = (unsigned __int8 *)param;
  v7 = strlen(param);
  v8 = (char *)malloc(v7 + 1);
  v10 = v8;
  buf = v8;
  if ( !v8 )
  {
    strcpy(tmp42, "Failed to malloc pooldetails buf");
    applog(3, tmp42, 1);
    quit(1);
  }
  *url = v8;
  copyadvanceafter(v14, &buf, v9);
  if ( *v14[0] && (*user = buf, copyadvanceafter(v14, &buf, v11), *v14[0]) )
  {
    *pass = buf;
    copyadvanceafter(v14, &buf, v12);
    return 1;
  }
  else
  {
    free(v10);
    return 0;
  }
}
