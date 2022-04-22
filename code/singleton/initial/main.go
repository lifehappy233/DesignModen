package main

import (
	"sync"
)

type Value struct {
	value interface{}
}

var val Value

type Singleton struct {
	value *Value
	mu    sync.Mutex
}

func NewSingleton() *Singleton {
	return &Singleton{value: &val}
}

// 直接加锁，代价太高
func (s *Singleton) GetValue1() string {
	s.mu.Lock()
	defer s.mu.Unlock()
	if s.value.value == nil {
		s.value.value = "value"
	}
	return s.value.value.(string)
}

// 有可能因为 内存读写reload不安全
func (s *Singleton) GetValue2() string {
	if s.value.value != nil {
		return s.value.value.(string)
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	if s.value.value == nil {
		s.value.value = "value"
	}
	return s.value.value.(string)
}

func main() {

}
