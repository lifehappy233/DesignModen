package main

import (
	"fmt"
	"hash/fnv"
)

func ihash(key string) int {
	h := fnv.New32a()
	h.Write([]byte(key))
	return int(h.Sum32() & 0x7fffffff)
}

func main() {
	fmt.Println(ihash("aaa"))
}
