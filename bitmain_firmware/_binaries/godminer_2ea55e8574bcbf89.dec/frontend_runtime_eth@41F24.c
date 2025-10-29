void *frontend_runtime_eth()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173D50 = (int)stratum_connect;
  dword_173D54 = (int)stratum_disconnect;
  dword_173D58 = (int)stratum_recv_line;
  dword_173D5C = (int)stratum_send_line;
  dword_173D60 = (int)stratum_login_base;
  dword_173D64 = (int)stratum_handle_method_eth;
  dword_173D68 = (int)pre_stratum_handle_method_eth;
  dword_173D6C = (int)stratum_handle_response_eth;
  dword_173D70 = (int)sub_40ED8;
  dword_173D74 = (int)sub_40E00;
  dword_173D78 = (int)sub_3FFB4;
  dword_173D7C = (int)stratum_authorize_eth;
  dword_173D80 = (int)sub_40938;
  LODWORD(v0) = diff_to_target_eth;
  HIDWORD(v0) = target_to_double_diff_eth;
  dword_173D84 = (int)sub_40750;
  dword_173D88 = (int)sub_40570;
  *(_QWORD *)&dword_173D90 = v0;
  dword_173D8C = (int)target_to_diff_eth;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173D50, 0x54u);
}
