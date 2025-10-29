api_data *__fastcall api_add_avg(api_data *root, char *name, float *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_AVG, data, copy_data);
}
