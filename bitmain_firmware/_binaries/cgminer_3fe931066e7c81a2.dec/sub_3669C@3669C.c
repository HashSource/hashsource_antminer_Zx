int sub_3669C()
{
  void *v0; // r0
  int result; // r0
  char v2[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = calloc(1u, 0x40u);
  if ( !v0 )
  {
    strcpy(v2, "Failed to calloc mcast thr");
    sub_38730(3, v2, 1);
    sub_16CA8(1);
  }
  result = sub_2F174((int)v0, 0, (void *(*)(void *))sub_31CA0, v0);
  if ( result )
  {
    strcpy(v2, "API mcast thread create failed");
    sub_38730(3, v2, 1);
    sub_16CA8(1);
  }
  return result;
}
