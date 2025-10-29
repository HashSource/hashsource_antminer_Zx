int __fastcall sub_26D10(int a1)
{
  char *v2; // r0
  char *v3; // r4
  char *v4; // r0
  char *v5; // r8
  char *v6; // r0
  void *v7; // r7
  char *v8; // r10
  char *v9; // r0
  char *v10; // r9
  int v11; // r6
  char v13[4096]; // [sp+8h] [bp-1000h] BYREF

  immedok((WINDOW *)dword_7B430, 1);
  strcpy(v13, "Input server details.\n");
  sub_18BC0(v13);
  v2 = sub_25FDC("URL");
  v3 = v2;
  if ( *v2 == 45 && v2[1] == 49 && (v5 = (char *)(unsigned __int8)v2[2], !v2[2])
    || (v4 = sub_25FDC("Username"), v5 = v4, *v4 == 45) && v4[1] == 49 && !v4[2] )
  {
    immedok((WINDOW *)dword_7B430, 0);
    v7 = 0;
LABEL_19:
    v11 = 0;
    free(v3);
    free(v5);
    free(v7);
    return v11;
  }
  v6 = sub_25FDC("Password");
  v7 = v6;
  if ( *v6 == 45 && v6[1] == 49 && !v6[2] )
  {
    free(v6);
    v7 = calloc(1u, 1u);
  }
  v8 = sub_17A3C();
  if ( !sub_1557C((int)v8, v3) && strncmp(v3, "http://", 7u) && strncmp(v3, "https://", 8u) )
  {
    v9 = (char *)malloc(0x100u);
    v10 = v9;
    if ( !v9 )
    {
      strcpy(v13, "Failed to malloc httpinput");
      sub_38730(3, v13, 1);
      sub_16CA8(1);
    }
    strcpy(v9, "http://");
    strncat(v9, v3, 0xF8u);
    free(v3);
    v3 = v10;
  }
  v11 = sub_26BCC((int)v8, a1, v3, v5, (const char *)v7);
  immedok((WINDOW *)dword_7B430, 0);
  if ( !v11 )
    goto LABEL_19;
  return v11;
}
