#ifndef _OPENCV3_CUDA_CORE_H_
#define _OPENCV3_CUDA_CORE_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudaarithm.hpp>
extern "C" {
#endif

#include "cuda.h"

// Wrapper for the vector of GpuMat aka std::vector<GpuMat>
typedef struct GpuMats {
    GpuMat* mats;
    int length;
} GpuMats;

void GpuRects_Close(struct Rects rs);
void GpuMat_Split(GpuMat src, struct GpuMats* mats, Stream s);
void GpuMats_Close(struct GpuMats mats);
GpuMat GpuMats_get(struct GpuMats mats, int i);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDA_CORE_H_

