void __fastcall dupalloc(cgpu_info *cgpu, int timelimit)
{
  const char *func; // r5
  _DWORD *v5; // r4
  const char *file; // r3
  const char *v7; // r0
  K_LIST *v8; // r0
  K_LIST *v9; // r0
  int v10; // r3
  const char *v11; // r2
  char tmp42[4100]; // [sp+10h] [bp-1004h] BYREF

  LOWORD(func) = 28104;
  HIWORD(func) = (unsigned int)"can't %s() a store - from %s %s() line %d in %s %s():%d" >> 16;
  v5 = calloc(1u, 0x20u);
  if ( !v5 )
  {
    LOWORD(v10) = 28128;
    LOWORD(v11) = 28140;
    HIWORD(v10) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
    HIWORD(v11) = (unsigned int)"ne %d in %s %s():%d" >> 16;
    snprintf(tmp42, 0x1000u, v11, v10, func, 36);
    applog(3, tmp42, 1);
    quit(1);
  }
  LOWORD(file) = 28128;
  HIWORD(file) = (unsigned int)"m %s %s() line %d in %s %s():%d" >> 16;
  LOWORD(v7) = 28180;
  *v5 = timelimit;
  HIWORD(v7) = (unsigned int)"the list - from %s %s() line %d in %s %s():%d" >> 16;
  v8 = k_new_list(v7, 0x10u, 1024, 0, 1, file, func, 39);
  v5[1] = v8;
  v9 = k_new_store(v8);
  cgpu->dup_data = v5;
  v5[2] = v9;
}
