/* Sample KD/kdext.h for OpenKODE Core */
#ifndef __kdext_h_
#define __kdext_h_

#ifdef __cplusplus
extern "C" {
#endif

#include "KD/kd.h"



/*******************************************************
 * OpenKODE Core extension: KD_KHR_crypto
 *******************************************************/
#define KD_CRYPTO_RANDOM_FAIL_KHR (-1)

/* KDCipherKHR: The opaque representation of a cipher state. */
typedef struct KDCipherKHR KDCipherKHR;

/* KDHashKHR: The opaque representation of a digest state. */
typedef struct KDHashKHR KDHashKHR;

/* KDcipherTypeKHR: Enums for supported ciphers. */
typedef enum {
    KD_AES_128_CBC_SSL_ENCRYPT_KHR, 
    KD_AES_128_CBC_SSL_DECRYPT_KHR, 
    KD_AES_128_ECB_SSL_ENCRYPT_KHR, 
    KD_AES_128_ECB_SSL_DECRYPT_KHR, 
    KD_AES_128_CBC_NONE_ENCRYPT_KHR, 
    KD_AES_128_CBC_NONE_DECRYPT_KHR, 
    KD_AES_128_ECB_NONE_ENCRYPT_KHR, 
    KD_AES_128_ECB_NONE_DECRYPT_KHR, 
    KD_AES_192_CBC_SSL_ENCRYPT_KHR, 
    KD_AES_192_CBC_SSL_DECRYPT_KHR, 
    KD_AES_192_ECB_SSL_ENCRYPT_KHR, 
    KD_AES_192_ECB_SSL_DECRYPT_KHR, 
    KD_AES_192_CBC_NONE_ENCRYPT_KHR, 
    KD_AES_192_CBC_NONE_DECRYPT_KHR, 
    KD_AES_192_ECB_NONE_ENCRYPT_KHR, 
    KD_AES_192_ECB_NONE_DECRYPT_KHR, 
    KD_AES_256_CBC_SSL_ENCRYPT_KHR, 
    KD_AES_256_CBC_SSL_DECRYPT_KHR, 
    KD_AES_256_ECB_SSL_ENCRYPT_KHR, 
    KD_AES_256_ECB_SSL_DECRYPT_KHR, 
    KD_AES_256_CBC_NONE_ENCRYPT_KHR, 
    KD_AES_256_CBC_NONE_DECRYPT_KHR, 
    KD_AES_256_ECB_NONE_ENCRYPT_KHR, 
    KD_AES_256_ECB_NONE_DECRYPT_KHR
} KDcipherTypeKHR;

/* KDhashTypeKHR: The type of hash. */
typedef enum {
  KD_SHA1_KHR
} KDhashTypeKHR;

/* kdCipherInitKHR: Initializes a cipher. */
typedef KDCipherKHR *(*KD_APIENTRY PFNKDCIPHERINITKHR)(KDcipherTypeKHR type, const KDuint8 *key, KDint keyLen, const KDuint8 *iv, KDint ivLen);

/* kdCipherKHR: Encrypt or decrypt data. */
typedef KDint (*KD_APIENTRY PFNKDCIPHERKHR)(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherFinalKHR: Finishes encrypting or decrypting data. */
typedef KDint (*KD_APIENTRY PFNKDCIPHERFINALKHR)(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherResultKHR: Returns an encryption result. */
typedef KDint (*KD_APIENTRY PFNKDCIPHERRESULTKHR)(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherReinitKHR: Re-initializes a cipher. */
typedef KDCipherKHR *(*KD_APIENTRY PFNKDCIPHERREINITKHR)(KDCipherKHR *c, const KDuint8 *key, KDint keyLen, const KDuint8 *iv, KDint ivLen);

/* kdHashInitKHR: Initializes a hash. */
typedef KDHashKHR *(*KD_APIENTRY PFNKDHASHINITKHR)(KDhashTypeKHR type);

/* kdHashKHR: Hash data. */
typedef KDint (*KD_APIENTRY PFNKDHASHKHR)(KDHashKHR *c, const KDuint8 *data, KDint dataLen);

/* kdHashFinalKHR: Finishes hashing data. */
typedef KDint (*KD_APIENTRY PFNKDHASHFINALKHR)(KDHashKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdHashResultKHR: Finishes hashing data without deleting the hash object. */
typedef KDint (*KD_APIENTRY PFNKDHASHRESULTKHR)(KDHashKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/*******************************************************
 * OpenKODE Core extension: KD_KHR_perfcounter
 *******************************************************/
#define KD_INFINITE_COUNTER_VAL_KHR (DBL_MAX)
#define KD_UNKNOWN_COUNTER_VAL_KHR (-1)

/* KDCounterInfoKHR: Information on a single performance counter. */
typedef struct KDCounterInfoKHR {
    const KDchar *st_vendorName;
    const KDchar *st_name;
    const KDchar *st_description;
    KDint64 d_minValue;
    KDint64 d_maxValue;
    KDfloat32 d_defaultScale;
} KDCounterInfoKHR;

/* kdGetNumberOfCountersKHR: Return the number of performance counters. */
typedef KDint (*KD_APIENTRY PFNKDGETNUMBEROFCOUNTERSKHR)(void);

/* kdGetCounterInformationKHR: Retrieve information on a performance counter. */
typedef const KDCounterInfoKHR *(*KD_APIENTRY PFNKDGETCOUNTERINFORMATIONKHR)(KDint index);

/* kdActivateCountersKHR: Make counters active. */
typedef KDint (*KD_APIENTRY PFNKDACTIVATECOUNTERSKHR)(const KDint *indexes, KDint numindexes);

/* kdDeactivateCountersKHR: Makes counters inactive. */
typedef KDint (*KD_APIENTRY PFNKDDEACTIVATECOUNTERSKHR)(const KDint *indexes, KDint numindexes);

/* kdStartSamplingKHR: Start the performance counters sampling. */
typedef KDint (*KD_APIENTRY PFNKDSTARTSAMPLINGKHR)(void);

/* kdStopSamplingKHR: Stop the performance counters sampling. */
typedef KDint (*KD_APIENTRY PFNKDSTOPSAMPLINGKHR)(void);

/* kdGetCounterValuesKHR: Retrieves list of counter values. */
typedef KDint (*KD_APIENTRY PFNKDGETCOUNTERVALUESKHR)(const KDint *indexes, KDint numindexes, KDint64 *values);

#ifdef __cplusplus
}
#endif

#endif /* __kdext_h_ */

