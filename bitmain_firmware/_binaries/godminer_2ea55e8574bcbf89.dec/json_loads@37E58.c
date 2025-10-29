_DWORD *__fastcall json_loads(int a1, int a2, char *a3)
{
  _DWORD *v6; // r4
  _DWORD v8[2]; // [sp+0h] [bp-54h] BYREF
  _DWORD v9[2]; // [sp+8h] [bp-4Ch] BYREF
  char v10; // [sp+10h] [bp-44h]
  int v11; // [sp+18h] [bp-3Ch]
  int v12; // [sp+1Ch] [bp-38h]
  int v13; // [sp+20h] [bp-34h]
  int v14; // [sp+24h] [bp-30h]
  int v15; // [sp+2Ch] [bp-28h]
  _DWORD v16[9]; // [sp+30h] [bp-24h] BYREF

  jsonp_error_init(a3, "<string>");
  if ( a1 )
  {
    v6 = 0;
    v8[0] = a1;
    v9[0] = sub_36C28;
    v8[1] = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v14 = 0;
    v15 = 0;
    v9[1] = v8;
    v13 = 1;
    if ( !strbuffer_init(v16) )
    {
      v16[3] = a2;
      v16[5] = -1;
      v6 = sub_37D54(v9, a2, (int)a3);
      sub_36DFC((int)v9);
    }
  }
  else
  {
    v6 = 0;
    sub_36CCC((int)a3, 0, 4, "wrong arguments");
  }
  return v6;
}
