void *frontend_runtime_dash()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173CA8 = (int)stratum_connect;
  dword_173CAC = (int)stratum_disconnect;
  dword_173CB0 = (int)stratum_recv_line;
  dword_173CB4 = (int)stratum_send_line;
  dword_173CB8 = (int)stratum_login_base;
  dword_173CBC = (int)stratum_handle_method_base;
  dword_173CC0 = (int)pre_stratum_handle_method_base;
  dword_173CC4 = (int)stratum_handle_response_base;
  dword_173CC8 = (int)sub_3ED60;
  dword_173CCC = (int)sub_3DFBC;
  dword_173CD0 = (int)stratum_subscribe_base;
  dword_173CD4 = (int)stratum_authorize_base;
  dword_173CD8 = (int)sub_3E028;
  LODWORD(v0) = diff_to_target_dash;
  HIDWORD(v0) = target_to_double_diff_dash;
  dword_173CDC = (int)sub_3DCC8;
  dword_173CE0 = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173CE8 = v0;
  dword_173CE4 = (int)target_to_diff_dash;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173CA8, 0x54u);
}
