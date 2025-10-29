char *__fastcall sub_25FDC(const char *a1)
{
  char *v2; // r4
  char v4[4100]; // [sp+0h] [bp-1004h] BYREF

  echo();
  v2 = (char *)malloc(0xFFu);
  if ( !v2 )
  {
    strcpy(v4, "Failed to malloc input");
    sub_38730(3, v4, 1);
    sub_16CA8(1);
  }
  leaveok((WINDOW *)dword_7B430, 0);
  snprintf(v4, 0x1000u, "%s:\n", a1);
  sub_18BC0(v4);
  wgetnstr((WINDOW *)dword_7B430, v2, 255);
  if ( !*v2 )
    strcpy(v2, "-1");
  leaveok((WINDOW *)dword_7B430, 1);
  noecho();
  return v2;
}
