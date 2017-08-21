package singleton

import (
	"sync"
	"sync/atomic"
)

var initialized uint32 = 0
var instance *map[string]string
var m Sync.Mutex

func GetInstance() *singleton {
	if atomic.LoadUint32(&initialized) == 1 {
		return instance
	}
	m.Lock()
	defer m.Unlock()
	if initialized == 0 {
	        instance = &map[string]string{}
		atomic.StoreUint32(&initialized, 1)
	}
	return instance
}
