int __fastcall json_dumpb(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // [sp+4h] [bp-Ch] BYREF
  int v6; // [sp+8h] [bp-8h]
  int v7; // [sp+Ch] [bp-4h]

  v7 = a2;
  v5 = a3;
  v6 = 0;
  if ( json_dump_callback(a1, (int (__fastcall *)(__int16 *, int, int))sub_34F94, (int)&v5, a4) )
    return 0;
  else
    return v6;
}
