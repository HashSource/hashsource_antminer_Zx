void *frontend_runtime_dcr()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173CFC = (int)stratum_connect;
  dword_173D00 = (int)stratum_disconnect;
  dword_173D04 = (int)stratum_recv_line;
  dword_173D08 = (int)stratum_send_line;
  dword_173D0C = (int)stratum_login_base;
  dword_173D10 = (int)stratum_handle_method_base;
  dword_173D14 = (int)pre_stratum_handle_method_base;
  dword_173D18 = (int)stratum_handle_response_base;
  dword_173D1C = (int)sub_3FDB8;
  dword_173D20 = (int)sub_3FD50;
  dword_173D24 = (int)stratum_subscribe_base;
  dword_173D28 = (int)stratum_authorize_base;
  dword_173D2C = (int)sub_3F264;
  LODWORD(v0) = diff_to_target_dcr;
  HIDWORD(v0) = target_to_double_diff_dcr;
  dword_173D30 = (int)sub_3EF28;
  dword_173D34 = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173D3C = v0;
  dword_173D38 = (int)target_to_diff_dcr;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173CFC, 0x54u);
}
