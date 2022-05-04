package networkstate

import "fmt"

type NetworkState interface {
	Operation()
	GetNextState() NetworkState
}

type OpenState struct {
	NextState NetworkState
}

func (o *OpenState) Operation() {
	fmt.Printf("NetworkState is : NetworkOpen\n")
	o.NextState = &CloseState{}
}

func (o *OpenState) GetNextState() NetworkState {
	return o.NextState
}

type CloseState struct {
	NextState NetworkState
}

func (c *CloseState) Operation() {
	fmt.Printf("NetworkState is : NetworkClose\n")
	c.NextState = &ConnectState{}
}

func (c *CloseState) GetNextState() NetworkState {
	return c.NextState
}

type ConnectState struct {
	NextState NetworkState
}

func (c *ConnectState) Operation() {
	fmt.Printf("NetworkState is : NetworkConnect\n")
	c.NextState = &WaiteState{}
}

func (c *ConnectState) GetNextState() NetworkState {
	return c.NextState
}

type WaiteState struct {
	NextState NetworkState
}

func (w *WaiteState) Operation() {
	fmt.Printf("NetworkState is : NetworkWaite\n")
	w.NextState = &OpenState{}
}

func (w *WaiteState) GetNextState() NetworkState {
	return w.NextState
}
