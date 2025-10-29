_DWORD *__fastcall json_loadfd(int a1, int a2, char *a3)
{
  char *v4; // r1
  _DWORD *v6; // r4
  int v8; // [sp+4h] [bp-4Ch] BYREF
  _DWORD v9[2]; // [sp+8h] [bp-48h] BYREF
  char v10; // [sp+10h] [bp-40h]
  int v11; // [sp+18h] [bp-38h]
  int v12; // [sp+1Ch] [bp-34h]
  int v13; // [sp+20h] [bp-30h]
  int v14; // [sp+24h] [bp-2Ch]
  int v15; // [sp+2Ch] [bp-24h]
  _DWORD v16[8]; // [sp+30h] [bp-20h] BYREF

  v8 = a1;
  if ( a1 )
    v4 = "<stream>";
  else
    v4 = "<stdin>";
  jsonp_error_init(a3, v4);
  if ( v8 < 0 )
  {
    v6 = 0;
    sub_36CCC((int)a3, 0, 4, "wrong arguments");
  }
  else
  {
    v6 = 0;
    v9[0] = sub_36E3C;
    v9[1] = &v8;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 1;
    if ( !strbuffer_init(v16) )
    {
      v16[3] = a2;
      v16[5] = -1;
      v6 = sub_37D54(v9, a2, (int)a3);
      sub_36DFC((int)v9);
    }
  }
  return v6;
}
