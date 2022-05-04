package main

import (
	"encoding/json"
	"fmt"
	"os"
)

func main() {
	writer, _ := os.Create("test")
	enc := json.NewEncoder(writer)
	val := []string{"fjdslf", "fjdsl"}
	for _, kv := range val {
		err := enc.Encode(&kv)
		if err != nil {
			fmt.Println(err)
		}
	}
}
