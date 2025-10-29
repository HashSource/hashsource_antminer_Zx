bool __fastcall sub_5BC84(_DWORD *a1, const char **a2, void (*a3)(const char *, ...))
{
  const char *v4; // r1
  int v7; // r0
  int v9; // [sp+4h] [bp-8h] BYREF

  v4 = *a2;
  v9 = 0;
  dword_9D780 = (int)v4;
  do
    v7 = sub_5BDEC(a1, a2, &v9, a3);
  while ( v7 == 1 );
  return v7 == 0;
}
