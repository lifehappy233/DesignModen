package main

import "fmt"

// 目标接口
type Target interface {
	Process()
}

// 遗留接口
type Adaptee interface {
	Foo()
	Bar()
}

type Oldclass struct {
}

func (o *Oldclass) Foo() {
	fmt.Println("Oldclass Foo")
}

func (o *Oldclass) Bar() {
	fmt.Println("Oldclass Bar")
}

type Adapter struct {
	adaptee Adaptee
}

func (a *Adapter) Process() {
	a.adaptee.Bar()
	// do something
	a.adaptee.Foo()
}

func mainWork(t Target) {
	t.Process()
}

func main() {
	adaptee := &Oldclass{}
	adapter := &Adapter{
		adaptee: adaptee,
	}
	mainWork(adapter)
}
