void *frontend_runtime_ltc()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173EE4 = (int)stratum_connect;
  dword_173EE8 = (int)stratum_disconnect;
  dword_173EEC = (int)stratum_recv_line;
  dword_173EF0 = (int)stratum_send_line;
  dword_173EF4 = (int)stratum_login_base;
  dword_173EF8 = (int)stratum_handle_method_base;
  dword_173EFC = (int)pre_stratum_handle_method_base;
  dword_173F00 = (int)stratum_handle_response_base;
  dword_173F04 = (int)sub_462B8;
  dword_173F08 = (int)sub_45B38;
  dword_173F0C = (int)stratum_subscribe_base;
  dword_173F10 = (int)stratum_authorize_base;
  dword_173F14 = (int)sub_45B70;
  LODWORD(v0) = diff_to_target_ltc;
  HIDWORD(v0) = target_to_double_diff_ltc;
  dword_173F18 = (int)sub_45880;
  dword_173F1C = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173F24 = v0;
  dword_173F20 = (int)target_to_diff_ltc;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173EE4, 0x54u);
}
