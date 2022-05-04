package main

import (
	"design.model/state/improve/networkstate"
)

type NetworkProcessor struct {
	State networkstate.NetworkState
}

func (n *NetworkProcessor) Operation() {
	n.State.Operation()
	n.State = n.State.GetNextState()
}

func main() {
	processor := NetworkProcessor{
		State: &networkstate.OpenState{},
	}
	for i := 0; i < 4; i++ {
		processor.Operation()
	}
}
