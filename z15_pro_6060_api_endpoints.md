# Bitmain Antminer Z15 Pro - Port 6060 API Documentation

## Overview

The Bitmain Z15 Pro godminer binary exposes a simple HTTP API on port 6060 for monitoring and retrieving miner information. This API is used internally for status monitoring and diagnostics.

**Binary Information:**

- **File**: `godminer_2ea55e8574bcbf89`
- **MD5**: `8207f1afddbb2f6fe549017081521a7e`
- **SHA256**: `2ea55e8574bcbf89d9c081fbc69fd54b9608be53bc5219411f42dbf9e215c784`

## API Endpoints

### 1. GET /rate

Returns the current sale hashrate of the miner.

**Implementation**: `get_miner_sale_hashrate()` @ `0x2ec74`

---

### 2. GET /ideal_rate

Returns the theoretical ideal hashrate for the miner configuration.

**Implementation**: `get_theory_hashrate()` @ `0x2f0d4`

---

### 3. GET /max_rate

Returns the maximum expected hashrate (102% of theoretical).

**Implementation**: `(get_theory_hashrate() * 102) / 100`

---

### 4. GET /test or GET /test.{id1}.{id2}

Generic test endpoint with optional parameters.

**URL Parameters**:

- `id1`: First test parameter (integer)
- `id2`: Second test parameter (integer)

**Special Behavior**:

- When `id1 = 523`: Returns detailed miner information via `get_miner_info()` @ `0x2eb74`
- Otherwise: Returns acknowledgment message

**Implementation**: Parses parameters using `sscanf(url, "/test.%d.%d", &id1, &id2)`

---

### 5. GET /miner_status

Returns the current status of the miner.

---

### 6. GET /productName

Returns the product name/model of the miner.

**Implementation**: Returns global variable `g_miner_type`

---

### 7. GET /get_sn

Retrieves the miner's serial number from persistent storage.

**Storage Location**:

- Primary: `/config/sn`
- Alternate: `/sn/sn`

**Implementation**:

- Reads 17-byte serial number from file at `g_miner_sn_file_path`
- Uses `fopen64()`, `fread()`, `fclose()`

---

### 8. GET /set_sn

Attempts to set/update the miner's serial number.

**Status**: **DISABLED** in release builds

---

## Testing Examples

### Using curl

```bash
# Get current hashrate
curl http://<miner-ip>:6060/rate

# Get product name
curl http://<miner-ip>:6060/productName

# Get serial number
curl http://<miner-ip>:6060/get_sn

# Get ideal hashrate
curl http://<miner-ip>:6060/ideal_rate

# Get max hashrate
curl http://<miner-ip>:6060/max_rate

# Test endpoint
curl http://<miner-ip>:6060/test.523.0

# Get miner status
curl http://<miner-ip>:6060/miner_status
```
