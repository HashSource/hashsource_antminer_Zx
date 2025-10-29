int __fastcall sub_17744(char *a1, size_t a2, int a3)
{
  double v3; // d0
  double v7; // r0
  double v8; // d17
  unsigned __int64 v9; // r4
  int v10; // r1
  unsigned __int64 v11; // r0
  size_t v12; // r11
  char v14[16]; // [sp+28h] [bp-1064h] BYREF
  char v15[16]; // [sp+38h] [bp-1054h] BYREF
  char s[64]; // [sp+48h] [bp-1044h] BYREF
  char v17[4100]; // [sp+88h] [bp-1004h] BYREF

  sub_157EC(a3);
  LODWORD(v7) = sub_5CB64(*(_QWORD *)(a3 + 192));
  v8 = v7;
  LODWORD(v9) = sub_5CC48(*(double *)(a3 + 48));
  HIDWORD(v9) = v10;
  LODWORD(v11) = sub_5CC48(*(double *)(a3 + 80) / v3);
  sub_11580(v11, v14, 0x10u, 4);
  sub_11580(v9, v15, 0x10u, 4);
  snprintf(a1, a2, "%s%d ", *(const char **)(*(_DWORD *)(a3 + 4) + 8), *(_DWORD *)(a3 + 8));
  (*(void (__fastcall **)(char *, size_t, int))(*(_DWORD *)(a3 + 4) + 20))(a1, a2, a3);
  v12 = strlen(a1);
  snprintf(
    s,
    0x40u,
    "(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",
    dword_75DCC,
    v15,
    v14,
    *(double *)(a3 + 200),
    *(double *)(a3 + 208),
    *(_DWORD *)(a3 + 44),
    v8 / v3 * 60.0);
  if ( a2 <= strlen(s) + v12 )
  {
    snprintf(v17, 0x1000u, "tailsprintf buffer overflow in %s %s line %d", "cgminer.c", "get_statline", 3081);
    sub_38730(3, v17, 1);
    sub_16CA8(1);
  }
  strcat(a1, s);
  return (*(int (__fastcall **)(char *, size_t, int))(*(_DWORD *)(a3 + 4) + 24))(a1, a2, a3);
}
