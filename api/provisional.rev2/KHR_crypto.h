
/*******************************************************
 * OpenKODE Core extension: KD_KHR_crypto
 *******************************************************/
/* Sample KD/KHR_crypto.h for OpenKODE Core */
#ifndef __kd_KHR_crypto_h_
#define __kd_KHR_crypto_h_
#include <KD/kd.h>

#ifdef __cplusplus
extern "C" {
#endif



/* kdCipherInitKHR: Initializes a cipher. */
typedef struct KDCipherKHR KDCipherKHR;
KD_API KDCipherKHR *KD_APIENTRY kdCipherInitKHR(KDint type, const KDuint8 *key, KDint keyLen, const KDuint8 *iv, KDint ivLen);
#define KD_AES_128_CBC_SSL_ENCRYPT_KHR 80
#define KD_AES_128_CBC_SSL_DECRYPT_KHR 81
#define KD_AES_128_ECB_SSL_ENCRYPT_KHR 82
#define KD_AES_128_ECB_SSL_DECRYPT_KHR 83
#define KD_AES_128_CBC_NONE_ENCRYPT_KHR 84
#define KD_AES_128_CBC_NONE_DECRYPT_KHR 85
#define KD_AES_128_ECB_NONE_ENCRYPT_KHR 86
#define KD_AES_128_ECB_NONE_DECRYPT_KHR 87
#define KD_AES_192_CBC_SSL_ENCRYPT_KHR 88
#define KD_AES_192_CBC_SSL_DECRYPT_KHR 89
#define KD_AES_192_ECB_SSL_ENCRYPT_KHR 90
#define KD_AES_192_ECB_SSL_DECRYPT_KHR 91
#define KD_AES_192_CBC_NONE_ENCRYPT_KHR 92
#define KD_AES_192_CBC_NONE_DECRYPT_KHR 93
#define KD_AES_192_ECB_NONE_ENCRYPT_KHR 94
#define KD_AES_192_ECB_NONE_DECRYPT_KHR 95
#define KD_AES_256_CBC_SSL_ENCRYPT_KHR 96
#define KD_AES_256_CBC_SSL_DECRYPT_KHR 97
#define KD_AES_256_ECB_SSL_ENCRYPT_KHR 98
#define KD_AES_256_ECB_SSL_DECRYPT_KHR 99
#define KD_AES_256_CBC_NONE_ENCRYPT_KHR 100
#define KD_AES_256_CBC_NONE_DECRYPT_KHR 101
#define KD_AES_256_ECB_NONE_ENCRYPT_KHR 102
#define KD_AES_256_ECB_NONE_DECRYPT_KHR 103

/* kdCipherKHR: Encrypt or decrypt data. */
KD_API KDint KD_APIENTRY kdCipherKHR(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherFinalKHR: Finishes encrypting or decrypting data. */
KD_API KDint KD_APIENTRY kdCipherFinalKHR(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherResultKHR: Returns an encryption result. */
KD_API KDint KD_APIENTRY kdCipherResultKHR(KDCipherKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdCipherReinitKHR: Re-initializes a cipher. */
KD_API KDCipherKHR *KD_APIENTRY kdCipherReinitKHR(KDCipherKHR *c, const KDuint8 *key, KDint keyLen, const KDuint8 *iv, KDint ivLen);

/* kdHashInitKHR: Initializes a hash. */
typedef struct KDHashKHR KDHashKHR;
KD_API KDHashKHR *KD_APIENTRY kdHashInitKHR(KDint type);
#define KD_SHA1_KHR 104

/* kdHashKHR: Hash data. */
typedef KDint KD_APIENTRY kdHashKHR(KDHashKHR *c, const KDuint8 *data, KDint dataLen);

/* kdHashFinalKHR: Finishes hashing data. */
KD_API KDint KD_APIENTRY kdHashFinalKHR(KDHashKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

/* kdHashResultKHR: Finishes hashing data without deleting the hash object. */
KD_API KDint KD_APIENTRY kdHashResultKHR(KDHashKHR *c, const KDuint8 *data, KDint dataLen, KDuint8 *out, KDint *outLen);

#ifdef __cplusplus
}
#endif

#endif /* __kd_KHR_crypto_h_ */

