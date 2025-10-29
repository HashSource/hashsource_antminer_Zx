int __fastcall main(int argc, const char **argv, const char **envp)
{
  const char *v3; // r6
  int v6; // r3
  int v7; // r5
  int v8; // r8
  int v10; // r6
  const char *v11; // r5
  const char *v12; // r0
  const char **v13; // r4
  int v14; // r8
  char *v15; // r6
  char *v16; // r0
  const char *v17; // r0

  if ( argc <= 1 )
    goto LABEL_22;
  v3 = argv[1];
  v6 = *(unsigned __int8 *)v3;
  v7 = 45 - v6;
  if ( v6 == 45 )
  {
    v8 = *((unsigned __int8 *)v3 + 1);
    if ( v8 != 63 && v8 != 104 )
    {
      if ( strcmp(v3, "--help") )
        goto LABEL_19;
LABEL_5:
      fprintf((FILE *)stderr, "usAge: %s [command [ip/host [port]]]\n", *argv);
      return 1;
    }
    if ( !v3[2] )
      goto LABEL_5;
  }
  if ( !strcmp(v3, "--help") )
    goto LABEL_5;
  if ( v7 )
  {
LABEL_8:
    v10 = 1;
    goto LABEL_9;
  }
  v8 = *((unsigned __int8 *)v3 + 1);
LABEL_19:
  if ( v8 != 111 || v3[2] )
    goto LABEL_8;
  dword_211B0 = 1;
  if ( argc == 2 )
  {
LABEL_22:
    v11 = "summary";
    goto LABEL_23;
  }
  v10 = 2;
LABEL_9:
  v11 = "summary";
  v12 = (const char *)sub_10BCC(argv[v10]);
  if ( *v12 )
    v11 = v12;
  if ( argc > v10 + 1 )
  {
    v13 = &argv[v10];
    v14 = v10 + 2;
    v15 = "127.0.0.1";
    v16 = (char *)sub_10BCC(v13[1]);
    if ( *v16 )
      v15 = v16;
    if ( argc > v14 )
    {
      v17 = (const char *)sub_10BCC(v13[2]);
      if ( *v17 )
        strtol(v17, 0, 10);
    }
    return callapi((int)v11, v15);
  }
LABEL_23:
  v15 = "127.0.0.1";
  return callapi((int)v11, v15);
}
