int __fastcall sub_2A8FC(_DWORD *a1)
{
  struct timespec v3; // [sp+0h] [bp-8h] BYREF

  sub_2A5C0(&v3);
  sub_2A688(&v3.tv_sec, a1);
  return sub_2926C(&v3);
}
