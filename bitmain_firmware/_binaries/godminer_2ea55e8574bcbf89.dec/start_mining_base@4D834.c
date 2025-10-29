int __fastcall start_mining_base(int a1)
{
  int v1; // r4
  _DWORD *all_created_runtime; // r0
  _DWORD *v4; // r6
  _DWORD *v5; // r9
  int v6; // t1
  int v7; // r0
  _DWORD *v8; // r6
  int i; // r10
  int (**v10)(void); // t1
  int v11; // r0
  int v12; // r4
  int v13; // r0
  int *v14; // r8
  int v15; // r10
  unsigned int v16; // r0
  int *v17; // r6
  int j; // r4
  int v19; // t1
  int *v20; // r8
  int v21; // r6
  int v22; // t1
  int (__fastcall *v24)(int, int); // r4
  int v25; // r0
  int v26; // [sp+14h] [bp-1008h] BYREF
  char v27[4100]; // [sp+18h] [bp-1004h] BYREF

  v1 = 0;
  v26 = 0;
  all_created_runtime = get_all_created_runtime(&v26);
  v4 = all_created_runtime;
  if ( v26 > 0 )
  {
    if ( !*all_created_runtime )
    {
LABEL_35:
      printf(aInvalidPointer, "be_runtimes[c]");
      return 3;
    }
    v5 = all_created_runtime;
    while ( 1 )
    {
      v7 = dev_ctrl(all_created_runtime);
      all_created_runtime = (_DWORD *)(*(int (__fastcall **)(int))(v7 + 28))(v1++);
      if ( v26 <= v1 )
        break;
      v6 = v5[1];
      ++v5;
      if ( !v6 )
        goto LABEL_35;
    }
  }
  V_LOCK();
  logfmt_raw(v27, 0x1000u, 0, "all backend runtimes have been poweroff.");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/machine_runtime/machine_runtime_base.c",
    170,
    "start_mining_base",
    17,
    692,
    60,
    v27);
  if ( *(_DWORD *)(a1 + 64) <= 5u && opt_custom_power_mode == 1 )
  {
    byte_173FA4 = 1;
    V_LOCK();
    logfmt_raw(v27, 0x1000u, 0, "sleep on!");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/machine_runtime_base.c",
      170,
      "start_mining_base",
      17,
      698,
      60,
      v27);
  }
  if ( power_init((unsigned __int8)byte_173FA4, v26) )
  {
    V_LOCK();
    logfmt_raw(v27, 0x1000u, 0, ">> power init error, check PSU please <<");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/machine_runtime_base.c",
      170,
      "start_mining_base",
      17,
      701,
      100,
      v27);
    V_LOCK();
    logfmt_raw(v27, 0x1000u, 0, "Sweep error string = %s.", "V:1");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/machine_runtime_base.c",
      170,
      "start_mining_base",
      17,
      702,
      100,
      v27);
    return 30;
  }
  else
  {
    V_LOCK();
    logfmt_raw(v27, 0x1000u, 0, ">> power init success <<");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/machine_runtime_base.c",
      170,
      "start_mining_base",
      17,
      705,
      40,
      v27);
    if ( start_heartbeat_thread() )
    {
      return start_heartbeat_thread();
    }
    else
    {
      if ( opt_algo != 9
        || (v24 = *(int (__fastcall **)(int, int))(a1 + 28),
            v25 = platfrom_get_check_asic_voltage(),
            (v15 = v24(a1, v25)) == 0) )
      {
        (*(void (__fastcall **)(int, _DWORD))(a1 + 32))(a1, *(_DWORD *)(a1 + 72));
        if ( v26 > 0 )
        {
          v8 = v4 - 1;
          for ( i = 0; i < v26; ++i )
          {
            v10 = (int (**)(void))v8[1];
            ++v8;
            v11 = (*v10)();
            if ( !v11 )
            {
              v12 = 3;
              do
              {
                v13 = dev_ctrl(v11);
                (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(v13 + 24))(
                  *(_DWORD *)(*v8 + 220),
                  *(_DWORD *)(*v8 + 928),
                  *(_DWORD *)(*v8 + 952));
                (*(void (**)(void))(*v8 + 208))();
                v11 = (*(int (**)(void))(*v8 + 196))();
                if ( !v11 )
                  break;
                --v12;
              }
              while ( v12 );
            }
          }
        }
        check_and_destroy_abnormal_runtime();
        v14 = (int *)get_all_created_runtime(&v26);
        if ( v26 <= 0 )
        {
          V_LOCK();
          v15 = 12;
          logfmt_raw(v27, 0x1000u, 0, "there is no qualified device remain after check abnormal runtime!");
          V_UNLOCK();
          zlog(
            g_zc,
            "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmi"
            "ner-origin_godminer-new/machine_runtime/machine_runtime_base.c",
            170,
            "start_mining_base",
            17,
            738,
            100,
            v27);
        }
        else
        {
          v15 = (*(int (__fastcall **)(int, _DWORD))(a1 + 32))(a1, *(_DWORD *)(a1 + 76));
          if ( !v15 )
          {
            (*(void (__fastcall **)(int))(a1 + 56))(a1);
            if ( *(_DWORD *)(a1 + 64) != 9 )
            {
              V_LOCK();
              logfmt_raw(v27, 0x1000u, 0, "check bringup temperature %d C", *(_DWORD *)(a1 + 84));
              V_UNLOCK();
              zlog(
                g_zc,
                "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/g"
                "odminer-origin_godminer-new/machine_runtime/machine_runtime_base.c",
                170,
                "start_mining_base",
                17,
                752,
                60,
                v27);
            }
            v16 = (*(int (__fastcall **)(_DWORD))(a1 + 24))(*(_DWORD *)(a1 + 84));
            fan_pwm_set(v16);
            if ( v26 > 0 )
            {
              v17 = v14 - 1;
              for ( j = 0; j < v26; ++j )
              {
                v19 = v17[1];
                ++v17;
                redirect_nonce_output(*v14, v19);
                (*(void (**)(void))(*v17 + 216))();
              }
            }
            if ( *(_DWORD *)(a1 + 64) == 9 )
            {
              (*(void (__fastcall **)(int))(a1 + 56))(a1);
              V_LOCK();
              logfmt_raw(v27, 0x1000u, 0, "check bringup temperature %d C", *(_DWORD *)(a1 + 84));
              V_UNLOCK();
              zlog(
                g_zc,
                "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/g"
                "odminer-origin_godminer-new/machine_runtime/machine_runtime_base.c",
                170,
                "start_mining_base",
                17,
                768,
                60,
                v27);
            }
            v15 = (*(int (__fastcall **)(int))(a1 + 36))(a1);
            if ( !v15 && v26 > 0 )
            {
              v20 = v14 - 1;
              v21 = 0;
              do
              {
                v22 = v20[1];
                ++v20;
                ++v21;
                (*(void (**)(void))(v22 + 4))();
                (*(void (**)(void))(*v20 + 120))();
                (*(void (**)(void))(*v20 + 16))();
              }
              while ( v26 > v21 );
            }
          }
        }
      }
      return v15;
    }
  }
}
