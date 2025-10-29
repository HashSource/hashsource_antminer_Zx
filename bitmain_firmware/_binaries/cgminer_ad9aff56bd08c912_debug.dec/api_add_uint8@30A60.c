api_data *__fastcall api_add_uint8(api_data *root, char *name, uint8_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_UINT8, data, copy_data);
}
