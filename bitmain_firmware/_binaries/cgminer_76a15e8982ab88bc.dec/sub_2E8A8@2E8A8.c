int __fastcall sub_2E8A8(_DWORD *a1)
{
  const char *v1; // r12
  const char *v3; // r3
  int v4; // r2
  size_t v5; // r0
  int *v6; // r4
  int v7; // r4
  int *v9; // r7
  _DWORD *v10; // r4
  _DWORD *v11; // r0
  char *v12; // r4
  char *v13; // r0
  int v14; // r3
  int v15; // r3
  int v16; // r2
  size_t v17; // r0
  int v18; // r2
  size_t v19; // r0
  char v20[252]; // [sp+Ch] [bp-3100h] BYREF
  char s[4088]; // [sp+108h] [bp-3004h] BYREF
  char v22[8196]; // [sp+1108h] [bp-2004h] BYREF

  v1 = (const char *)a1[52];
  v3 = (const char *)a1[51];
  v4 = dword_77F20++;
  sprintf(v22, "{\"id\": %d, \"method\": \"mining.authorize\", \"params\": [\"%s\", \"%s\"]}", v4, v3, v1);
  v5 = strlen(v22);
  if ( sub_2B520((int)a1, v22, v5) )
  {
    while ( 1 )
    {
      v6 = (int *)sub_2AF98((int)a1);
      if ( !v6 )
        return 0;
      if ( !sub_2CE98(a1, v6) )
        break;
      free(v6);
    }
    v9 = sub_565E8(v6, 0, v20);
    free(v6);
    v10 = (_DWORD *)sub_571D8(v9, "result");
    v11 = (_DWORD *)sub_571D8(v9, "error");
    if ( !v10 || *v10 == 6 )
    {
      if ( !v11 )
      {
        v12 = (char *)malloc(0x11u);
        if ( v12 )
          strcpy(v12, "(unknown reason)");
        goto LABEL_13;
      }
    }
    else if ( !v11 || *v11 == 7 )
    {
      if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
      {
        snprintf(s, 0x1000u, "Stratum authorisation success for pool %d", *a1);
        sub_385C8(7, s, 0);
      }
      *((_BYTE *)a1 + 131) = 1;
      byte_75AE8 = 1;
      if ( dword_7894C )
      {
        v18 = dword_77F20++;
        sprintf(v22, "{\"id\": %d, \"method\": \"mining.suggest_difficulty\", \"params\": [%d]}", v18, dword_7894C);
        v19 = strlen(v22);
        sub_2B520((int)a1, v22, v19);
      }
      if ( dword_72CF4 )
      {
        v16 = dword_77F20++;
        sprintf(v22, "{\"id\": %d, \"method\": \"mining.multi_version\", \"params\": [%d]}", v16, dword_72CF4);
        v7 = 1;
        v17 = strlen(v22);
        sub_2B520((int)a1, v22, v17);
      }
      else
      {
        v7 = 1;
      }
      goto LABEL_18;
    }
    v12 = (char *)sub_54C0C(v11, 3);
LABEL_13:
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(s, 0x1000u, "pool %d JSON stratum auth failed: %s", *a1, v12);
      sub_385C8(7, s, 0);
    }
    v13 = v12;
    v7 = 0;
    free(v13);
    sub_2AE38((int)a1);
LABEL_18:
    if ( v9 )
    {
      v14 = v9[1];
      if ( v14 != -1 )
      {
        v15 = v14 - 1;
        v9[1] = v15;
        if ( !v15 )
          sub_5779C((void **)v9);
      }
    }
    return v7;
  }
  return 0;
}
