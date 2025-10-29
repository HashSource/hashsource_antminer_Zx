_DWORD *__fastcall json_loadb(int a1, int a2, int a3, char *a4)
{
  _DWORD *v8; // r4
  _DWORD v10[3]; // [sp+4h] [bp-54h] BYREF
  _DWORD v11[2]; // [sp+10h] [bp-48h] BYREF
  char v12; // [sp+18h] [bp-40h]
  int v13; // [sp+20h] [bp-38h]
  int v14; // [sp+24h] [bp-34h]
  int v15; // [sp+28h] [bp-30h]
  int v16; // [sp+2Ch] [bp-2Ch]
  int v17; // [sp+34h] [bp-24h]
  _DWORD v18[8]; // [sp+38h] [bp-20h] BYREF

  jsonp_error_init(a4, "<buffer>");
  if ( a1 )
  {
    v8 = 0;
    v10[0] = a1;
    v10[1] = a2;
    v11[0] = sub_36C4C;
    v10[2] = 0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v16 = 0;
    v17 = 0;
    v11[1] = v10;
    v15 = 1;
    if ( !strbuffer_init(v18) )
    {
      v18[3] = a3;
      v18[5] = -1;
      v8 = sub_37D54(v11, a3, (int)a4);
      sub_36DFC((int)v11);
    }
  }
  else
  {
    v8 = 0;
    sub_36CCC((int)a4, 0, 4, "wrong arguments");
  }
  return v8;
}
