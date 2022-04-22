package main

type TaxStrategy interface {
	Calculate() float64
}

type CNTax struct {
}

func (c *CNTax) Calculate() float64 {
	return 0
}

type USTax struct {
}

func (c *USTax) Calculate() float64 {
	return 0
}

type FRTax struct {
}

func (f *FRTax) Calculate() float64 {
	return 0
}

type JPTax struct {
}

func (j *JPTax) Calculate() float64 {
	return 0
}

type SalesOrder struct {
	straregy TaxStrategy
}

func (s *SalesOrder) CalculateTax() float64 {
	/*
		......
	*/
	return s.straregy.Calculate()
}
