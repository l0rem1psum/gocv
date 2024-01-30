#include "../core.h"
#include "core.h"
#include <string.h>

void GpuRects_Close(struct Rects rs) {
    delete[] rs.rects;
}

void GpuMat_Split(GpuMat src, struct GpuMats* mats, Stream s) {
    std::vector<cv::cuda::GpuMat> channels;
    cv::cuda::split(*src, channels, *s);
    mats->mats = new GpuMat[channels.size()];

    for (size_t i = 0; i < channels.size(); ++i) {
        mats->mats[i] = new cv::cuda::GpuMat(channels[i]);
    }

    mats->length = (int)channels.size();
}


void GpuMats_Close(struct GpuMats mats) {
    delete[] mats.mats;
}

GpuMat GpuMats_get(struct GpuMats mats, int i) {
    return mats.mats[i];
}
