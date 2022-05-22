package main

import "fmt"

type Element interface {
	Process(v Visitor)
}

type Element1 struct {
}

func (e *Element1) Process(v Visitor) {
	v.ProcessElement1(e)
}

type Element2 struct {
}

func (e *Element2) Process(v Visitor) {
	v.ProcessElement2(e)
}

type Visitor interface {
	ProcessElement1(e Element)
	ProcessElement2(e Element)
}

type Visitor1 struct {
}

func (v *Visitor1) ProcessElement1(e Element) {
	fmt.Println("Visitor1 process Element1")
}

func (v *Visitor1) ProcessElement2(e Element) {
	fmt.Println("Visitor1 process Element2")
}

type Visitor2 struct {
}

func (v *Visitor2) ProcessElement1(e Element) {
	fmt.Println("Visitor2 process Element1")
}

func (v *Visitor2) ProcessElement2(e Element) {
	fmt.Println("Visitor2 process Element2")
}

func main() {
	element1 := &Element1{}
	element2 := &Element2{}

	visitor1 := &Visitor1{}
	visitor2 := &Visitor2{}

	element1.Process(visitor1)
	element1.Process(visitor2)
	element2.Process(visitor1)
	element2.Process(visitor2)
}
