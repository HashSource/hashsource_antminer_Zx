void *frontend_runtime_kas()
{
  __int64 v0; // r2
  void *v1; // r0

  dword_173E3C = (int)stratum_connect;
  dword_173E40 = (int)stratum_disconnect;
  dword_173E44 = (int)stratum_recv_line;
  dword_173E48 = (int)stratum_send_line;
  dword_173E4C = (int)stratum_login_base;
  dword_173E50 = (int)stratum_handle_method_base;
  dword_173E54 = (int)pre_stratum_handle_method_base;
  dword_173E58 = (int)stratum_handle_response_kas;
  dword_173E5C = (int)sub_4458C;
  dword_173E60 = (int)sub_43890;
  dword_173E64 = (int)sub_4503C;
  dword_173E68 = (int)stratum_authorize_kas;
  dword_173E6C = (int)sub_43D10;
  LODWORD(v0) = diff_to_target_kas;
  HIDWORD(v0) = target_to_double_diff_kas;
  dword_173E70 = (int)sub_43A1C;
  dword_173E74 = (int)stratum_set_diff_or_target_base;
  *(_QWORD *)&dword_173E7C = v0;
  dword_173E78 = (int)target_to_diff_kas;
  v1 = calloc(1u, 0x54u);
  return memcpy(v1, &dword_173E3C, 0x54u);
}
