package cuda

/*
#include <stdlib.h>
#include "../core.h"
#include "core.h"
*/
import "C"
import (
	"image"
	"reflect"
	"unsafe"
)

func toRectangles(ret C.Rects) []image.Rectangle {
	cArray := ret.rects
	length := int(ret.length)
	hdr := reflect.SliceHeader{
		Data: uintptr(unsafe.Pointer(cArray)),
		Len:  length,
		Cap:  length,
	}
	s := *(*[]C.Rect)(unsafe.Pointer(&hdr))

	rects := make([]image.Rectangle, length)
	for i, r := range s {
		rects[i] = image.Rect(int(r.x), int(r.y), int(r.x+r.width), int(r.y+r.height))
	}
	return rects
}

func Split(src GpuMat) (mv []GpuMat) {
	cGpuMats := C.struct_GpuMats{}
	C.GpuMat_Split(src.p, &(cGpuMats), nil)
	defer C.GpuMats_Close(cGpuMats)
	mv = make([]GpuMat, cGpuMats.length)
	for i := C.int(0); i < cGpuMats.length; i++ {
		mv[i].p = C.GpuMats_get(cGpuMats, i)
	}
	return
}

func (m *GpuMat) Ptr() C.GpuMat {
	return m.p
}

