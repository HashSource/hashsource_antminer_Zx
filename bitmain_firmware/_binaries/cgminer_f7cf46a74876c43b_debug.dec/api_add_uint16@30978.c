api_data *__fastcall api_add_uint16(api_data *root, char *name, uint16_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_UINT16, data, copy_data);
}
