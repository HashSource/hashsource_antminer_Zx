void __fastcall dupalloc(cgpu_info *cgpu, int timelimit)
{
  _DWORD *v4; // r4
  K_LIST *v5; // r0
  K_LIST *v6; // r0
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  v4 = calloc(1u, 0x20u);
  if ( !v4 )
  {
    snprintf(tmp42, 0x1000u, "Failed to calloc dupdata in %s %s():%d", "noncedup.c", "dupalloc", 36);
    applog(3, tmp42, 1);
    quit(1);
  }
  *v4 = timelimit;
  v5 = k_new_list("Nonces", 0x10u, 1024, 0, 1, "noncedup.c", "dupalloc", 39);
  v4[1] = v5;
  v6 = k_new_store(v5);
  cgpu->dup_data = v4;
  v4[2] = v6;
}
