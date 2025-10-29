void __fastcall default_save_file(char *filename)
{
  size_t v2; // r0
  int *v3; // r3
  char *v4; // r2
  size_t v5; // r5
  int v6; // r0
  int v7; // r1
  size_t v8; // r0
  int *v9; // r3
  char *v10; // r5
  size_t v11; // r6
  int v12; // r0
  int v13; // r1
  int v14; // r2
  char *v15; // r0

  if ( default_config && *default_config )
  {
    j_strcpy(filename, default_config);
  }
  else
  {
    if ( getenv("HOME") && *getenv("HOME") )
    {
      v15 = getenv("HOME");
      *(_WORD *)stpcpy(filename, v15) = 47;
    }
    else
    {
      *filename = 0;
    }
    v2 = strlen(filename);
    LOWORD(v3) = -2104;
    v4 = &filename[v2];
    HIWORD(v3) = (unsigned int)": true" >> 16;
    v5 = v2;
    v6 = *v3;
    v7 = v3[1];
    LOWORD(v3) = *((_WORD *)v3 + 4);
    *(_DWORD *)&filename[v5] = v6;
    *((_DWORD *)v4 + 1) = v7;
    *((_WORD *)v4 + 4) = (_WORD)v3;
    mkdir(filename, 0x1FFu);
    v8 = strlen(filename);
    LOWORD(v9) = -2092;
    v10 = &filename[v8];
    HIWORD(v9) = (unsigned int)"otate\" : \"%d\"" >> 16;
    v11 = v8;
    v12 = *v9;
    v13 = v9[1];
    v14 = v9[2];
    LOBYTE(v9) = *((_BYTE *)v9 + 12);
    *(_DWORD *)&filename[v11] = v12;
    *((_DWORD *)v10 + 1) = v13;
    v10[12] = (char)v9;
    *((_DWORD *)v10 + 2) = v14;
  }
}
