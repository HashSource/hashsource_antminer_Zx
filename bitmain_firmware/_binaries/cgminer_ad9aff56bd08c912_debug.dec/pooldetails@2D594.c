bool __fastcall pooldetails(char *param, char **url, char **user, char **pass)
{
  size_t v7; // r0
  char *v8; // r0
  char **v9; // r2
  char *v10; // r4
  char **v11; // r2
  char **v12; // r2
  int *v14; // r6
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r6
  unsigned __int8 *v24[2]; // [sp+4h] [bp-100Ch] BYREF
  char *buf; // [sp+Ch] [bp-1004h] BYREF
  char tmp42[4096]; // [sp+10h] [bp-1000h] BYREF

  v24[0] = (unsigned __int8 *)param;
  v7 = strlen(param);
  v8 = (char *)malloc(v7 + 1);
  v10 = v8;
  buf = v8;
  if ( !v8 )
  {
    LOWORD(v14) = 21412;
    HIWORD(v14) = (unsigned int)" %d first go" >> 16;
    v15 = *v14;
    v16 = v14[1];
    v17 = v14[2];
    v18 = v14[3];
    v14 += 4;
    *(_DWORD *)tmp42 = v15;
    *(_DWORD *)&tmp42[4] = v16;
    *(_DWORD *)&tmp42[8] = v17;
    *(_DWORD *)&tmp42[12] = v18;
    v19 = *v14;
    v20 = v14[1];
    v21 = v14[2];
    v22 = v14[3];
    v23 = v14[4];
    *(_DWORD *)&tmp42[16] = v19;
    *(_DWORD *)&tmp42[20] = v20;
    *(_DWORD *)&tmp42[24] = v21;
    *(_DWORD *)&tmp42[28] = v22;
    tmp42[32] = v23;
    applog(3, tmp42, 1);
    quit(1);
  }
  *url = v8;
  copyadvanceafter(v24, &buf, v9);
  if ( *v24[0] && (*user = buf, copyadvanceafter(v24, &buf, v11), *v24[0]) )
  {
    *pass = buf;
    copyadvanceafter(v24, &buf, v12);
    return 1;
  }
  else
  {
    free(v10);
    return 0;
  }
}
