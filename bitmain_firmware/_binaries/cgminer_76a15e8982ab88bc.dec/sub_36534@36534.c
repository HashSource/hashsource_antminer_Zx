int sub_36534()
{
  void *v0; // r0
  int result; // r0
  char v2[4096]; // [sp+0h] [bp-1000h] BYREF

  v0 = calloc(1u, 0x40u);
  if ( !v0 )
  {
    strcpy(v2, "Failed to calloc mcast thr");
    sub_385C8(3, v2, 1);
    sub_16BE0(1);
  }
  result = sub_2EFE4((int)v0, 0, (void *(*)(void *))sub_31B10, v0);
  if ( result )
  {
    strcpy(v2, "API mcast thread create failed");
    sub_385C8(3, v2, 1);
    sub_16BE0(1);
  }
  return result;
}
