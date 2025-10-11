# Antminer Z15 Pro godminer print_summary

## Log Format

```
chain [ID] device [ID] wc [COUNT] nc [COUNT] detail: [STATS]
```

### Example Log Entries

```
chain 0 device 0 wc 0 nc 0 detail: 1: 10 60 5 0 0 1 /2: 8 64 6 0 0 0 /3: 11 67 4 0 0 0 /4: 9 72 10 0 0 0 /5: 11 61 4 0 0 0 /6: 10 64 2 0 0 0 /

chain 1 device 1 wc 0 nc 0 detail: 1: 12 61 2 0 0 0 /2: 18 63 7 0 0 0 /3: 12 66 8 0 0 0 /4: 9 68 5 0 0 0 /5: 9 63 3 0 0 0 /6: 12 60 11 0 0 0 /

chain 2 device 2 wc 0 nc 0 detail: 1: 0 0 0 0 0 0 /2: 0 0 0 0 0 0 /3: 0 0 0 0 0 0 /4: 0 0 0 0 0 0 /5: 0 0 0 0 0 0 /6: 0 0 0 0 0 0 /
```

---

## Runtime Data Structure

### Structure Offsets (verified in code):

| Offset  | Type    | Field Name      | Description                            |
| ------- | ------- | --------------- | -------------------------------------- |
| 55      | uint32  | Device ID       | Mining device identifier               |
| 56      | uint32  | Chain ID        | Physical hashboard ID (0-2)            |
| 304     | uint32  | Stats Count     | Number of stat entries (6 for Z15 Pro) |
| 408-415 | uint64  | NC              | Nonce count (total attempts)           |
| 416-423 | uint64  | WC              | Work count (valid solutions)           |
| 424     | pointer | Stats Array Ptr | Pointer to statistics array            |

---

## Result Code Meanings

| Code  | Type          | Description                                     | Increments WC |
| ----- | ------------- | ----------------------------------------------- | ------------- |
| **0** | Best Quality  | Valid Equihash solution, best quality tier      | Yes           |
| **1** | Good Quality  | Valid Equihash solution, alternate quality tier | Yes           |
| **2** | Lower Quality | Solution found, didn't meet difficulty target   | No            |
| **3** | Invalid       | Failed Equihash validation                      | No            |
| **4** | Error         | Duplicate nonce or hardware error               | No            |
| **5** | Error         | Hardware or validation error                    | No            |

**Special Case - Code 4:** When `platform_check_repeat_nonce()` detects a duplicate nonce, code 4 counter at offset 32 is incremented (backend_base.c:123283).

---

## Detail Statistics Format

Each chain reports **6 entries** (based on offset 304 = 6 for Z15 Pro):

```
[INDEX]: [Code0] [Code1] [Code2] [Code3] [Code4] [Code5] /
```

**Example:**

```
1: 10 60 5 0 0 1 /
```

- Entry 1 statistics:
  - Code 0: 10 solutions
  - Code 1: 60 solutions
  - Code 2: 5 solutions
  - Code 3: 0 solutions
  - Code 4: 0 errors
  - Code 5: 1 error

---

## Example Log Analysis

### Chain 0 - Active & Healthy

```
chain 0 device 0 wc 0 nc 0 detail:
  1: 10 60 5 0 0 1
  2: 8 64 6 0 0 0
  3: 11 67 4 0 0 0
  4: 9 72 10 0 0 0
  5: 11 61 4 0 0 0
  6: 10 64 2 0 0 0
```

#### Per-Entry Breakdown

| Entry     | Code 0 | Code 1  | Code 2 | Code 3 | Code 4 | Code 5 | Valid (0+1) | Total   | Error %  |
| --------- | ------ | ------- | ------ | ------ | ------ | ------ | ----------- | ------- | -------- |
| 1         | 10     | 60      | 5      | 0      | 0      | 1      | 70          | 76      | 1.3%     |
| 2         | 8      | 64      | 6      | 0      | 0      | 0      | 72          | 78      | 0%       |
| 3         | 11     | 67      | 4      | 0      | 0      | 0      | 78          | 82      | 0%       |
| 4         | 9      | 72      | 10     | 0      | 0      | 0      | 81          | 91      | 0%       |
| 5         | 11     | 61      | 4      | 0      | 0      | 0      | 72          | 76      | 0%       |
| 6         | 10     | 64      | 2      | 0      | 0      | 0      | 74          | 76      | 0%       |
| **Total** | **59** | **388** | **31** | **0**  | **0**  | **1**  | **447**     | **479** | **0.2%** |

**Status:** Healthy - All 6 entries producing valid solutions with minimal errors (1 code-5 error total).

**Solution Quality Distribution:**

- Code 0 (Best): 59 (12.3%)
- Code 1 (Good): 388 (81.0%)
- Code 2 (Low): 31 (6.5%)
- Errors (3-5): 1 (0.2%)

---

### Chain 1 - Active & Healthy

```
chain 1 device 1 wc 0 nc 0 detail:
  1: 12 61 2 0 0 0
  2: 18 63 7 0 0 0
  3: 12 66 8 0 0 0
  4: 9 68 5 0 0 0
  5: 9 63 3 0 0 0
  6: 12 60 11 0 0 0
```

#### Per-Entry Statistics

| Entry     | Code 0 | Code 1  | Code 2 | Code 3-5 | Valid (0+1) | Total   | Error % |
| --------- | ------ | ------- | ------ | -------- | ----------- | ------- | ------- |
| 1         | 12     | 61      | 2      | 0        | 73          | 75      | 0%      |
| 2         | 18     | 63      | 7      | 0        | 81          | 88      | 0%      |
| 3         | 12     | 66      | 8      | 0        | 78          | 86      | 0%      |
| 4         | 9      | 68      | 5      | 0        | 77          | 82      | 0%      |
| 5         | 9      | 63      | 3      | 0        | 72          | 75      | 0%      |
| 6         | 12     | 60      | 11     | 0        | 72          | 83      | 0%      |
| **Total** | **72** | **381** | **36** | **0**    | **453**     | **489** | **0%**  |

**Status:** Healthy - All 6 entries producing valid solutions, zero errors.

---

### Chain 2 - DEAD/INACTIVE

```
chain 2 device 2 wc 0 nc 0 detail:
  1: 0 0 0 0 0 0
  2: 0 0 0 0 0 0
  3: 0 0 0 0 0 0
  4: 0 0 0 0 0 0
  5: 0 0 0 0 0 0
  6: 0 0 0 0 0 0
```

**Status:** Dead - No activity detected on hashboard 3.

**Possible Causes:**

- Hashboard not connected/detected
- Power supply issue to this hashboard
- Complete hashboard failure
- Chain disabled in configuration

---

## Performance Overview

### Miner-Wide Statistics

```
Physical Hashboards:          3 total
Active Hashboards:            2/3 (66.7%)
Total Stat Entries:           18 (6 per hashboard)
Active Entries:               12/18 (66.7%)
Total Valid Solutions:        900 (codes 0+1)
Total Low-Quality:            67 (code 2)
Total Errors:                 1 (codes 3-5)
Overall Error Rate:           0.1%
```

### Solution Quality Distribution (Active Chains)

```
Code 0 (Best Quality):   131 (14.5%)  ███████
Code 1 (Good Quality):   769 (85.3%)  █████████████████████████████████████████
Code 2 (Lower Quality):   67 (0.2%)   ▌
Errors (3-5):              1 (0.1%)   ▏
```

### Health Distribution

```
Healthy Entries:  ████████████ 12 entries (chains 0-1: 2 × 6 entries)
Dead Entries:     ██████ 6 entries (chain 2: 1 × 6 entries)
```

---

**Reference:** Based on godminer binary analysis and Z15 Pro firmware examination
**Binary Hash:** 2ea55e8574bcbf89
