package main

import "fmt"

type RequestType int

const (
	Handl1 RequestType = 1
	Handl2 RequestType = 2
	Handl3 RequestType = 3
)

type Request struct {
	description string
	requestType RequestType
}

type Handler interface {
	handler(req *Request)
	canHandler(req *Request) bool
	processRequest(req *Request)
}

type ChainHandler struct {
	NextHandler Handler
}

func (c *ChainHandler) SendRequestToNextHandler(req *Request) {
	if c.NextHandler != nil {
		c.NextHandler.handler(req)
	}
}

func (c *ChainHandler) SetNext(handler Handler) {
	c.NextHandler = handler
}

type Handl1Handler struct {
	ChainHandler
}

func (h *Handl1Handler) processRequest(req *Request) {
	fmt.Println("Handl1", req.description)
}

func (h *Handl1Handler) canHandler(req *Request) bool {
	return req.requestType == Handl1
}

func (h *Handl1Handler) handler(req *Request) {
	if h.canHandler(req) {
		h.processRequest(req)
	}
	h.SendRequestToNextHandler(req)
}

type Handl2Handler struct {
	ChainHandler
}

func (h *Handl2Handler) processRequest(req *Request) {
	fmt.Println("Handl2", req.description)
}

func (h *Handl2Handler) canHandler(req *Request) bool {
	return req.requestType == Handl2
}

func (h *Handl2Handler) handler(req *Request) {
	if h.canHandler(req) {
		h.processRequest(req)
	}
	h.SendRequestToNextHandler(req)
}

func main() {
	req1 := &Request{"request1", Handl1}
	req2 := &Request{"request2", Handl2}
	req3 := &Request{"request3", Handl3}
	handl1 := &Handl1Handler{}
	Handl2 := &Handl2Handler{}
	handl1.SetNext(Handl2)

	handl1.handler(req1)
	handl1.handler(req2)
	handl1.handler(req3)
}
