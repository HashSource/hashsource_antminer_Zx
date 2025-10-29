void *frontend_runtime_rvn()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173F38 = (int)stratum_connect;
  dword_173F3C = (int)stratum_disconnect;
  dword_173F40 = (int)stratum_recv_line;
  dword_173F44 = (int)stratum_send_line;
  dword_173F48 = (int)stratum_login_base;
  dword_173F4C = (int)stratum_handle_method_base;
  dword_173F50 = (int)pre_stratum_handle_method_base;
  dword_173F54 = (int)stratum_handle_response_rvn;
  dword_173F58 = (int)sub_46BDC;
  dword_173F5C = (int)sub_46B04;
  dword_173F60 = (int)sub_47610;
  dword_173F64 = (int)stratum_authorize_rvn;
  dword_173F68 = (int)sub_46498;
  LODWORD(v0) = diff_to_target_rvn;
  HIDWORD(v0) = target_to_double_diff_rvn;
  dword_173F6C = (int)sub_46480;
  dword_173F70 = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173F78 = v0;
  dword_173F74 = (int)target_to_diff_rvn;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173F38, 0x54u);
}
