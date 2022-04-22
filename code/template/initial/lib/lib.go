package lib

import "fmt"

type Library struct {
}

func (Library) Step1() {
	fmt.Println("Base step1()")
}

func (Library) Step3() {
	fmt.Println("Base step3()")
}

func (Library) Step5() {
	fmt.Println("Base step5()")
}
