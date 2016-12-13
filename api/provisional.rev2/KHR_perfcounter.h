
/*******************************************************
 * OpenKODE Core extension: KD_KHR_perfcounter
 *******************************************************/
/* Sample KD/KHR_perfcounter.h for OpenKODE Core */
#ifndef __kd_KHR_perfcounter_h_
#define __kd_KHR_perfcounter_h_
#include <KD/kd.h>

#ifdef __cplusplus
extern "C" {
#endif


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

#endif /* __kd_KHR_perfcounter_h_ */

