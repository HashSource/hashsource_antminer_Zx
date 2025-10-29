char *__fastcall sub_16CB0(char *a1)
{
  int *v2; // r0
  size_t v3; // r6
  size_t v4; // r6
  char *v5; // r0
  char *v6; // r4
  char v8[92]; // [sp+Ch] [bp-10FCh] BYREF
  char s[160]; // [sp+68h] [bp-10A0h] BYREF
  char v10[4096]; // [sp+108h] [bp-1000h] BYREF

  v2 = sub_5940C(a1, 0, v8);
  if ( v2 && !*v2 )
  {
    byte_76F20 = 1;
    return sub_16DEC(v2, 1);
  }
  else
  {
    v3 = strlen(a1);
    v4 = v3 + strlen(s) + 35;
    v5 = (char *)malloc(v4);
    v6 = v5;
    if ( !v5 )
    {
      strcpy(v10, "Malloc failure in json error");
      sub_38730(3, v10, 1);
      sub_16CA8(1);
    }
    snprintf(v5, v4, "JSON decode of file '%s' failed\n %s", a1, s);
  }
  return v6;
}
