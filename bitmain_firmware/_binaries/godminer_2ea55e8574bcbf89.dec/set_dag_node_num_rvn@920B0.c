int __fastcall set_dag_node_num_rvn(int a1, int a2, int a3, int a4)
{
  int v8; // [sp+4h] [bp-100Ch]
  char v9[4096]; // [sp+10h] [bp-1000h] BYREF

  V_LOCK();
  logfmt_raw(v9, 0x1000u, 0, "%s at %llx ...", "set_dag_node_num_rvn", v8, a3, a4);
  V_UNLOCK();
  zlog(
    g_zc,
    "/workspace/jenkins/jenkins/workspace/Antminer_Z15-Pro_release/build/rootfs/buildroot/tmp/release/build/godminer-orig"
    "in_godminer-new/backend/backend_rvn_2020/backend_rvn_2020.c",
    175,
    "set_dag_node_num_rvn",
    20,
    1895,
    60,
    v9);
  sub_9206C(a1, 27, a3);
  usleep(0x3E8u);
  return 0;
}
