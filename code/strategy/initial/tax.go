package main

import "fmt"

type TaxCountry int

// enum
const (
	CNTax TaxCountry = 1
	USTax TaxCountry = 2
	FRTax TaxCountry = 3
	JPTax TaxCountry = 4
)

type SalesOrder struct {
	tax TaxCountry
}

func (s *SalesOrder) CalculateTax() {
	switch s.tax {
	case CNTax:
		// CN
	case USTax:
		// US
	case FRTax:
		// FR
	case JPTax:
		// JP
	default:
		fmt.Println("no that country")
	}
}
