int __fastcall sub_33AA4(int a1, int a2, const char *a3, int a4, unsigned __int8 a5)
{
  const char *v8; // r0
  _UNKNOWN **v9; // r4
  const char *v10; // t1
  const __int32_t **v11; // r0
  __int32_t v12; // r2
  int v13; // r8
  int v14; // r9
  char *v15; // r1
  int v16; // r10
  const char *v17; // r2
  _DWORD *v18; // r0
  const char *v19; // r2
  _DWORD *v20; // r0
  int result; // r0
  char s[100]; // [sp+Ch] [bp-64h] BYREF

  if ( !a3 || !*a3 )
    return sub_32ECC((unsigned int *)a1, 71, 0, 0, a4);
  v8 = (const char *)off_7336C;
  if ( off_7336C )
  {
    v9 = &off_7336C;
    while ( strcmp(v8, a3) )
    {
      v10 = (const char *)v9[3];
      v9 += 3;
      v8 = v10;
      if ( !v10 )
        goto LABEL_23;
    }
    sprintf(s, "|%s|", a3);
    v11 = _ctype_toupper_loc();
    v12 = (*v11)[a5];
    if ( v12 == (*v11)[87] || strstr(*((const char **)&unk_78B4C + v12 - (*v11)[65]), s) )
    {
      v13 = 1;
      v14 = 1;
    }
    else
    {
      v13 = 0;
      v14 = 1;
    }
  }
  else
  {
LABEL_23:
    v13 = (int)v8;
    v14 = (int)v8;
  }
  sub_32ECC((unsigned int *)a1, 72, 0, 0, a4);
  v15 = "CHECK,";
  if ( a4 )
    v15 = ",\"CHECK\":[";
  v16 = sub_30638((unsigned int *)a1, v15);
  if ( v14 )
    v17 = "Y";
  else
    v17 = "N";
  v18 = sub_32CB0(0, "Exists", v17, 0);
  if ( v13 )
    v19 = "Y";
  else
    v19 = "N";
  v20 = sub_32CB0(v18, "Access", v19, 0);
  result = sub_323A4((unsigned int *)a1, (int)v20, a4, 0);
  if ( (v16 & a4) != 0 )
    *(_BYTE *)(a1 + 13) = 1;
  return result;
}
