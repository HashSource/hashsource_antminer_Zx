_DWORD *__fastcall json_loadf(int a1, int a2, char *a3)
{
  char *v6; // r1
  _DWORD *v7; // r4
  _DWORD v9[2]; // [sp+0h] [bp-4Ch] BYREF
  char v10; // [sp+8h] [bp-44h]
  int v11; // [sp+10h] [bp-3Ch]
  int v12; // [sp+14h] [bp-38h]
  int v13; // [sp+18h] [bp-34h]
  int v14; // [sp+1Ch] [bp-30h]
  int v15; // [sp+24h] [bp-28h]
  _DWORD v16[9]; // [sp+28h] [bp-24h] BYREF

  if ( stdin == a1 )
    v6 = "<stdin>";
  else
    v6 = "<stream>";
  jsonp_error_init(a3, v6);
  if ( a1 )
  {
    v7 = 0;
    v9[1] = a1;
    v9[0] = fgetc;
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
      v7 = sub_37D54(v9, a2, (int)a3);
      sub_36DFC((int)v9);
    }
  }
  else
  {
    v7 = 0;
    sub_36CCC((int)a3, 0, 4, "wrong arguments");
  }
  return v7;
}
