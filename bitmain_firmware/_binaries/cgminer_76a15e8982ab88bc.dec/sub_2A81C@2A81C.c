int __fastcall sub_2A81C(_DWORD *a1)
{
  struct timespec v3; // [sp+0h] [bp-8h] BYREF

  sub_2A558(&v3);
  sub_2A5E0(&v3.tv_sec, a1);
  return sub_291C4(&v3);
}
