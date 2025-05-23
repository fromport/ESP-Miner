#ifndef BM1366_H_
#define BM1366_H_

#include "common.h"
#include "driver/gpio.h"
#include "mining.h"

#define ASIC_BM1366_JOB_FREQUENCY_MS 2000

#define BM1366_ASIC_DIFFICULTY 256

#define BM1366_SERIALTX_DEBUG false
#define BM1366_SERIALRX_DEBUG false
#define BM1366_DEBUG_WORK false //causes insane amount of debug output
#define BM1366_DEBUG_JOBS false //causes insane amount of debug output

static const uint64_t BM1366_CORE_COUNT = 112;
static const uint64_t BM1366_SMALL_CORE_COUNT = 894;

typedef struct __attribute__((__packed__))
{
    uint8_t job_id;
    uint8_t num_midstates;
    uint8_t starting_nonce[4];
    uint8_t nbits[4];
    uint8_t ntime[4];
    uint8_t merkle_root[32];
    uint8_t prev_block_hash[32];
    uint8_t version[4];
} BM1366_job;

uint8_t BM1366_init(uint64_t frequency, uint16_t asic_count);
void BM1366_send_work(void * GLOBAL_STATE, bm_job * next_bm_job);
void BM1366_set_job_difficulty_mask(int);
void BM1366_set_version_mask(uint32_t version_mask);
int BM1366_set_max_baud(void);
int BM1366_set_default_baud(void);
void BM1366_send_hash_frequency(float frequency);
bool BM1366_set_frequency(float target_freq);
task_result * BM1366_process_work(void * GLOBAL_STATE);

#endif /* BM1366_H_ */
