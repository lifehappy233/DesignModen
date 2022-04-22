package main

import (
	"fmt"

	"design.model/template/initial/lib"
)

type myLibrary struct {
	lib.Library
}

func (myLibrary) Step2() bool {
	return true
}

func (myLibrary) Step4() {
	fmt.Println("myLibrary step4()")
}

func main() {
	l := myLibrary{}

	l.Step1()

	if l.Step2() {
		l.Step3()
	}

	for i := 0; i < 4; i++ {
		l.Step4()
	}

	l.Step5()
}
