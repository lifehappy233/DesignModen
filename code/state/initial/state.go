package main

import "fmt"

type NetworkState int

const (
	NetworkOpen    NetworkState = 0
	NetworkClose   NetworkState = 1
	NetworkConnect NetworkState = 2
	NetworkWaite   NetworkState = 3
)

type NetworkProcessor struct {
	State NetworkState
}

func (n *NetworkProcessor) Operation() {
	if n.State == NetworkOpen {
		fmt.Printf("NetworkState is : NetworkOpen\n")
		// do something
		n.State = NetworkClose
	} else if n.State == NetworkClose {
		fmt.Printf("NetworkState is : NetworkClose\n")
		// do something
		n.State = NetworkConnect
	} else if n.State == NetworkConnect {
		fmt.Printf("NetworkState is : NetworkConnect\n")
		// do something
		n.State = NetworkWaite
	} else if n.State == NetworkWaite {
		fmt.Printf("NetworkState is : NetworkWaite\n")
		// do someghing
		n.State = NetworkClose
	}
}

func main() {
	processor := &NetworkProcessor{NetworkOpen}
	for i := 0; i < 4; i++ {
		processor.Operation()
	}
}
