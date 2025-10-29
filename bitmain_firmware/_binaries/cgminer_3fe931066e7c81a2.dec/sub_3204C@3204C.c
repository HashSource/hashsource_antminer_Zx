int __fastcall sub_3204C(unsigned __int8 *a1, unsigned __int8 **a2, _DWORD *a3, _DWORD *a4)
{
  size_t v7; // r0
  unsigned __int8 *v8; // r0
  unsigned __int8 *v9; // r4
  int v10; // r5
  unsigned __int8 *v12[2]; // [sp+4h] [bp-1010h] BYREF
  unsigned __int8 *v13; // [sp+Ch] [bp-1008h] BYREF
  char v14[4100]; // [sp+10h] [bp-1004h] BYREF

  v12[0] = a1;
  v7 = strlen((const char *)a1);
  v8 = (unsigned __int8 *)malloc(v7 + 1);
  v13 = v8;
  v9 = v8;
  if ( !v8 )
  {
    strcpy(v14, "Failed to malloc pooldetails buf");
    sub_38730(3, v14, 1);
    sub_16CA8(1);
  }
  *a2 = v8;
  LOWORD(v10) = -4108;
  sub_31FC4(v12, &v13);
  HIWORD(v10) = -1;
  if ( **(_BYTE **)&v14[v10 + 4096] && (*a3 = v13, sub_31FC4(v12, &v13), **(_BYTE **)&v14[v10 + 4096]) )
  {
    *a4 = v13;
    sub_31FC4(v12, &v13);
    return 1;
  }
  else
  {
    free(v9);
    return 0;
  }
}
