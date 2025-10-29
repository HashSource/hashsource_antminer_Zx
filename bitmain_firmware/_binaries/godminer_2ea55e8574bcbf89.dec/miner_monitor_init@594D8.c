int __fastcall miner_monitor_init(int a1)
{
  int (**v1)(void); // r0
  int v2; // r0
  _DWORD *v3; // r5
  _DWORD *v4; // r8
  _BYTE *v5; // r0
  char *v6; // r9
  char *v7; // r4
  void *v8; // r0
  char *v9; // r2
  char *v10; // r3
  int v11; // r0

  v1 = (int (**)(void))dev_ctrl(a1);
  v2 = (*v1)();
  if ( v2 > 0 )
  {
    v3 = dword_1747F8;
    v4 = &dword_1747F8[54 * v2];
    do
    {
      v5 = calloc(0x100u, 1u);
      *v5 = 63;
      v3[17] = v5;
      v3[24] = calloc(0x10u, 4u);
      v3[25] = calloc(0x10u, 4u);
      v6 = (char *)calloc(0x10u, 4u);
      v3[1] = v6;
      v7 = (char *)calloc(0x10u, 4u);
      *v3 = v7;
      v3[3] = calloc(0x10u, 4u);
      v8 = calloc(0x10u, 4u);
      v9 = v7 - 4;
      v10 = v6 - 4;
      v3[2] = v8;
      *((_QWORD *)v3 + 26) = 0;
      v3[50] = 0;
      do
      {
        *((_DWORD *)v10 + 1) = -64;
        v10 += 4;
        *((_DWORD *)v9 + 1) = -64;
        v9 += 4;
      }
      while ( v10 != v6 + 60 );
      v11 = (int)v3;
      v3 += 54;
      init_temp_senor_info(v11);
    }
    while ( v3 != v4 );
  }
  dword_175584 = (int)new_observable_subject();
  dword_17557C = (int)new_observable_subject();
  dword_175580 = (int)new_observable_subject();
  dword_175578 = (int)new_observable_subject();
  dword_175588 = (int)new_task_timer();
  add_new_task(dword_175588, (int)sub_59380, 1000);
  add_new_task(dword_175588, (int)sub_592B8, (int)"le_bypass_mode");
  add_new_task(dword_175588, (int)sub_5991C, 60000);
  dword_17558C = (int)new_task_timer();
  add_new_task(dword_17558C, (int)sub_591F0, 5000);
  add_new_task(dword_17558C, (int)sub_59128, 1000);
  return add_new_task(dword_17558C, (int)task_check_miner_status, 1000);
}
