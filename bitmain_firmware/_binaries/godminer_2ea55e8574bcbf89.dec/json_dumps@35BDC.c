_BYTE *__fastcall json_dumps(_DWORD *a1, int a2)
{
  _BYTE *v4; // r4
  const char *v6; // r0
  _DWORD v7[3]; // [sp+4h] [bp-Ch] BYREF

  v4 = (_BYTE *)strbuffer_init(v7);
  if ( v4 )
    return 0;
  if ( !json_dump_callback(a1, (int (__fastcall *)(__int16 *, int, int))sub_34F80, (int)v7, a2) )
  {
    v6 = (const char *)strbuffer_value((int)v7);
    v4 = jsonp_strdup(v6);
  }
  strbuffer_close((int)v7);
  return v4;
}
