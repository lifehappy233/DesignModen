package lib

import "fmt"

type Library interface {
	Step1()
	Step2() bool
	Step3()
	Step4()
	Step5()
}

func Run(l Library) {
	l.Step1()

	if l.Step2() {
		l.Step3()
	}

	for i := 0; i < 4; i++ {
		l.Step4()
	}

	l.Step5()
}

type Base struct {
}

func (Base) Step1() {
	fmt.Println("Base step1()")
}

func (Base) Step3() {
	fmt.Println("Base step3()")
}

func (Base) Step5() {
	fmt.Println("Base step5()")
}
