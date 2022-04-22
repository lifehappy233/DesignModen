package main

import (
	"fmt"

	"design.model/template/improve/lib"
)

type myBase struct {
	lib.Base
}

func (myBase) Step2() bool {
	return true
}

func (myBase) Step4() {
	fmt.Println("myBase step4()")
}

func main() {
	a := myBase{}
	lib.Run(&a)
}
