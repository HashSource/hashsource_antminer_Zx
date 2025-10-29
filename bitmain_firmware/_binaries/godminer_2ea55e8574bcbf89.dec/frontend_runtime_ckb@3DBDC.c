_DWORD *frontend_runtime_ckb()
{
  _DWORD *result; // r0

  result = calloc(1u, 0x54u);
  *result = stratum_connect;
  result[1] = stratum_disconnect;
  result[2] = stratum_recv_line;
  result[3] = stratum_send_line;
  result[4] = stratum_login_base;
  result[5] = stratum_handle_method_base;
  result[6] = pre_stratum_handle_method_base;
  result[7] = stratum_handle_response_base;
  result[8] = sub_3DB4C;
  result[9] = sub_3D794;
  result[10] = stratum_subscribe_base;
  result[11] = stratum_authorize_base;
  result[12] = sub_3D7CC;
  result[13] = sub_3D43C;
  result[14] = stratum_set_diff_or_target_base;
  result[15] = target_to_diff_ckb;
  result[16] = diff_to_target_ckb;
  result[17] = target_to_double_diff_ckb;
  return result;
}
