int __fastcall sub_2E69C(int *a1)
{
  int v1; // r2
  size_t v3; // r0
  int *v4; // r5
  int v5; // r4
  int *v7; // r6
  _DWORD *v8; // r7
  _DWORD *v9; // r0
  _DWORD *v10; // r5
  const char *v11; // r7
  char *v12; // r5
  int v13; // r3
  const char *v14; // r2
  int v15; // r3
  int v16; // r3
  char v17[252]; // [sp+Ch] [bp-3100h] BYREF
  char s[4088]; // [sp+108h] [bp-3004h] BYREF
  char v19[8196]; // [sp+1108h] [bp-2004h] BYREF

  v1 = dword_7B0F8++;
  sprintf(v19, "{\"id\": %d, \"method\": \"mining.extranonce.subscribe\", \"params\": []}", v1);
  v3 = strlen(v19);
  if ( !sub_2B5C8((int)a1, v19, v3) )
    return 0;
  while ( 1 )
  {
    if ( !sub_28AFC((int)a1, 2) )
    {
      if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
      {
        strcpy(s, "Timed out waiting for response extranonce.subscribe");
        sub_38730(7, s, 0);
      }
      return 1;
    }
    v4 = (int *)sub_2B040((int)a1);
    if ( !v4 )
      return 0;
    if ( !sub_2CF40(a1, v4) )
      break;
    free(v4);
  }
  v7 = sub_59230(v4, 0, v17);
  free(v4);
  v8 = (_DWORD *)sub_59E20(v7, "result");
  v9 = (_DWORD *)sub_59E20(v7, "error");
  v10 = v9;
  if ( !v8 || *v8 == 6 )
  {
    if ( !v9 )
    {
      v12 = (char *)malloc(0x11u);
      if ( v12 )
        strcpy(v12, "(unknown reason)");
      goto LABEL_22;
    }
    goto LABEL_18;
  }
  if ( v9 && *v9 != 7 )
  {
LABEL_18:
    v11 = (const char *)sub_29294(v9, 1u);
    if ( !v11 && (v11 = (const char *)sub_5A178(v10)) == 0
      || strcmp(v11, "Method 'subscribe' not found for service 'mining.extranonce'")
      && strcmp(v11, "Unrecognized request provided") )
    {
      v12 = (char *)sub_57854(v10, 3);
LABEL_22:
      if ( byte_7AD48 || byte_78E08 || dword_766C4 > 5 )
      {
        snprintf(s, 0x1000u, "Pool %d JSON extranonce subscribe failed: %s", *a1, v12);
        sub_38730(6, s, 0);
      }
      v5 = 0;
      free(v12);
      goto LABEL_31;
    }
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 5 )
      goto LABEL_41;
    v13 = *a1;
    v14 = "Cannot subscribe to mining.extranonce for pool %d";
    goto LABEL_30;
  }
  if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 5 )
  {
LABEL_41:
    v5 = 1;
    goto LABEL_31;
  }
  v13 = *a1;
  v14 = "Stratum extranonce subscribe for pool %d";
LABEL_30:
  v5 = 1;
  snprintf(s, 0x1000u, v14, v13);
  sub_38730(6, s, 0);
LABEL_31:
  if ( v7 )
  {
    v15 = v7[1];
    if ( v15 != -1 )
    {
      v16 = v15 - 1;
      v7[1] = v16;
      if ( !v16 )
        sub_5A3E4((void **)v7);
    }
  }
  return v5;
}
