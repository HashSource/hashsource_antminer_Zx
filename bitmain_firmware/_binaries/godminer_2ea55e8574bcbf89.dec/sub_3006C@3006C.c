int sub_3006C()
{
  int v0; // r3

  v0 = ++dword_173268;
  if ( dword_173268 > total_pools )
  {
    add_pool();
    v0 = dword_173268;
  }
  return *(_DWORD *)(pools + 4 * (v0 + 0x3FFFFFFF));
}
