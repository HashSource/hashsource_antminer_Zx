int __fastcall start_mining_kas(int a1)
{
  int v1; // r4
  _DWORD *all_created_runtime; // r0
  _DWORD *v4; // r10
  _DWORD *v5; // r6
  int v6; // t1
  int v7; // r0
  int v8; // r9
  _DWORD *v9; // r4
  int i; // r6
  int v11; // t1
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r0
  _DWORD *v15; // r4
  int (**v16)(void); // t1
  int v17; // r0
  int v18; // r6
  int v19; // r0
  int v20; // r11
  int *v21; // r6
  char *v22; // r9
  int v23; // r0
  char *v24; // r11
  char *v25; // r3
  int v26; // r4
  int v27; // t1
  unsigned int v28; // r0
  int *v29; // r8
  int j; // r4
  int v31; // t1
  int v32; // r4
  _DWORD *v33; // r10
  int *v34; // r9
  int v35; // r8
  int v36; // r3
  int v37; // t1
  int v38; // t1
  int *v39; // r6
  int k; // r8
  int v41; // t1
  char *v43; // r4
  int v44; // r0
  int v45; // r0
  int v46; // t1
  int v47; // [sp+18h] [bp-100Ch] BYREF
  int v48; // [sp+1Ch] [bp-1008h] BYREF
  _DWORD v49[13]; // [sp+20h] [bp-1004h] BYREF
  __int16 v50; // [sp+54h] [bp-FD0h]

  v1 = 0;
  v47 = 0;
  all_created_runtime = get_all_created_runtime(&v47);
  v4 = all_created_runtime;
  if ( v47 > 0 )
  {
    if ( !*all_created_runtime )
    {
LABEL_46:
      v32 = 3;
      printf(aInvalidPointer, "be_runtimes[c]");
      return v32;
    }
    v5 = all_created_runtime;
    while ( 1 )
    {
      v7 = dev_ctrl(all_created_runtime);
      all_created_runtime = (_DWORD *)(*(int (__fastcall **)(int))(v7 + 28))(v1++);
      if ( v47 <= v1 )
        break;
      v6 = v5[1];
      ++v5;
      if ( !v6 )
        goto LABEL_46;
    }
  }
  V_LOCK();
  logfmt_raw((char *)v49, 0x1000u, 0, "all backend runtimes have been poweroff.");
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
    183,
    "start_mining_kas",
    16,
    129,
    60,
    v49);
  if ( support_of_sleepmode(*(_DWORD *)(a1 + 64)) && opt_custom_power_mode == 1 )
  {
    V_LOCK();
    logfmt_raw((char *)v49, 0x1000u, 0, "sleep on!");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
      183,
      "start_mining_kas",
      16,
      137,
      60,
      v49);
  }
  if ( power_init(0, v47) )
  {
    V_LOCK();
    logfmt_raw((char *)v49, 0x1000u, 0, ">> power init error, check PSU please <<");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
      183,
      "start_mining_kas",
      16,
      140,
      100,
      v49);
    V_LOCK();
    logfmt_raw((char *)v49, 0x1000u, 0, "Sweep error string = %s.", "V:1");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
      183,
      "start_mining_kas",
      16,
      141,
      100,
      v49);
    return 30;
  }
  else
  {
    V_LOCK();
    logfmt_raw((char *)v49, 0x1000u, 0, ">> power init success <<");
    V_UNLOCK();
    zlog(
      g_zc,
      "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-or"
      "igin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
      183,
      "start_mining_kas",
      16,
      144,
      40,
      v49);
    if ( !start_heartbeat_thread() )
    {
      v8 = 10;
      puts("send fake work to open cores");
      do
      {
        usleep((__useconds_t)&stru_1869C.st_value);
        if ( v47 > 0 )
        {
          v9 = v4 - 1;
          for ( i = 0; i < v47; ++i )
          {
            v49[0] = 53520981;
            v49[1] = -1996423168;
            v49[2] = 1568885659;
            v49[3] = -2022340884;
            v49[4] = 739994112;
            v49[5] = 2023104256;
            v49[6] = 504402544;
            v49[7] = 232286627;
            v49[8] = 1496646687;
            v49[9] = 295890251;
            v49[10] = 1890778236;
            v49[11] = 60442;
            v49[12] = 0;
            v50 = 13171;
            v11 = v9[1];
            ++v9;
            v12 = pthread_mutex_lock((pthread_mutex_t *)(v11 + 896));
            do
            {
              v13 = dev_ctrl(v12);
              v12 = (*(int (__fastcall **)(_DWORD))(v13 + 68))(*(_DWORD *)(*v9 + 220));
            }
            while ( v12 <= 0x35 );
            v14 = dev_ctrl(v12);
            (*(void (__fastcall **)(_DWORD, _DWORD *, int))(v14 + 52))(*(_DWORD *)(*v9 + 220), v49, 54);
            pthread_mutex_unlock((pthread_mutex_t *)(*v9 + 896));
          }
        }
        --v8;
      }
      while ( v8 );
      (*(void (__fastcall **)(int, _DWORD))(a1 + 32))(a1, *(_DWORD *)(a1 + 72));
      if ( v47 > 0 )
      {
        v15 = v4 - 1;
        do
        {
          v16 = (int (**)(void))v15[1];
          ++v15;
          v17 = (*v16)();
          if ( !v17 )
          {
            v18 = 3;
            do
            {
              v19 = dev_ctrl(v17);
              (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD))(v19 + 24))(
                *(_DWORD *)(*v15 + 220),
                *(_DWORD *)(*v15 + 928),
                *(_DWORD *)(*v15 + 952));
              v20 = (*(int (**)(void))(*v15 + 196))();
              v17 = (*(int (**)(void))(*v15 + 208))();
              if ( !v20 )
                break;
              --v18;
            }
            while ( v18 );
          }
          ++v8;
        }
        while ( v47 > v8 );
      }
      check_and_destroy_abnormal_runtime();
      v21 = (int *)get_all_created_runtime(&v47);
      if ( v47 <= 0 )
      {
        V_LOCK();
        v32 = 12;
        logfmt_raw((char *)v49, 0x1000u, 0, "there is no qualified device remain after check abnormal runtime!");
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
          183,
          "start_mining_kas",
          16,
          191,
          100,
          v49);
      }
      else
      {
        (*(void (__fastcall **)(int))(a1 + 56))(a1);
        V_LOCK();
        logfmt_raw((char *)v49, 0x1000u, 0, "check bringup temperature %d C", *(_DWORD *)(a1 + 84));
        V_UNLOCK();
        zlog(
          g_zc,
          "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godmine"
          "r-origin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
          183,
          "start_mining_kas",
          16,
          197,
          60,
          v49);
        v22 = (char *)get_all_created_runtime(&v48);
        if ( v48 > 0 )
        {
          v23 = *(_DWORD *)(a1 + 84);
          if ( *(_DWORD *)(*(_DWORD *)v22 + 376) > v23 )
          {
            V_LOCK();
            logfmt_raw((char *)v49, 0x1000u, 0, "bringup temperature too low! refuse to start mining");
            V_UNLOCK();
            zlog(
              g_zc,
              "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/god"
              "miner-origin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
              183,
              "check_if_bringup_temp_too_low",
              29,
              101,
              100,
              v49);
          }
          else
          {
            v24 = v22;
            v25 = v22;
            v26 = 0;
            do
            {
              if ( ++v26 == v48 )
                goto LABEL_34;
              v27 = *((_DWORD *)v25 + 1);
              v25 += 4;
            }
            while ( *(_DWORD *)(v27 + 376) <= v23 );
            V_LOCK();
            v43 = &v22[4 * v26];
            logfmt_raw((char *)v49, 0x1000u, 0, "bringup temperature too low! refuse to start mining");
            V_UNLOCK();
            zlog(
              g_zc,
              "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/god"
              "miner-origin_godminer-new/machine_runtime/kas_2380/machine_runtime_kas_2380.c",
              183,
              "check_if_bringup_temp_too_low",
              29,
              101,
              100,
              v49);
            do
            {
              v44 = (*(int (**)(void))(*(_DWORD *)v24 + 20))();
              v45 = dev_ctrl(v44);
              v46 = *(_DWORD *)v24;
              v24 += 4;
              (*(void (__fastcall **)(_DWORD))(v45 + 28))(*(_DWORD *)(v46 + 220));
            }
            while ( v43 != v24 );
          }
          power_off();
          while ( 1 )
            sleep(1u);
        }
        v23 = *(_DWORD *)(a1 + 84);
LABEL_34:
        v28 = (*(int (__fastcall **)(int))(a1 + 24))(v23);
        fan_pwm_set(v28);
        if ( v47 > 0 )
        {
          v29 = v21 - 1;
          for ( j = 0; j < v47; ++j )
          {
            v31 = v29[1];
            ++v29;
            redirect_nonce_output(*v21, v31);
            (*(void (**)(void))(*v29 + 216))();
          }
        }
        v32 = (*(int (__fastcall **)(int))(a1 + 36))(a1);
        if ( v47 > 0 )
        {
          v33 = v4 - 1;
          v34 = v21 - 1;
          v35 = 0;
          do
          {
            v37 = v33[1];
            ++v33;
            v36 = v37;
            ++v35;
            v38 = v34[1];
            ++v34;
            (*(void (__fastcall **)(int))(v36 + 56))(v38);
          }
          while ( v47 > v35 );
        }
        if ( !v32 )
        {
          v32 = (*(int (__fastcall **)(int, _DWORD))(a1 + 32))(a1, *(_DWORD *)(a1 + 76));
          if ( !v32 && v47 > 0 )
          {
            v39 = v21 - 1;
            for ( k = 0; k < v47; ++k )
            {
              v41 = v39[1];
              ++v39;
              (*(void (**)(void))(v41 + 120))();
              (*(void (**)(void))(*v39 + 16))();
            }
          }
        }
      }
      return v32;
    }
    return start_heartbeat_thread();
  }
}
