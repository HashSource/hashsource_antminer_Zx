work *make_work()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4
  char tmp42[4100]; // [sp+0h] [bp-1004h] BYREF

  v0 = calloc(1u, 0x7B0u);
  if ( !v0 )
  {
    strcpy(tmp42, "Failed to calloc work in make_work");
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v1 = v0;
  v0[457] = total_work_inc();
  return (work *)v1;
}
