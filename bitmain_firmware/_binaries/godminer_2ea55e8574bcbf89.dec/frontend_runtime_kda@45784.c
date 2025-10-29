void *frontend_runtime_kda()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173E90 = (int)stratum_connect;
  dword_173E94 = (int)stratum_disconnect;
  dword_173E98 = (int)stratum_recv_line;
  dword_173E9C = (int)stratum_send_line;
  dword_173EA0 = (int)stratum_login_base;
  dword_173EA4 = (int)stratum_handle_method_base;
  dword_173EA8 = (int)pre_stratum_handle_method_base;
  dword_173EAC = (int)stratum_handle_response_base;
  dword_173EB0 = (int)sub_456EC;
  dword_173EB4 = (int)sub_45150;
  dword_173EB8 = (int)stratum_subscribe_base;
  dword_173EBC = (int)stratum_authorize_base;
  dword_173EC0 = (int)sub_45418;
  LODWORD(v0) = diff_to_target_kda;
  HIDWORD(v0) = target_to_double_diff_kda;
  dword_173EC4 = (int)sub_45184;
  dword_173EC8 = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173ED0 = v0;
  dword_173ECC = (int)target_to_diff_kda;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173E90, 0x54u);
}
