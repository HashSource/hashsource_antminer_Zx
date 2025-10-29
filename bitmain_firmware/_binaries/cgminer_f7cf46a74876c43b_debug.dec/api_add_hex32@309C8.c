api_data *__fastcall api_add_hex32(api_data *root, char *name, uint32_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_HEX32, data, copy_data);
}
