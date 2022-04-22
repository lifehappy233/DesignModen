package main

import (
	"fmt"
	"sync"

	"sync/atomic"
)

type Value struct {
	value atomic.Value
}

var val Value

type Singleton struct {
	value *Value
	mu    sync.Mutex
}

func NewSingleton() *Singleton {
	return &Singleton{value: &val}
}

// 通过一个原子变量来实现
func (s *Singleton) GetValue() string {
	val := s.value.value.Load()
	if val != nil {
		return val.(string)
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	val = s.value.value.Load()
	if val == nil {
		val = "value"
		s.value.value.Store(val)
	}
	return val.(string)
}

func main() {
	fi := NewSingleton()
	se := NewSingleton()
	fmt.Println(fi.GetValue())
	fmt.Println(se.GetValue())
}
