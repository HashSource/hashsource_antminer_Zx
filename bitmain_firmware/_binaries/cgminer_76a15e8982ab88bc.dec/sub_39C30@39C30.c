int __fastcall sub_39C30(const char **ptr, const char *a2, const char *a3, int a4)
{
  char s[4096]; // [sp+20h] [bp-1000h] BYREF

  if ( !*((_BYTE *)ptr + 4) )
  {
    snprintf(
      s,
      0x1000u,
      "Store %s can't %s() the list - from %s %s() line %d in %s %s():%d",
      *ptr,
      "_k_free_store",
      a2,
      a3,
      a4,
      "klist.c",
      "_k_free_store",
      424);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  free(ptr);
  return 0;
}
